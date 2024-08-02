#ifndef _CWL_WINDOW_H_
#define _CWL_WINDOW_H_
#include "cwl_defines.h"

typedef struct
cwl_window
{
    int width;
    int height;
    const char* title;
} CWL_window;

CWL_window*   CWL_Create_Window     (int width, int height, const char* title, unsigned int flags);
void          CWL_Release_Window    (CWL_window* cwl_window);

void          CWL_Poll_Events       ();

#endif // __CWL_WINDOW_H__
