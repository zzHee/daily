#include <iostream>
using namespace std;

void dell(Str &str,char ch)
{
	if(str.length!=0)
	{
		int sum=0;
		int i;
		int j;
		for(i=0;i<str.length;++i)
		{
			if(str.ch[i]==ch)
			{
				++sum;
			}
		}
		if(sum!=0)
		{
			char *temp_ch=(char *)malloc(sizeof(char) * str.length-sum+1); //多1存什么你应该知道吧
			for(i=0,j=0;i<str.length;++i)
			{
				if(str.ch[i]!=ch)
				{
					temp_ch[j++]=str.ch[i];
				}
			} 
			temp_ch[j]='\0';
			str.length=str.length-sum;
			free(str.ch);
			str.ch=temp_ch;
		}
	}
} 
