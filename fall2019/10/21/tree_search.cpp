#include <iostream>
#include <queue>
using namespace std;
struct Node{
	int data;
	int left;
	int right;
};
int order[10000];
int k=0;
Node tree[10100];
Node *root=NULL;
Node *addnode(int l,int in,int r){
	if(root==NULL){
		tree[in].data=in;
		tree[in].left=l;
		tree[in].right=r;
		root=&tree[in];
	}else{
		tree[in].data=in;
		tree[in].left=l;
		tree[in].right=r;
		if((l!=-1&&tree[l].data!=-1)||(r!=-1&&tree[r].data!=-1)){
			root=&tree[in];
		}
	}
	return root;
}
void inorder(Node *r){
	if(r->left!=-1)inorder(&tree[r->left]);
	order[k++]=r->data;
	if(r->right!=-1)inorder(&tree[r->right]);
}
bool isBST(Node *root){
    inorder(root);
//    for(int i=0;i<k;++i)
//    {
//    	cout << order[i] << " ";
//	}
    for(int i=0;i<k-1;++i){
    	if(order[i]>=order[i+1])
    	{
    		return false;
		}
	}
	return true;
}
int deep(Node *root){
	queue <int> q;
	queue <int> d;
	q.push(root->data);
	d.push(1);
	int max=1;
	int tempd,tempq;
	while(q.empty()!=1){
		tempd=d.front();
		d.pop();
		tempq=q.front();
		q.pop();
		if(tree[tempq].left!=-1){
			q.push(tree[tempq].left);
			d.push(tempd+1);
		}
		if(tree[tempq].right!=-1){
			q.push(tree[tempq].right);
			d.push(tempd+1);
		}
		if(tempd>max){
			max=tempd;
		}
	}
	return max;
}
int main(){
	int n;
	int left,in,right;
	int temp;
	cin >> n;
	for(int i=0;i<n;++i){
		tree[i].data=-1;//表示未被连接到树当中 
	}
	for(int i=0;i<n;++i){
		cin >> left >> in >> right;
		root=addnode(left,in,right);
	}
//	inorder(root);
//    
//	for(int i=0;i<k;++i){
//    	cout << order[i] << " ";
//	}
	if(isBST(root)){
		cout << deep(root);
	}else{
		cout << "-1";
	}
	return 0;
}
