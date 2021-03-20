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
	Button color_button;

	Menu style_menu;
	Button style_button;

	void change_c(Color c) {lines.set_color(c);}
	void change_s(Line_style s) {lines.set_style(s);}

	void hide_color_menu() {color_menu.hide(); color_button.show();}
	void hide_style_menu() {style_menu.hide();style_button.show();}

	//actions invoded by callbacks:

	void red_pressed() {change_c(Color::red); hide_color_menu();}
	void blue_pressed() {change_c(Color::blue); hide_color_menu();}
	void black_pressed() {change_c(Color::black); hide_color_menu();}

	void color_menu_pressed() {color_button.hide(); color_menu.show();}

	void solid_pressed() {change_s(Line_style::solid);hide_style_menu();}
	void dash_pressed() {change_s(Line_style::dash);hide_style_menu();}
	void dashdot_pressed() {change_s(Line_style::dashdot);hide_style_menu();}
	void dashdotdot_pressed() {change_s(Line_style::dashdotdot);hide_style_menu();}

	void style_menu_pressed() {style_button.hide();style_menu.show();}
	
	void next();
	void quit();

	//callback functions:
	/*static void cb_red(Address,Address);
	static void cb_blue(Address,Address);
	static void cb_black(Address,Address);
	static void cb_next(Address,Address);
	static void cb_quit(Address,Address);*/
};