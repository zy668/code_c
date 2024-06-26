#include <stdio.h>
#include <set>
using namespace std;
int main(){
	set<int>s;
	int n,i,a;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		s.insert(a);
	}
	for(set<int>::iterator it=s.begin();it!=s.end();it++){
		printf("%d",*it);
	}
	return 0;
}
