#include <CWL/cwl.h>

int
main(int argc, char **argv)
{
    CWL_window* window = CWL_Create_Window(1280, 720, "Test", 0);

    while (1)
    {
        CWL_Poll_Events();
    }

    CWL_Release_Window(window);

    return 0;
}