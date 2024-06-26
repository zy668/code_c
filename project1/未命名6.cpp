#include <stdio.h>
using namespace std;
class person{
	public:
		int score;
		static int age;
};
int person::age=2;
void test01(){
	person p1;
	person p2;
	p1.age=5;
	printf("%d\n",p1.age);
	p2.age=6;
	printf("%d\n",p1.age);
	printf("%d\n",p2.age);
}
int main(){
	test01();
	printf("%d",person::age);
	return 0;
}
