#include <gtest/gtest.h>
#include <sm/BoostPropertyTree.hpp>
#include <sm/value_store/LayeredValueStore.hpp>
#include <sm/value_store/PropertyTreeValueStore.hpp>
#include <sm/value_store/VerboseValueStore.hpp>

TEST(ValueStoreSuite, isEmpty)
{
  sm::BoostPropertyTree pt;

  EXPECT_EQ(pt.begin(), pt.end()); // empty condition

  sm::ExtendibleValueStoreRef vpt(pt);

  EXPECT_TRUE(vpt.isEmpty());

  pt.setDouble("d", 0.1);

  EXPECT_FALSE(vpt.isEmpty());
}

namespace sm {
class NonExtendiblePropertyTreeValueStore : public PropertyTreeValueStore {
  using PropertyTreeValueStore::PropertyTreeValueStore;
  bool isExtendible() const override {
    return false;
  }
};
}  // namespace sm

TEST(ValueStoreSuite, isExtendible)
{
  sm::BoostPropertyTree pt;
  sm::NonExtendiblePropertyTreeValueStore pt2 = sm::NonExtendiblePropertyTreeValueStore(pt);
  sm::ValueStoreRef vpt(static_cast<sm::ValueStore&>(pt2));
  sm::ValueStoreRef evpt = sm::ExtendibleValueStoreRef(pt);

  EXPECT_FALSE(vpt.isExtendible());
  EXPECT_TRUE(evpt.isExtendible());

  EXPECT_THROW(vpt.asExtendible(), std::runtime_error);
  EXPECT_NO_THROW(evpt.asExtendible());
}
 
TEST(ValueStoreSuite, testSimplePropertyTreeValueStore)
{
  sm::BoostPropertyTree pt;

  pt.setDouble("d", 0.1);
  pt.setDouble("d/i", 10);
  pt.setDouble("d/d", 0.2);
  pt.setDouble("d/d/d", 0.3);
  pt.setDouble("d/d/j", 11);
  EXPECT_EQ(0.1, pt.getDouble("d"));
  EXPECT_EQ(10, pt.getInt("d/i"));
  EXPECT_EQ(0.2, pt.getDouble("d/d"));
  EXPECT_EQ(0.3, pt.getDouble("d/d/d"));
  EXPECT_EQ(11, pt.getInt("d/d/j"));
  EXPECT_EQ(11, pt.getInt("d/d/j"));

  sm::ExtendibleValueStoreRef vpt(pt);

  EXPECT_FALSE(vpt.hasKey("BLA"));
  EXPECT_TRUE(vpt.hasKey("d"));
  EXPECT_EQ(0.1, vpt.getDouble("d").get());
  EXPECT_TRUE(vpt.hasKey("d/d"));
  EXPECT_EQ(0.2, vpt.getDouble("d/d").get());
  auto dChild = vpt.getValueStore().getChild("d");
  EXPECT_EQ("d", dChild.getKey());
  EXPECT_EQ(0.1, dChild.getValueStore().getDouble("").get());
  EXPECT_EQ(0.2, dChild.getValueStore().getDouble("d").get());

  auto dChildF = vpt.getChild("d");
  EXPECT_EQ(0.2, dChildF.getDouble("d").get());
  auto ddChildF = dChildF.getChild("d");
  EXPECT_EQ(0.3, ddChildF.getDouble("d").get());

  {
    const std::vector<const char *> expectedKeys{"i", "d"};
    unsigned i = 0;
    for (auto & c : dChildF.getChildren()){
      ASSERT_LT(i, expectedKeys.size());
      EXPECT_EQ(expectedKeys[i], c.getKey());
      i++;
    }
    EXPECT_EQ(expectedKeys.size(), i);
  }
  {
    const std::vector<const char *> expectedKeys{"d", "j"};
    unsigned i = 0;
    for (auto & c : ddChildF.getChildren()){
      ASSERT_LT(i, expectedKeys.size());
      EXPECT_EQ(expectedKeys[i], c.getKey());
      i++;
    }
    EXPECT_EQ(expectedKeys.size(), i);
  }
  {
    const std::vector<const char *> expectedKeys{"d"};
    unsigned i = 0;
    for (auto & c : vpt.getChildren()){
      ASSERT_LT(i, expectedKeys.size());
      EXPECT_EQ(expectedKeys[i], c.getKey());
      i++;
      if(c.getKey() == "d"){
        EXPECT_NEAR(0.1, c.getValueStore().getDouble(""), 1e-16);
        EXPECT_NEAR(0.2, c.getValueStore().getDouble("d"), 1e-16);
        const std::vector<const char *> expectedKeys = { "i", "d"};
        unsigned i = 0;
        for (auto & c2 : c.getChildren()){
          ASSERT_LT(i, expectedKeys.size());
          EXPECT_EQ(expectedKeys[i], c2.getKey());
          i++;
        }
        EXPECT_EQ(expectedKeys.size(), i);
      }
    }
    EXPECT_EQ(expectedKeys.size(), i);
  }

  vpt.addInt("ai", 4);
  EXPECT_EQ(4, pt.getInt("ai"));
  EXPECT_EQ(4, vpt.getInt("ai").get());

  vpt.addDouble("a/ad", 4.1);
  EXPECT_EQ(4.1, pt.getDouble("a/ad"));
  EXPECT_EQ(4.1, vpt.getDouble("a/ad").get());

  vpt.addString("a/a/as", "add_string");
  EXPECT_EQ("add_string", pt.getString("a/a/as"));
  EXPECT_EQ("add_string", vpt.getString("a/a/as").get());
  
  {
    auto newChild = vpt.getExtendibleChild("aC");
    newChild.addBool("ab", true);
    EXPECT_TRUE(newChild.getBool("ab"));
    EXPECT_TRUE(vpt.getBool("aC/ab"));
  }

  {
    auto aCChild = vpt.getExtendibleChild("aC");
    EXPECT_TRUE(aCChild.getBool("ab"));
    EXPECT_NO_THROW(aCChild.addInt("ai", 1));
  }

  {
    const std::vector<const char *> expectedKeys{"ab", "ai"};
    unsigned i = 0;
    for (auto & c : vpt.getExtendibleChild("aC").getExtendibleChildren()){
      ASSERT_LT(i, expectedKeys.size());
      EXPECT_EQ(expectedKeys[i], c.getKey());
      i++;
    }
    EXPECT_EQ(expectedKeys.size(), i);
  }

  // TODO (HannesSommer) complete ExtendibleValueStore (testing)
  //  auto nDchild = vpt.addChild("nD");
  //  nDchild.addInt("i", 3);
}

