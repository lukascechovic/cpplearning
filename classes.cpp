#include <array>
#include <iostream>
#include <memory>

#include "lib_usr.h"

void classes_guide() {

  class CRectangle rect, rect_b;
  rect.set_values(3, 4);
  std::cout << "Area: " << rect.area() << std::endl;
  std::cout << "get_pointer: " << rect.get_pointer() << std::endl;
  std::cout << "get_pointer: " << (unsigned long int)&rect << std::endl;
  std::cout << "get_pointer: " << rect_b.get_pointer() << std::endl;
  std::cout << "get_pointer: " << (unsigned long int)&rect_b << std::endl;

  // class CCircle foo(10.0); // functional form
  // class CCircle foo = 10.0; // assignment init.
  // class CCircle foo{10.0}; // uniform init.
  // class CCircle foo = {10.0}; // POD-like
  class CCircle fooo(10.0);
  CCircle(10);

  std::cout << "foo's circumference: " << fooo.circum() << '\n';

  //**Poznamka
  //**Funkcia sa vola so zatvorkami standardne a
  //**bez zatvoriek je smernik
  //**Class je standardne bez zatvoriek a preklada sa
  //**do zatvorkovej formy koli konstruktoru
  //**mozno preto smernik = class nefunguje s errorom
  //** ze chcem priradit class do *class
  void (*pp)(int);
  (void)pp;
  pp = CCircle;
  class CRectangle obj; // obj nieje smernik!!!!!
                        // teda nemozem foo = obj;
  obj.set_values(2, 2);
  class CRectangle *foo, *bar, *baz = new CRectangle[2];
  (void)bar;
  foo = &obj;
  (*foo).set_values(3, 3);
  foo->set_values(3, 3);
  baz[0].set_values(4, 4);
  baz[1].set_values(4, 4);

  // overloading operators
  CVector a_vect(5, 5);
  CVector b_vect(5, 5);
  CVector result;

  result = a_vect - b_vect;
  std::cout << "a_vect + b_vect = (" << result.x << "," << result.y << ")"
            << std::endl;

  CMy_int a;
  CMy_int b;
  CMy_int res;

  res = a + b;
  // ako vypisat res.n len ako res
  // pertazit operator <<
  //
  std::cout << "a + b = (" << res.n << "," << res.n << ")" << std::endl;

  // end
};
