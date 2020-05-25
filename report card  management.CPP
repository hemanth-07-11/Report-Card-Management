#include<fstream.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<string.h>
#include<iomanip.h>

ofstream r;
ifstream t;

void end();
void menu1();
void menu2();
void menu3();
void start();

void micky();

//FOR MOUSE SETTINGS
  union REGS in,out;

       int callmouse()
       {
	      in.x.ax=1;
	      int86(51,&in,&out);
	      return 1;
       }
       void mouseposi(int &xpos,int &ypos,int &click)
       {
	      in.x.ax=3;
	      int86(51,&in,&out);
	      click=out.x.bx;
	      xpos=out.x.cx;
	      ypos=out.x.dx;
       }
       int mousehide()
       {
	      in.x.ax=2;
	      int86(51,&in,&out);
	      return 1;
       }
       void setposi(int &xpos,int &ypos)
       {
	     in.x.ax=4;
	     in.x.cx=xpos;
	     in.x.dx=ypos;
	     int86(51,&in,&out);
       }
		     //-------------------//



class xii
	{
	 public:
	 int roll;
	 char na[20];
	 int m1,m2,m3,m4,m5;
	 char g[10];
	 int t;
	 int p;
	 void input()
	  {
	   gotoxy(1,5);
	   cout<<"\tENTER ROLL NUMBER OF THE STUDENT :";
	   cin>>roll;
	   cout<<"\tENTER NAME OF THE STUDENT :";
	   gets(na);
	   cout<<"\n\n\tENTER MARKS OF THE 5 SUBJECTS OUT OF 100";
	   cout<<"\n";
	   cout<<"\tENTER ENGLISH MARKS :";
	   cin>>m1;
	   cout<<"\n";
	   cout<<"\tENTER PHYSICS MARKS :";
	   cin>>m2;
	   cout<<"\n";
	   cout<<"\tENTER CHEMISTRY MARKS :";
	   cin>>m3;
	   cout<<"\n";
	   cout<<"\tENTER MATHEMATICS MARKS :";
	   cin>>m4;
	   cout<<"\n";
	   cout<<"\tENTER COMPUTER SCIENCE MARKS :";
	   cin>>m5;
	   cout<<"\n";
	   cleardevice();
	   t=m1+m2+m3+m4+m5;
	   p=t/5;
	   gotoxy(1,1);
	  }

	  void output()
	   {
	   cout<<"\n";
	   cout<<" "<<roll<<"\t"<<" "<<na<<setw(10)<<"\t";
	   cout<<" "<<m1<<","<<m2<<","<<m3<<","<<m4<<","<<m5<<"\t";
	   cout<<"  "<<p<<"%"<<"\t"<<"\t"<<" "<<g<<"\n";
	   cout<<"\t";
	   }
      }s[30];

int i,n;
void writes()
{
 clrscr();
 cleardevice();
 cout<<"\n";
 cout<<"\tENTER THE NUMBER OF RECORDS TO BE CREATED :";
 cin>>n;
 cleardevice();
 for(i=0;i<n;i++)
  {
   s[i].input();
   if(s[i].p>=95)
	strcpy(s[i].g,"A1");
   if(s[i].p>=90&&s[i].p<95)
	strcpy(s[i].g,"A2");
   if(s[i].p>=80&&s[i].p<90)
	strcpy(s[i].g,"B1");
   if(s[i].p>=70&&s[i].p<80)
	strcpy(s[i].g,"B2");
   if(s[i].p>=60&&s[i].p<70)
	strcpy(s[i].g,"C1");
   if(s[i].p>=50&&s[i].p<60)
	strcpy(s[i].g,"C2");
   if(s[i].p>=40&&s[i].p<50)
	strcpy(s[i].g,"D1");
   if(s[i].p<40)
	strcpy(s[i].g,"D2");
   r.write((char*)&s[i],sizeof(s[i]));
  }
}

