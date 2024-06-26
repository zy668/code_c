#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#include <conio.h>
#include <queue>
#include <thread>
#include <string.h>
#define PIC_SIZE 40
using namespace std;
IMAGE img[20];
int map[26][32];
int click[26][32]={0};
int flag=0;
int ROW;
int COL;
int count=0;
int MINE_NUM=0;
int isok=IDOK;
int Begin=0;
int difficulty=0;
time_t start_time, end_time;
char pass[40];
typedef struct position{
	int x;
	int y;
}pos;
int Rank(void){
	FILE* fp;
	char s[80];
	sprintf(s,"rank%d.txt",difficulty);
		fp=fopen(s,"r");
		if(fp==NULL){
			fp=fopen(s,"w");
			fprintf(fp,"%s",pass);
			fclose(fp);
			return 1;
		}
		else{
			char temp[80]="";
			fscanf(fp,"%s",temp);
			if(strcmp(temp,pass)>0){
				fp=fopen(s,"w");
				fprintf(fp,"%s",pass);
				fclose(fp);
				return 1;
			}
			fclose(fp);
			return 0;
		}
}
void timer(void){
	time(&end_time);
	double diff=difftime(end_time,start_time);
    int hours=(int)diff/3600;
    int minutes=((int)diff%3600)/60;
    int seconds=((int)diff%3600)%60;
    setbkcolor(RGB(189,189,189));
    sprintf(pass,"%02d:%02d:%02d",hours,minutes,seconds);
    settextcolor(BLUE);
    settextstyle(26,13,"Consolas");
    outtextxy(PIC_SIZE+5,ROW*PIC_SIZE+PIC_SIZE/5,pass);
    Sleep(10);
}
void drawMineCount(void){
	char buffer[41];
	settextstyle(30,15,"Consolas");
    fillrectangle(COL*PIC_SIZE-2.5*PIC_SIZE-11,ROW*PIC_SIZE+4,COL*PIC_SIZE-PIC_SIZE-1,ROW*PIC_SIZE+PIC_SIZE*0.9);
    sprintf(buffer,"%d",MINE_NUM-flag);
    settextcolor(YELLOW);
    settextstyle(30,15,"Consolas");
    outtextxy(COL*PIC_SIZE-2.5*PIC_SIZE-10,ROW*PIC_SIZE+PIC_SIZE/8,buffer);
}
void playmusic(const char music[]){	
	char str[50]="";
	sprintf(str,"close %s",music);
	mciSendString(str,0,0,0);
	sprintf(str,"open %s", music);
	mciSendString(str,0,0,0);
	sprintf(str,"play %s", music);
	mciSendString(str,0,0,0);
}
void refresh(void){
	int i,j;
	for(i=0;i<26;i++){
		for(j=0;j<32;j++){
			map[i][j]=0;
			click[i][j]=0;
		}
	}
	count=0;
	flag=0;
	Begin=0;
	end_time=start_time;
	drawMineCount();
}
void load(void){
	int i;
	char temp[20];
	for(i=0;i<20;i++){
		sprintf(temp,"./%d.jpg",i);
		loadimage(&img[i],temp,PIC_SIZE,PIC_SIZE);
	}
}
void draw(void){
	int i,j;
	for(i=1;i<=ROW;i++){
		for(j=1;j<=COL;j++){
			putimage((j-1)*PIC_SIZE,(i-1)*PIC_SIZE,&img[10]);
		}
	}
	putimage(0.5*(COL-1)*PIC_SIZE,ROW*PIC_SIZE,&img[15]);
	setlinecolor(RGB(153,170,199));
	setfillcolor(RGB(189,189,189));
	fillrectangle(PIC_SIZE+1,ROW*PIC_SIZE+4,PIC_SIZE+115,ROW*PIC_SIZE+PIC_SIZE*0.9);
	putimage(0,ROW*PIC_SIZE,&img[13]);
	putimage(COL*PIC_SIZE-PIC_SIZE,ROW*PIC_SIZE,&img[14]);
	settextcolor(BLUE);
	setbkcolor(RGB(189,189,189));
    settextstyle(26,13,"Consolas");
    outtextxy(PIC_SIZE+5,ROW*PIC_SIZE+PIC_SIZE/5,"00:00:00");
}
void end(void){
	timer();
	playmusic("bomb.wav");
	int i,j;
	for(i=1;i<=ROW;i++){
		for(j=1;j<=COL;j++){
				if(map[i][j]<0){
				putimage((j-1)*PIC_SIZE,(i-1)*PIC_SIZE,&img[9]);
			}
	}
}
      putimage(0.5*(COL-1)*PIC_SIZE,ROW*PIC_SIZE,&img[16]);
}
void open(int x,int y){
	if(x<1||x>ROW||y<1||y>COL||click[x][y]!=0) return;
	int i;
	int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
	queue<pos>q;
	pos p={x,y};
	q.push(p);
	click[p.x][p.y]=1;
	while(!q.empty()){
		p=q.front();
		q.pop();
		count++;
		if(map[p.x][p.y]==0){
		putimage((p.y-1)*PIC_SIZE,(p.x-1)*PIC_SIZE,&img[0]);
		for(i=0;i<8;i++){
			pos temp={p.x+dir[i][0],p.y+dir[i][1]};
			if(temp.x<1||temp.x>ROW||temp.y<1||temp.y>COL||click[temp.x][temp.y]!=0){
				continue;
			}
			q.push(temp);
			click[temp.x][temp.y]=1;
		}
	}
		else if(map[p.x][p.y]>0){
			putimage((p.y-1)*PIC_SIZE,(p.x-1)*PIC_SIZE,&img[map[p.x][p.y]]);
		}
	}
}
void CreateMine(int x,int y){
	int i,j,k,a,b;
	for(k=0;k<MINE_NUM;){
		i=rand()%ROW+1;
		j=rand()%COL+1;
		if(abs(i-y)<=1&&abs(j-x)<=1){
			continue;
		}
		if(map[i][j]>=0){
		map[i][j]=-10;
		for(a=i-1;a<=i+1;a++){
			for(b=j-1;b<=j+1;b++){
				map[a][b]++;
			}
		}
		k++;
	}
	}
}
int lclick(int r,int c){
	if(click[r][c]<0||r==ROW+1) return 0;
	if(count==0){
    	time(&start_time);
      	end_time=start_time;
        putimage((c-1)*PIC_SIZE,(r-1)*PIC_SIZE,&img[0]);
        CreateMine(c,r);
        open(r,c);
        return 0;
	}
      if(map[r][c]<0){
        end();
        return 1;
      }
      else{
        open(r,c);
      }
      return 0;
}
void rclick(int r,int c){
		if(r==ROW+1) return;
		if(click[r][c]==1) return;
		if(click[r][c]==0){
			click[r][c]=-1;
			putimage((c-1)*PIC_SIZE,(r-1)*PIC_SIZE,&img[11]);
			flag++;
		}
		else if(click[r][c]==-1){
			click[r][c]=-2;
			putimage((c-1)*PIC_SIZE,(r-1)*PIC_SIZE,&img[12]);
			flag--;
		}
        else if(click[r][c]==-2){
          putimage((c-1)*PIC_SIZE,(r-1)*PIC_SIZE,&img[10]);
          click[r][c]=0;
		}
	drawMineCount();
}
int dbclick(int r,int c){
	if(click[r][c]!=1) return 0;
      int i,j,k=0,t=0;
      for(i=r-1;i<=r+1;i++){
        for(j=c-1;j<=c+1;j++){
          if(click[i][j]==-1){
            k++;
          }
          if(click[i][j]==0&&map[i][j]<0){
          	t=1;
		  }
        }
      }
      if(k==map[r][c]&&k>0){
      	if(t==1){
            return 1;
		}
        for(i=r-1;i<=r+1&&i<=ROW;i++){
          for(j=c-1;j<=c+1;j++){
          	if(i<1||i>ROW||j<1||j>COL){
      				continue;
				}
            if(click[i][j]==0){
				open(i,j);
            }
          }
        }
      }
	return 0;
}
int mouse(void){ 
  if(MouseHit()){
    MOUSEMSG msg = GetMouseMsg();
    int r=msg.y/PIC_SIZE+1;
    int c=msg.x/PIC_SIZE+1;
    if(r==ROW+1&&((COL-1)*PIC_SIZE/2<msg.x&&msg.x<(COL+1)*PIC_SIZE/2)&&(msg.uMsg==WM_LBUTTONDOWN||msg.uMsg==WM_RBUTTONDOWN)){
      	if(msg.uMsg==WM_LBUTTONDOWN){
      		Begin=1;
		  }
		  else if(msg.uMsg==WM_RBUTTONDOWN){
		  	Begin=2;
		  }
		  return 0;
	  }
	if(r==ROW+1) return 0;
    if(GetAsyncKeyState(VK_LBUTTON)&0x8000&&GetAsyncKeyState(VK_RBUTTON)&0x8000){
		return dbclick(r,c);
    }
    else if(msg.uMsg==WM_LBUTTONDOWN){
		return lclick(r,c);
    }
    else if(msg.uMsg==WM_RBUTTONDOWN){
      rclick(r,c);
        Sleep(50);
    }
  }
  return 0;
}
void game(void){
  while(count==0){
  	mouse();
  	if(Begin!=0) break;
    Sleep(10);
  }
  while(1){
  	if(Begin!=0) break;
  	timer();
    if(mouse()){
      end();
      isok=MessageBox(GetHWnd(),"Bad luck,You lose!\nDo you want to play again?","notice",MB_OKCANCEL);
      playmusic("lose.mp3");
      break;
    }
    else if(count==ROW*COL-MINE_NUM){
      playmusic("win.wav");
      char buffer[100];
    	char temp[80];
    	FILE* fp;
		char s[80];
		sprintf(s,"rank%d.txt",difficulty);
		fp=fopen(s,"r");
		fscanf(fp,"%s",temp);
      if(Rank()){
      	fp=fopen(s,"r");
		fscanf(fp,"%s",temp);
		sprintf(buffer,"New Record!\nBest time:%s\ntotal time: %s\nDo you want to play again?",temp,pass);
	  }
      else{
	  sprintf(buffer,"You win!\nBest time:%s\ntotal time: %s\nDo you want to play again?",temp,pass);
}
	fclose(fp);
      isok=MessageBox(GetHWnd(),buffer,"notice",MB_OKCANCEL);
      break;
    }
  }
}
void select(void){
	initgraph(500, 530);
	HWND hwnd = GetHWnd();
	MoveWindow(hwnd, 350, 180,500,540,TRUE);
	setbkcolor(RGB(100,160,150));
	cleardevice();
	settextcolor(BLACK);
	rectangle(40, 0, 350, 100);
	outtextxy(100, 50, "请选择难度：");
	rectangle(40, 100, 350, 200);
	outtextxy(100, 150, "初级9*9，雷数10");
	rectangle(40, 200, 350, 300);
	outtextxy(100, 250, "中级16*16，雷数40");
	rectangle(40, 300, 350, 400);
	outtextxy(100, 350, "高级16*30，雷数99");
	rectangle(40, 400, 350, 520);
	outtextxy(130, 420, "自定义");
	outtextxy(50, 455, "雷区大小不能超过24x30，最小为9x9");
	outtextxy(50, 485, "雷数最少10个，最多不能超过雷区的90%");
	Sleep(10);
	while(1){
	if(MouseHit()){
		MOUSEMSG msg=GetMouseMsg();
		if(msg.uMsg==WM_LBUTTONDOWN){
		if(msg.x>40&&msg.x<350){
		if(msg.y<100) continue;
		else if(100<msg.y&&msg.y<200){
			difficulty=1;
			ROW=9;
			COL=9;
			MINE_NUM=10;
			break;
		}
		else if(200<msg.y&&msg.y<300){
			difficulty=2;
			ROW=16;
			COL=16;
			MINE_NUM=40;
			break;
		}
		else if(300<msg.y&&msg.y<400){
			difficulty=3;
			ROW=16;
			COL=30;
			MINE_NUM=99;
			break;
		}
		else if(400<msg.y&&msg.y<530){
			difficulty=4;
			char s[20];
			bool t=InputBox(s,20,"请输入行数和列数和雷数，用空格分开","自定义",NULL,0,0,0);
			if(t) sscanf(s,"%d %d %d",&ROW,&COL,&MINE_NUM);
			while(t&&(ROW>24||COL>30||10*MINE_NUM>=ROW*COL*9||ROW<=0||COL<=0||MINE_NUM<10)){
				t=InputBox(s,20,"invalid,请重新输入行数和列数和雷数，用空格分开","自定义",NULL,0,0,0);
				sscanf(s,"%d %d %d",&ROW,&COL,&MINE_NUM);
			}
			if(t) break;
		}
	}
}
}
}
closegraph();
}
void start(void){
	select();
	load();
	initgraph(PIC_SIZE*COL,PIC_SIZE*(ROW+1),0);
	setbkcolor(RGB(160,180,205));
	cleardevice();
	draw();
	drawMineCount();
	refresh();
	game();
	while(isok==IDOK&&Begin!=2){
		draw();
		GetMouseMsg();
		GetAsyncKeyState(VK_LBUTTON);
		GetAsyncKeyState(VK_RBUTTON);
		refresh();
		Sleep(50);
		game();
	}
	if((Begin!=0&&isok!=IDOK)||Begin==2){
	closegraph();
}
}
int main(){
	srand(time(NULL));
	start();
	while(Begin!=0){
		if(Begin==1){
			refresh();
			draw();
			game();
		}
		else if(Begin==2){
			start();
		}
	}
	return 0;
}
