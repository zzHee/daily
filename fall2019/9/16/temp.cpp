#include <iostream>
#include <stdlib.h>
#include <ctype.h>
using namespace std;
typedef struct Node
{
	char data;
	struct Node *next;
}Node;
void push(Node *lst,char x)
{
	Node *p;
	p=(Node *)malloc(sizeof(Node));
	p->data=x;
	
	p->next=lst->next;
	lst->next=p;
}
int pop(Node *lst,char &x)
{
	if(lst->next==NULL)
		return 0;
	Node *p;
	p=lst->next;
	x=p->data;
	lst->next=p->next;
	free(p);
	return 1;
}
void cal(char *str,int l)
{
	Node *head;
	head=(Node *)malloc(sizeof(Node));
	head->next=NULL;
	Node *p=head;
	char a,b;
	for(int i=0;i<l;i++)
	{
		if(isdigit(str[i]))
		{
			push(p,str[i]);
		}
		if(ispunct(str[i]))
		{
			pop(p,b);
			pop(p,a);  //首先出栈的是第二操作数 
			if(str[i]=='+')
			{
				push(p,a+b-'0');
			}else if(str[i]=='-')
			{
				push(p,a-b+'0');
			}else if(str[i]=='*')
			{
				push(p,(a-'0')*(b-'0')+'0');
			}else if(str[i]=='/')
			{
				if(b-'0'==0)
				{
					cout << "ERROR" << endl;
					return;
				}
				else
				{
					push(p,(a-'0')/(b-'0')+'0');
				}
			}
		}
	}
	char f;
	pop(p,f);
	cout << f-'0' << endl;
}
int main()
{
	cal("2312+*+",7);//答案应该为11 
	return 0;
}
