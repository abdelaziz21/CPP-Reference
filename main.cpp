/*
 * Created by Codeblocks.
 * User: *********
 * Date: 9/18/2017
 * Time: 2:26 PM
 *
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//structure with anonymous union
struct book2_t {
  char title[50];
  char author[50];
  union {
    float dollars;
    int yen;
  };
} book2;

//structure with regular union
struct book1_t {
  char title[50];
  char author[50];
  union {
    float dollars;
    int yen;
  } price;
} book1;

//union
union mytypes_t {
  char c;
  int i;
  float f;
} mytypes;

//enumerated types
enum class Colors {black, blue, green, cyan, red, purple, yellow, white};

//Data structure
struct movies_t1 {
  string title;
  int year;
};
struct movies_t {
  string title;
  int year;
} films [3];

void printmovie (movies_t movie);
//Non-type template arguments
template <class T, int N>
T fixed_multiply (T val)
{
  return val * N;
}
// function template
template <class T, class U>
bool are_equal (T a, U b)
{
  return (a==b);
}
// another function template
template <class T>
T sum (T a, T b)
{
  T result;
  result = a + b;
  return result;
}
// friend functions
class Rectangle5 {
    int width, height;
  public:
    Rectangle5() {}
    Rectangle5(int x, int y) : width(x), height(y) {}
    int area() {return width * height;}
    friend Rectangle5 duplicate (const Rectangle5&);
};

Rectangle5 duplicate (const Rectangle5& param)
{
  Rectangle5 res;
  res.width = param.width*2;
  res.height = param.height*2;
  return res;
}

//function prototype
class Square;

class Rectangle4 {
    int width, height;
  public:
    int area ()
      {return (width * height);}
    void convert (Square a);
};

class Square {
  // friend class
  friend class Rectangle4;
  private:
    int side;
  public:
    Square (int a) : side(a) {}
};

void Rectangle4::convert (Square a) {
  width = a.side;
  height = a.side;
}

// multiple inheritance
class Polygon2 {
  protected:
    int width, height;
  public:
    Polygon2 (int a, int b) : width(a), height(b) {}
};

class Output {
  public:
    static void print (int i);
};

void Output::print (int i) {
  cout << i << '\n';
}

class Rectangle2: public Polygon2, public Output {
  public:
    Rectangle2 (int a, int b) : Polygon2(a,b) {}
    int area ()
      { return width*height; }
};

class Triangle2: public Polygon2, public Output {
  public:
    Triangle2 (int a, int b) : Polygon2(a,b) {}
    int area ()
      { return width*height/2; }
};

//abstract class Polygon
class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
      // virtual member
    virtual int area ()
      { return 0; }
};

class Rectangle: public Polygon {
  public:
    int area ()
      { return width * height; }
};

class Triangle: public Polygon {
  public:
    int area ()
      { return (width * height / 2); }
};

// overloading functions
int operate (int a, int b)
{
  return (a*b);
}

double operate (double a, double b)
{
  return (a/b);
}
// dynamic allocation and polymorphism
class Polygon1 {
  protected:
    int width, height;
  public:
    Polygon1 (int a, int b) : width(a), height(b) {}
    virtual int area (void) =0;
    void printarea()
      { cout << this->area() << '\n'; }
};

class Rectangle1: public Polygon1 {
  public:
    Rectangle1(int a,int b) : Polygon1(a,b) {}
    int area()
      { return width*height; }
};

class Triangle1: public Polygon1 {
  public:
    Triangle1(int a,int b) : Polygon1(a,b) {}
    int area()
      { return width*height/2; }
};

// constructors and derived classes
class Mother {
  public:
    Mother ()
      { cout << "Mother: no parameters\n"; }
    Mother (int a)
      { cout << "Mother: int parameter\n"; }
};

class Daughter : public Mother {
  public:
    Daughter (int a)
      { cout << "Daughter: int parameter\n\n"; }
};

class Son : public Mother {
  public:
    Son (int a) : Mother (a)
      { cout << "Son: int parameter\n\n"; }
};



// derived classes
class Polygon3 {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b;}
 };

class Rectangle3: public Polygon {
  public:
    int area ()
      { return width * height; }
 };

class Triangle3: public Polygon {
  public:
    int area ()
      { return width * height / 2; }
  };
int main()
{
    cout<<"Hello World"<<endl;

  Rectangle rect;
  Triangle trgl;
  Polygon poly;
  Polygon * ppoly1 = &rect;
  Polygon * ppoly2 = &trgl;
  Polygon * ppoly3 = &poly;
  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
  ppoly3->set_values (4,5);
  cout << ppoly1->area() << '\n';
  cout << ppoly2->area() << '\n';
  cout << ppoly3->area() << '\n';

  Polygon1 * ppoly4 = new Rectangle1 (4,5);
  Polygon1 * ppoly5 = new Triangle1 (4,5);
  ppoly4->printarea();
  ppoly5->printarea();
  delete ppoly4;
  delete ppoly5;

  Rectangle3 rect2;
  Triangle3 trgl2;
  rect2.set_values (4,5);
  trgl2.set_values (4,5);
  cout << rect.area() << '\n';
  cout << trgl.area() << '\n';

  Daughter kelly(0);
  Son bud(0);

  Rectangle2 rect1 (4,5);
  Triangle2 trgl1 (4,5);
  rect1.print (rect.area());
  Triangle2::print (trgl1.area());

  Rectangle4 rect3;
  Square sqr (4);
  rect3.convert(sqr);
  cout << rect3.area()<<endl;

  Rectangle5 foo;
  Rectangle5 bar (2,3);
  foo = duplicate (bar);
  cout << foo.area() << '\n';

  int x=5,y=2;
  double n=5.0,m=2.0;
  cout << operate (x,y) << '\n';
  cout << operate (n,m) << '\n';

  int i=5, j=6, k;
  double f=2.0, g=0.5, h;
  k=sum<int>(i,j);
  h=sum<double>(f,g);
  cout << k << '\n';
  cout << h << '\n';

  if (are_equal(10,10.0))
    cout << "x and y are equal\n";
  else
    cout << "x and y are not equal\n";

  std::cout << fixed_multiply<int,2>(10) << '\n';
  std::cout << fixed_multiply<int,3>(10) << '\n';

    string mystr;
  int num;

  for (num=0; num<3; num++)
  {
    cout << "Enter title: ";
    getline (cin,films[num].title);
    cout << "Enter year: ";
    getline (cin,mystr);
    stringstream(mystr) >> films[num].year;
  }

  cout << "\nYou have entered these movies:\n";
  for (num=0; num<3; num++){
    printmovie (films[num]);
    }

    movies_t1 amovie;
  movies_t1 * pmovie;
  pmovie = &amovie;

  cout << "Enter title: ";
  getline (cin, pmovie->title);
  cout << "Enter year: ";
  getline (cin, mystr);
  (stringstream) mystr >> pmovie->year;

  cout << "\nYou have entered:\n";
  cout << pmovie->title;
  cout << " (" << pmovie->year << ")\n";

  Colors mycolor;

mycolor = Colors::blue;
if (mycolor == Colors::green) mycolor = Colors::red;

  //basic file operations
  ofstream myfile;
  myfile.open ("example.txt");
  myfile << "Writing this to a file.\n";
  myfile.close();

    ofstream myfile2 ("example.txt");
  if (myfile2.is_open())
  {
    myfile2 << "This is a line.\n";
    myfile2 << "This is another line.\n";
    myfile2.close();
  }
  else cout << "Unable to open file";

   //writing on a text file
   ofstream myfile3 ("example.txt");
  if (myfile.is_open())
  {
    myfile3 << "This is a line.\n";
    myfile3 << "This is another line.\n";
    myfile3.close();
  }
  else cout << "Unable to open file";

  //reading a text file
  string line;
  ifstream myfile4 ("example.txt");
  if (myfile4.is_open())
  {
    while ( getline (myfile4,line) )
    {
      cout << line << '\n';
    }
    myfile4.close();
  }

  else cout << "Unable to open file";


    return 0;
}
void printmovie (movies_t movie)
{
  cout << movie.title;
  cout << " (" << movie.year << ")\n";
}
