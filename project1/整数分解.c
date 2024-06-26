#include <stdio.h>
void change(int *a){
	int i;
    for(i=0;i<31;i++){
        if(a[i]==0){
            i--;
            if(i==0){
            	break;
            }
            else{
              if(a[i-1]+1==a[i]||a[i-1]==a[i]){
                    a[i-1]+=a[i];
                    a[i]=0;
                }
              else if(a[i]-a[i-1]>=a[i-1]+3){
                    a[i-1]++;
                    a[i+1]=a[i]-a[i-1]-1;
                    a[i]-=a[i+1]+1;
                }
                else{
                    a[i-1]++;
                    a[i]--;
                }
        }
    }
}
}
int main(){
	int a[100];
	return 0;
}
