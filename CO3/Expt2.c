#include <stdio.h>
#include <string.h>

// CFG: S -> 0S0 | 1S1 | 0 | 1 | e
// Language: Palindromes over {0, 1}
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
        int is_palindrome = 1;
        for (int i = 0; i < len / 2; i++) {
            if (str[i] != str[len - 1 - i]) {
                is_palindrome = 0;
                break;
            }
        }
        if (is_palindrome) {
            printf("String is accepted\n");
        } else {
            printf("String is not accepted\n");
        }
    } else {
        printf("String is not accepted\n");
    }

    return 0;
}
