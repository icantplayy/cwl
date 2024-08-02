#include <CWL/cwl.h>

int main(void)
{
    CWL_window* window = CWL_Create_Window(800, 600, "Test", 0);

    while (1)
    {
        CWL_Poll_Events();
    }

    CWL_Release_Window(window);

    return 0;
}