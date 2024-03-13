//Exercise 7-1, pg. 237
//creates a class with int var.; intialize 2, add those together
//into an uninitialized 3rd

#include <conio.h>
#include <iostream.h>

class Int
 {
  int value;  //private data, keyword private not needed

  public:
    void InitInt(int d)  //initialize value
     { value = d; }

    void AddInt(Int d1, Int d2) //add two Int's
     { value = d1.value + d2.value; }

    void ShowInt() //show value
     { cout << "The value is " << value << "\n"; }
 };

void main()
 {
  Int var1, var2, var3;

  clrscr();
  var1.InitInt(10);
  var1.ShowInt();

  var2.InitInt(15);
  var2.ShowInt();

  var3.AddInt(var1, var2);
  var3.ShowInt();
 }