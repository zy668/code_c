#include <iostream>
using namespace std;
template <typename T>
void myswap(T &a,T &b){
	T temp=a;
	a=b;
	b=temp;
}
int main(){
	int a=10;
	int b=20;
	myswap<int>(a,b);
	printf("%d %d",a,b);
	return 0;
}
