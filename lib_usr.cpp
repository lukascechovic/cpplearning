#include "lib_usr.h"
#include <iostream>

/*
class hodnoty *test_return_pointer_bad(void) {
  class hodnoty result;
  result.a = 10;
  result.b = 20;
  return (&result);
}
*/
/*
//!!!!!!!!!!!JESUS sice vrati smernik ale pamat uz nieje vyhradena a teda sa
moze lubovolne zmenit!!!!!
*/

/*
Factory - vyrabam kopie na inych adresach vdaka "new"
 */
class hodnoty *test_return_pointer(void) {
  class hodnoty *result = new hodnoty;
  result->a = 10;
  result->b = 20;
  return (result);
}
/*
Erasor hodnoty, schopny handlovat aj NULL pointer
 */

int test_return_pointer_erasor(class hodnoty *ptr_hodnoty) {
  if (ptr_hodnoty == nullptr) {
    return -1;
  }
  delete ptr_hodnoty;
  ptr_hodnoty = nullptr;
  return 0;
}

void increment_all(int *start, int *stop) {
  int *current;
  current = start;
  while (current != stop) {
    *current = *current + 1;
    current++;
  }
}

void print_all(const int *start, const int *stop) {
  const int *current;
  current = start;
  while (current != stop) {
    std::cout << *current << std::endl;
    current++;
  }
}

void print_all_two(int *start, int *stop) {
  int *current;
  current = start;
  while (current != stop) {
    std::cout << *current << std::endl;
    current++;
  }
}

void do_nothing(int *start, int *stop) {
  (void)start;
  (void)stop;
}

void increase_diff_type(void *data, int psize) {
  if (psize == sizeof(char)) {
    /* code */
    char *pchar = new char;
    pchar = (char *)data;
    *pchar = (*pchar) + 1;
  }
  if (psize == sizeof(int)) {
    /* code */
    int *pint = new int;
    pint = (int *)data;
    *pint = (*pint) + 1;
  }
}
//**
// Funkcie a classy pre CLASS guide
void CRectangle::set_values(int x, int y) {
  /* code */
  this->width = x;
  // width = x; //ekvivalent this->width = x;
  height = y;
}
// this VRATI ADRESU INSTANCIE OBJEKTU
// mal by byt unikatny :-) pouzitelne ako ID objektu
unsigned long int CRectangle::get_pointer() {
  /*code*/
  return (unsigned long int)this;
}

CRectangle::CRectangle() {
  width = 0;
  height = 0;
}

CRectangle::~CRectangle() {}

int CRectangle::area(void) {
  /*code*/
  return width * height;
}

CCircle::CCircle(double r) {
  /*code*/
  radius = r;
}

CCircle::~CCircle() {}

double CCircle::circum() {
  /*code*/
  return 2 * radius * 3.14159265;
}

void CCircle(int a) { (void)a; }

CVector::CVector() {
  x = 0;
  y = 0;
};
CVector::CVector(int a, int b) {
  x = a;
  y = b;
}
CVector CVector::operator-(const CVector &param) {
  CVector temp;
  temp.x = x + param.x;
  temp.y = y + param.y;
  return temp;
}
CVector::~CVector(){};

int CVector::xyadd() { return (x + y); }

CMy_int CMy_int::operator+(const CMy_int &param) {
  /*code*/
  CMy_int temp;
  temp.n = n * param.n;
  return temp;
}
/*
CMy_int CMy_int::&operator=(int param) {
  n = param;
  return *this;
}
*/
