#include "../../cg_base/cg_obj/cg_window.h"
#include "cg.h"

void thermometer_draw(cg_message_t* cg_message)
{
	cg_win_handle_t* hWin;
	hWin = cg_message->win;
}

void cg_gui_main()
{
	cg_rect_t             rect = {.x0 = 0, .y0 = 0, .x1 = 600, .y1 = 400};
	cg_win_handle_t       win;
	cg_model_handle_t     model;
	cg_view_handle_t      view;
	cg_presenter_handle_t presenter;

	win           = cg_window_create(&rect);
	win.model     = cg_model_create();
	win.view      = cg_view_create(thermometer_draw);
	win.presenter = cg_presenser_create();

	while (true) {
		;
	}
}
