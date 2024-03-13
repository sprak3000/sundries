//Exercise 6-3, pg. 201
//use a func. that sets smaller num to 0

#include <conio.h>
#include <iostream.h>



void main()
 {
  void zeroSmaller(int&, int&);
  int num1, num2;

  clrscr();
  cout << "Enter two numbers:  ";
  cin >> num1 >> num2;
  zeroSmaller(num1, num2);
  cout << "The numbers are " << num1 << " " << num2;
 }

void zeroSmaller(int& num_1, int& num_2)
 {
  if (num_1 < num_2)
   num_1 = 0;
  else
   num_2 = 0;
 }