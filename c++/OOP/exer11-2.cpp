//Exercise 11-2 pg. 414
//Draw a car using a modified shape class

#include <graphics.h>
#include <conio.h>

class shape
{
 protected:
  int xCo, yCo;			//coordinates of center
  int width, height;		//shape's dimensions
  int linecolor;		//color of outline
  int fillcolor;		//color of interior
 public:
  shape()			//no-arg. constructor
   { xCo = 0; yCo = 0; width = 0; height = 0;
     linecolor = WHITE; fillcolor = WHITE; }
  void set(int x, int y, int h, int w, int lc, int fc)
  { xCo = x; yCo = y; height = h; width = w;
    linecolor = lc; fillcolor = fc; }
  void draw()
  {
   setcolor(linecolor);
   setlinestyle(SOLID_LINE, 0 ,THICK_WIDTH);
   setfillstyle(SOLID_FILL, fillcolor);
  }
};

class ball : public shape
{
 public:
  ball() : shape()		//no-arg. constructor
  { }
  void set(int x, int y, int h, int w, int lc, int fc)
  { shape::set(x, y, h, w, lc, fc); }
  void draw()
  {
   shape::draw();
   circle(xCo, yCo, width);
   floodfill(xCo, yCo, linecolor);
  }
};

class rect : public shape
{
 public:
  rect() : shape()			//no arg. constructor
  { }
  void set(int x, int y, int h, int w, int lc, int fc)
  { shape::set(x, y, h, w, lc, fc); }
  void draw()
  {
   shape::draw();
   rectangle(xCo+width, yCo+height, xCo-width, yCo-height);
   floodfill(xCo, yCo, linecolor);
   moveto(xCo-width, yCo+height);
   lineto(xCo+width, yCo-height);
  }
};

void main()
{
 int driver, mode;
 driver = DETECT;
 initgraph(&driver, &mode, "\\tc\\bgi");

 rect r1, r2;
 ball b1, b2;

 b1.set(150, 307, 50, 50, YELLOW, WHITE);
 b2.set(350, 307, 50, 50, YELLOW, WHITE);
 r1.set(250, 150, 25, 75, YELLOW, BLUE);
 r2.set(250, 215, 40, 150, YELLOW, BLUE);

 b1.draw();
 b2.draw();
 r1.draw();
 r2.draw();

 getch();
 closegraph();
}