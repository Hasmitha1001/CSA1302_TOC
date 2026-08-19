#include <stdio.h>
#include <string.h>

// CFG: S -> A101A, A -> 0A | 1A | e
// Language: Strings containing "101" as a substring
int main() {
    char str[100];
    printf("Enter a string: ");
    if (scanf("%s", str) != 1) return 0;

    int len = strlen(str);
    int valid = 1;
    for (int i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1') {
            valid = 0;
            break;
        }
    }

    if (valid) {
        if (strstr(str, "101") != NULL) {
            printf("String is accepted\n");
        } else {
            printf("String is not accepted\n");
        }
    } else {
        printf("String is not accepted\n");
    }

    return 0;
}
