# include <iostream>
using namespace std;

int num[1000005],n;

void quicksort(int low, int high);

int main()
{
	cin>>n;
	for(int i=0; i<n; ++i) cin>>num[i];
	quicksort(0, n-1);
	for(int i=0; i<n; ++i) cout<<num[i]<<' ';
	
	return 0;
}

void quicksort(int low, int high)
{
	if(low >= high) return;
	int l = low, r = high;
	int tmp = num[low];
	while(l < r){
		while(l < r && num[r] >= tmp) r--;
		if(l < r) num[l] = num[r],l++;
		while(l < r && num[l] < tmp) l++;
		if(l < r) num[r] = num[l],r--;
	}
	num[l] = tmp;
	quicksort(low, l-1);
	quicksort(l+1, high);
	
	return;
}
