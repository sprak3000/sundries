//Exercise 5-1, pg. 155
//initialize phone structure, user inputs another
//output both numbers

#include<iostream.h>
#include<conio.h>

struct phone
{
 int area;
 int exchange;
 int num;
};

void main()
{ //begin main
 phone p_num1 = { 813, 574, 8256 } , p_num2;

 clrscr();
 cout << "Enter area code, exchange, number:  ";
 cin >> p_num2.area >> p_num2.exchange >> p_num2.num;

 cout << "My phone number is (" << p_num1.area << ")"
      << p_num1.exchange << "-" << p_num1.num;

 cout << "\nYour phone number is (" << p_num2.area << ")"
      << p_num2.exchange << "-" << p_num2.num;
} //end main
