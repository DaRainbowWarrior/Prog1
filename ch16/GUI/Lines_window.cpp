#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-300,0}, 150, 40, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},

    quit_button{Point{x_max()-150,0}, 150, 40, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},

    next_x{Point{300,0}, 50, 40, "next x:"},
    next_y{Point{450,0}, 50, 40, "next y:"},
    xy_out{Point{100,0}, 100, 40, "current (x,y):"},

    color_menu{Point{x_max()-150,40},150,40,Menu::vertical,"color"},
    colormenu_button{Point{x_max()-150,40}, 150, 40, "color menu", cb_colormenu},

    line_menu{Point{x_max()-300,40},150,40,Menu::vertical,"line"},
    linemenu_button{Point{x_max()-300,40}, 150, 40, "line menu", cb_line_menu}

{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    xy_out.put("no point");
    

    color_menu.attach(new Button{Point{0,0},0,0,"red",cb_red});
    color_menu.attach(new Button{Point{0,0},0,0,"blue",cb_blue});
    color_menu.attach(new Button{Point{0,0},0,0,"black",cb_black});
    attach(color_menu);
    color_menu.hide();
    attach(colormenu_button);

    line_menu.attach(new Button{Point{0,0},0,0,"solid",cb_solid});
    line_menu.attach(new Button{Point{0,0},0,0,"dashed",cb_dashed});
    line_menu.attach(new Button{Point{0,0},0,0,"dotted",cb_dotted});
    attach(line_menu);
    line_menu.hide();
    attach(linemenu_button);

    attach(lines);
}

void Lines_window::cb_red(Address, Address pw)
{
    reference_to<Lines_window>(pw).red_pressed();
}

void Lines_window::cb_blue(Address, Address pw)
{
    reference_to<Lines_window>(pw).blue_pressed();
}

void Lines_window::cb_black(Address, Address pw)
{
    reference_to<Lines_window>(pw).black_pressed();
}

void Lines_window::cb_colormenu(Address, Address pw)
{
    reference_to<Lines_window>(pw).colormenu_pressed();
}

void Lines_window::cb_solid(Address, Address pw)
{
    reference_to<Lines_window>(pw).solid_pressed();
}

void Lines_window::cb_dashed(Address, Address pw)
{
    reference_to<Lines_window>(pw).dashed_pressed();
}

void Lines_window::cb_dotted(Address, Address pw)
{
    reference_to<Lines_window>(pw).dotted_pressed();
}

void Lines_window::cb_line_menu(Address, Address pw)
{
    reference_to<Lines_window>(pw).linemenu_pressed();
}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}