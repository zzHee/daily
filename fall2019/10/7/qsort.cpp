#include <iostream>
using namespace std;
void QuickSort(int R[],int low,int high)
{
	int temp;
	int i=low,j=high;
	if(low<high)
	{
		temp=R[low];
		while(i<j)
		{
			while(j>i&&R[j]>=temp) --j;
			if(i<j)
			{
				R[i]=R[j];
				++i;
			}
			while(i<j&&R[i]<temp) ++i;
			
			if(i<j)
			{
				R[j]=R[i];
				--j;
			}
		}
		R[i]=temp;
		QuickSort (R,low,i-1);
		QuickSort (R,i+1,high);
	}
}
int main()
{
	int a[]={44,2,65,3,5,2,6,8,43};
	QuickSort(a,0,8);
	for(int i=0;i<9;++i)
	{
		cout << a[i] << ' ';
	}
	return 0;
}
