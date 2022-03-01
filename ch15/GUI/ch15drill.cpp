/*
    g++ ch13drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ch13drill `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    int xmax = 800;
    int ymax = 1000;


	int x_size = 800;
	int y_size = 801;
	int x_grid = 100;
	int y_grid = 100;


	Lines grid;
	for (int x=x_grid; x<x_size; x+=x_grid)
		grid.add(Point{x,0},Point{x,y_size});
	for (int y = y_grid; y<y_size; y+=y_grid)
		grid.add(Point{0,y},Point{x_size,y});

	int plusz = y_size;
	//for(int i=0; i<=x_size; i=i+x_size)
	//{
		Rectangle Rect {Point{plusz,plusz},100,100};
		plusz = plusz + y_size;
	//}



    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};

    win.attach(grid);
    win.attach(Rect);

    win.wait_for_button();

}
