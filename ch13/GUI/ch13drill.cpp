/*
    g++ ch13drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ch13drill.out `fltk-config --ldflags --use-images` -std=c++11
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

	Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};

	Lines grid;
	for (int x=x_grid; x<x_size; x+=x_grid)
		grid.add(Point{x,0},Point{x,y_size});
	for (int y = y_grid; y<y_size; y+=y_grid)
		grid.add(Point{0,y},Point{x_size,y});

	Vector_ref<Rectangle> rekt;

	for(int i=0; i < x_size; i += x_grid)
	{
		rekt.push_back(new Rectangle{Point{i,i}, Point{i+x_grid,i+x_grid}});
		rekt[rekt.size() - 1].set_fill_color(Color::red);
		win.attach(rekt[rekt.size() - 1]);
	}


	Image image1 {Point{0,300},"beka.jpg"};
    Image image2 {Point{300,600},"beka.jpg"};
    Image image3 {Point{600,300},"beka.jpg"};
    Image imageR {Point{0,0}, "beka2.jpg"};

    win.attach(grid);
	win.attach(image1);
	win.attach(image2);
	win.attach(image3);
	win.attach(imageR);

	win.wait_for_button();

	for(int i=0;i<701;i+=100)
	{
		for(int j=0;j<700;j+=100)
		{
			imageR.move(100,0);
			win.wait_for_button();
		}
		if( i < 700)
		{
			imageR.move(-700,100);
			win.wait_for_button();
		}
	}



}
