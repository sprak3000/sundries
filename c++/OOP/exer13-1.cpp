//Exercise 13-1 pg. 513
//virtual publishing company

#include <iostream.h>
#include <conio.h>
#include <stdio.h>

const int LEN = 80;

class publication
{
 private:
  char title[LEN];		//title of publication
  float price;			//price of publication

 public:
  void getdata() 		//virtual getdata base function
  {
   cout << "\nEnter title of publication:  "; gets(title);
   cout << "Enter price of publication:  "; cin >> price;
  }

  virtual void putdata()	//virtual putdata base function
  {
   cout << "\n\nTitle of publication:  " << title;
   cout << "\nPrice of publication:  " << price;
  }
};

class book : public publication
{
 private:
  int page_count;

 public:
  void getdata()
  {
   publication::getdata();
   cout << "Enter page count of publication:  "; cin >> page_count;
  }

  void putdata()
  {
   publication::putdata();
   cout << "\nPage count of publication:  " << page_count;
  }
};

class tape : public publication
{
 private:
  float time;

 public:
  void getdata()
  {
   publication::getdata();
   cout << "Enter time length(in min.) of publication:  "; cin >> time;
  }

  void putdata()
  {
   publication::putdata();
   cout << "\nTime length(in min.) of publication:  " << time;
  }
};

int main()
{
 int pub_count = 0;
 char choice;
 publication* pub_array[LEN];
 book* bookptr;
 tape* tapeptr;

 clrscr();
 do
 {
  cout << "\nEnter type of publication, (b)ook or (t)ape:  ";
  choice = getche();

  if ((choice == 'b')||(choice == 'B'))
  {
   bookptr = new book;
   bookptr->getdata();
   pub_array[pub_count++] = bookptr;
  }
  else
  {
   tapeptr = new tape;
   tapeptr->getdata();
   pub_array[pub_count++] = tapeptr;
  }

  cout << "\nEnter another publication(y/n)?  ";
  choice = getche();
 }
 while ((choice == 'y')||(choice == 'Y'));

 for(int loop = 0; loop < pub_count; loop++)
 {
  pub_array[loop]->putdata();
 }

 for(loop = 0; loop < pub_count; loop++)
 {
  delete pub_array[loop];
 }

 return 0;		//everything OK
}