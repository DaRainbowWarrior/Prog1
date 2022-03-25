#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );
	
	Open_polyline lines;
	
	bool wait_for_button();

	


private:
	Button next_button;
	Button quit_button;

	In_box next_x;
	In_box next_y;

	Out_box xy_out;
	
	Menu color_menu;
	Button colormenu_button;

	Menu line_menu;
	Button linemenu_button;

	void changecolor(Color c) { lines.set_color(c); }
	void hide_colormenu() { color_menu.hide(); colormenu_button.show(); }

	void changeline(Line_style s){lines.set_style(s);}
    void hide_linemenu() {line_menu.hide(); linemenu_button.show(); }

	void red_pressed() { changecolor(Color::red); hide_colormenu(); }
	void blue_pressed() { changecolor(Color::blue); hide_colormenu(); }
	void black_pressed() { changecolor(Color::black); hide_colormenu(); }
	void colormenu_pressed() { colormenu_button.hide(); color_menu.show(); }
	
	void dotted_pressed() { changeline(Line_style::dot); hide_linemenu(); }
    void dashed_pressed() { changeline(Line_style::dash); hide_linemenu(); }
    void solid_pressed() { changeline(Line_style::solid); hide_linemenu(); }

    void linemenu_pressed() { linemenu_button.hide(); line_menu.show(); }

	void next();
	void quit();
	
	static void cb_red(Address, Address);
	static void cb_blue(Address, Address);
	static void cb_black(Address, Address);
	static void cb_colormenu(Address, Address);
	static void cb_solid(Address,Address);
    static void cb_dashed(Address,Address);
    static void cb_dotted(Address,Address);
    static void cb_line_menu(Address, Address);
};
