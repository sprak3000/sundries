// Exercise 3-1 pg. 73
// Program assumes 7.481 gallons in cubic foot
// prompts for # of gallons, then displays number of cubic feet

#include<iostream.h>

void main()
{
const float g_to_cfeet = 7.481;
float gallons;

cout << "Enter the number of gallons -> ";
cin >> gallons;
cout << "Gallons = " << gallons << '\n' << "Cubic Feet = " << gallons/g_to_cfeet;
}