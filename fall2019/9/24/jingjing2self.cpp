#include <iostream>
#define maxSize 1000
using namespace std;
int main()
{
	int n;
	int res=0;
	int num[maxSize];
	cin >> n;
	for(int i=0;i<n;++i)
	{
		cin >> num[i];
		res ^= num[i];
	}
	int k=0;
	while((res^1)!=0)
	{
		++k;
		res >>= 1;
	}
	int res1=0;
	int res2=0;
	for(int i=0;i<n;++i)
	{
		if((num[i]>>k)==0)
		{
			res1 ^= num[i];
		}
		else
		{
			res2 ^= num[i];
		}
	}
	cout << res1 << " " << res2 << endl;
	return 0;
} 
