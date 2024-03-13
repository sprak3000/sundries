// Exercise 3-3 pg. 73
// generates 10 \n 20 \n 19 with int const for 10
// math assignment for 20 and decrement for 19

#include <iostream.h>
#include <conio.h>
void main(void)
{
const int num = 10;
const char endl = '\n';
int temp = 2;
clrscr();
temp *= num;
cout << num << endl << temp--;
cout << endl << temp;
}