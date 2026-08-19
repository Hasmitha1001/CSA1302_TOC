#include <stdio.h>
#include <string.h>

// CFG: S -> 0S0 | A, A -> 1A | e
// Language: 0^n 1^m 0^n, where n>=0, m>=0
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

    if (!valid) {
        printf("String is not accepted\n");
        return 0;
    }

    int i = 0;
    while (i < len && str[i] == '0') i++;
    
    int j = len - 1;
    while (j >= 0 && str[j] == '0') j--;

    if (i > j) { // No 1s present, only 0s
        if (len % 2 == 0) {
            printf("String is accepted\n");
        } else {
            printf("String is not accepted\n");
        }
    } else {
        int left_zeros = i;
        int right_zeros = len - 1 - j;
        if (left_zeros == right_zeros) {
            int accepted = 1;
            for (int k = i; k <= j; k++) {
                if (str[k] != '1') {
                    accepted = 0;
                    break;
                }
            }
            if (accepted) {
                printf("String is accepted\n");
            } else {
                printf("String is not accepted\n");
            }
        } else {
            printf("String is not accepted\n");
        }
    }

    return 0;
}
