#include <iostream>
#define maxSize 101000
using namespace std;
int tree[maxSize]={0};
int arr[maxSize];
void build_tree(int arr[],int tree[],int node,int start,int end){
	if (start == end){
		tree[node] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	int left_node = 2 * node + 1;
	int right_node = 2 * node + 2;
	
	build_tree(arr, tree, left_node, start, mid);
	build_tree(arr, tree, right_node, mid+1, end);
	tree[node] = tree[left_node] + tree[right_node];
}
int query_tree(int arr[], int tree[], int node, int start, int end, int L, int R) {
	if(R < start || L > end) {
		return 0;
	}
	else if(start == end) {
		return tree[node]; 
	}
	else{
		int mid = (start + end) / 2;
		int left_node = 2 * node + 1;
		int right_node = 2 * node + 2;
		
		int sum_left = query_tree(arr, tree, left_node, start, mid, L, R);
		int sum_right = query_tree(arr, tree, right_node, mid+1, end, L, R);
		return sum_left + sum_right;
	}
}
void update_tree(int arr[], int tree[], int node, int start, int end ,int idx, int val) {
	if(start == end) {
		arr[idx] += val;
		tree[node] += val;
		return;
	}
	int mid = (start + end) / 2;
	int left_node = 2 * node + 1;
	int right_node = 2 * node + 2;
	
	if(idx >= start && idx <= mid) {
		update_tree(arr, tree, left_node, start, mid, idx, val);
	}
	else {
		update_tree(arr, tree, right_node, mid+1, end, idx, val);
	}
	tree[node] = tree[left_node] + tree[right_node];
}
int main(){
	int n,m;
	cin >> n >> m;
	for(int i=0; i<n; ++i){
		cin >> arr[i];
	}
	build_tree(arr, tree, 0, 0, n-1);
//	for(int i = 0; i < 15; ++i) {
//		cout << i << " " << tree[i] << endl;
//	}
	char lab;
	int l,r,x;
	for(int i = 0; i < m; ++i) {
		cin >> lab;
		if(lab == 'Q') {
			cin >> l >> r;
			cout << query_tree(arr, tree, 0, 0, n-1, l-1, r-1) << endl;
		}
		else if(lab == 'C') {
			cin >> l >> r >> x;
			for(int i = l; i <= r; ++i) {
				update_tree(arr, tree, 0, 0, n-1, i-1, x);	
			}
		}
	}
	return 0;
} 
