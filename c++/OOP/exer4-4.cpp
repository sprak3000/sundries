//Exercise 4-4, pg. 125
//simulates a 4 function calculator

#include<iostream.h>
#include<conio.h>

void main()
{ //begin main

  int first_num = 0, sec_num = 0, answer = 0;
  char oper, choice;

  do
    { //begin do
     clrscr();

     cout << "Enter number, operator, number -> ";
     cin >> first_num >> oper >> sec_num;

     switch(oper)
      { //begin switch
       case '+' : answer = first_num + sec_num; break;
       case '-' : answer = first_num - sec_num; break;
       case 'x' : answer = first_num * sec_num; break;
       case '/' : answer = first_num / sec_num; break;
       default  : answer = 0;
      } //end switch

     cout << "\nAnswer = " << answer;
     cout << "\nCalculate another (y/n)";
     choice = getche();
    } //end do
  while(choice == 'y');
} //end main