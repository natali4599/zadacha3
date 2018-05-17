#include <iostream>  // Будем работать с стандартным выводом
#include <stdlib.h>

using namespace std;


 // цвет фигуры
enum  fig_color {black, white};
 // горизонталь
enum coord {a ,b ,c, d, e, f, g, h};
char const* coord_str [] =  {
      "A","B","C","D","E","F","G","H"
};

//
class figure {                 //класс «фигура»
  protected:
	int hor;                      //позиция фигуры по горизонтали
    coord vert;                    //позиция фигуры по вертикали
    fig_color color;                     //цвет фигуры
  public:
    figure(coord x, int y, fig_color c); //конструктор
	virtual ~figure();
	   //чистая функция «ход»
   virtual bool step (coord new_letter, int new_digit)=0;
};


figure::figure(coord x, int y, fig_color c): //конструктор
          vert(x), hor(y), color(c) {

 }

figure::~figure() {

}


 class castle : public figure  //класс ладья
  {
    public:
	  castle(coord x, int y, fig_color c);               //конструктор
	  bool step(coord new_letter, int new_digit); //функция, реализующая ход ладьи на поле [x y ]

  };


 castle::castle(coord x, int y, fig_color z): figure (x, y, z) {               //конструктор
    cout << "Ладья "<< coord_str[vert] << "-" << hor << endl;    
 }


  bool castle::step(coord new_letter,
 int new_digit) {
  cout << "Ладья "<< coord_str[vert] << "-" << hor;
   if ( ((new_letter == vert) 
&& (new_digit != hor)) 
   || ((new_letter != vert) 
&& (new_digit == hor)))
   {
      vert = new_letter; hor = new_digit;
	  cout << "->"<< coord_str[new_letter] << "-" << new_digit << endl;
      return true;
   }
   	cout << " - Нет хода" << endl;
   return false;
  };

  class bishop : public figure          //класс слон
  { 
    public:
      bishop(coord x, int y, fig_color z);   //конструктор
      bool step(coord new_letter, int new_digit);

  };

bishop::bishop(coord x, int y, fig_color z):
       figure (x, y, z) {              //конструктор
   cout << "Слон "<< coord_str[vert] << "-" << hor << endl;    
}

bool bishop::step(coord new_letter, int new_digit)     //функция, реализующая ход слона на поле [x y ]
{
   cout << "Слон "<< coord_str[vert] << "-" << hor;
	if (abs((new_letter - vert)
          == abs(new_digit - hor))
            && (new_letter != vert)) {
      vert= new_letter; new_digit=hor;
	  cout << "->"<< coord_str[new_letter] << "-" << new_digit << endl;
      return 1;
   }
	cout << " - Нет хода" << endl;
   return 0;
}

// Класс Королева
class queen: public figure
{
  public:
    queen(coord x, int y, fig_color z); //конструктор
   bool step(coord new_letter, int new_digit);
};


queen::queen(coord x, int y, fig_color z): //конструктор
  figure (x, y, z) {
	     cout << "Королева " << coord_str[vert] << "-" << hor << endl;
}

bool queen::step(coord new_letter, int new_digit)
{
   cout << "Королева " << coord_str[vert] << "-" << hor;
	if ( ((new_letter == vert)
 && (new_digit != hor)) 
      || ((new_letter != vert)
 && (new_digit == hor))
      || (abs((new_letter - vert)
 == abs(new_digit - hor)) 
      && (new_letter != vert)))
   {
     vert = new_letter; hor = new_digit;
	 cout << "->" << coord_str[new_letter] << "-" << new_digit << endl;
     return true; 
   }
	cout << " - Нет хода" << endl;
   return false;
}
;




int main()
{
  setlocale(LC_ALL, "Russian");// Русский в консоли
  figure* f0=new castle(b,2,white);  // устанавливаем ладью на доску
  figure* f1=new queen(e,4,black);	// устанавливаем королеву
  figure* f2=new bishop(e,4,black);  // устанавливаем слона

  f0->step(b,3);  // Ход ладьей 
  f1->step(d,3);  // Ход королевой
  f2->step(e,5);  // Ход слоном
  return 0;
}
