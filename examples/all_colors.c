#include "../printfcolor.h"

int main()
{
    printf("FOREGROUND\n");
    printfc_fg(GRAY, "Gray text\n");
    printfc_fg(RED, "Red text\n");
    printfc_fg(GREEN, "Green text\n");
    printfc_fg(BLUE, "Blue text\n");
    printfc_fg(CYAN, "Cyan text\n");
    printfc_fg(MAGENTA, "Magenta text\n");
    printfc_fg(YELLOW, "Yellow text\n");
    printfc_fg(WHITE, "White text\n\n");
    printfc_fg(ORANGE, "Orange text\n\n");

    printf("BACKGROUND\n");
    printfc_bg(GRAY, "Gray background\n");
    printfc_bg(RED, "Red background\n");
    printfc_bg(GREEN, "Green background\n");
    printfc_bg(BLUE, "Blue background\n");
    printfc_bg(CYAN, "Cyan background\n");
    printfc_bg(MAGENTA, "Magenta background\n");
    printfc_bg(YELLOW, "Yellow background\n");
    printfc_bg(WHITE, "White background\n\n");
    printfc_bg(ORANGE, "Orange background\n");

    printf("BACKGROUND AND FOREGROUND\n");
    printfc(YELLOW, BLUE, "Yellow on blue\n");
    printfc(RED, YELLOW, "Red on yellow\n");
    printfc(GRAY, GREEN, "Gray on green\n");
    printfc(MAGENTA, CYAN, "Magenta on cyan\n");
    printfc(GREEN, WHITE, "Green on white\n");
    printfc(GRAY, RED, "Gray on red\n");
    printfc(BLUE, GRAY, "Blue on gray\n");
    printfc(ORANGE, BLUE, "Orange on blue\n");
}