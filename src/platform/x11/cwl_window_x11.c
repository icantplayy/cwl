#include "cwl_window.h"
#include "cwl_defines.h"
#ifdef CWL_PLAT_LINUX
#include <X11/Xlib.h>

#include <stdio.h>
#include <stdlib.h>

static Display* display = {0};
static Window window = {0};
static XEvent event = {0};
static int screen = 0;

CWL_window* CWL_Create_Window(int width, int height, const char* title, unsigned int flags)
{
    CWL_window* cwl_window = malloc(sizeof(*cwl_window));
    cwl_window->width = width;
    cwl_window->height = height;
    cwl_window->title = title;

    display = XOpenDisplay(NULL);
    if (display == NULL)
    {
        fprintf(stderr, "Failed to open a X11 Display!");
        exit(EXIT_FAILURE);
    }

    screen = DefaultScreen(display);
    window = XCreateSimpleWindow(display, RootWindow(display, screen), 10, 10, width, height, 1, BlackPixel(display, screen), WhitePixel(display, screen));

    XStoreName(display, window, title);    

    XSelectInput(display, window, ExposureMask | KeyPressMask);
    XMapWindow(display, window);

    return cwl_window;
}

void CWL_Release_Window(CWL_window* cwl_window)
{
    XCloseDisplay(display);
    free(cwl_window);
}

void CWL_Poll_Events()
{
    XNextEvent(display, &event);
}

#endif // CWL_PLAT_LINUX