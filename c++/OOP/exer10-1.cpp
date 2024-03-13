//Exercise 10-1, classes modeling a publishing company

#include <conio.h>
#include <iostream.h>

const int sMax = 80;

class publication
 {
  private:
    char title[sMax];  //title of publication
    float price;      //price of publication
  public:
    void getdata()    //get data from user
     {
      cout << "\nEnter title of work:  ";  cin >> title;
      cout << "Enter price of work:  ";  cin >> price;
     }
    void putdata()   //show data on screen
     {
      cout << "\nTitle - " << title << "\nPrice - " << price;
     }
 };

class book : public publication
 {
  private:
    int pg_cnt;
  public:
    void getdata()
     {
      publication::getdata();
      cout << "Enter page count:  "; cin >> pg_cnt;
     }
    void putdata()
     {
      publication::putdata();
      cout << "\nPage count - " << pg_cnt;
     }
 };

class tape : public publication
 {
  private:
    float tp_len;
  public:
    void getdata()
     {
      publication::getdata();
      cout << "Enter tape length in minutes:  "; cin >> tp_len;
     }
    void putdata()
     {
      publication::putdata();
      cout << "\nTape length (min.) - " << tp_len;
     }
 };

void main()
 {
  book b1;
  tape t1;

  clrscr();
  b1.getdata();
  t1.getdata();
  b1.putdata();
  t1.putdata();
 }