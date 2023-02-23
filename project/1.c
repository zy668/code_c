#include<stdio.h>
int main(){
    int n,m,p;
    scanf("%d %d %d",&n,&m,&p);
    int a[1000001]={0};
    int i,k,j;
    while(n--){
        scanf("%d",&k);
        while(k--){
            scanf("%d",&j);
            a[j]++;
        }
    }
    for(i=1,j=0;i<=m;i++){
        if(a[i]==p){
            j++;
        }
    }
    printf("%d\n",j);
    for(i=1,k=1;i<=m;i++,k++){
        if(a[i]==p&&k!=j){
            printf("%d ",i);
        }
        else{
            printf("%d",i);
        }
    }
    return 0;
}