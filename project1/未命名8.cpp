#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class person{
	public:
		person(string name,int age){
			this->name=name;
			this->age=age;
		}
		bool operator==(const person &p){
			return this->age==p.age;
		}
	string name;
	int age;
};
int main(){
	vector<person>w;
	person p1("tom",35);
	person p2("jack",12);
	person p3("li",18);
	person p4("mike",23);
	person p("niu",12);
	w.push_back(p1);
	w.push_back(p2);
	w.push_back(p3);
	w.push_back(p4);
w.push_back(p);
	int num=count(w.begin(),w.end(),p);
	cout<<num;
	return 0;
}
