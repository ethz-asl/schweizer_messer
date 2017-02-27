#include <iostream>
#include <sm/MatrixArchive.hpp>

void usage(const char * cmd) {
  std::cerr << "USAGE: " << cmd << " <PATH_TO_MATRIX_ARCHIVE>" << std::endl;
}

int main(int argc, char **argv) {
  if(argc < 2){
    usage(argv[0]);
    return -1;
  }
  using sm::MatrixArchive;
  for(int i = 1; i < argc; i++){
    const std::string path = std::string(argv[i]);
    MatrixArchive ma;
    ma.load(path);
    const std::string namePrefix = (argc > 2) ? path + ":" : std::string();
    for (auto & s : ma.getStrings()){
      std::cout << namePrefix << s.first << " : " << s.second << std::endl;
    }
    for (auto & m : ma){
      std::cout << namePrefix << m.first << " :\n" << m.second << std::endl;
    }
  }
  return 0;
}
