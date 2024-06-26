#include <stdio.h>
long long qpow(int a,int n){
	if(n==0){
		return 1;
	}
	else if(n%2==1){
		return a*qpow(a,n-1);
	}
	else{
		return qpow(a,n/2)*qpow(a,n/2);
	}
}
int main(){
	printf("%lld",qpow(3,11));
	return 0;
} 
