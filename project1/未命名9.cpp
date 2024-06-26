#include <stdio.h>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
void print(vector<int>&v){
	for(vector<int>::iterator it=v.begin();it!=v.end();it++){
		printf("%d",*it);
	}
}
int main(){
	vector<int>v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(7);
	v.push_back(9);
	v.push_back(5);
	sort(v.begin(),v.end(),greater<int>());
	print(v);
	return 0;
}