void append()
{
 clrscr();
 cleardevice();
 cout<<"\n";
 int k;
 cout<<"\t\t\t*-----------*"<<"\n";
 cout<<"\t\t\t| APPENDING |"<<"\n";
 cout<<"\t\t\t*-----------*"<<"\n"<<"\n";
 cout<<"\tENTER THE NUMBER OF RECORDS TO BE APPENDED :";
 cin>>k;
 for(i=0;i<k;i++)
  {
   s[i].input();
   if(s[i].p>=95)
	strcpy(s[i].g,"A1");
   if(s[i].p>=90&&s[i].p<95)
	strcpy(s[i].g,"A2");
   if(s[i].p>=80&&s[i].p<90)
	strcpy(s[i].g,"B1");
   if(s[i].p>=70&&s[i].p<80)
	strcpy(s[i].g,"B2");
   if(s[i].p>=60&&s[i].p<70)
	strcpy(s[i].g,"C1");
   if(s[i].p>=50&&s[i].p<60)
	strcpy(s[i].g,"C2");
   if(s[i].p>=40&&s[i].p<50)
	strcpy(s[i].g,"D1");
   if(s[i].p<40)
	strcpy(s[i].g,"D2");
   r.write((char*)&s[i],sizeof(s[i]));
  }
 getch();
 n+=k;
}

void search()
{
 clrscr();
 cleardevice();
 char name[20];
 int flag=0;
 cout<<"\n";
 cout<<"\t\t\t*-----------*"<<"\n";
 cout<<"\t\t\t| SEARCHING |"<<"\n";
 cout<<"\t\t\t*-----------*"<<"\n"<<"\n";

 step:
 cout<<"\n\tENTER THE NAME TO BE SEARCHED :";
 gets(name);
 cout<<"\n";
 cout<<"ROLL	 NAME     	MARKS           PERCENTAGE	GRADE"<<"\n";
 for(i=0;i<n;i++)
  {
   t.read((char *) &s[i],sizeof(s[i]));
   if(strcmp(name,s[i].na)==0)
    {
     flag=1;
     s[i].output();
     break;
    }
  }
 if(flag==0)
  {
   cleardevice();
   cout<<"\tSORRY\n";
   cout<<"\tTHE NAME DOES NOT EXIST.\n";
  }
 getch();
}

void update()
{
 clrscr();
 cleardevice();
 cout<<"\t\t\t*--------------*"<<"\n";
 cout<<"\t\t\t| UPDATED LIST |"<<"\n";
 cout<<"\t\t\t*--------------*"<<"\n"<<"\n";
 cout<<"ROLL	  NAME		             MARKS                    PERCENTAGE          GRADE"<<"\n";
 cout<<"-----------------------------------------------------------"<<"\n";
 for(i=0;i<n;i++)
  {
   if(s[i].p<=40.0)
	s[i].t=s[i].t+(s[i].t/10);
	s[i].p=s[i].t/5.0;
   if(s[i].p>=50.0&&s[i].p<60.0)
	strcpy(s[i].g,"C2");
   if(s[i].p>=40.0&&s[i].p<50.0)
	strcpy(s[i].g,"D1");
   if(s[i].p<40.0)
	strcpy(s[i].g,"Failed");
   r.write((char*)&s[i],sizeof(s[i]));
   s[i].output();
  }
 getch();
}

void sort()
 {
 clrscr();
 cleardevice();
 xii tp;
 cout<<"\t\t\t*-------------*"<<"\n";
 cout<<"\t\t\t| SORTED LIST |"<<"\n";
 cout<<"\t\t\t*-------------*"<<"\n"<<"\n";
 cout<<"ROLL    NAME	    MARKS           PERCENTAGE	    GRADE"<<"\n";
 cout<<"---------------------------------------------------------"<<"\n";
 for(i=0;i<n;i++)
 {
  t.read((char *) &s[i],sizeof(s[i]));
  for(i=0;i<n-1;i++)
   {	 for(int j=i+1;j<n;j++)
    {	  if(strcmp(s[i].na,s[j].na)>0)
     {	   tp=s[i];
	   s[i]=s[j];
	   s[j]=tp;
     }
    }
   }
  for(i=0;i<n;i++)
  s[i].output();
 }
 getch();
}

