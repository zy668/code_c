#include <stdio.h>
class person{
	public:
		void fun(){
			printf("1");
		}
		void fun1(){
			printf("%d",age);
		}
		int age;
};
int main(){
	person *p=NULL;
	p->fun();
	return 0;
}
