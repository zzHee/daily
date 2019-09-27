#include <iostream>
#include <string>
#include <queue> 
using namespace std;

	queue <int> aq[100010];
	int mark[100010]={0};
int main()
{	
	int j=1;
	string temp;
	int a,b;
	while(cin >> temp)
	{
		if(temp == "END")
		{
			break;
		}
		else
		{
			cin >> a >> b;
			if(mark[b]==0)
			{
				aq[j].push(a);
				mark[b]=j++;
			}
			else
			{
				aq[mark[b]].push(a);
			}
		} 
	}
	int k=0;
	int order[100010];
	for(int i=0;i<j;++i)
	{
		while(aq[i].empty()!=1)
		{
			order[k++]=aq[i].front();
			aq[i].pop();
		}
	}
	int t=0;
	for(int i=0;i<k;++i)
	{
		if(++t==1)
		{
			cout << order[i];
		}
		else
		{
			cout << " " << order[i] ;
		}
	}
	return 0;
}
