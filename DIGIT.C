#include<stdio.h>
#include<conio.h>
#include<dos.h>

#define hor cprintf("%c%c%c",254,254,254)
#define ver cprintf("%c",219)
int flag=0;
void writeDigit(int n,int x,int y){
	int a,b,c,d,e,f,g,rem;

	a=b=c=d=e=f=g=1;
	//textbackground(BLACK);
	textcolor(GREEN);



	if(n>=10){

		rem=n%10;
		writeDigit(rem,x+6,y);
		n=n/10;
	}


	if(n==9)	e=0;
	if(n==7)	d=e=f=g=0;
	if(n==6)	b=0;
	if(n==5)	b=e=0;
	if(n==4)	a=e=d=0;
	if(n==3)	e=f=0;
	if(n==2)	c=f=0;
	if(n==1)	a=d=e=f=g=0;
	if(n==0)	g=0;


	if(a==1){
		gotoxy(x,y);
		hor;
	}
	if(b==1){
		gotoxy(x+3,y+1);
		ver;
	}
	if(c==1){
		gotoxy(x+3,y+3);
		ver;
	}
	if(d==1){
		gotoxy(x,y+4);
		hor;
	}
	if(e==1){
		gotoxy(x-1,y+3);
		ver;
	}
	if(f==1){
		gotoxy(x-1,y+1);
		ver;
	}
	if(g==1){
		gotoxy(x,y+2);
		hor;
	}
}

void Loading(){
	int i;

	clrscr();
	gotoxy(5,8);
	textcolor(WHITE);
	cprintf("Installing Clock.....");
	for(i=5;i<80;i++){
		gotoxy(i,10);

		cprintf("%c",219);
	}

	for(i=5;i<80;i++){
		gotoxy(i,10);
		textcolor(GREEN);
		cprintf("%c",219);
		if(i>=40)delay(10);
		else delay(100);


	}
	sleep(1);
	clrscr();
	gotoxy(15,10);
	textcolor(CYAN);
	cprintf("PRESS ANY KEY.............");
	getch();
	textbackground(BLACK);
      /*	gotoxy(5,12);
	textcolor(WHITE);
	cprintf("Installing Finished");
	sleep(1);
	clrscr();*/
}


void main(){
	int i;
	struct time t;
	struct date d;

	clrscr();

	Loading();

	while(! kbhit()){
		clrscr();
		//gotoxy(35,1);
		//printf("%c%c%c%c 'S DIGIT %c%c%c%c",219,219,219,219,219,219,219,219);
		gettime(&t);
		writeDigit(t.ti_hour%12,15,10);
		textcolor(GREEN);

		gotoxy(27,11);
		cprintf("%c",258);
		gotoxy(27,13);
		cprintf("%c",258);


		writeDigit(t.ti_min,30,10);

		textcolor(GREEN);
		gotoxy(42,11);
		cprintf("%c",258);
		gotoxy(42,13);
		cprintf("%c",258);

		writeDigit(t.ti_sec,45,10);

		if(t.ti_hour<12){
			gotoxy(57,14);
			printf("AM");
		}
		else{
			gotoxy(57,14);
			printf("PM");
		}
		textcolor(CYAN);
		for(i=1;i<=80;i++){
			gotoxy(i,1);
			cprintf("%c",219);

		}

		gotoxy(5,1);
		printf("DEV'S DIGIT");
		textcolor(RED);
		getdate(&d);
		gotoxy(44,1);
		cprintf(" %d / ",d.da_day);
		gotoxy(50,1);
		cprintf("%d / ",d.da_mon);
		gotoxy(54,1);
		cprintf("%d ",d.da_year);
		textcolor(GREEN);

		delay(1000);
	}
	textcolor(WHITE);
	getch();
}