void failed()
{
 cleardevice();
 cout<<"\t**----------------------------------------------------------**"<<"\n";
 cout<<"\t|| THE LIST OF STUDENTS WHO FAILED IN MORE THAN ONE SUBJECT ||"<<"\n";
 cout<<"\t**----------------------------------------------------------**\n\n";
 cout<<"ROLL	NAME	    MARKS	  PERCENTAGE	  GRADE"<<"\n";
 cout<<"-------------------------------------------------------"<<"\n";
 for(i=0;i<n;i++)
 {
  int c=0;
  t.read((char *) &s[i],sizeof(s[i]));
  if (s[i].m1<40)
	c++;
  if (s[i].m2<40)
	c++;
  if (s[i].m3<40)
	c++;
  if (s[i].m4<40)
	c++;
  if (s[i].m5<40)
	c++;
  if(c>=2)
   {
    s[i].output();
   }
 }
 getch();
}

void reads()
{
 clrscr();
 cleardevice();
 cout<<"\n";
 cout<<"\t**------------------------------------------------**"<<"\n";
 cout<<"\t||   THE REPORT CARD OF STUDENTS OF CLASS XII||"<<"\n";
 cout<<"\t**------------------------------------------------**"<<"\n"<<"\n";
 cout<<"ROLL	NAME      MARKS	         PERCENTAGE	   GRADE"<<"\n";
 cout<<"--------------------------------------------------------"<<"\n";
 for(i=0;i<n;i++)
 {
  t.read((char *) &s[i],sizeof(s[i]));
  s[i].output();
 }
 getch();
}

void start()
{

  int x,y,cl,a,b;

 int gdriver = DETECT, gmode, errorcode;
 initgraph(&gdriver,&gmode,"");


setcolor(13);
bar3d(65,70,590,150,10,20);
settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
outtextxy(80,93,"CLASS XII REPORT CARD");

bar3d(200,190,400,230,10,20);
setcolor(12);
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
outtextxy(240,200,"Ist TERM");

setcolor(12);
bar3d(200,250,400,290,10,20);
setcolor(12);
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
outtextxy(240,260,"IInd TERM");

setcolor(5);
bar3d(200,310,400,350,10,20);
setcolor(12);
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
outtextxy(220,322,"IIIrd TERM");

setcolor(5);
bar3d(140,380,470,440,10,20);
setcolor(BLUE);
settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
outtextxy(220,400,"EXIT");



 a=100;
 b=400;
 setposi(a,b);
 callmouse();
	     do
	     {
		    mouseposi(x,y,cl);
		    gotoxy(10,9);
		    if(cl==1 && x>=200 && x<=400 && y>=190 && y<=230)
		    {
		    cleardevice();
		    menu1();
		    break;
		    }
		    else if(cl==1 && x>=200 && x<=400 && y>=250 && y<=290)
		    {
		    cleardevice();
		    menu2();
		    break;
		    }
		    else if(cl==1 && x>=200 && x<=400 && y>=310 &&y<=350)
		    {
		    cleardevice();
		    menu3();
		    break;
		    }
		    else if(cl==1 && x>=140 && x<=470  && y>=380 &&y<=440)
		    {
		    cleardevice();
		    end();
		    exit(0);
		    // end();
		    break;
		    }
	     } while( !kbhit() );

}





void end()
{
/*cleardevice();
setbkcolor(4);
gotoxy(33,6);
cout<<"-:Created By:-";
for(int i=32;i>28;i--)
{
gotoxy(i,7);
cout<<"HEMANTH.";
delay(80);
}
for(i=70;i>28;i--)
{
gotoxy(i,10);
cout<<"";
delay(70);
}
gotoxy(28,25);
cout<<"Press any key to exit...";
getch();
exit(0);
}
   */


 int x,y,cl,a,b;
int gd=DETECT,gm;
initgraph(&gd,&gm,"c://tc//bgi");

setcolor(RED);
bar3d(100,100,530,200,10,20);
setcolor(6);
settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
outtextxy(150,140,"DONE? !!!");
delay(1500);

cleardevice();

bar3d(200,230,400,280,10,20);
setcolor(GREEN);
settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
outtextxy(230,240,"MENU");

setcolor(RED);
bar3d(200,320,400,370,10,20);
setcolor(4);
settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
outtextxy(230,330,"EXIT");


 a=100;
 b=400;
 setposi(a,b);
 callmouse();
	     do
	     {
		    mouseposi(x,y,cl);
		    gotoxy(10,9);
		    if(cl==1 && x>=200 && x<=400 && y>=230 && y<=280)
		    {
		    cleardevice();
		    start();
		    break;
		    }
		    else if(cl==1 && x>=200 && x<=400 && y>=320 && y<=370)
		    {  cleardevice();
		       bar3d(100,190,700,240,10,20);
		       setcolor(12);
		       settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		       outtextxy(130,210,"BY  N.HEMANTH     ROLL NO:1223A");
		       delay(2000);
		     exit(0);
		    break;
		    }
	     }while(!kbhit());
}

