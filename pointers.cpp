#include <array>
#include <iostream>
#include <memory>

#include "lib_usr.h"

void pointers_guide() {
  /*
    int pom;
    (void)pom; // aby nebol unused warning

    int *ptr_standart = new int;
    delete ptr_standart; // aby nebol unused warning

    std::shared_ptr<int> ptr_smart(new int); // smart pointer
  */

  //***********TO DO pointer on std::array
  // Pointerand int array

  int myarray[5];
  int *my_ptr = new int;

  // std::array<int, 5> myarray;
  // std::array *my_ptr;

  my_ptr = myarray; // no need for & operator, myarrray is pointer to arrray
                    // from definition
  *my_ptr = 10;

  my_ptr++; // posuvam sa po adresach prvkov struktury na ktoru ukazuje pointer
  *my_ptr = 20;

  my_ptr = &myarray[2]; // priradim adresu druheho prvku
  *my_ptr = 30;

  my_ptr = myarray + 3; // posuniem sa adresou o tri prvky
  *my_ptr = 40;

  my_ptr = myarray;
  *(my_ptr + 4) = 50;

  for (size_t i = 0; i < 5; i++) {
    std::cout << myarray[i] << std::endl;
  }

  std::cout << std::endl;

  int *ptr_value = new int;
  ptr_value = myarray;
  std::cout << "Pre Value: " << *ptr_value << std::endl;
  std::cout << "Pre Adress: " << ptr_value << std::endl;
  std::cout << std::endl;

  // Ako zistim  hruby odhad velkosti dynamickeho pola posunom indexu :D
  int *pole = new int[1000];
  std::cout << "-1 pointer pola: " << pole[-2] << std::endl;

  // NEKOMBINOVAT ++ a NIECO INE, VYSLEDOK JE POTOM V RUKACH BOZICH!!!!
  // AKO VIDNO DOLE
  // ptr_value = ptr_value++; // inc sa vykona az po priradeni = no effect
  // ptr_value = ++ptr_value; // inc adresy pred priradenim
  // ptr_value++; // inc adresy pred priradenim
  // ++ptr_value; // inc adresy pred priradenim
  // *ptr_value++; // inc adresy pred priradenim = * has no effect
  // *++ptr_value; // inc adresy pred priradenim = * has no effect
  // ++*ptr_value; // inc hodnoty kde ukazuje pointer
  // (*ptr_value)++; // inc hodnoty kde ukazuje pointer

  std::cout << "Pos Value: " << *ptr_value << std::endl;
  std::cout << "Pos Adress: " << ptr_value << std::endl;
  std::cout << std::endl;
  //****************************
  int myvar = 25;
  int *ptr_1 = new int;

  ptr_1 = &myvar;

  std::cout << "Value of myvar: " << myvar << std::endl;
  std::cout << "Value of &myvar: " << &myvar << std::endl;
  std::cout << "Value of *ptr_1: " << *ptr_1 << std::endl;
  // std::cout << "Value of SET: " << SET << std::endl;

  // system("pause")2 = new int;d::cout << "Press enter to continue ...";
  // std::cin.get();
  //
  //****************************
  // Pointers and Constants
  int x;
  int y = 10;
  const int *p;
  p = &y;

  x = *p;
  (void)x; // warning suppressor
  //*p = 10; // Error Read only location, its constant

  // Test for changing * to char* or char *
  char *ptr, nieco;
  std::cout << "Value of sizeof(ptr): " << sizeof(ptr) << std::endl;
  std::cout << "Value of sizeof(nieco): " << sizeof(nieco) << std::endl;

  // Pointers as Arguments:
  int numbers[] = {10, 20, 30};
  increment_all(numbers, numbers + 3);
  print_all(numbers, numbers + 3);

  // Invalid pointer
  // int *po;
  // int m_array[10];
  // int *q = m_array + 20;

  // Pointers to functions
  //
  //
  std::cout << std::endl;
  int numbers_two[] = {10, 20, 30};
  void (*actual_function)(int *, int *) = increment_all;
  (void)actual_function;

  actual_function(numbers_two, numbers_two + 3);
  actual_function = do_nothing;
  actual_function(numbers_two, numbers_two + 3);
  actual_function = increment_all;
  actual_function(numbers_two, numbers_two + 3);
  actual_function = print_all_two;
  actual_function(numbers_two, numbers_two + 3);

  // VOID pointers
  char pismeno = 'a';
  int cislo = 1;

  increase_diff_type(&pismeno, sizeof(pismeno));
  increase_diff_type(&cislo, sizeof(cislo));
  std::cout << pismeno << "," << cislo << std::endl;
}
