#include <stdio.h>

int main() {
    FILE *fp;

    // 打开文件
    fp = fopen("test.txt", "w");
    if(fp==NULL){
    	printf("Failed");
    	return 0;
	}
    // 写入数据
    fprintf(fp, "Hello, world!\n");
    fputs("This is a test.\n", fp);

    // 关闭文件
    fclose(fp);

    // 重新打开文件，读取数据
    char buffer[1024];
    fp = fopen("example.txt", "r");

    // 读取数据
    int c;
    while ((c = fgetc(fp)) != EOF) {
        fputc(c, stdout);
    }

    // 关闭文件
    fclose(fp);

    return 0;
}