/***********************************menu1************************************/

void menu1()
{
cleardevice();
micky();
delay(500);
cleardevice();
char ch;
back:
settextstyle(GOTHIC_FONT,VERT_DIR,10);
settextjustify(LEFT_TEXT,CENTER_TEXT);
outtextxy(50,240,"REPORT CARD");
settextstyle(SANS_SERIF_FONT,VERT_DIR,9);
setbkcolor(BLUE);
settextjustify(LEFT_TEXT,CENTER_TEXT);
outtextxy(110,240,"Ist TERM");
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
outtextxy(290,50,"1.MAKE REPORT CARD");
outtextxy(290,90,"2.APPEND NAMES");
outtextxy(290,130,"3.SORT NAMES");
outtextxy(290,170,"4.SEARCH A NAME");
outtextxy(290,210,"5.UPDATE GRADE");
outtextxy(290,250,"6.VIEW REPORT CARD");
outtextxy(290,290,"7.LIST OF FAILURES");
outtextxy(290,330,"8.MAIN MENU");
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,7);
outtextxy(300,420,"ENTER CHOICE");
ch=getch();

switch(ch)
 {
case '1':
r.open("report_1");
writes();
r.close();
cleardevice();
goto back;

case '2':
r.open("report_1",ios::app|ios::out);
append();
r.close();
cleardevice();
goto back;

case '3':
t.open("report_1");
sort();
t.close();
cleardevice();
goto back;

case '4':
t.open("report_1");
search();
t.close();
cleardevice();
goto back;

case '5':
r.open("report_1",ios::end);
update();
r.close();
cleardevice();
goto back;

case '6':
t.open("report_1");
reads();
t.close();
cleardevice();
goto back;

case '7':
t.open("report_1");
failed();
t.close();
cleardevice();
goto back;

case '8':
closegraph();

start();

default :clrscr();
cleardevice();
settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
outtextxy(220,240,"TAKING YOU TO ");
outtextxy(190,280,"REPORT CARD Ist TERM ");
sleep(2);
cleardevice();
goto back;
}
}

/***************************************menu2********************************************/
void menu2()
{
cleardevice();
micky();
delay(3000);
cleardevice();
char ch;
back:
settextstyle(BOLD_FONT,VERT_DIR,10);
settextjustify(LEFT_TEXT,CENTER_TEXT);
outtextxy(50,240,"REPORT CARD");
settextstyle(SANS_SERIF_FONT,VERT_DIR,10);
setbkcolor(BLUE);
settextjustify(LEFT_TEXT,CENTER_TEXT);
outtextxy(110,240,"IInd TERM");
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
outtextxy(290,50,"1.MAKE REPORT CARD");
outtextxy(290,90,"2.APPEND NAMES");
outtextxy(290,130,"3.SORT NAMES");
outtextxy(290,170,"4.SEARCH A NAME");
outtextxy(290,210,"5.UPDATE GRADE");
outtextxy(290,250,"6.VIEW REPORT CARD");
outtextxy(290,290,"7.LIST OF FAILURES");
outtextxy(290,330,"8.MAIN MENU");
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,7);
outtextxy(300,420,"ENTER CHOICE");
ch=getch();

