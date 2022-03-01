/*
    g++ ch15drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ch15drill.out `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"


double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double slope_cos(double x) {return cos(x) + slope(x);}

	
int main()
{
    using namespace Graph_lib;

    int xmax = 600;
    int ymax = 600;


	int x_origo = xmax/2;
	int y_origo = ymax/2;

	int x_scale = 20;
	int y_scale = 20;

	Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};

	Point origo{x_origo,y_origo};

	Axis x(Axis :: x, Point{100,y_origo},400,400/x_scale, "1 == 20 pixels");
	Axis y(Axis :: y, Point{x_origo,500},400,400/y_scale, "1 == 20 pixels");

	x.set_color(Color :: red);
	y.set_color(Color :: red);

	//Function egy(one, -10, 11, origo,400);
	Function egy(one, -10, 11, origo,400, x_scale,y_scale);

	Function ketto(slope, -10, 11, origo,400, x_scale,y_scale);
	Text t {Point{100, 380}, "x/2"};

	Function harom(square, -10, 11, origo,400, x_scale,y_scale);

	Function negy(slope_cos, -10, 11, origo,400, x_scale,y_scale);

	Function ot( [] (double x) {return cos(x);}, -10, 11, origo,400, x_scale,y_scale);
	ot.set_color(Color :: blue);

    win.attach(x);
    win.attach(y);
    win.attach(egy);
    win.attach(ketto);
    win.attach(t);
    win.attach(harom);
    win.attach(negy);
    win.attach(ot);

    win.wait_for_button();

}
