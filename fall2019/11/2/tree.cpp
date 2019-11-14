#include<iostream>
#include <vector>
using namespace std;
const int MAXN = 1e5 + 5;
int  d[MAXN];//�������
vector<int>edge[MAXN];
void dfs(int x,int o)
{
    d[x]=o;
    for(int i=0;i<edge[x].size();i++)
        dfs(edge[x][i],o+1);//ÿ��һ����ȼ�һ
}
int main()
{
    int n,k,x,s;
    cin>>n;
    s=(n+1)*n/2;
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        while(k--)
        {
            cin>>x;
            s-=x;//Ѱ�����
            edge[i].push_back(x);
        }
    }
    dfs(s,1);
    s=0;//��¼�������
    for(int i=1;i<=n;i++)
        if(d[s]<d[i])
            s=i;
    cout<<s<<endl;
    return 0;
}

