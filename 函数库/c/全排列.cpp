#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int a[4] = {1, 2, 3, 4};
	do {
		for(int i = 0 ; i <4; ++i) cout<<a[i];
		cout<<endl;
	}while(next_permutation(a, a + 4));
	
	return 0;
}
