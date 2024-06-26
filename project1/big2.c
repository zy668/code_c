#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 函数来反转一个字符串
void reverse(char str[], int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// 大数乘法函数
char* multiply(char num1[], char num2[]) {
    int length1 = strlen(num1);
    int length2 = strlen(num2);
    int n1Sign = (num1[0] == '-') ? -1 : 1;
    int n2Sign = (num2[0] == '-') ? -1 : 1;

    // 移除负号
    if (n1Sign == -1) {
        memmove(num1, num1 + 1, length1);
        length1--;
    }
    if (n2Sign == -1) {
        memmove(num2, num2 + 1, length2);
        length2--;
    }

    char *result = (char *)malloc((length1 + length2 + 2) * sizeof(char));
    memset(result, 0, (length1 + length2 + 2) * sizeof(char));

    // 反转两个数字
    reverse(num1, length1);
    reverse(num2, length2);

    for (int i = 0; i < length1; i++) {
        for (int j = 0; j < length2; j++) {
            result[i + j] += (num1[i] - '0') * (num2[j] - '0');
            if (result[i + j] >= 10) {
                result[i + j + 1] += result[i + j] / 10;
                result[i + j] %= 10;
            }
            result[i + j] += '0'; // 转换回字符
        }
    }

    // 添加负号（如果需要）
    int resultLength = strlen(result);
    if (n1Sign * n2Sign == -1) {
        memmove(result + 1, result, resultLength + 1);
        result[0] = '-';
        resultLength++;
    }

    // 去掉前导零
    while (resultLength > 1 && result[resultLength - 1] == '0') {
        resultLength--;
    }
    result[resultLength] = '\0';

    // 反转结果
    reverse(result, resultLength);

    return result;
}

int main() {
    char num1[1024];
    char num2[1024];

    // 读取两个大数
   // printf("Enter first number: ");
    scanf("%s", num1);
   // printf("Enter second number: ");
    scanf("%s", num2);

    // 计算乘积
    char *product = multiply(num1, num2);
    printf("%s", product);

    // 释放内存
    free(product);

    return 0;
}