// Exercise 5-2, pg.155-156
//input two xy coords., sum them, output all

#include<conio.h>
#include<iostream.h>

struct point
{
 int x;
 int y;
};

void main()
{ //begin main
 point p1, p2, total;

 clrscr();
 cout << "Enter coordinates for p1:  ";
 cin >> p1.x >> p1.y;

 cout << "Enter coordinates for p2:  ";
 cin >> p2.x >> p2.y;

 total.x = p1.x + p2.x;
 total.y = p1.y + p2.y;

 cout << "Coordinates for the sum of p1 and p2:  "
      << total.x << ", " << total.y;
} //end main
