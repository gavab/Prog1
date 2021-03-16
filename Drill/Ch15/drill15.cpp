/*
	g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

double one(double x) {return 1;}
double slope(double x) {return x/2;}
double square(double x){return x*x;}
double slope_cos(double x){return cos(x)+slope(x);}

int main()
{
	constexpr int xmax=600;
	constexpr int ymax=600;

	Point tl {100,100};

	Simple_window win {tl,xmax,ymax,"Function graphs"};

	const int x_orig=300;
	const int y_orig=300;

	const int x_length=400;
	const int y_length=400;

	const int notches=20;

	Axis xa {Axis::x,Point{100,y_orig},x_length,notches,"1==20 pixels"};
	Axis ya {Axis::y,Point{x_orig,y_length+100},y_length,notches,"1==20 pixels"};

	xa.set_color(Color::red);
	ya.set_color(Color::red);

	win.attach(xa);
	win.attach(ya);

	const int rmin=-10;
	const int rmax=11;

	const int n_o_ps=400;

	Point origo{300,300};

	const int xscale=20;
	const int yscale=20;

	Function s(one,rmin,rmax,origo,n_o_ps,xscale,yscale);

	Function slo(slope,rmin,rmax,origo,n_o_ps,xscale,yscale);

	Text slolabel{Point{100,385},"x/2"};

	Function sq(square,rmin,rmax,origo,n_o_ps,xscale,yscale);

	Function c(cos,rmin,rmax,origo,n_o_ps,xscale,yscale);
	c.set_color(Color::blue);

	Function sl_cos(slope_cos,rmin,rmax,origo,n_o_ps,xscale,yscale);

	win.attach(s);
	win.attach(slo);
	win.attach(slolabel);
	win.attach(sq);
	win.attach(c);
	win.attach(sl_cos);

	win.wait_for_button();
}
