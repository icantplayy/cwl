// MIT License
// 
// Copyright (c) 2024 icantplay
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "cwl_window.h"
#include "cwl_defines.h"
#ifdef CWL_PLAT_LINUX
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

static Display* display;
static XEvent   event;
static Window   window;
static int      screen;

CWL_window*
CWL_Create_Window(int width, int height, const char* title, unsigned int flags)
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

void
CWL_Release_Window(CWL_window* cwl_window)
{
    XCloseDisplay(display);
    free(cwl_window);
}

void
CWL_Poll_Events()
{
    XNextEvent(display, &event);
}

#endif // CWL_PLAT_LINUX