#include <stdio.h>
#include <time.h>
#include <graphics.h>
#include <conio.h>
#include <thread>
using namespace std;
void print(void){
	while(1){
		printf("1\n");
		Sleep(1000);
	}
}
int main(){
	thread t(print);
	while(1){
		printf("2\n");
		Sleep(1000);
	}
	t.join();
	return 0;
}
