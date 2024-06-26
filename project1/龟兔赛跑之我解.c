#include <stdio.h>
int main(){
    int a,b,c;
    scanf("%d",&a);
    b=a%90;
    c=a/90;
    if(b%30==0){printf("-_- %d",3*a);}
    if(60<b&&b<90){printf("@_@ %d",3*a);}
    if(30<a&&a<45){printf("@_@ %d,3*a");}
    if(b==45){printf("-_- %d",3*a);}
    if(10<=b&&b<30){printf("^_^ %d",270*c+90);}
    if(50<b&&b<60){printf("^_^ %d",270*c+180);}
    if(45<b&&b<=50){printf("^_^ %d",270*c+90+(b-40)*9);}
    if(0<b&&b<10){printf("^_^ %d",270*c+b*9);}
 return 0;
}
