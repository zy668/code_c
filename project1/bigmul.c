#include <stdio.h>
#include <string.h>

int main() {
    char a[2001], b[2001], c[4002];
    //printf("Enter two large numbers (including negatives):\n");
    scanf("%s %s", a, b);

    // Determine and handle the sign of the numbers
    int sign = 1;
    int startA = 0, startB = 0;
    if (a[0] == '-') {
        sign *= -1;
        startA = 1;
    }
    if (b[0] == '-') {
        sign *= -1;
        startB = 1;
    }

    int lena = strlen(a), lenb = strlen(b);
    memset(c, '0', sizeof(c));
    c[lena + lenb - 1] = '\0';

    // Core multiplication logic
    for (int i = lena - 1; i >= startA; i--) {
        int carry = 0;
        for (int j = lenb - 1; j >= startB; j--) {
            int product = (a[i] - '0') * (b[j] - '0') + (c[i + j + 1 - startA - startB] - '0') + carry;
            c[i + j + 1 - startA - startB] = product % 10 + '0';
            carry = product / 10;
        }
        c[i - startA + lenb - startB] += carry;
    }

    // Find the start of the result (ignoring leading zeros)
    int start = 0;
    while (c[start] == '0' && c[start + 1] != '\0') {
        start++;
    }

    // Output the result
    if (sign < 0 && c[start] != '0') {
        putchar('-');
    }
    printf("%s\n", c + start);

    return 0;
}