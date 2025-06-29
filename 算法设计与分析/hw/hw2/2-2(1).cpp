#include <iostream>
#include <fstream>
using namespace std;
struct grid
{
    //表示坐标
	int x;
	int y;
};
class Knight{
	public:
		Knight(int m,int n);
		~Knight(){};
		void out0(int m,int n,ofstream &out);
		grid *b66,*b68,*b86,*b88,*b810,*b108,*b1010,*b1012,*b1210,link[20][20];
		int m,n;
		int pos(int x,int y,int col);
		void step(int m,int n,int a[20][20],grid *b);
		void build(int m,int n,int offx,int offy,int col,grid *b);
		void base0(int mm,int nn,int offx,int offy);
		bool comp(int mm,int nn,int offx,int offy);
};
Knight::Knight(int mm,int nn){
	int i,j,a[20][20];
	m=mm;
	n=nn;
	b66=new grid[36];b68=new grid[48];
	b86=new grid[48];b88=new grid[64];
	b810=new grid[80];b108=new grid[80];
	b1010=new grid[100];b1012=new grid[120];
	b1210=new grid[120];
	//cout<<"6*6"<<"\n";
	ifstream in0("66.txt",ios::in); //利用文件流读取数据
	ifstream in1("68.txt",ios::in); //利用文件流读取数据
	ifstream in2("88.txt",ios::in); //利用文件流读取数据
	ifstream in3("810.txt",ios::in); //利用文件流读取数据
	ifstream in4("1010.txt",ios::in); //利用文件流读取数据
	ifstream in5("1012.txt",ios::in); //利用文件流读取数据
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			in0>>a[i][j];
		}
	}
	step(6,6,a,b66);
	//cout<<"6*8"<<"\n";
	for(i=0;i<6;i++)
	{
		for(j=0;j<8;j++)
		{
			in1>>a[i][j];
		}
	}
	step(6,8,a,b68);
	step(8,6,a,b86);
	//cout<<"8*8"<<"\n";
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			in2>>a[i][j];
		}
	}
	step(8,8,a,b88);
	for(i=0;i<8;i++)
	{
		for(j=0;j<10;j++)
		{
			in3>>a[i][j];
		}
	}
	step(8,10,a,b810);
	step(10,8,a,b108);
	//cout<<"10*10"<<"\n";
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			in4>>a[i][j];
		}
	}
	step(10,10,a,b1010);
	for(i=0;i<10;i++)
	{
		for(j=0;j<12;j++)
		{
			in5>>a[i][j];
		}
	}
	step(10,12,a,b1012);
	step(12,10,a,b1210);
}
//将读入的基础棋盘的数据转换为网格数据
void Knight::step(int m,int n,int a[20][20],grid *b)
{
	int i,j,k=m*n;
	if(m<n)
	{
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				int p=a[i][j]-1;
				b[p].x=i;
				b[p].y=j;
			}
		}
	}
	else
	{
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				int p=a[j][i]-1;
				b[p].x=i;
				b[p].y=j;
			}
		}
	}
}
//分治法的主体部分
bool Knight::comp(int mm,int nn,int offx,int offy)
{
	int mm1,mm2,nn1,nn2;
	int x[8],y[8],p[8];
	if(mm%2||nn%2||mm-nn>2||nn-mm>2||mm<6||nn<6) return 1;
	if(mm<12||nn<12)
    {
		base0(mm,nn,offx,offy);
		return 0;
	}
	mm1=mm/2;
	if(mm%4>0)
	{
		mm1--;
	}
	mm2=mm-mm1;
	nn1=nn/2;
	if(nn%4>0)
	{
		nn1--;
	}
	nn2=nn-nn1;
	//分割
	comp(mm1,nn1,offx,offy);//左上角
	comp(mm1,nn2,offx,offy+nn1);//右上角
	comp(mm2,nn1,offx+mm1,offy);//左下角
	comp(mm2,nn2,offx+mm1,offy+nn1);//右下角
	//合并
	x[0]=offx+mm1-1; y[0]=offy+nn1-3;
	x[1]=x[0]-1;     y[1]=y[0]+2;
	x[2]=x[1]-1;     y[2]=y[1]+2;
	x[3]=x[2]+2;     y[3]=y[2]-1;
	x[4]=x[3]+1;     y[4]=y[3]+2;
	x[5]=x[4]+1;     y[5]=y[4]-2;
	x[6]=x[5]+1;     y[6]=y[5]-2;
	x[7]=x[6]-2;     y[7]=y[6]+1;
	for(int i=0;i<8;i++)
	{
		p[i]=pos(x[i],y[i],n);
	}
	for(int i=1;i<8;i+=2)
	{
		int j1=(i+1)%8,j2=(i+2)%8;
		if(link[x[i]][y[i]].x==p[i-1])
			link[x[i]][y[i]].x=p[j1];
		else
			link[x[i]][y[i]].y=p[j1];
		if(link[x[j1]][y[j1]].x==p[j2])
			link[x[j1]][y[j1]].x=p[i];
		else
			link[x[j1]][y[j1]].y=p[i];
	}
	return 0;
}
//根据基础解构造子棋盘的Hamilton回路
void Knight::base0(int mm,int nn,int offx,int offy)
{
	if(mm==6&&nn==6)
		build(mm,nn,offx,offy,n,b66);
	if(mm==6&&nn==8)
		build(mm,nn,offx,offy,n,b68);
	if(mm==8&&nn==6)
		build(mm,nn,offx,offy,n,b86);
	if(mm==8&&nn==8)
		build(mm,nn,offx,offy,n,b88);
	if(mm==8&&nn==10)
		build(mm,nn,offx,offy,n,b810);
	if(mm==10&&nn==8)
		build(mm,nn,offx,offy,n,b108);
	if(mm==10&&nn==10)
		build(mm,nn,offx,offy,n,b1010);
	if(mm==10&&nn==12)
		build(mm,nn,offx,offy,n,b1012);
	if(mm==12&&nn==10)
		build(mm,nn,offx,offy,n,b1210);
}
void Knight::build(int m,int n,int offx,int offy,int col ,grid *b)
{
	int i,p,q,k=m*n;
	for(i=0;i<k;i++)
	{
		int x1=offx+b[i].x,y1=offy+b[i].y,x2=offx+b[(i+1)%k].x,y2=offy+b[(i+1)%k].y;
		p=pos(x1,y1,col);
		q=pos(x2,y2,col);
		link[x1][y1].x =q;
		link[x2][y2].y =p;
	}
}
//计算方格的编号
int Knight::pos(int x,int y,int col)
{
	return col*x+y;
}
void Knight::out0(int m,int n,ofstream &out)
{
	int i,j,k,x,y,p,a[20][20];
	if(comp(m,n,0,0))
		return;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=0;
		}
	}
	i=0;j=0;k=2;
	a[0][0]=1;
	out<<"(0,0)"<<"";
	for(p=1;p<m*n;p++)
	{
		x=link[i][j].x;
		y=link[i][j].y;
		i=x/n;j=x%n;
		if(a[i][j]>0)
		{
			i=y/n;
			j=y%n;
		}
		a[i][j]=k++;
		out<<"("<<i<<","<<j<<")";
		if((k-1)%n==0)
		{
			out<<"\n";
		}
	}
	out<<"\n";
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			out<<a[i][j]<<"   ";
		}
		out<<"\n";
	}
}
int main()
{
	int m,n;
	ifstream in("input.txt",ios::in); //利用文件流读取数据
	ofstream out("output.txt",ios::out);//利用文件流将数据存到文件中
	in>>m>>n;
	Knight k(m,n);
	k.comp(m,n,0,0);
	k.out0(m,n,out);
	in.close();
	out.close();
}

