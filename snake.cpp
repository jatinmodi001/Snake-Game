#include<iostream>
#include<vector>
#include<stdlib.h>
#include<ncurses.h>

using namespace std;

struct food
{
int x,y;
char value;
};
struct snake
{
int x,y;
char value;
};


void generate(struct food &a)
{
a.x=a.x+7;
a.y=a.x+35;
if(a.x>=20)
{
a.x=2;
}
else
{
a.y=3;
}

a.value='F';


}
void addnode(vector<struct snake> &f,char board[20][80],struct food &a,int k,int j)
{
  f[f.size()-1].value='#';
  struct snake r;
  r.x=f[f.size()-1].x;
  r.y=f[f.size()-1].y-1;
  r.value='T';
  f.push_back(r);
  


}





void insertfood(struct food a,char board[20][80],int r,int c)
{
board[a.x][a.y]=a.value;
}
void insertsnake(vector<struct snake> &f,char board[20][80],int r,int c)
{
for(int i=0;i<f.size();i++)
{
 board[f[i].x][f[i].y]=f[i].value;
}
}

void move(vector<struct snake> &f,char board[20][80],int r,int c,int o,struct food &a)
{
int k,j;



if(o==2){


if(f[0].x+1==20){
 k=0;
 j=f[0].y;}
else
{
   k=f[0].x+1;
 j=f[0].y;
}

for(int i=0;i<f.size();i++)
{
 board[k][j]=board[f[i].x][f[i].y];
int h=k,n=j;
  k=f[i].x;
  j=f[i].y;
  f[i].x=h,f[i].y=n;
}
board[k][j]='.';
if(a.x==f[0].x&&a.y==f[0].y)
{
   addnode(f,board,a,k,j);
    generate(a);
  insertfood(a,board,r,c);
}
}




else if(o==4)
{
if(f[0].y-1<0){
 k=f[0].x;
 j=79;}
else{
k=f[0].x;
j=f[0].y-1;
}


for(int i=0;i<f.size();i++)
{
 board[k][j]=board[f[i].x][f[i].y];
  int h=k,n=j;
  k=f[i].x;
  j=f[i].y;
  f[i].x=h,f[i].y=n;
}
board[k][j]='.';

if(a.x==f[0].x&&a.y==f[0].y)
{
   addnode(f,board,a,k,j);
    generate(a);
  insertfood(a,board,r,c);
}
}




else if(o==6)
{
if(f[0].y+1==80)
{
k=f[0].x;
j=0;
}
else
{
 k=f[0].x;
 j=f[0].y+1;
}

for(int i=0;i<f.size();i++)
{
 board[k][j]=board[f[i].x][f[i].y];
  int h=k,n=j;
  k=f[i].x;
  j=f[i].y;
  f[i].x=h,f[i].y=n;
}board[k][j]='.';
if(a.x==f[0].x&&a.y==f[0].y)
{
   addnode(f,board,a,k,j);
    generate(a);
  insertfood(a,board,r,c);
}
}






else if(o==8)
{
if(f[0].x-1<0)
{
k=19;
j=f[0].y;
}
else
{
 k=f[0].x-1;
 j=f[0].y;
}

for(int i=0;i<f.size();i++)
{
 board[k][j]=board[f[i].x][f[i].y];
  int h=k,n=j;
  k=f[i].x;
  j=f[i].y;
  f[i].x=h,f[i].y=n;
}
board[k][j]='.';}
if(a.x==f[0].x&&a.y==f[0].y)
{
   addnode(f,board,a,k,j);
    generate(a);
  insertfood(a,board,r,c);
}
}







void print(char board[20][80],int r,int c)
{
for(int i=0;i<r;i++)
{
for(int j=0;j<c;j++)
{
cout<<board[i][j];
}
cout<<endl;
}
}

int main()
{
char board[20][80];
for(int i=0;i<20;i++)
{
for(int j=0;j<80;j++)
{
board[i][j]='.';
}
}
struct food a;
a.x=5,a.y=5;a.value='F';
insertfood(a,board,20,80);
struct snake d;
vector<struct snake>v;
d.x=2;
d.y=9;
d.value='H';
v.push_back(d);
d.x=2;
d.y=10;
d.value='#';
v.push_back(d);
d.x=2;
d.y=11;
d.value='T';
v.push_back(d);



insertsnake(v,board,20,80);
int o;

print(board,20,80);

while(true)
{

int flag=0;


cin>>o;




move(v,board,20,80,o,a);
insertsnake(v,board,20,80);
for(int i=1;i<v.size();i++)
{
  if(v[0].x==v[i].x&&v[0].y==v[i].y)
{
    flag=1;
}
   

}
if(flag==1)
{
cout<<"GAME OVER";
break;
}
system("clear");

print(board,20,80);
}
}




