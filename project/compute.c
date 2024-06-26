#include <stdio.h>

typedef union {
    float input;   // assumes sizeof(float) == sizeof(int)
    int   output;
} float_bits;

void print_binary(int n, int i)
{
    // stop condition
    if (i == 0) {
        return;
    }

    // recursive call
    print_binary(n / 2, i - 1);

    // print the remainder
    printf("%d", n % 2);
}

int main()
{
    float a = 27.0 / 64;
    float_bits t;
    t.input = a;

    // print sign
    printf("Sign : ");
    print_binary((t.output >> 31) & 1, 1);
    printf("\n");

    // print exponent
    printf("Exponent : ");
    print_binary((t.output >> 23) & 0xFF, 8);
    printf("\n");

    // print mantissa
    printf("Mantissa : ");
    print_binary(t.output & 0x7FFFFF, 23);
    printf("\n");

    return 0;
}