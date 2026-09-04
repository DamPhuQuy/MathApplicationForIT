#include <stdio.h>
#include <stdlib.h>

int main() {
    char *s = malloc(0); // Allocate memory for the string
    if (s == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit with error code
    }; // Allocate memory for the string

    printf("Nhap S: ");

    // Read input until newline character is encountered
    scanf("%[^\n]", s);

    printf("S: %s", s);

    return 0;
}
