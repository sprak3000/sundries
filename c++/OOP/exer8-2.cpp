//Exercise 8-2, pg. 278
//employee class - name & number, getdata(), putdata()

#include <conio.h>
#include <iostream.h>

const int aMax = 100;
const int sMax = 25;

class employee
 {
  char name[sMax];  //private data - employee name
  long num;         //private data - employee number

  public:
   void getdata()   //get data from user
    { cout << "Enter employee name:  "; cin >> name;
      cout << "Enter employee number:  "; cin >> num; }
   void putdata()
    { cout << "\n" << name << " " <<num; }
 };

void main()
 {
  employee e_array[aMax];
  int count = 0;
  char choice;

  clrscr();
  do
   {
    e_array[count++].getdata();
    cout << "Enter another (y/n)?  ";
    cin >> choice;
   }
  while(choice != 'n');

  for (int i = 0; i < count; i++)
   e_array[i].putdata();
 }