#include <conio.h>
#include <stdio.h>





int c[9][9]= {0,0,0,2,6,0,7,0,1,
	     6,8,0,0,7,0,0,9,0,
	     1,9,0,0,0,4,5,0,0,
	     8,2,0,1,0,0,0,4,0,
	     0,0,4,6,0,2,9,0,0,
	     0,5,0,0,0,3,0,2,8,
	     0,0,9,3,0,0,0,7,4,
	     0,4,0,0,5,0,0,3,6,
	     7,0,3,0,1,8,0,0,0
	     };


int ww(int a[9][9],int p,int q);
void sh(int o[9][9],int x,int y);
void g(int x,int y);
void d(int a[9][9]);
int aa(int c[9][9]);
int ch(int c[9][9],int x,int y);
void show(int a[9][9],int x,int y);
int getkey();
void grid(int x,int y);
void main()
{
clrscr();
int ch,i,j,v;
int a[9][9]={0,0,0,2,6,0,7,0,1,
	     6,8,0,0,7,0,0,9,0,
	     1,9,0,0,0,4,5,0,0,
	     8,2,0,1,0,0,0,4,0,
	     0,0,4,6,0,2,9,0,0,
	     0,5,0,0,0,3,0,2,8,
	     0,0,9,3,0,0,0,7,4,
	     0,4,0,0,5,0,0,3,6,
	     7,0,3,0,1,8,0,0,0
	     };





grid(9,9);
show(a,9,9);
i=20;
j=4;
gotoxy(i,j);
while(1==1)
{
ch=getkey();

if(ch==8&&c[(j/2)-2][(i/2)-10]==0)
{
a[(j/2)-2][(i/2)-10]=0;
show(a,9,9);
gotoxy(i,j);
}
if(ch>=49&&ch<=57&&c[(j/2)-2][(i/2)-10]==0)
{
a[(j/2)-2][(i/2)-10]=ch-48;
show(a,9,9);
v=ww(a,i,j);


if(v==1)
{
gotoxy(1,24);
textcolor(2);
cprintf("right move");
}
if(v==0)
{
gotoxy(1,24);
textcolor(4);
cprintf("perhaphs wrong move");
}
gotoxy(i,j);
}
switch (ch)
{
case 80:
if(j==20)
{
printf("\a");
break;
}


else
{
j=j+2;
gotoxy(i,j);
break;
}
case 72:
if(j==4)
{
printf("\a");
break;
}
else
{
j=j-2;
gotoxy(i,j);
break;
}

case 75:
if(i==20)
{
printf("\a");
break;
}
else
{
i=i-2;
gotoxy(i,j);
break;
}

case 77:
if(i==36)
{
printf("\a");
break;
}

else
{
i=i+2;
gotoxy(i,j);
break;
}


case 27:
goto out;
}
}
out:

d(a);

getch();
}

void grid(int x,int y )
{
int i,j;
gotoxy(1,1);
textcolor(6);
cprintf("press escape to submit your final solution");
for(j=3;j<=3+2*(y);j+=2)
{
for(i=20;i<=20+2*(x-1);i++)
{
gotoxy(i,j);
printf("%c",196);
}
}
for(j=4;j<=2+2*y;j+=2)
{
for(i=19;i<=21+2*(x-1);i+=2)
{
gotoxy(i,j);
printf("%c",179);
}
}
for(j=5;j<=1+2*y;j+=2)
{
gotoxy(21+2*(x-1),j);
printf("%c",180);
gotoxy(19,j);
printf("%c",195);
for(i=21;i<=20+2*(x-1);i+=2)
{
gotoxy(i,3);
printf("%c",194);
gotoxy(i,3+(2*y));
printf("%c",193);
gotoxy(i,j);
printf("%c",197);
}
}




gotoxy(19,3);
printf("%c",218);
gotoxy(21+2*(x-1),3);
printf("%c",191);
gotoxy(19,3+2*y);
printf("%c",192);
gotoxy(21+2*(x-1),3+2*y);
printf("%c",217);

}

void show(int a[9][9],int x,int y)
{
int i,j;
int c[9][9]= {0,0,0,2,6,0,7,0,1,
	     6,8,0,0,7,0,0,9,0,
	     1,9,0,0,0,4,5,0,0,
	     8,2,0,1,0,0,0,4,0,
	     0,0,4,6,0,2,9,0,0,
	     0,5,0,0,0,3,0,2,8,
	     0,0,9,3,0,0,0,7,4,
	     0,4,0,0,5,0,0,3,6,
	     7,0,3,0,1,8,0,0,0
	     };
textcolor(4);
for(j=4;j<=20;j+=2)
{
for(i=20;i<=36;i+=2)
{
gotoxy(i,j);
if(a[(j/2)-2][(i/2)-10]==0)
{
printf(" ");
}
if(a[(j/2)-2][(i/2)-10]!=0 && c[(j/2)-2][(i/2)-10]!=0)
{
cprintf("%d",a[(j/2)-2][(i/2)-10]);
}
if(a[(j/2)-2][(i/2)-10]!=0 && c[(j/2)-2][(i/2)-10]==0)
{
printf("%d",a[(j/2)-2][(i/2)-10]);
}
}
}
}
int getkey()
{
int ch;
ch=getch();
if(ch==0)
{
ch=getch();
return (ch);
}
return (ch);
}




