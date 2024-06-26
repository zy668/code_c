#include <stdio.h>
#include <string.h>
#include <ctype.h>
char b[1002];
void t(char *a,char *c,char *d,int e){
        char *p=strstr(a,c);
        while(p!=NULL){
        	if(!isalnum(*(p-1))&&!isalnum(*(p+e))){
            strcpy(b,p+e);
            *p='\0';
            strcat(a,d);
            p=strstr(a,c);
            strcat(a,b);
        }
        else{
        	strcpy(b,p);
        	*p='0';
        	p=strstr(a,c);
        	*p=c[0];
        	strcat(a,b);
		}
    }
}
int main(){
    int n,i,j,k,ch,c;
    char a[1002]=" ";
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++){
        j=1;
        while((ch=getchar())!='\n'){
            putchar(ch);
            if(ch!='I'){
                ch=tolower(ch);
            }
            if(ch=='?'){
                ch='!';
            }
            if(ch==' '&&k==1){
                k=0;
                a[j]=ch;
                j++;
            }
            if(ch!=' '){
                a[j]=ch;
                k=1;
                j++;
            }
        }
        a[j]='\0';
        printf("\n");
        t(a,"I","you",1);
        t(a,"me","you",2);
        t(a,"can you","I can",7);
        t(a,"could you","I could",9);
        printf("AI:%s",a);
    }
    return 0;
}
