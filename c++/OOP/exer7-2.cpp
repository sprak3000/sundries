//Exercise 7-2, pg. 237
//models a tollbooth; counts # of cars and total money collected
//cars can pay or not pay; different keys determine this

#include <conio.h>
#include <iostream.h>

class tollBooth
 {
  unsigned int cars;  //private var. for car num.
  double money_tot;   //private var. for money total

  public:
    tollBooth() { cars = 0; money_tot =0; }  //constructor
    void payingCar()                         //counts a paying car
     { cars++; money_tot += 0.50; }
    void nopayCar() { cars++; }              //counts a non-paying car
    void display()                           //displays totals
     { cout << "\nTotal cars = " << cars
	    << "\nTotal money = $" << money_tot; }
 };

const char ESC = 27;

void InitInfo();

void main()
 {
  tollBooth toll_1;
  char keypress;

  InitInfo();
  do
   {
    keypress = getch();
    switch(keypress)
     {
      case 'j' : toll_1.payingCar(); break;
      case 'l' : toll_1.nopayCar(); break;
     }
    }
  while(keypress != ESC);

  toll_1.display();
 }

void InitInfo()
 {
  clrscr();
  cout << "The tollbooth program\n'J' counts paying car\n"
       << "'L' counts non-paying car\nESC quits and prints totals";
 }