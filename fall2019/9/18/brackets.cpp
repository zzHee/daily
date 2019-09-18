#include <iostream>
#define maxSize 1000010
using namespace std;
char str[maxSize];
int mark[maxSize];
char stack[maxSize];

int main()
{
	int temp=0;//先用这个变量储存个数扫描到为合法序列再把他的值赋给mark 
	int top=-1;
	int j=0;
	int max=0;
	int maxcnt=1;
	mark[0]=0;//整个数组都会被赋为0 
	cin >> str;
//	cout << str;
	for(int i=0;str[i]!='\0';++i)
	{
		if(str[i]=='(')
		{
			stack[++top]=='(';
			temp++;
//			mark[j]++;
//			cout << '*';
		}
		else if(str[i]==')')
		{
			if(top>=0)
			{
				top--;
				temp++;
//				mark[j]++;
			}
			
			//如果数组已经为空就直接判断，如果不为空则先出栈再判断 
			if(top==-1)//然后判断是否为空 为空则为一个合法序列 
			{
				mark[j]=temp;
				temp=0;
				j++;
			}
		}
	}
//	for(int i=0;i<j+1;i++)
//	{
//		cout << mark[i] << ' ';
//	}
//	cout << endl;
	for(int i=1;i<j+1;++i)
	{
		if(mark[i]!=0)
		{
			mark[i]=mark[i]+mark[i-1];
		}
	}
	
	for(int i=0;i<j+1;++i)
	{
		if(mark[i]==max)
		{
			maxcnt++;
		}
		else if(mark[i]>max)
		{
			max=mark[i];
			maxcnt=1;
		}
	}
	if(max==0)
	{
		cout << 0 << endl;
		cout << 1 << endl; 
	}
	else
	{
		cout << max << endl;
		cout << maxcnt << endl;
	}

//	for(int i=0;i<j+1;i++)
//	{
//		cout << mark[i] << ' ';
//	}
//	cout << endl;
	return 0;
}
