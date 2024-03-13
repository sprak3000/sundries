//Exercise 6-2, pg. 201
//raises a number to a power using functions

#include <conio.h>
#include <iostream.h>

double power(double, int = 2);

void main()
 {
  double number = 0;
  int powr = 2;

  clrscr();
  cout << "Enter a number and a power:  ";
  cin >> number >> powr;

  cout << "Answer is " << power(number, powr);
 }

double power(double num, int pow)
 {
  double ans = 1;

  for (int i = 1; i <= pow; i++)
    ans *= num;

  return ans;
 }