switch(ch)
 {
case '1':
r.open("report_2");
writes();
r.close();
cleardevice();
goto back;

case '2':
r.open("report_2",ios::app|ios::out);
append();
r.close();
cleardevice();
goto back;

case '3':
t.open("report_2");
sort();
t.close();
cleardevice();
goto back;

case '4':
t.open("report_2");
search();
t.close();
cleardevice();
goto back;

case '5':
r.open("report_2",ios::end);
update();
r.close();
cleardevice();
goto back;

case '6':
t.open("report_2");
reads();
t.close();
cleardevice();
goto back;

case '7':
t.open("report_2");
failed();
t.close();
cleardevice();
goto back;

case '8':
closegraph();
start();

default :clrscr();
cleardevice();
settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
outtextxy(220,240,"TAKING YOU TO ");
outtextxy(190,280,"REPORT CARD IInd TERM");
sleep(2);
cleardevice();
goto back;
}
}

/*********************************menu3**************************************/
void menu3()
{
cleardevice();
micky();
delay(3000);
cleardevice();
char ch;
back:
settextstyle(GOTHIC_FONT,VERT_DIR,10);
settextjustify(LEFT_TEXT,CENTER_TEXT);
outtextxy(50,240,"REPORT CARD");
settextstyle(SANS_SERIF_FONT,VERT_DIR,9);
setbkcolor(BLUE);
settextjustify(LEFT_TEXT,CENTER_TEXT);
outtextxy(110,240,"IIIrd TERM");
settextstyle(SANS_SERIF_FONT,0,4);
outtextxy(290,50,"1.MAKE REPORT CARD");
outtextxy(290,90,"2.APPEND NAMES");
outtextxy(290,130,"3.SORT NAMES");
outtextxy(290,170,"4.SEARCH A NAME");
outtextxy(290,210,"5.UPDATE GRADE");
outtextxy(290,250,"6.VIEW REPORT CARD");
outtextxy(290,290,"7.LIST OF FAILURES");
outtextxy(290,330,"8.MAIN MENU");
settextstyle(SANS_SERIF_FONT,0,7);
outtextxy(300,420,"ENTER CHOICE");
ch=getch();

switch(ch)
 {
case '1':
r.open("report_3");
writes();
r.close();
cleardevice();
goto back;
case '2':
r.open("report_3",ios::app|ios::out);
append();
r.close();
cleardevice();
goto back;

case '3':
t.open("report_3");
sort();
t.close();
cleardevice();
goto back;

case '4':
t.open("report_3");
search();
t.close();

 cleardevice();
goto back;

case '5':
r.open("report_3",ios::end);
update();
r.close();
cleardevice();
goto back;

case '6':
t.open("report_3");
reads();
t.close();
cleardevice();
goto back;

case '7':
t.open("report_3");
failed();
t.close();
cleardevice();
goto back;

case '8':
closegraph();
start();

default :clrscr();
cleardevice();
settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
outtextxy(220,240,"TAKING YOU TO ");
outtextxy(190,280,"REPORT CARD IIIrd TERM");
sleep(2);
cleardevice();
goto back;
}
}

/**********************************main**************************************/
void main()
{
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver,&gmode,"c:\\tc\\bgi");

/*settextstyle(SANS_SERIF_FONT,HORIZ_DIR,5);
rectangle(1,1,getmaxx(),getmaxy());
setbkcolor(9);
outtextxy(140,100,"A");
delay(2000);
outtextxy(200,170,"PROJECT ON");
delay(2000);
outtextxy(349,240,"REPORT CARD MAKING");
delay(2000);*/

  bar3d(70,190,700,240,10,20);
  setbkcolor(BLACK);
setcolor(12);
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
outtextxy(98,210,"A PROJECT ON REPORT CARD MAKING ");

delay(3000);
/*for(int i=0;i<360;i++)
 {
 ellipse(300,240,0,i,300,100);
 delay(12);
 }      */

closegraph();
start();
}


/*  bar3d(200,190,400,230,10,20);
setcolor(12);
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
outtextxy(240,200,"A PROJECT ON REPORT CARD MAKING ");
  */


void  *buf;            /*for micky mouse*/
void firstleft();
void secondleft();

