#include <iostream>
#define maxSize 1000010
using namespace std;
char str[maxSize];
int mark[maxSize];
char stack[maxSize];

int main()
{
	int left=0;//������������������ɨ�赽Ϊ�Ϸ������ٰ�����ֵ����mark 
	int total=0;
	int top=-1;
	int j=0;
	int max=0;
	int maxcnt=1;
	mark[0]=0;//�������鶼�ᱻ��Ϊ0 
	cin >> str;
//	cout << str;
	for(int i=0;str[i]!='\0';++i)
	{
		if(str[i]=='(')
		{
			stack[++top]=='(';
			left++;
		}
		else if(str[i]==')')
		{
			if(top>=0)
			{
				top--;
				left--;
				total+=2;
			}
			
			//��������Ѿ�Ϊ�վ�ֱ���жϣ������Ϊ�����ȳ�ջ���ж� 
			if(top==-1)//Ȼ���ж��Ƿ�Ϊ�� Ϊ����Ϊһ���Ϸ����� 
			{
				mark[j]=total;
				left=0;
				total=0;
				j++;
			}
		}
	}
	if(left!=0)
	{
		mark[j++]=0;
		mark[j++]=total;
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
