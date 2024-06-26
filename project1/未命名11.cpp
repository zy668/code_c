#include <stdio.h>
using namespace std;
class person{
	public:
		void func1()
		{
		a=100;
			//int b=200;
		}
	mutable int a;
};
int main(){
	person p;
	p.func1();
	printf("%d",p.a);
	return 0;
}
