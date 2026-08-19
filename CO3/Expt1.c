#include <stdio.h>
#include <string.h>

// CFG: S -> 0A1, A -> 0A | 1A | e
// Language: Strings over {0, 1} starting with '0' and ending with '1'. Length >= 2.
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

    if (valid && len >= 2 && str[0] == '0' && str[len - 1] == '1') {
        printf("String is accepted\n");
    } else {
        printf("String is not accepted\n");
    }

    return 0;
}
