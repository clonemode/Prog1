/*
    g++ drillch13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13ch `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	Point t(100,100);
	int magassag = 1000;
	int szelesseg = 800;
	Simple_window win (t,szelesseg,magassag,"drill 13 window");

	Lines vonalak;
	int racs_x = 100;
	int racs_y = 100;
	for(int i=racs_x;i<=szelesseg;i+=racs_x)
		vonalak.add(Point{i,0},Point{i,magassag-200});
	for(int i=racs_y;i<=magassag-200;i+=racs_y)
		vonalak.add(Point{0,i},Point{szelesseg,i});

	win.attach(vonalak);

	Vector_ref<Rectangle>kockak;
	for(int i=0;i<8;i++)
	{
		kockak.push_back(new Rectangle{Point{i*100,i*100},101,101});
		kockak[i].set_fill_color(Color::red);
		win.attach(kockak[i]);
	}

	Image kep1{Point{300,0},"maci.jpg"};
	Image kep2{Point{200,500},"maci.jpg"};
	Image kep3{Point{600,200},"maci.jpg"};
	Image kep4{Point{0,0},"smile.jpg"};
	win.attach(kep1);
	win.attach(kep2);
	win.attach(kep3);
	win.attach(kep4);

	win.wait_for_button();
	int oszlop=0;
	while(true)
	{
		for(int i=0;i<7;i++)
		{
			kep4.move(0,100);
			win.wait_for_button();
		}
		if(oszlop==7)
		{
			oszlop=0;
			kep4.move(-700,-700);
		}
		else
		{
			kep4.move(100,-700);
			oszlop++;
		}
		win.wait_for_button();
	}
}
