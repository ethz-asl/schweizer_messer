#include <sm/deprecation.h>

SM_DEPRECATED("DEP_TEST_MESSAGE") void foo();



void bar() {
#ifndef SM_DEPRECATION_SUPPORTED
  int SM_DEPRECATION_NOT_SUPPORTED; // cause warning about unused variable!
#endif
  foo();
}
