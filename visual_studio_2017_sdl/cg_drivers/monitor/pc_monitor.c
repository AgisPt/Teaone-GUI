/************************************************************************/
/* includes                                                             */
/************************************************************************/
#include "cg_drv_conf.h"
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pc_monitor.h"

/************************************************************************/
/* static variables                                                     */
/************************************************************************/
static uint32_t lcd_fb[MONITOR_HOR_PX * MONITOR_VER_PX];

static SDL_Window*   window;
static SDL_Renderer* renderer;
static SDL_Texture*  texture;

static SDL_mutex* fb_lock;

static void pc_monitor_sdl_init(void);
static void pc_monitor_sdl_refresh_core(void);
static void pc_monitor_sdl_clean_up(void);
static void pc_monitor_sdl_refresh_thread(void);

/************************************************************************/
/* global functions                                                     */
/************************************************************************/
void pc_monitor_init(void)
{
	fb_lock = SDL_CreateMutex();
	SDL_CreateThread(pc_monitor_sdl_refresh_thread, "sdl_thread", NULL);
	// SDL_CreateThread(pc_monitor_fill, "fill_thread", NULL);
	SDL_Delay(100);
}

cg_error_t pc_monitor_refresh(cg_rect_t* area, cg_color_t* frame_p)
{
	if (true != cg_area_isexist(area)) {
		return cg_err_graphical_rect_not_exist;
	}

#if CG_MULTI_BUFFER_ENABLE == 0
	cg_ruler_t y;
	cg_ruler_t ye = area->y1;
#	if CG_COLOR_DEPTH != 24 && CG_COLOR_DEPTH != 32
	cg_ruler_t x;
	cg_ruler_t xe = area->x1;
	for (y = area->y0; y < ye; y++) {
		for (x = area->x0; x < xe; x++) {
			lcd_fb[y * MONITOR_HOR_PX + x] =
			        cg_color_to32(*frame_p);
			frame_p++;
		}
	}
#	else
	uint32_t xw = area->x_width;
	for (; y < ye; y++) {
		memcpy(&lcd_fb[y * MONITOR_HOR_PX + x],
		       frame_p,
		       w * sizeof(cg_color_t));
		frame_p += xw;
	}
#	endif  // CG_COLOR_DEPTH != 24 && CG_COLOR_DEPTH != 32

#else

#endif  // CG_MULTI_BUFFER_ENABLE == 0
}

void pc_monitor_fill(cg_rect_t* area, cg_color_t color)
{
	/*If the area is not on the screen, return*/
	if ((area->x1 < 0) || (area->y1 < 0) || (area->x0 > CG_HOR_PX - 1) ||
	    (area->y0 > CG_VER_PX - 1)) {
		return cg_err_area_not_inlcd;
	}

	if (true != cg_area_isexist(area)) {
		return cg_err_graphical_rect_not_exist;
	}

	/*Capturing content on the screen*/
	int32_t scr_x1 = area->x0 < 0 ? 0 : area->x0;
	int32_t scr_y1 = area->y1 < 0 ? 0 : area->y0;
	int32_t scr_x2 = area->x1 > CG_HOR_PX - 1 ? CG_HOR_PX - 1 : area->x1;
	int32_t scr_y2 = area->y1 > CG_VER_PX - 1 ? CG_VER_PX - 1 : area->y1;

	uint32_t color32 = cg_color_to32(color);

	int32_t x, y;

	for (y = scr_y1; y < scr_y2; y++) {
		for (x = scr_x1; x < scr_x2; x++) {
			lcd_fb[y * CG_HOR_PX + x] = color32;
		}
	}
}

/************************************************************************/
/* Static function                                                      */
/************************************************************************/
static void pc_monitor_sdl_init(void)
{
	SDL_Init(SDL_INIT_VIDEO);
	window   = SDL_CreateWindow("embedded GUI",
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  MONITOR_HOR_PX * MONITOR_ZOOM,
                                  MONITOR_VER_PX * MONITOR_ZOOM,
                                  SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	texture  = SDL_CreateTexture(renderer,
                                    SDL_PIXELFORMAT_ARGB8888,
                                    SDL_TEXTUREACCESS_STATIC,
                                    MONITOR_HOR_PX,
                                    MONITOR_VER_PX);

	memset(lcd_fb,
	       0x00,
	       MONITOR_HOR_PX * MONITOR_VER_PX * sizeof(uint32_t));

	SDL_UpdateTexture(
	        texture, NULL, lcd_fb, MONITOR_HOR_PX * sizeof(uint32_t));
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

static void pc_monitor_sdl_refresh_core(void)
{
	// SDL_LockMutex(fb_lock);
	SDL_UpdateTexture(
	        texture, NULL, lcd_fb, MONITOR_HOR_PX * sizeof(uint32_t));
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
	printf("refresh core+++++++++++++++++++++\n");
	// SDL_UnlockMutex(fb_lock);
	SDL_Delay(1);
}

static void pc_monitor_sdl_clean_up(void)
{
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

static void pc_monitor_sdl_refresh_thread(void)
{
	pc_monitor_sdl_init();

	while (1) {
		pc_monitor_sdl_refresh_core();
	}

	pc_monitor_sdl_clean_up();
}
