//Exercise 5-3, pg. 156
// this program models the volume of a room; using structures
//values are initailized as feet inches and volume represented
//as all feet

#include<conio.h>
#include<iostream.h>

struct Distance
 {
  int feet;
  float inches;
 };

struct Volume
 {
  Distance length;
  Distance width;
  Distance height;
 };

void main()
 { //begin main
  Volume room = { {12, 17}, {12, 21}, {12, 25} };
  float vol = 0;

  clrscr();
  vol = ((room.length.feet * room.width.feet * room.height.feet) +
	((room.length.inches * room.width.inches
	* room.height.inches) / 12));
  cout << "The volume of the room is " << vol;
 } //end main