TEST(ValueStoreSuite, convertValueStoreToPropertyTree)
{
  sm::BoostPropertyTree pt;

  pt.setDouble("d", 0.1);
  pt.setDouble("d/i", 10);
  pt.setDouble("d/d", 0.2);
  pt.setDouble("d/d/d", 0.3);
  pt.setDouble("d/d/j", 11);
  pt.setString("d/s", "BLA");
  sm::ExtendibleValueStoreRef vpt(pt);

  sm::ConstPropertyTree ptvpt = vpt.asPropertyTree();

  EXPECT_EQ(0.1, ptvpt.getDouble("d"));
  EXPECT_EQ(10, ptvpt.getInt("d/i"));
  EXPECT_EQ(0.2, ptvpt.getDouble("d/d"));
  EXPECT_EQ(0.3, ptvpt.getDouble("d/d/d"));
  EXPECT_EQ("BLA", ptvpt.getString("d/s"));

  auto child = vpt.getChild("d");
  EXPECT_EQ(0.1, child.getDouble(""));
  EXPECT_EQ(10, child.getInt("i"));
  EXPECT_EQ(0.2, child.getDouble("d"));
  EXPECT_EQ(0.3, child.getDouble("d/d"));
  EXPECT_EQ("BLA", child.getString("s").get());

  sm::ConstPropertyTree ptvptc = child.asPropertyTree();
  EXPECT_EQ(0.1, ptvptc.getDouble(""));
  EXPECT_EQ(10, ptvptc.getInt("i"));
  EXPECT_EQ(0.2, ptvptc.getDouble("d"));
  EXPECT_EQ(0.3, ptvptc.getDouble("d/d"));
  EXPECT_EQ("BLA", ptvptc.getString("s"));
}

