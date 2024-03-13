//Exercise 6-1, pg. 201
//this program uses functions to find the area of the circle

#include <conio.h>
#include <iostream.h>

float circarea(float);

void main()
 { //begin main
  float radius = 0;

  clrscr();
  cout << "Enter the radius of the circle:  ";
  cin >> radius;
  cout << "The area of the circle is " << circarea(radius);
 } //end main

float circarea(float rad)
 { //begin circarea
  const float pi = 3.14;

  return (pi * rad * rad);
 } //end circarea