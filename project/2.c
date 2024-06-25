#include <stdio.h>
#include <string.h>

void print(char *mode, void a[], int num) {
    int n = sizeof(a[0]) * num;
    int i;
    if (n == sizeof(int)) {
        int *p = a;
        printf("%p %p", &p[1], &p[2]);
    }
}

int main() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7};
    print("%d",a, 10);
    return 0;
}