TEST(ValueStoreSuite, layeredValueStore)
{
  sm::BoostPropertyTree pt;
  pt.setDouble("d", 0.1);
  sm::BoostPropertyTree pt2;
  pt2.setDouble("a", 0.1);
  pt2.setDouble("d", 0.2); // going to be shadowed!
  sm::value_store::ValueStoreRef vpt(pt);
  sm::value_store::ValueStoreRef vpt2(pt2);
  sm::value_store::ValueStoreRef lpt(std::shared_ptr<sm::value_store::LayeredValueStore>(new sm::value_store::LayeredValueStore{vpt.getValueStoreSharedPtr(), vpt2.getValueStoreSharedPtr()}));

  EXPECT_FALSE(lpt.hasKey("BLA"));
  EXPECT_TRUE(lpt.hasKey("d"));
  EXPECT_EQ(0.1, lpt.getDouble("d"));
  EXPECT_TRUE(lpt.hasKey("a"));
  EXPECT_EQ(0.1, lpt.getDouble("a"));

  // update through layers:
  lpt.getDouble("d").update(0.3);
  lpt.getDouble("a").update(0.4);
  EXPECT_EQ(0.3, lpt.getDouble("d"));
  EXPECT_EQ(0.3, pt.getDouble("d"));
  EXPECT_EQ(0.2, pt2.getDouble("d"));
  EXPECT_EQ(0.4, lpt.getDouble("a"));
  EXPECT_EQ(0.4, pt2.getDouble("a"));
}

TEST(ValueStoreSuite, save)
{
  sm::BoostPropertyTree pt;

  pt.setDouble("d", 0.1);
  pt.setDouble("d/i", 10);
  pt.setDouble("d/d", 0.2);
  pt.setDouble("d/d/d", 0.3);
  pt.setDouble("d/d/j", 11);
  EXPECT_EQ(0.1, pt.getDouble("d"));
  EXPECT_EQ(10, pt.getInt("d/i"));
  EXPECT_EQ(0.2, pt.getDouble("d/d"));
  EXPECT_EQ(0.3, pt.getDouble("d/d/d"));
  EXPECT_EQ(11, pt.getInt("d/d/j"));
  EXPECT_EQ(11, pt.getInt("d/d/j"));
  const std::string fileName = "test.xml";
  sm::ValueStoreRef ptVs = sm::ValueStoreRef(pt);
  EXPECT_TRUE(ptVs.canSave());
  ptVs.saveTo(fileName);
  auto vpt = sm::ValueStoreRef::fromFile(fileName);

  EXPECT_FALSE(vpt.hasKey("BLA"));
  EXPECT_TRUE(vpt.hasKey("d"));
  EXPECT_EQ(0.1, vpt.getDouble("d").get());
  EXPECT_TRUE(vpt.hasKey("d/d"));
  EXPECT_EQ(0.2, vpt.getDouble("d/d").get());
  auto dChild = vpt.getValueStore().getChild("d");
  EXPECT_EQ("d", dChild.getKey());
  EXPECT_EQ(0.1, dChild.getValueStore().getDouble("").get());
  EXPECT_EQ(0.2, dChild.getValueStore().getDouble("d").get());
}

TEST(ValueStoreSuite, verboseValueStore)
{
  sm::BoostPropertyTree pt;

  pt.setInt("i", 1);

  const std::string fileName = "test.xml";
  std::stringstream buffer;
  auto logToBuffer = [&buffer](const std::string& s) {
    buffer << s;
  };
  auto emptyBuffer = [&buffer]() {
    buffer.str("");
    buffer.clear();
  };

  sm::ValueStoreRef ptVVs = sm::ValueStoreRef(std::make_shared<sm::VerboseValueStore>(sm::ValueStoreRef(pt), logToBuffer));

  EXPECT_EQ(1, ptVVs.getInt("i"));
  EXPECT_EQ("getInt(\"i\")->1", buffer.str());

  pt.setDouble("d", 0.1);
  sm::BoostPropertyTree pt2;
  pt2.setDouble("a", 0.1);
  pt2.setDouble("d", 0.2); // going to be shadowed!
  sm::value_store::ValueStoreRef vpt(pt);
  sm::value_store::ValueStoreRef vpt2(pt2);
  sm::value_store::ValueStoreRef lpt(std::shared_ptr<sm::value_store::LayeredValueStore>(new sm::value_store::LayeredValueStore{vpt.getValueStoreSharedPtr(), vpt2.getValueStoreSharedPtr()}));

  ptVVs = sm::ValueStoreRef(std::make_shared<sm::VerboseValueStore>(sm::ValueStoreRef(lpt), logToBuffer));

  emptyBuffer();
  EXPECT_EQ(1, ptVVs.getInt("i"));
  EXPECT_EQ("getInt(\"i\")->1", buffer.str());

  emptyBuffer();
  EXPECT_EQ(0.1, ptVVs.getDouble("d"));
  EXPECT_EQ("getDouble(\"d\")->0.100000", buffer.str());
  emptyBuffer();
  EXPECT_EQ(0.1, ptVVs.getDouble("a"));
  EXPECT_EQ("getDouble(\"a\")->0.100000", buffer.str());
}
