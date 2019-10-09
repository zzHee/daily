#include <iostream>
using namespace std;
int x[101000];
int y[101000];
int d1[101000];
int d2[101000];
int maxd2[101000];
void QuickSort(int R[],int x[],int y[],int low,int high)
{
	int temp;
	int tempx,tempy;
	int i=low,j=high;
	if(low<high)
	{
		temp=R[low];
		tempx=x[low];
		tempy=y[low];
		while(i<j)
		{
			while(j>i&&R[j]>=temp) --j;
			if(i<j)
			{
				R[i]=R[j];
				x[i]=x[j];
				y[i]=y[j];
				++i;
			}
			while(i<j&&R[i]<temp) ++i;
			
			if(i<j)
			{
				R[j]=R[i];
				x[j]=x[i];
				y[j]=y[i];
				--j;
			}
		}
		R[i]=temp;
		x[i]=tempx;
		y[i]=tempy;
		QuickSort (R,x,y,low,i-1);
		QuickSort (R,x,y,i+1,high);
	}
}
int main()
{
	int x1,y1;
	int x2,y2;
	int n;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> n;
	for(int i=0;i<n;++i)
	{
		cin >> x[i] >> y[i];
		d1[i]=(x[i]-x1)*(x[i]-x1)+(y[i]-y1)*(y[i]-y1);
	}
	QuickSort(d1,x,y,0,n-1);
	for(int i=0;i<n;++i)
	{
		d2[i]=(x[i]-x2)*(x[i]-x2)+(y[i]-y2)*(y[i]-y2);
	}
	int max=n-1;//这里之前搞错了，明确max是储存下标还是数字 
	for(int i=n-1;i>=0;--i)
	{
		if(d2[i]>d2[max])
		{
			max=i;
		}
		maxd2[i]=d2[max];
	}
	int mins;
	if(n==1)
	{
		mins=(d1[0]<maxd2[0])?d1[0]:maxd2[0];	
	}else
	{ 
		mins=d1[0]+maxd2[1];
		for(int i=0;i<n-1;++i)
		{
			if(d1[i]+maxd2[i+1]<mins)
			{
				mins=d1[i]+maxd2[i+1];
			}
		}
		
		if(maxd2[0]<mins)
		{
			mins=maxd2[0];
		}
		if(d1[n-1]<mins)
		{
			mins=d1[n-1];
		}
	} 
	cout << mins;
	
//	cout << endl;
//	for(int i=0;i<n;++i)
//	{
//		cout << maxd2[i] << ' ';
//	}
//	
//	cout << endl;
//	for(int i=0;i<n;++i)
//	{
//		cout << d1[i] << ' ' << d2[i] << ' '<< x[i] << ' ' << y[i]<< endl;
//	}
//	
	return 0;
}
