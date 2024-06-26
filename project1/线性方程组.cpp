#include <iostream>
using namespace std;
int main(){
	int n,i,j,k,c;//i,j是控制行，列的变量 ，k也是用于控制行，c是用于主对角线以下全为0的判断。 
	double p,t;
	cin>>n;//n为未知数个数。 
	double a[n][n+1];//矩阵 
	double b[n];//用来储存解 
	for(i=0;i<n;i++){
		for(j=0;j<n+1;j++){
			cin>>a[i][j];
		}
	}//输入矩阵 
	for(i=0;i<n-1;i++){
	if(a[i][i]==0){//如果主对角线上的这个数为0 
		c=1;
		for(k=i+1;k<n;k++){
			if(a[k][i]!=0){//它下面有不为0的数 
				c=0;
				for(j=0;j<n+1;j++){
					t=a[k][j];
					a[k][j]=a[i][j];
					a[i][j]=t;
				}//用于交换这两行
				break;
			}
		}
		if(c){
			continue;//如果全为0，这一列不用相减，直接看下一列 。 
		}
	}
		for(k=i+1;k<n;k++){
			p=a[k][i]/a[i][i];//p是要乘的倍数。 
			for(j=i;j<n+1;j++){
				a[k][j]-=p*a[i][j];
			}
		}//主对角线下的每一列减主对角线的该列 
}
for(i=n-1;i>=0;i--){
	c=0;t=0;//重复利用变量，来判断 
	for(j=n-1;j>=0;j--){
		if(a[i][j]!=0){
			c=1;
		}
	}
	if(c){
		if(a[i][n]==0){
			cout<<"无穷解"<<endl; 
			break;
		}
		else{
			t=1;//有唯一解 
			break; 
		}
	}
	else{
		if(a[i][n]==0){
			continue;
		}
		else{
			cout<<"无解"<<endl;
			break;
		}
	}
}
if(t){
	for(i=n-1;i>=0;i--){
		for(j=n-1;j>i;j--){
			a[i][n]-=a[i][j]*b[j];//a[i][j]相当于系数。 
		}
		b[j]=a[i][n]/a[i][j];
	}//求解的过程 ，a[i][n]为等号右边的值 
for(j=0;j<n;j++){
	cout<<"x"<<j<<"="<<b[j]<<endl;
}
}
	return 0;
}
