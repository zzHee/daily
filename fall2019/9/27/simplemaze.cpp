#include <iostream>
#include <queue>
using namespace std;
int a[250][250];
int b[250][250];
int r,c;
struct Point
{
	int x;
	int y;
};

queue <Point> order;
void findn(int x,int y)
{
	int at=a[x][y];
	if(x>0)
	{
		if(b[2*x-1][y]==0)
		{
			if(a[x-1][y]==-1)
				a[x-1][y]=at+1;
				Point temp;
				temp.x=x-1;
				temp.y=y;
				order.push(temp);
		}
	}
	if(x+1<r)
	{
		if(b[2*x+1][y]==0)
		{
			if(a[x+1][y]==-1)
				a[x+1][y]=at+1;
				Point temp;
				temp.x=x+1;
				temp.y=y;
				order.push(temp);
		}
	}
	if(y>0)
	{
		if(b[2*x][y-1]==0)
		{
			if(a[x][y-1]==-1)
				a[x][y-1]=at+1;
				Point temp;
				temp.x=x;
				temp.y=y-1;
				order.push(temp);
		}
	}
	if(y+1<c)
	{
		if(b[2*x][y]==0)
		{
			if(a[x][y+1]==-1)
				a[x][y+1]=at+1;
				Point temp;
				temp.x=x;
				temp.y=y+1;
				order.push(temp);
		}
	}
}
int main()
{
	int min;
	int ent,exit;
	cin >> r >> c >> ent >> exit;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			a[i][j]=-1;
		}
	}
	
	for(int i=0;i<r*2-1;++i)
	{
		if(i%2==0)
		{
			for(int j=0;j<c-1;++j)
			{
				cin >> b[i][j];
			}
		}
		else
		{
			for(int j=0;j<c;++j)
			{
				cin >> b[i][j]; 
			}
		}
	}
	a[0][ent-1]=0;
	findn(0,ent-1);
	Point temp;
	temp.x=0;
	temp.y=ent-1;
	order.push(temp);
//	cout << order.empty();
	while(order.empty()!=1)
	{
//		cout << "*";
		Point p=order.front();
		order.pop();
		findn(p.x,p.y);
		if(a[r-1][exit]!=-1) 
		{
			cout << a[r-1][exit-1]+2;
//		cout << "*";
			return 0;
		}
	}
	cout << "No way";
	
	
//	for(int i=0;i<r*2-1;++i)
//	{
//		if(i%2==0)
//		{
//			for(int j=0;j<c-1;++j)
//			{
//				cout << b[i][j] << " ";
//			}
//			cout << endl;
//		}
//		else
//		{
//			for(int j=0;j<c;++j)
//			{
//				cout << b[i][j] << " "; 
//			}
//			cout << endl;
//		}
//	}

//	for(int i=0;i<r;++i)
//	{
//		for(int j=0;j<c;++j)
//		{
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	} 
	return 0;
}
