#include <stdio.h>
int qpow(int a, int n){
    int ans = 1;
    while(n){
        if(n&1)
            ans *= a;  
        a *= a;        
        n >>= 1;       
    }
    return ans;
}
int main(){
	printf("%d",qpow(2,10));
	return 0;
}
