//Exercise 8-3, pg. 278
//calculate average of 100 English distances

#include <conio.h>
#include <iostream.h>

class Distance
 {
  int feet;        //private data
  float inches;    //private data

  public:
   Distance() { feet = 0; inches = 0; }  //constructor
   Distance(int ft, float in)            //constructor two args.
    { feet = ft; inches = in; }
   void getdist()   //get length from user
    {
     cout << "\nEnter feet:  "; cin >> feet;
     cout << "Enter inches:  "; cin >> inches;
    }
   void showdist()  //display distance
    { cout << "\n" << feet << "\'-" << inches << "\""; }
   void avg_dist(Distance total, int tot_num)
    {
     float tot_ft = (total.feet + (total.inches/12)); //convert to all feet
     tot_ft /= tot_num;  //take average
     feet = tot_ft;  //store in private feet data
     inches = (tot_ft - feet) * 12.0;  //find inches left store in private
    }
   Distance operator - (Distance);    //declarator
   Distance operator +(Distance d2)   //add distance together
    {
     int f = feet + d2.feet;
     float i = inches + d2.inches;
     if (i >= 12.0)
      {
       i -= 12.0;
       f++;
      }
     return Distance(f, i);
    }
 };

 Distance Distance::operator - (Distance d2)
  {
   int f = feet - d2.feet;
   float i = inches - d2.inches;
   if (i >= 12.0)
    {
     i -= 12.0;
     f++;
    }
   return Distance(f, i);
  }

void main()
 {
  Distance dist1(12, 10), dist2(9, 10), dist3;

  clrscr();
  dist3 = dist1 - dist2;
  dist1.showdist();
  dist2.showdist();
  dist3.showdist();
 }