void micky()
{

int h=0;
int gd=DETECT,gm,n,m,area;
//initgraph( &gd,&gm,"c://tc//bgi");//put your directory contains egavga.bgi
initgraph(&gd,&gm,"c://tc//bgi");

settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
outtextxy(320,300,"WELCOME");


rectangle(0,0,getmaxx(),getmaxy());
arc(240,120,40,140,70);
ellipse(165,80,10,280,20,20);
ellipse(315,80,-100,170,20,20);
arc(235,120,163,215,70);
arc(245,120,-35,17,70);
ellipse(193,178,85,280,40,20);
ellipse(283,178,-100,95,40,20);
ellipse(238,199,180,0,39,50);
ellipse(213,123,44,240,33,40);
ellipse(262,123,-60,135,33,40);
ellipse(210,123,0,360,13,20);//left eye
ellipse(265,123,0,360,13,20);//right eye
ellipse(210,133,0,360,10,10);//left eye ball
ellipse(265,133,0,360,10,10);//right eye ball
ellipse(210,133,0,360,3,3);//left eye ball
ellipse(265,133,0,360,3,3);//right eye ball
ellipse(238,160,0,360,10,13);//nose
arc(240,125,228,312,68);//mouth
arc(240,120,230,310,72);//mouth
setfillstyle(1,4);
floodfill(238,160,15);//nose
setfillstyle(1,15);
floodfill(210,113,15);
floodfill(265,113,15);
setfillstyle(1,9);
floodfill(210,100,15);
setfillstyle(1,1);
floodfill(315,80,15);
moveto(203,220);
lineto(203,260);
lineto(183,260);
lineto(183,350);
lineto(293,350);
lineto(293,260);
lineto(273,260);
lineto(273,220);
moveto(183,350);
lineto(173,460);
lineto(213,460);
lineto(238,400);
lineto(263,460);
lineto(303,460);
lineto(293,350);
moveto(173,460);
lineto(143,478);
lineto(213,478);
lineto(213,460);
moveto(263,460);
lineto(263,478);
lineto(333,478);
lineto(303,460);
line(238,400,238,350);
//right hand
moveto(183,260);
lineto(113,310);
lineto(183,375);
moveto(183,280);
lineto(137,310);
lineto(181,353);
setfillstyle(2,13);
floodfill(190,300,15);
setfillstyle(1,5);
floodfill(223,400,15);
setfillstyle(1,5);
floodfill(253,400,15);
setfillstyle(1,6);
floodfill(173,470,15);
floodfill(303,470,15);
//fingers
secondleft();
ellipse(413.5,228,0,180,3.5,3.5);
line(420,240,433,240);
line(423,247,440,247);
line(413,240,410,228);
line(417,228,420,240);
ellipse(433,243.5,-90,90,3.5,3.5);
line(423,254,440,254);
ellipse(440,250.5,-90,90,3.5,3.5);
ellipse(430,257,-90,90,3,3);
line(413,260,430,260);
area=imagesize(409,224,444,261);
buf=malloc(area);
getimage(409,224,444,261,buf);
while(!kbhit())
{
if(h==0)
{
setfillstyle(1,15);
setcolor(15);
ellipse(210,133,0,360,10,10);//left eye ball
ellipse(265,133,0,360,10,10);//right eye ball
setcolor(0);
ellipse(210,133,0,360,3,3);//left eye ball
ellipse(265,133,0,360,3,3);//right eye ball
floodfill(210,133,15);
floodfill(265,133,15);
setcolor(0);
putimage(391,209,buf,1);
firstleft();
setcolor(15);
secondleft();
putimage(409,224,buf,0);
h=1;
}
else
{
setfillstyle(1,0);
setcolor(0);
ellipse(210,133,0,360,10,10);//left eye ball
ellipse(265,133,0,360,10,10);//right eye ball
floodfill(210,133,0);
floodfill(265,133,0);
setcolor(15);
ellipse(210,133,0,360,3,3);//left eye ball
ellipse(265,133,0,360,3,3);//right eye ball
floodfill(210,133,15);
floodfill(265,133,15);
setcolor(0);
putimage(409,224,buf,1);
secondleft();
setcolor(15);
firstleft();
putimage(391,209,buf,0);
h=0;
}
delay(300);
}

}
void firstleft()
{
moveto(293,260);
lineto(353,276);
lineto(395,223);
moveto(293,280);
lineto(355,296);
lineto(395,245);
}
void secondleft()
{
moveto(293,260);
lineto(363,280);
lineto(413,240);
moveto(293,280);
lineto(363,300);
lineto(413,260);
}
