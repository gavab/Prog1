/*
	g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;

int main()
{
	

	constexpr int xmax=800;
	constexpr int ymax=1000;


	Simple_window win {Point{100,100}, xmax, ymax, "Lester a Moleszter"};
	win.wait_for_button();

	int x_size=800;
	int y_size=800;

	int x_grid=100;
	int y_grid=100;

	Lines grid;

	for(int x=x_grid;x<=x_size;x+=x_grid)
		grid.add(Point{x,0},Point{x,y_size});
	
	for (int y=y_grid;y<=y_size;y+=y_grid)
		grid.add(Point{0,y},Point{x_size,y});
	

	win.attach(grid);
	win.wait_for_button();
	
	int grid_size=100;

	Vector_ref<Rectangle> vr;

	for(int i=0; i<8; ++i)
	{	
		vr.push_back(new Rectangle{Point{i*grid_size,i*grid_size}, grid_size , grid_size});
		vr[i].set_fill_color(Color::red);
		win.attach(vr[i]);
	}
	win.wait_for_button();
												
	Vector_ref<Image> vi;

	vi.push_back(new Image{Point{0,200},"MK_scorpion.jpg"});
	vi.push_back(new Image{Point{0,400},"MK_scorpion.jpg"});
	vi.push_back(new Image{Point{0,600},"MK_scorpion.jpg"});

	int s_x=600;
	int s_y=125;

	int i_s=200;

	for(int i=0; i<vi.size(); ++i)
	{
		vi[i].set_mask(Point{s_x,s_y},i_s,i_s);
		win.attach(vi[i]);

	}
	win.wait_for_button();

	Image mozaik {Point{0,0}, "lilscorpion.jpeg"};
	
	win.attach(mozaik);
	win.wait_for_button();


	for (int i = 0; i < 8; ++i) 
	 {
        for (int j = 0; j < 8; ++j) 
        {
            
            if(j<7)
            {	
        	    mozaik.move(100, 0);
            	win.wait_for_button();
        	}
        	else{
        		
        		 mozaik.move(-700, 100);
        		 win.wait_for_button();
        	}
        	         
        }
       
    }

}
