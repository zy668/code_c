#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#include <conio.h>
#define PIC_SIZE 20
IMAGE img[12];
int map[26][32];
int click[26][32]={0};
int flag=0;
int ROW;
int COL;
int count=0;
int MINE_NUM;
int isok;
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
}
void load(void){
	int i;
	char temp[20];
		for (i = 0; i < 12;i++)
	{
		sprintf(temp,"./%d.jpg",i);
		loadimage(&img[i], temp, PIC_SIZE, PIC_SIZE);
	}
}
void draw(void){
	int i,j;
	for(i=1;i<=ROW;i++){
		for(j=1;j<=COL;j++){
			putimage((j-1)*PIC_SIZE,(i-1)*PIC_SIZE, &img[10]);
		}
	}
}
void end(void){
	int i,j;
	for(i=1;i<=ROW;i++){
		for(j=1;j<=COL;j++){
				if(map[i][j]==-1){
				putimage((j-1)*PIC_SIZE,(i-1)*PIC_SIZE,&img[9]);
			}
	}
}
}
void open(int x,int y){
  if(x<1||x>ROW||y<1||y>COL||click[x][y]==1)
    return;
  if(map[x][y]>0){
    putimage((y-1)*PIC_SIZE,(x-1)*PIC_SIZE,&img[map[x][y]]);
    click[x][y]=1;
    count++;
    return;
  }
  if(click[x][y]!=-1){
  putimage((y-1)*PIC_SIZE,(x-1)*PIC_SIZE,&img[0]);
  click[x][y]=1;
  count++;
}
  open(x-1,y);
  open(x+1,y);
  open(x,y-1);
  open(x,y+1);
  open(x-1,y-1);
  open(x-1,y+1);
  open(x+1,y-1);
  open(x+1,y+1);
}
void CreateMine(int x,int y){
	int i,j,k,a,b;
	for(k=0;k<MINE_NUM;){
		i=rand()%ROW+1;
		j=rand()%COL+1;
		if(abs(i-y)<=1&&abs(j-x)<=1){
			continue;
		}
		if(map[i][j]==0){
		map[i][j]=-1;
		k++;
	}
	}
	for(i=1;i<=ROW;i++){
		for(j=1;j<=COL;j++){
			if(map[i][j]==0){
				for(a=i-1;a<=i+1;a++){
					for(b=j-1;b<=j+1;b++){
						if(map[a][b]==-1){
							map[i][j]++;
						}
					}
				}
			}
		}
	}
}
int mouse(void){
	if(MouseHit()){
		MOUSEMSG msg = GetMouseMsg();
		int r=msg.y/PIC_SIZE+1;
		int c=msg.x/PIC_SIZE+1;
		if(msg.uMsg==WM_LBUTTONDOWN){
			if(click[r][c]==-1) return 0;
			if(map[r][c]==-1){
				end();
				return 1;
			}
			else{
				open(r,c);
			}
		}
		else if(msg.uMsg==WM_RBUTTONDOWN){
			if(click[r][c]==0){
			click[r][c]=-1;
			putimage((c-1)*PIC_SIZE,(r-1)*PIC_SIZE, &img[11]);
			flag++;
		}
		else if(click[r][c]==-1){
			click[r][c]=0;
			putimage((c-1)*PIC_SIZE,(r-1)*PIC_SIZE, &img[10]);
			flag--;
		}
		}
	}
	return 0;
}
void print(void){
	int i,j;
	for(i=1;i<=ROW;i++){
		for(j=1;j<=COL;j++){
			printf("%d ",map[i][j]);
		}
		putchar('\n');
	}
}
void game(void){
		while(1){
		if(MouseHit()){
		MOUSEMSG msg = GetMouseMsg();
		int r=msg.y/PIC_SIZE+1;
		int c=msg.x/PIC_SIZE+1;
		if(msg.uMsg==WM_LBUTTONDOWN){
			putimage((c-1)*PIC_SIZE,(r-1)*PIC_SIZE, &img[0]);
			CreateMine(c,r);
			open(r,c);
			break;
		}
		else if(msg.uMsg==WM_RBUTTONDOWN){
			if(click[r][c]==0){
			putimage((c-1)*PIC_SIZE,(r-1)*PIC_SIZE, &img[11]);
			click[r][c]=-1;
			flag++;
		}
		else if(click[r][c]==-1){
			putimage((c-1)*PIC_SIZE,(r-1)*PIC_SIZE,&img[10]);
			click[r][c]=0;
			flag--;
		}
		}
	}
}
	while(1){
		if(mouse()){
			isok=MessageBox(GetHWnd(), "You lose! Do you want to play again?", "notice", MB_OKCANCEL);
			break;
		}
		else if(count==ROW*COL-MINE_NUM){
			isok=MessageBox(GetHWnd(), "You win! Do you want to play again?", "notice", MB_OKCANCEL);
			break;
		}
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
		MOUSEMSG msg = GetMouseMsg();
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
			char  s[20];
			InputBox(s,20,"请输入行数和列数，用空格分开");
			sprintf(s,"%d %d %d",&ROW,&COL,&MINE_NUM);
//			while(ROW>24||COL>30||MINE_NUM>=ROW*COL){
//				InputBox(s,20,"invalid,请重新输入行数和列数和雷数，用空格分开");
//				sprintf(s,"%d %d %d",&ROW,&COL,&MINE_NUM);
//			}
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
	initgraph(PIC_SIZE*COL,PIC_SIZE*ROW,0);
	draw();
	game();
	while(isok==IDOK){
		refresh();
		draw();
		game();
	}
	closegraph();
	return 0;
}