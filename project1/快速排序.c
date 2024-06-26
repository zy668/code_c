#include<stdio.h>
void quickSort(int *number, int first, int last) {
    int i, j, pivot;
    int temp;
    if (first<last) {
        pivot = first;
        i = first;
        j = last;
        while (i<j) {
            while (number[i] <= number[pivot] && i<last)
                i++;
            while (number[j]>number[pivot])
                j--;
            if (i<j) {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        quickSort(number, first, j - 1);
        quickSort(number, j + 1, last);
    }
}
int main(){
	int a[10]={1,2,3,6,5,4,8,9,7,0};
	quickSort(a,0,9);
	int i;
	for(i=0;i<10;i++){
		printf(" %d"+!i,a[i]);
	}
	return 0;
}
