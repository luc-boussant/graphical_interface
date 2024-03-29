#include <stdlib.h>
#include "ei_draw.h"
#include "ei_types.h"
#include "ei_main.h"
#include "ei_event.h"
#include "ei_utils.h"
#include "hw_interface.h"

int ei_main(int argc, char** argv)
{
	ei_surface_t			main_window		= NULL;
	ei_point_t point;
	point.x = 50;
	point.y = 50;
	ei_rect_t* ls_rect;
	ls_rect = malloc(sizeof(ei_rect_t));
	ls_rect -> size = ei_size(50, 50);
	ls_rect -> top_left = point;
	ei_size_t			main_window_size	= ei_size(640, 480);
	ei_event_t			event;
  ei_color_t* color;
  color = malloc(sizeof(ei_color_t));
  color -> red = 255;
  color -> green = 0;
  color -> blue = 0;
  color -> alpha = 0;
  // Init acces to hardware.

	hw_init();
  // Create the main window.
  main_window = hw_create_window(&main_window_size, EI_FALSE);
  ei_fill(main_window, color, ls_rect);

  event.type = ei_ev_none;
	while (event.type != ei_ev_keydown)
		hw_event_wait_next(&event);
	// Free hardware resources.
	hw_quit();

	// Terminate program with no error code.
	return 0;
}
