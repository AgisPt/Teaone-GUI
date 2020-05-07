/************************************************************************/
/* includes                                                             */
/************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include "cg_drv_conf.h"

#include "pc_monitor.h"


/************************************************************************/
/* static variables                                                     */
/************************************************************************/
static uint32_t lcd_fb[MONITOR_HOR_PX * MONITOR_VER_PX];

static SDL_Window* window;
static SDL_Renderer* renderer;
static SDL_Texture* texture;

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
        //SDL_CreateThread(pc_monitor_fill, "fill_thread", NULL);
        SDL_Delay(100);
}

void pc_monitor_refresh(cg_rect_t* area, cg_color_t* frame_p)
{
        if (cg_err_area_exist != cg_area_isexist(area))
        {
                return;
        }

#if CG_MULTI_BUFFER_ENABLE == 0
        cg_ruler_t y = area->y;
        cg_ruler_t ye = y + area->y_width;
#   if CG_COLOR_DEPTH != 24 && CG_COLOR_DEPTH != 32
        cg_ruler_t x = area->x;
        cg_ruler_t xe = x + area->x_width;
        for (; y < ye; y++)
        {
                for (; x < xe; x++)
                {
                        lcd_fb[y * MONITOR_HOR_PX + x] = cg_color_to32(*frame_p);
                        frame_p++;
                }
        }
#   else
        uint32_t xw = area->x_width;
        for (; y < ye; y++)
        {
                memcpy(&lcd_fb[y * MONITOR_HOR_PX + x], frame_p, w * sizeof(cg_color_t));
                frame_p += xw;
        }
#   endif // CG_COLOR_DEPTH != 24 && CG_COLOR_DEPTH != 32

#else

#endif // CG_MULTI_BUFFER_ENABLE == 0
}

void pc_monitor_fill(cg_rect_t* area, cg_color_t color)
{
        //int32_t x_max, x_min, y_max, y_min;
        //x_max = CG_MATH_MAX(x1, x2);
        //x_min = CG_MATH_MIN(x1, x2);
        //y_max = CG_MATH_MAX()

        /*If the area is not on the screen, return*/
        if ((x_width < 0) || (y_width < 0) || (x > CG_HOR_PX - 1) || (y > CG_VER_PX - 1))
        {
                return;
        }

        /*Capturing content on the screen*/
        int32_t scr_x1 = x < 0 ? 0 : x;
        int32_t scr_y1 = y < 0 ? 0 : y;
        int32_t scr_x2 = x_width > CG_HOR_PX - 1 ? CG_HOR_PX - 1 : x_width;
        int32_t scr_y2 = y_width > CG_VER_PX - 1 ? CG_VER_PX - 1 : y_width;

        uint32_t color32 = cg_color_to32(color);

        int32_t x, y;

        for (y = scr_y1; y < scr_y2; y++)
        {
                for (x = scr_x1; x < scr_x2; x++)
                {
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
        window = SDL_CreateWindow("embedded GUI", SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED, MONITOR_HOR_PX * MONITOR_ZOOM, MONITOR_VER_PX * MONITOR_ZOOM, SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
        texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, MONITOR_HOR_PX, MONITOR_VER_PX);

        memset(lcd_fb, 0x00, MONITOR_HOR_PX * MONITOR_VER_PX * sizeof(uint32_t));

        SDL_UpdateTexture(texture, NULL, lcd_fb, MONITOR_HOR_PX * sizeof(uint32_t));
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);

}

static void pc_monitor_sdl_refresh_core(void)
{
        //SDL_LockMutex(fb_lock);
        SDL_UpdateTexture(texture, NULL, lcd_fb, MONITOR_HOR_PX * sizeof(uint32_t));
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
        printf("refresh core+++++++++++++++++++++\n");
        //SDL_UnlockMutex(fb_lock);
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

        while (1)
        {
                pc_monitor_sdl_refresh_core();
        }

        pc_monitor_sdl_clean_up();
}
