#include<stdio.h>
#include <string.h>
int mystrstr(char *a,char *b){
    int i=0,j=0,k;
    int lenA=strlen(a);
    int lenB=strlen(b);
    for(i=0;i<=lenA-lenB;i++){
        k=1;
        for(j=0;j<lenB;j++){
            if(a[j+i]!=b[j]){
                k=0;
                break;
            }
        }
        if(k==1){
            return i;
        }
    }
    return -1;
}
int main(){
    char a[20]="ababcabcacbab";
    char b[20]="abcac";
    int c=mystrstr(a,b);
    printf("%d",c);
    return 0;
}
