#include "../printfcolor.h"

int main()
{
    printfc_fg(RED, "Red text\n");
    printfc_fg(GREEN, "Green text\n");
    printfc_fg(BLUE, "Blue text\n\n");

    printfc_bg(CYAN, "Cyan background\n");
    printfc_bg(MAGENTA, "Magenta background\n");
    printfc_bg(YELLOW, "Yellow background\n\n");

    printfc(CYAN, BLUE, "Cyan on blue\n");
    printfc(GREEN, WHITE, "Green on white\n");
    printfc(GRAY, RED, "Gray on red\n");
}