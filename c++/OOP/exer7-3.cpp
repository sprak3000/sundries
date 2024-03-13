//Exercise 7-3, pg. 237
//class of time; initialize and add time

#include <conio.h>
#include <iostream.h>

class time
 {
  int hours, min, sec;  //private data

  public:
    time()                          //constructor for no parameters
     {hours = min = sec = 0; }

    time(int hrs, int m, int s)                 //constructor for parameters given
     { hours = hrs; min = m; sec = s; }

    void display()		    //display time
     { cout << hours << ":" << min << ":" << sec << "\n"; }

    void addTime(time t1, time t2)  //add times together
     {
      sec = t1.sec + t2.sec;
      min = t1.min + t2.min;
      hours = t1.hours + t2.hours;
      if (sec > 59) { sec -= 60; min++; }
      if (min > 59) { min -= 60; hours++; }
     }
 };

void main()
 {
  time time1(12, 30, 31), time2(12, 30, 31), time3;

  clrscr();
  time1.display();
  time2.display();
  time3.addTime(time1, time2);
  time3.display();
 }