void d(int a[9][9])
{

int o[9][9];


int x,y,w,i,j,m,h,n;
for(i=0;i<=8;i++)
{
for(j=0;j<=8;j++)
{
o[i][j]=c[i][j];
}
}



m=1;
while(m>0)
{
m=aa(o);




















for(x=0;x<=8;x++)
{
y=0;
while(y<=8)
{
if(o[x][y]!=0)
{
y++;
}
if(o[x][y]==0 && y<=8)
{
w=ch(o,x,y);
if(w==0)
{
y++;
}
if(w!=0)
{
o[x][y]=w;
y++;
}
}
}
}








}











for(i=0;i<=8;i++)
{
for(j=0;j<=8;j++)
{
h=o[i][j]-a[i][j];
if(h!=0)
{
goto e;
}
}
}


e:



if (h==0)
{
gotoxy(22,23);
textcolor(2);
cprintf("your solution is correct");
}
if(h!=0)
{
textcolor(4);
gotoxy(22,23);
cprintf("sorry your solution is wrong");
}


grid(9,9);
show(a,9,9);


gotoxy(1,24);
textcolor(9);
cprintf(" want to see the solution hit 'backspace key'or hit any key 2 times to exit");
gotoxy(42,2);
gotoxy(1,8);
n=getch();

switch(n)
{
case 8:

g(9,9);
sh(o,9,9);
break;
}
if(n!=32)
{
goto yy;
}
yy:
}
int ch(int o[9][9],int x,int y)
{
auto int i,j,t,u,k;
auto int p,q,g;
p=(x/3)*3;
q=(y/3)*3;

int b[9]={1,2,3,4,5,6,7,8,9};
auto int z[9]={1,2,3,4,5,6,7,8,9};


for(k=0;k<=8;k++)
{
for(i=p;i<=p+2;i++)
{
for(j=q;j<=q+2;j++)
{
t=o[i][j]-b[k];
if(t==0)
{
z[k]=0;
}
}
}
}
k=0;
p=9;
q=7;
while(k<=8)
{
if(z[k]==0)
{
k++;
}
else
{
for(i=0;i<=8;i++)
{
p=o[x][i]-z[k];
q=o[i][y]-z[k];
if(p==0 || q==0)
{
z[k]=0;
}
}
k++;
}
}
printf("\n");

i=0;
u=0;
while(i<=7)
{
if(z[i]==0)
{
i++;
}
if(z[i]!=0)
{
u++;
i++;
}
}
if(u==1)
{
i=0;
while(i<=8)
{
if(z[i]==0)
{
i++;
}
if(z[i]!=0)
{
g=z[i];
break;
}
}
return (g);
}
if(i!=1)
{
return 0;
}
}

int aa(int o[9][9])
{
int i,j,m;

  for(i=0;i<=8;i++)
{
for(j=0;j<=8;j++)
{
m=o[i][j];
if(m==0)
{
goto v;
}
}
}
v:
if(m==0)
{
return 1;
}
if(m!=0)
{
return 0;
}
}




void g(int x,int y )
{
int i,j;

for(j=3;j<=3+2*(y);j+=2)
{
for(i=42;i<=42+2*(x-1);i++)
{
gotoxy(i,j);
printf("%c",196);
}
}
for(j=4;j<=2+2*y;j+=2)
{
for(i=41;i<=43+2*(x-1);i+=2)
{
gotoxy(i,j);
printf("%c",179);
}
}
for(j=5;j<=1+2*y;j+=2)
{
gotoxy(43+2*(x-1),j);
printf("%c",180);
gotoxy(41,j);
printf("%c",195);
for(i=43;i<=42+2*(x-1);i+=2)
{
gotoxy(i,3);
printf("%c",194);
gotoxy(i,3+(2*y));
printf("%c",193);
gotoxy(i,j);
printf("%c",197);
}
}




gotoxy(41,3);
printf("%c",218);
gotoxy(43+2*(x-1),3);
printf("%c",191);
gotoxy(41,3+2*y);
printf("%c",192);
gotoxy(43+2*(x-1),3+2*y);
printf("%c",217);

}


void sh(int o[9][9],int x,int y)
{
int i,j;
int c[9][9]= {0,0,0,2,6,0,7,0,1,
	     6,8,0,0,7,0,0,9,0,
	     1,9,0,0,0,4,5,0,0,
	     8,2,0,1,0,0,0,4,0,
	     0,0,4,6,0,2,9,0,0,
	     0,5,0,0,0,3,0,2,8,
	     0,0,9,3,0,0,0,7,4,
	     0,4,0,0,5,0,0,3,6,
	     7,0,3,0,1,8,0,0,0
	     };

for(j=4;j<=20;j+=2)
{
for(i=42;i<=58;i+=2)
{
gotoxy(i,j);
if(o[(j/2)-2][(i/2)-21]==0)
{
printf(" ");
}
if(o[(j/2)-2][(i/2)-21]!=0 && c[(j/2)-2][(i/2)-21]!=0)
{
textcolor(4);
cprintf("%d",o[(j/2)-2][(i/2)-21]);
}
if(o[(j/2)-2][(i/2)-21]!=0 && c[(j/2)-2][(i/2)-21]==0)
{
textcolor(2);
cprintf("%d",o[(j/2)-2][(i/2)-21]);
}
}
}
}


int ww(int a[9][9],int p,int q)
{

int o[9][9];


int x,y,w,i,j,m,h,n;
for(i=0;i<=8;i++)
{
for(j=0;j<=8;j++)
{
o[i][j]=c[i][j];
}
}



m=1;
while(m>0)
{
m=aa(o);




















for(x=0;x<=8;x++)
{
y=0;
while(y<=8)
{
if(o[x][y]!=0)
{
y++;
}
if(o[x][y]==0 && y<=8)
{
w=ch(o,x,y);
if(w==0)
{
y++;
}
if(w!=0)
{
o[x][y]=w;
y++;
}
}
}
}








}



























grid(9,9);
show(a,9,9);


n=o[(q/2)-2][(p/2)-10]-a[(q/2)-2][(p/2)-10];
if(n!=0)
{
return 0;
}
if(n==0)
{
return 1;
}
}