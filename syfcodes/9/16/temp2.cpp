#include <iostream>
#define maxSize 100
using namespace std;
int op(int a,char Op,int b)
{
	if(Op=='+') return a+b;
	if(Op=='-') return a-b;
	if(Op=='*') return a*b;
	if(Op=='/')
	{
		if(b==0)
		{
			cout << "ERROR" << endl;
		}
		else
		{
			return a/b;
		}
	}
}
int com(char exp[])
{
	int i,a,b,c;
	int stack[maxSize];
	int top=-1;
	char Op;
	for(i=0;exp[i]!='\0';++i)
	{
		if(exp[i]>='0'&&exp[i]<='9')
		{
			stack[++top]=exp[i]-'0';
		}
		else
		{
			Op=exp[i];

			b=stack[top--];
			a=stack[top--];
			c=op(a,Op,b);
			stack[++top]=c;

		}
	}
	return stack[top];
}
int main()
{
	char a[]="2312+*+";
	cout << com(a) << endl;//答案应该为11 
	return 0;
}
