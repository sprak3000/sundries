//Exercise 4-1 pg. 124
//generates a table of multiples of a user inputed number.

#include <iostream.h>
#include <iomanip.h>
#include <conio.h>

void main()
{
  const char endl = '\n';
  int user_num;

  clrscr();
  cout << "Enter a number:  ";
  cin >> user_num;
  for(int loop = 1; loop <= 200; loop++)
    {
     cout << setw(5) << user_num*loop << "  ";
     if (!(loop%10)) cout << endl;
    }
}