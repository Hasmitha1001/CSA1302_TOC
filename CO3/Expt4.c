#include <stdio.h>
#include <string.h>

// CFG: S -> 0S1 | e
// Language: 0^n 1^n, where n>=0
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

    if (!valid || len % 2 != 0) {
        printf("String is not accepted\n");
        return 0;
    }

    int accepted = 1;
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != '0') {
            accepted = 0;
            break;
        }
    }
    for (int i = len / 2; i < len; i++) {
        if (str[i] != '1') {
            accepted = 0;
            break;
        }
    }

    if (accepted) {
        printf("String is accepted\n");
    } else {
        printf("String is not accepted\n");
    }

    return 0;
}
