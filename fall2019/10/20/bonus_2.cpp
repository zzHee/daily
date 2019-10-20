#include <iostream>
#include <queue> 
#include <algorithm>
using namespace std;
struct Node{
	double pi;
	int father;
	int isleaf;
};
queue <int> aside;
queue <double> asidep;
Node num[10100];//存储父亲,路径概率,是否为叶节点 
int v[10000];
double rootp[10000];
int k=0; 
int searchroot(int c){
	if(c==1) return 1;
	if(num[c].father!=c)
		return 1;
	else return 0;
}
int main(){
	for(int i=0;i<10000;++i){
		num[i].pi=0;
		num[i].father=i;
		num[i].isleaf=-1;//-1表示未被定义 
	}
	int n;
	int a,b;
	int ra,rb;
	int temp;
	double pi;
	cin >> n;
	num[1].father=-1;
	for(int i=0;i<n-1;++i){
		cin >> a >> b >> pi;
		ra=searchroot(a);
		rb=searchroot(b);
		if(ra==1){
			num[a].isleaf=0;//0表示不是叶节点 
			if(num[b].isleaf==-1){
				num[b].isleaf=1;
			}
			num[b].father=a;
			num[b].pi=pi;//表示到父亲节点路径的概率 
		}else if(rb==1){
			temp=a;
			a=b;
			b=temp;
			num[a].isleaf=0;//0表示不是叶节点 
			if(num[b].isleaf==-1){
				num[b].isleaf=1;
			}
			num[b].father=a;
			num[b].pi=pi;//表示到父亲节点路径的概率 
		}else{
			aside.push(a);
			aside.push(b);
			asidep.push(pi);
		}
	}
	while(asidep.empty()!=1){
		a=aside.front();
		aside.pop();
		b=aside.front();
		aside.pop();
		pi=asidep.front();
		asidep.pop();
		ra=searchroot(a);
		rb=searchroot(b);
		
		if(ra==1){
			num[a].isleaf=0;//0表示不是叶节点 
			if(num[b].isleaf==-1){
				num[b].isleaf=1;
			}
			num[b].father=a;
			num[b].pi=pi;//表示到父亲节点路径的概率 
		}else if(rb==1){
			temp=a;
			a=b;
			b=temp;
			num[a].isleaf=0;//0表示不是叶节点 
			if(num[b].isleaf==-1){
				num[b].isleaf=1;
			}
			num[b].father=a;
			num[b].pi=pi;//表示到父亲节点路径的概率 
		}else{
			aside.push(a);
			aside.push(b);
			asidep.push(pi);
		}
	}
//	for(int i=1;i<n;++i)
//	{
//		cout << i << " ";
//		cout << num[i].father << " " << num[i].isleaf << " " << num[i].pi << endl; 
//	 } 
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
//	for(int i=0;i<k;i++)
//	{
//		cout << rootp[i] << " ";
//	}
	double out=0;
	for(int i=0;i<k;i++)
	{
		out += rootp[i]*v[i];
	}
	printf("%.10lf",out);
	return 0;
}

