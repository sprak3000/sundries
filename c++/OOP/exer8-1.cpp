//Exercise 8-1, pg.278
//reverses a string

#include <conio.h>
#include <iostream.h>
#include <string.h>

const int Max = 80;

void reversit(char str[]);

void main()
 {
  char user_str[Max];

  clrscr();
  cout << "Enter a string:  ";
  cin.get(user_str, Max);
  reversit(user_str);
  cout << "Reversed string is " << user_str;
 }

void reversit(char str[])
 {
   for (int l=0; l < (strlen(str))/2; l++)
    {
     int bot = strlen(str);

     char temp = str[l];
     str[l] = str[bot - l - 1];
     str[bot - l - 1] = temp;
    }
 }