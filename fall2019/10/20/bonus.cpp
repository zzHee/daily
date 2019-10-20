#include <iostream>
#include <algorithm>
using namespace std;
struct Node{
	double pi;
	int father;
	int isleaf;
};
Node num[10100];//存储父亲,路径概率
int v[10000];
double rootp[10000];
int k=0; 
int main(){
	for(int i=0;i<10000;++i){
		num[i].pi=0;
		num[i].father=i;
		num[i].isleaf=-1;//-1表示未被定义 
	}
	int n;
	int a,b;
	double pi;
	cin >> n;
	num[1].father=-1;
	for(int i=0;i<n-1;++i){
		cin >> a >> b >> pi;
		num[a].isleaf=0;//0表示不是叶节点 
		if(num[b].isleaf==-1){
			num[b].isleaf=1;
		}
		num[b].father=a;
		num[b].pi=pi;//表示到父亲节点路径的概率 
	}
	for(int i=0;i<n;++i){
		cin >> v[i];
	}
	sort(v,v+n);
	for(int i=1;i<n+1;i++){
		int j=i;
		if(num[j].isleaf==1){
			double tp=1;
			while(num[j].father!=-1)
			{
				tp*=num[j].pi;
				j=num[j].father;
			}
			rootp[k++]=tp;
		}
	}
	sort(rootp,rootp+k,greater<double>());
	double out=0;
	for(int i=0;i<k;i++)
	{
		out += rootp[i]*v[i];
	}
	printf("%.10lf",out);
	return 0;
}

