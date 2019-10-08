#include <iostream>
using namespace std;
int num[501000];
int main()
{
	int n;
	int temp;
	int flag=0;
	__int64 cnt=0;;
	scanf("%d\n",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&num[i]);
	}
	for(int i=0;i<n;++i)
	{
		flag=0;
		for(int j=0;j<n-1;++j)
		{
			if(num[j]>num[j+1])
			{
				temp=num[j];
				num[j]=num[j+1];
				num[j+1]=temp;
				cnt++;
				flag=1;
			}
		}
		if(flag==0) break;
	}
	printf("%I64d",cnt);
	return 0;
}
