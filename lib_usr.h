#ifndef _LIB_USR_H_
#define _LIB_USR_H_

/**
 * usr funkcie a struktury pre pointers.cpp
 */
class hodnoty {
public:
  int a;
  int b;
};

class hodnoty *test_return_pointer(void);
int test_return_pointer_erasor(class hodnoty *ptr_hodnoty);

void increment_all(int *start, int *stop);
void print_all(const int *start, const int *stop);
void print_all_two(int *start, int *stop);
void do_nothing(int *start, int *stop);

void increase_diff_type(void *data, int size);

class hodnoty *test_return_pointer_bad(void);

/**
 * usr funkcie a struktury pre classes.cpp
 */
class CRectangle {
  int width, height;
public:
  CRectangle();
  ~CRectangle();
  void set_values (int,int);
  int area(void);
  unsigned long int get_pointer();
};

class CCircle{
  double radius;
public:
  CCircle (double r);
  ~CCircle();
  double circum();
};

//ked sa funkcia vola rovnako ako class
//musime vytvarat classu s class operatorom inak vola funkciu
void CCircle(int);

class CVector{
  public:
    int x,y;
    CVector();
    CVector(int a, int b);
    CVector operator - (const CVector &param);
    int xyadd();
    int operator + (int param);
    ~CVector();
};

//TO DO pretazit operator + na nasobenie
//template
class CMy_int{
  public:
    int n;
    CMy_int(){n = 5;}
    CMy_int operator+(const CMy_int &param);
    //CMy_int &operator = (int param);
};
// overloading operator
//my_int operator+(my_int &lhs, my_int &rhs);



#endif
