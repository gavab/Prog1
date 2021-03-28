#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    
    next_button{Point{x_max()-200,0}, 80, 40, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
    
    quit_button{Point{x_max()-100,0}, 80, 40, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
    
    next_x{Point{400,0}, 60, 40, "next x:"},
    
    next_y{Point{600,0}, 60, 40, "next y:"},
    
    xy_out{Point{200,0}, 100, 40, "current (x,y):"},
    
    color_menu{Point{x_max()-110,150},100,40,Menu::vertical,"color"},
    
    color_button{Point{x_max()-110,150},100,40,"Color menu",
    [](Address,Address pw){reference_to<Lines_window>(pw).color_menu_pressed();}},

    style_menu{Point{x_max()-210,150},100,40,Menu::vertical,"style"},

    style_button{Point{x_max()-210,150},100,40,"Style menu",
    [](Address,Address pw){reference_to<Lines_window>(pw).style_menu_pressed();}}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    xy_out.put("no point");
    
    color_menu.attach(new Button{Point{0,0},0,0,"red",
    [](Address,Address pw){reference_to<Lines_window>(pw).red_pressed();}});
    
    color_menu.attach(new Button{Point{0,0},0,0,"blue",
    [](Address,Address pw){reference_to<Lines_window>(pw).blue_pressed();}});
    
    color_menu.attach(new Button{Point{0,0},0,0,"black",
    [](Address,Address pw){reference_to<Lines_window>(pw).black_pressed();}});

    attach(color_menu);
    color_menu.hide();
    attach(color_button);

    style_menu.attach(new Button{Point{0,0},0,0,"solid",
    [](Address,Address pw){reference_to<Lines_window>(pw).solid_pressed();}});

    style_menu.attach(new Button{Point{0,0},0,0,"dash",
    [](Address,Address pw){reference_to<Lines_window>(pw).dash_pressed();}});

    style_menu.attach(new Button{Point{0,0},0,0,"dashdot",
    [](Address,Address pw){reference_to<Lines_window>(pw).dashdot_pressed();}});

    style_menu.attach(new Button{Point{0,0},0,0,"dashdotdot",
    [](Address,Address pw){reference_to<Lines_window>(pw).dashdotdot_pressed();}});

    attach(style_menu);
    style_menu.hide();
    attach(style_button);

    attach(lines);
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