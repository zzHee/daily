#include <iostream>
#include <stack>
#define maxSize 100010
using namespace std;
int num[maxSize];
int order[maxSize];
int *post;//�������� 
int main()
{
	int n;
	int pmax=0;
	int j=0;//������־ 
	int a;//��ʱ�洢pop�����ı���
	int k=0;//order����β��� 
	cin >> n;
	stack <int> s;
	for(int i=0;i<n;++i)
	{
		cin >> num[i];
	}
	post=&(num[j]);
	pmax=num[j];
	for(int i=0;post[i]!='\0';++i)
	{
		if(post[i]>pmax)
		{
			pmax=post[i];
		}
	}
	while(true)
	{
		if(num[j]=='\0'&&s.empty()==1)
		{
			break;
		}
		while(s.empty()==1 || pmax>s.top())
		{
			s.push(num[j++]);
			post=&(num[j]);
			pmax=num[j];
			for(int i=0;post[i]!='\0';++i)
			{
				if(post[i]>pmax)
				{
					pmax=post[i];
				}
			}
		}
		a=s.top();
		s.pop();
		order[k++]=a;
	}
	int temp=0;
	for(int i=0;i<k;i++)
	{
		if(++temp==1)
		{
			cout << order[i];
		}
		else
		{
			cout << ' ' << order[i];
		}
	}
//	cout << endl;
	return 0;
} 
