//Exercise 8-3, pg. 278
//calculate average of 100 English distances

#include <conio.h>
#include <iostream.h>

const int aMax = 100;

class Distance
 {
  int feet;        //private data
  float inches;    //private data

  public:
   Distance() { feet = 0; inches = 0; }  //constructor
   void getdist()   //get length from user
    {
     cout << "\nEnter feet:  "; cin >> feet;
     cout << "Enter inches:  "; cin >> inches;
    }
   void showdist()  //display distance
    { cout << feet << "\'-" << inches << "\""; }
   void add_dist(Distance, Distance);  //declaration
   void avg_dist(Distance total, int tot_num)
    {
     float tot_ft = (total.feet + (total.inches/12)); //convert to all feet
     tot_ft /= tot_num;  //take average
     feet = tot_ft;  //store in private feet data
     inches = (tot_ft - feet) * 12.0;  //find inches left store in private
    }
 };

void Distance::add_dist(Distance d2, Distance d3)
 {
  inches = d2.inches + d3.inches;  //add inches
  feet = 0;  //for possible carry
  if (inches >= 12.0)
   { inches -= 12.0; feet++; }
  feet = d2.feet + d3.feet;  //add feet
 }

void main()
 {
  Distance dArray[aMax];
  Distance avg, tot_dist;
  char choice;
  int count = 0;

  clrscr();
  do
   {
    dArray[count++].getdist();  //get distance from user
    cout << "Enter another (y/n)?  ";  cin >> choice;
   }
  while(choice != 'n');

  for (int l = 0; l < count; l++)
   tot_dist.add_dist(tot_dist, dArray[l]);
  avg.avg_dist(tot_dist, count);

  cout << "\nThe average is:  ";
  avg.showdist();
 }