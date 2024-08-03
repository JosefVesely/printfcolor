# `printfcolor` Library

A single-header C library for printing colored text to the console. It supports both Windows and Unix-like systems.

## How to use

Include the `printfcolor.h` header file in your C project:

```c
#include "printfcolor.h"
```

## Example code

```c
#include "printfcolor.h"

int main()
{
    printfColorFg(BLUE, "Blue text\n");
    printfColorFg(MAGENTA, "Magenta text\n\n");

    printfColorBg(GREEN, "Green background\n");
    printfColorBg(RED, "Red background\n\n");

    printfColor(WHITE, BLUE, "White on blue\n");
    printfColor(MAGENTA, CYAN, "Magenta on cyan\n");
}
```

Output:

![Example output](https://github.com/JosefVesely/printfcolor/blob/main/example.png)

## Compatibility

- **Windows:** Uses Windows Console API.
- **Unix-like Systems:** Uses ANSI escape codes.

## Error Handling

- **Invalid Color Code:** Prints an error message and returns `-1`.
- **Console Info Retrieval Failure:** Prints an error message and returns `-1`.

## License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/JosefVesely/printfcolor/blob/main/LICENSE) file for details