#include<stdio.h>
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
const int N=3000005;
int a[N];
int main()// 除了一个数只出现一次以外，其他数都出现了两次。你要做的就是找出只出现一次的数。
{
    int n;
    scanf("%d",&n);
    int res=0;
    int i;
    for(i=1;i<=n;i++)
    {
    scanf("%d",&a[i]);
    res^=a[i];
    }
    int k=0;
    while((res&1)==0)
    k++,res>>=1;

    int res1=0,res2=0;
    for(i=1;i<=n;i++)
    {
        if((a[i]>>k)&1)
        res1^=a[i];
        else
        res2^=a[i];
    }
    printf("%d %d\n",min(res1,res2),max(res1,res2));
    return 0;
}
