/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

#include <string>
#include <iostream>
#include <vector>

using namespace Graph_lib;

int main()
{
	Point t1(101,101);
	Simple_window win (t1,600,400,"My window");

	Image motor{Point{350,50},"motorkep.jpg"};
	win.attach(motor);

	Axis ax{Axis::x,Point{50,250},200,20,"x tengely"};
	ax.set_color(Color::red);
	win.attach(ax);
	Axis ay{Axis::y,Point{150,350},200,20,"y tengely"};
	ay.set_color(Color::dark_red);
	win.attach(ay);

	Function szin{sin,0,21,Point{43,250},1000,10,10};
	win.attach(szin);

	constexpr double PI = 3.14159265;
	const int X = win.x_max() / 2-50;
	const int Y = win.y_max() / 2-50;

	Polygon har;
	int alt = sin(60*PI/180)*100;
	har.add(Point{X,Y+alt});
	har.add(Point{X+50,Y});
	har.add(Point{X+100,Y+alt});
	har.set_color(Color::green);
	har.set_style(Line_style(Line_style::dot,5));
	har.set_fill_color(Color::dark_blue);
	win.attach(har);

	Rectangle koc {Point {X+25,Y-50},50,50};
	koc.set_color(Color::yellow);
	koc.set_fill_color(Color::dark_red);
	koc.set_style(Line_style(Line_style::dash,5));
	win.attach(koc);

	Closed_polyline zart;
	zart.add(Point{400,100});
	zart.add(Point{500,100});
	zart.add(Point{500,50});
	zart.add(Point{400,50});
	zart.add(Point{450,75});
	win.attach(zart);

	Text szoveg{Point{225,50},"CH12 drill!"};
	win.attach(szoveg);

	Circle kor{Point{105,195},25};
	win.attach(kor);


	Mark pont{Point{105,195},'o'};
	win.attach(pont);

	ostringstream info;
	info << "screen size: " << x_max() << "*" << y_max()
	<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text ablak {Point{100,20},info.str()};
	win.attach(ablak);

	Image clap{Point{10,300},"tenor.gif"};
	win.attach(clap);

	win.set_label("utolso window");
	

	win.wait_for_button();
}

	
	