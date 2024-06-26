#include <stdio.h>
#ifndef n
#undef n
#else
#define n 20
#endif
int main(){
	printf("%d",n);
	return 0;
}
