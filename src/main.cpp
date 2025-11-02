#include <iostream>
#include "array_fijo_smart.hpp" // "array_fijo.hpp"
#include "array_fijo_smart.hpp" // "vector_fijo.hpp"

// Prototypes from the exercise examples
void f();
//void g();

int main() {
    std::cout << "Running function f():" << std::endl;
    f();
    std::cout << "\nRunning function g():" << std::endl;
    //g();
    return 0;
}



// Implementations of the test functions
void f() {
  secuencia_fija_smart v1;
  std::cout << "v1 " << v1 << '\n';

  
  secuencia_fija_smart v2(2);
  std::cout << "v2 " << v2 << '\n';

  secuencia_fija_smart v3{1.0, 2.0, 3.0};
  std::cout << "v3" << v3 << '\n';

  secuencia_fija_smart v4{v3};
  std::cout << "v3 " << v3 << '\n';
  std::cout << "v4 " << v4 << '\n';

  v4 = v2;
  std::cout << "v2 " << v2 << '\n';
  std::cout << "v4 " << v4 << '\n';

  secuencia_fija_smart v5{std::move(v4)};
  std::cout << "v4 " << v4 << '\n';
  std::cout << "v5 " << v5 << '\n';

  v1 = std::move(v5);;
  std::cout << "v1 " << v1 << '\n';
  std::cout << "v5 " << v5 << '\n';
  /**/
}
/*
void g() {
  vector_fijo v1;
  std::cout << "v1" << v1 << '\n';

  vector_fijo v2(2);
  std::cout << "v2" << v2 << '\n';

  vector_fijo v3{1.0, 2.0, 3.0};
  std::cout << "v3" << v3 << '\n';

  vector_fijo v4{v3};
  std::cout << "v3" << v3 << '\n';
  std::cout << "v4" << v4 << '\n';

  v4 = v2;
  std::cout << "v2" << v2 << '\n';
  std::cout << "v4" << v4 << '\n';

  vector_fijo v5{std::move(v4)};
  std::cout << "v4" << v4 << '\n';
  std::cout << "v5" << v5 << '\n';

  v1 = std::move(v5);;
  std::cout << "v1" << v1 << '\n';
  std::cout << "v5" << v5 << '\n';
}
*/