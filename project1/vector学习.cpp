#include <stdio.h>
#include <vector>
#include <iostream>
#define N 10
using namespace std;
void print(const vector<int>&v1){
	for(auto it=v1.begin();it!=v1.end();it++){
		printf("%d ",*it);
	}
	printf("\n");
}
int main(){
	vector<int>v;
	int a,i;
	for(i=0;i<N;i++){
		scanf("%d",&a);
		v.push_back(a);
	}
	print(v);
	v.pop_back();
	print(v);
	v.erase(v.begin()+1,v.begin()+3);
	print(v);
	v.clear();
	printf("%d\n",v.capacity());
	printf("%d",v.size());
	v.push_back(1);
	vector<int>(v).swap(v);
	cout<<v.capacity()<<endl;
	cout<<v.size();
	return 0;
}
