#include <iostream>
#define maxSize 50
using namespace std;
typedef struct
{
	char *ch="ababaaababaa";
	int length=12;
}Str;
void getnext(Str substr,int next[])
{
	int i=1,j=0;
	next[1]=0;
	while(i<substr.length)
	{
		if(j==0||substr.ch[i]==substr.ch[j])
		{
			++i;
			++j;
			next[i]=j;
		}
		else
		{
			j=next[j];
		}
	}
}
int main()//²âÊÔÐ´µÄÓÐµã´Ö²Ú 
{
	Str str;
	int next[50];
	getnext(str,next);
	for(int i=1;i<14;i++)
	{
		cout << next[i] << ' ';
	}
	return 0;
}
