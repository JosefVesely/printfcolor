#include "../printfcolor.h"

int main() {
    printfc_fg(YELLOW, "Enter the height of the tree: ");

    int height;
    scanf("%d", &height);
    
    for (int i = 1; i <= height; i++) {
        // Print spaces
        for (int j = 1; j <= height - i; j++) {
            printf(" ");
        }
        // Print stars
        for (int k = 1; k <= (2 * i - 1); k++) {
            printfc_fg(GREEN, "*");
        }
        printf("\n");
    }
    // Print trunk
    for (int i = 0; i < height - 1; i++) {
        printf(" ");
    }
    printfc_bg(GRAY, "|\n");
}