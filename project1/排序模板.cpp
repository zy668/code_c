#include <stdio.h>
using namespace std;
template<typename T>
void bubblesort(T *a,int n){
	int i,j;
	for(i=0;i<n-1;i++){
		int k=0;
		for(j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				T temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				k=1;
			}
		}
		if(!k) break;
	}
}
template<typename T>
void quicksort(T *a,int l,int r){
	if(l>=r) return;
	int i=l,j=r;
	T k=a[(l+r)/2];
	while(i<=j){
		while(a[i]<k) i++;
		while(a[j]>k) j--;
		if(i<=j){
			T temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
			j--;
		}
	}
	quicksort<T>(a,l,j);
	quicksort<T>(a,i,r);
}
template<typename T>
void selectsort(T *a,int n){
	int i,j,k;
	for(i=0;i<n-1;i++){
		k=i;
		for(j=i+1;j<n;j++){
			if(a[j]<a[k]){
				k=j;
			}
		}
		T temp=a[i];
		a[i]=a[k];
		a[k]=temp;
	}
}
int main(){
	char a[6]={'a','o','i','u','e'};
	quicksort(a,0,4);
	for(int i=0;i<5;i++){
		putchar(a[i]);
	}
	return 0;
}
