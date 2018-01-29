#include <iostream>

#include "fibonacci.h"
#include "tests.h"

void fibonacci_unittest() {

  // test negative
  ExpectEqual("Negative Input",-1,fibonacci(-1));

  // test 0
  ExpectEqual("0 Input",0,fibonacci(0));

  // test boundary
  ExpectEqual("Border 1",1,fibonacci(1));
  ExpectEqual("Border 2",2,fibonacci(2));

  // test typical
  ExpectEqual("Typical 5", 5, fibonacci(5));
  ExpectEqual("Typical 10", 55, fibonacci(10));
}
