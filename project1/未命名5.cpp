#include <stdio.h>
#include <time.h>
#include <graphics.h>
#include <conio.h>
#include <thread>
time_t start_time, end_time;
using namespace std;
void timer(void){
	while(1){
	time(&end_time);
    double diff=difftime(end_time,start_time);
    int hours=(int)diff/3600;
    int minutes=((int)diff%3600)/60;
    int seconds=((int)diff%3600)%60;
    printf("%02d:%02d:%02d\n",hours,minutes,seconds);
    Sleep(100);
}
}
int main(){
	int i=10;
	time(&start_time);
	thread t(timer);
	while(1){
		printf("good\n");
		Sleep(100);
	}
	t.join();
	return 0;
}
