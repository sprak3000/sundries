//Exercise 10-3, classes modeling a publishing company
//with multiple inheiritance

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

class sales
 {
  private:
    float month_sales[3];
  public:
    void getdata()  //get data from user
     {
      for (int l=0; l < 3; l++)
	{
	 cout << "Enter the sales for month " << l+1 << ":  ";
	 cin >> month_sales[l];
	}
     }
    void putdata()  //show data on screen
     {
      for (int l=0; l < 3; l++)
       cout << "\nThe sales for month " << l+1 << " - " << month_sales[l];
     }
 };

class book : public publication, public sales
 {
  private:
    int pg_cnt;
  public:
    void getdata()
     {
      publication::getdata();
      cout << "Enter page count:  "; cin >> pg_cnt;
      sales::getdata();
     }
    void putdata()
     {
      publication::putdata();
      cout << "\nPage count - " << pg_cnt;
      sales::putdata();
     }
 };

class tape : public publication, public sales
 {
  private:
    float tp_len;
  public:
    void getdata()
     {
      publication::getdata();
      cout << "Enter tape length in minutes:  "; cin >> tp_len;
      sales::getdata();
     }
    void putdata()
     {
      publication::putdata();
      cout << "\nTape length (min.) - " << tp_len;
      sales::putdata();
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