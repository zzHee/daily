//串的基本操作
#include <iostream>
#include <stdlib.h> 
using namespace std;
typedef struct
{
	char *ch;
	int length;
}Str;
// 字符串初始化 
int strassign(Str& str,char *ch)
{
	if(str.ch)
		free(str.ch);
	int len=0;
	//求原ch数组的长度 
	char *c=ch;
	while(*c)
	{
		++len;
		++c;
	}
	
	if(len==0)
	{
		str.ch=NULL;
		str.length=0;
		return 1;
	}
	else
	{
		str.ch=(char *)malloc(sizeof(char)*(len+1));
		//空间分配失败处理
		if(str.ch==NULL)
		{
			return 0;
		}
		else
		{
			c=ch;
			for(int i=0;i<=len;++i,++c)
			{
				str.ch[i]=*c;
			}
			str.length=len;
			return 1;
		} 
	}
}
//取串长度操作
int strlength(Str str)
{
	return str.length;
}
//串比较操作 
int strcompare(Str s1,Str s2)
{
	for(int i=0;i<s1.length && i<s2.length;++i)
	{
		if(s1.ch[i]!=s2.ch[i])
		{
			return s1.ch[i]-s2.ch[i];
		}
	}
	return s1.length=s2.length;
}
//串连接操作
int concat(Str& str,Str s1,Str s2)
{
	if(str.ch)
	{
		free(str.ch);
		str.ch=NULL;
	}
	str.ch=(char *)malloc(sizeof(char)*(s1.length+s2.length+1));
	if(str.ch==NULL)
	{
		return 0;
	}
	int i=0;
	while(i<s1.length)
	{
		str.ch[i]=s1.ch[i];
		++i;
	}
	int j=0;
	while(j<=s2.length)//这里用<=直接把最后的结束标志一起复制进去了 
	{
		str.ch[i+j]=s2.ch[j];
		++j;
	}
	str.length=s1.length+s2.length;
	return 1; 
}
//求子串操作
int substring(Str& substr,Str str,int pos,int len)
{
	if(pos<0||pos>str.length||len<0||len+pos>str.length)
	{
		return 0;
	}
	if(substr.ch)
	{
		free(substr.ch);
		substr.ch=NULL;
	}
	if(len==0)
	{
		substr.ch=NULL;
		substr.length=0;
		return 1;
	}
	else
	{
		substr.ch=(char *)malloc(sizeof(char)*(len+1));
		int i=pos;
		int j=0;
		while(i<pos+len)
		{
			substr.ch[j]=str.ch[i];
			++i;
			++j;
		}
		substr.ch[j]='\0';
		substr.length=len;
		return 1;
	}
}
//串清空操作
int clearstr(Str &str)
{
	if(str.ch)
	{
		free(str.ch);
		str.ch=NULL;
	}
	str.length=0;
	return 1;
 } 
int main()
{
	//新建串的时候要给他赋初值，不然在后面的赋值操作里面会出错 
	Str str;
	str.ch=NULL;
	str.length=0;
	Str s1,s2; 
	s1.ch=NULL;
	s1.length=0;
	s2.ch=NULL;
	s2.length=0;
	strassign(str,"hello world");
	strassign(s1,"hello");
	strassign(s2,"world");
	cout << str.ch << endl;
	concat(str,s1,s2);
	cout << s1.ch << endl;
	clearstr(str);
	cout << s2.ch << endl;
	
	return 0;
	 
} 
