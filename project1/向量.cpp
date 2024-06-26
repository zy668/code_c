#include <stdio.h>
using namespace std;
struct vec{
	int x;
	int y;
};
vec operator%(vec &a,vec &b){
	vec c={a.x*b.x,a.y*b.y};
	return c;
}
int operator*(vec &a,vec &b){
	return a.x*b.x+a.y*b.y;
}
int main(){
	vec a={1,2};
	vec b={3,1};
	printf("%d\n",a*b);
	vec c=a%b;
	printf("%d %d",c.x,c.y);
	return 0;
}
