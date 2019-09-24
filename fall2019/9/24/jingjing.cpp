#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int num=0;
	int temp;
	for(int i=0;i<n;++i)
	{
		cin >> temp;
		num ^= temp;
	}
	cout << num;
	return 0;
}
