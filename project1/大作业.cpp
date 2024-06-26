#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#include <conio.h>
#include <queue>
#define PIC_SIZE 40
using namespace std;
IMAGE img[13];
int map[26][32];
int click[26][32]={0};
int flag=0;
int ROW;
int COL;
int count=0;
int MINE_NUM=0;
int isok;
time_t start_time, end_time;
typedef struct position{
	int x;
	int y;
}pos;
void timer(void){
	time(&end_time);
	double diff=difftime(end_time, start_time);
    int hours=(int)diff/3600;
    int minutes=((int)diff%3600)/60;
    int seconds=((int)diff%3600)%60;
    char buffer[80];
    setbkcolor(RGB(189,189,189));
    sprintf(buffer,"%02d:%02d:%02d",hours,minutes,seconds);
    settextcolor(BLUE);
    settextstyle(20,10, "Consolas");
    outtextxy(PIC_SIZE,ROW*PIC_SIZE+5,buffer);
}
void drawMineCount(void){
	char buffer[41];
	settextstyle(50,25,"Consolas");
	outtextxy(COL*PIC_SIZE-2*PIC_SIZE,ROW*PIC_SIZE+5,"                                 ");
	setbkcolor(RGB(189,189,189));
    sprintf(buffer,"%d",MINE_NUM-flag);
    settextcolor(YELLOW);
    settextstyle(30,15,"Consolas");
    outtextxy(COL*PIC_SIZE-1.5*PIC_SIZE,ROW*PIC_SIZE+5,buffer);
}
void playmusic(const char music[]){	
	char str[50]="";
	sprintf(str,"close %s",music);
	mciSendString(str,0,0,0);
	sprintf(str, "open %s", music);
	mciSendString(str,0,0,0);
	sprintf(str, "play %s", music);
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
	drawMineCount();
}
void load(void){
	int i;
	char temp[20];
	for(i=0;i<13;i++){
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
	settextcolor(BLUE);
    settextstyle(20,10, "Consolas");
    outtextxy(PIC_SIZE,ROW*PIC_SIZE+5,"00:00:00");
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
}
void open(int x,int y){
	if(x<1||x>ROW||y<1||y>COL||click[x][y]!=0) return;
	int i;
	int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
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
void rclick(int r,int c){
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
int mouse(void){
  static int lastB = 0; 
  if(MouseHit()){
    MOUSEMSG msg = GetMouseMsg();
    int r=msg.y/PIC_SIZE+1;
    int c=msg.x/PIC_SIZE+1;
    if(GetAsyncKeyState(VK_LBUTTON)&0x8000&&GetAsyncKeyState(VK_RBUTTON)&0x8000){
      int i,j,k=0;
      for(i=r-1;i<=r+1;i++){
        for(j=c-1;j<=c+1;j++){
          if(click[i][j]==-1){
            k++;
          }
        }
      }
      if(click[r][c]&&k==map[r][c]&&k>0){
        for(i=r-1;i<=r+1&&i<=ROW;i++){
          for(j=c-1;j<=c+1;j++){
            if(click[i][j]==0){
              if(map[i][j]>=0){
                open(i,j);
              }
              else{
                end();
                return 1;
              }
            }
          }
        }
      }
      lastB=clock();
    }
    else if(msg.uMsg==WM_LBUTTONDOWN&&(clock()-lastB)>100){
      lastB = clock();
      if(click[r][c]==-1) return 0;
      if(map[r][c]<0){
        end();
        return 1;
      }
      else{
        open(r,c);
      }
    }
    else if(msg.uMsg==WM_RBUTTONDOWN&&(clock()-lastB)>100){
      lastB = clock();
      rclick(r,c);
    }
  }
  return 0;
}
//void print(void){
//	int i,j;
//	for(i=1;i<=ROW;i++){
//		for(j=1;j<=COL;j++){
//			printf("%d ",map[i][j]);
//		}
//		putchar('\n');
//	}
//}
void game(void){
  while(1){
    if(MouseHit()){
    static int lastB = 0;
      MOUSEMSG msg = GetMouseMsg();
      int r=msg.y/PIC_SIZE+1;
      int c=msg.x/PIC_SIZE+1;
      if(msg.uMsg==WM_LBUTTONDOWN&&(clock()-lastB)>100){
      	time(&start_time);
      	end_time=start_time;
      	timer();
      	lastB = clock();
        putimage((c-1)*PIC_SIZE,(r-1)*PIC_SIZE, &img[0]);
        CreateMine(c,r);
        open(r,c);
        break;
      }
      else if(msg.uMsg==WM_RBUTTONDOWN&&(clock()-lastB)>100){
      	rclick(r,c);
      	lastB = clock();
      }
    }
    Sleep(10);
  }
  while(1){
  	timer();
    if(mouse()){
      isok=MessageBox(GetHWnd(),"You lose! Do you want to play again?","notice",MB_OKCANCEL);
      playmusic("lose.mp3");
      break;
    }
    else if(count==ROW*COL-MINE_NUM){
      playmusic("win.wav");
      isok=MessageBox(GetHWnd(),"You win! Do you want to play again?","notice",MB_OKCANCEL);
      break;
    }
    Sleep(10);
  }
}
void select(void){
	initgraph(520, 500);
	setbkcolor(RGB(100,160,150));
	cleardevice();
	settextcolor(BLACK);
	rectangle(80, 0, 350, 100);
	outtextxy(100, 50, "请选择难度：");
	rectangle(80, 100, 350, 200);
	outtextxy(100, 150, "初级9*9，雷数10");
	rectangle(80, 200, 350, 300);
	outtextxy(100, 250, "中级16*16，雷数40");
	rectangle(80, 300, 350, 400);
	outtextxy(100, 350, "高级16*30，雷数99");
	rectangle(80, 400, 350, 500);
	outtextxy(130, 450, "自定义");
	while(1){
	if(MouseHit()){
		MOUSEMSG msg=GetMouseMsg();
		if(msg.uMsg==WM_LBUTTONDOWN){
		if(msg.x>80&&msg.x<350){
		if(msg.y<100) continue;
		else if(100<msg.y&&msg.y<200){
			ROW=9;
			COL=9;
			MINE_NUM=10;
		}
		else if(200<msg.y&&msg.y<300){
			ROW=16;
			COL=16;
			MINE_NUM=40;
		}
		else if(300<msg.y&&msg.y<400){
			ROW=16;
			COL=30;
			MINE_NUM=99;
		}
		else if(400<msg.y&&msg.y<500){
			char s[20];
			InputBox(s,20,"请输入行数和列数和雷数，用空格分开");
			sscanf(s,"%d %d %d",&ROW,&COL,&MINE_NUM);
			while(ROW>24||COL>30||MINE_NUM>=ROW*COL*0.9){
				InputBox(s,20,"invalid,请重新输入行数和列数和雷数，用空格分开");
				sscanf(s,"%d %d %d",&ROW,&COL,&MINE_NUM);
			}
		}
		break;
	}
}
}
}
closegraph();
}
int main(){
	srand(time(NULL));
	load();
	select();
	initgraph(PIC_SIZE*COL,PIC_SIZE*(ROW+1),0);
	setbkcolor(RGB(189,189,189));
	cleardevice();
	draw();
	drawMineCount();
	game();
	while(isok==IDOK){
		refresh();
		draw();
		Sleep(50);
		game();
	}
	closegraph();
	return 0;
}
