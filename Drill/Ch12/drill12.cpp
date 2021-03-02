/*
	g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"
using namespace Graph_lib;

int main()
try{


	constexpr int xmax=600;	//Max width of the window
	constexpr int ymax=400;	//Max height of the window
	Point tl{100,100}; 	//top left of the window


	Simple_window win {tl,xmax,ymax,"Leszter a moleszter"};

	win.wait_for_button();//display

	Axis xa{Axis::x,Point{20,300},300,10,"x axis"};
			/*  an Axis is a kind of space
				Axis::x means horizontal
				starting at (20,300)
				280 pixels long
				10 "notches"
				label the axis "x axis"
			*/

	win.attach(xa); //attach xa
	win.set_label("Leszter a moleszter #2"); //relabel the window
	win.wait_for_button();	//display!

	Axis ya {Axis::y,Point{20,300},300,10,"y axis"};
	ya.set_color(Color::magenta);	//choose color
	ya.label.set_color(Color::dark_red); //choose color for the text
	win.attach(ya);
	win.set_label("Leszter a moleszter #3");
	win.wait_for_button();

	Function sine {sin,0,100,Point{20,150},1000,50,50}; //sine curve
			/*	plot sin() in the range [0:100) with (0,0) at (20,150)
				using 1000 points; scale x values *50, scale y values *50 
			*/
	win.attach(sine);
	win.set_label("Leszter a moleszter #4");
	win.wait_for_button();

	sine.set_color(Color::red); //we changed our mind about sine's color

	Polygon poly;
	poly.add(Point{300,200});	//a polygon is a kind of shape
	poly.add(Point{350,100});	//three points make a tringle
	poly.add(Point{400,200});
	 
	poly.set_color(Color::blue);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	win.set_label("Leszter a moleszter #5");
	win.wait_for_button();

	Rectangle r {Point{200,200},100,50};	//top left corner,width,height
	win.attach(r);
	win.set_label("Leszter a moleszter #6");
	win.wait_for_button();

	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	win.attach(poly_rect);
	win.set_label("Leszter a moleszter #6.1");
	win.wait_for_button();

	poly_rect.add(Point{50,75});
	win.set_label("Leszter a moleszter #6.2");
	win.wait_for_button();

	r.set_fill_color(Color::cyan);	//color the inside of the rectangle
	poly.set_style(Line_style(Line_style::dash,4));
	poly_rect.set_style(Line_style(Line_style::dash,2));
	poly_rect.set_fill_color(Color::green);
	win.set_label("Leszter a moleszter #7");
	win.wait_for_button();

	Text t {Point{150,150},"Hello, graphics world!"};
	win.attach(t);
	win.set_label("Leszter a moleszter #8");
	win.wait_for_button();

	t.set_font(Font::times_bold);
	t.set_font_size(20);
	win.set_label("Leszter a moleszter #9");
	win.wait_for_button();

	Image ii{Point{100,50},"scorpion.jpeg"};
	win.attach(ii);
	win.set_label("Leszter a moleszter #10");
	win.wait_for_button();

	ii.move(100,200);
	win.set_label("Leszter a moleszter #11");
	win.wait_for_button();

	Circle c {Point{200,300},50};
	//Ellipse e {Point{100,200},75,25};
	//e.set_color(Color::dark_red);
	Mark m {Point{200,300},'x'};

	ostringstream oss;
	oss << "screen size: " << x_max() << '*' << y_max()
		<< "; window size: " << win.x_max() << '*' << win.y_max();
	Text sizes{Point{250,50},oss.str()};
	
	Image cal {Point{225,225},"alan.gif"};
	cal.set_mask(Point{100,100},300,400);
	win.attach(c);
	//win.attach(e);
	win.attach(m);

	win.attach(sizes);	
	win.attach(cal);
	win.set_label("Leszter a moleszter #12");
	win.wait_for_button();


}catch(exception& e){
	cerr << e.what() << endl;
	return 1;
}catch(...){
	cerr << "exception\n";
	return 2;
}