#include <stdio.h>
#include <stdlib.h>
typedef struct vector{
	int *a;
	int size;
}array;
array create(int n){
	array p;
	p.size=n;
	p.a=malloc(sizeof(int)*p.size);
	return p;
}
void inflate(array *p,int more){
	int *b=malloc((p->size+more)*sizeof(int));
	int i;
	for(i=0;i<p->size;i++){
		b[i]=p->a[i];
	}
	free(p->a);
	p->a=b;
	p->size+=more;
}
int *arrayat(array *p,int index){
	if(index>=p->size){
		inflate(p,2*index+100);
	}
	return &(p->a[index]);
}
void clear(array *p){
	free(p->a);
	p->size=0;
	p->a=NULL;
}
int main(){
	array p=create(20);
	int *b=arrayat(&p,3);
	*b=5;
	printf("%d",p.a[3]);
	return 0;
}
