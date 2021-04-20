# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;

char a[100], b[100];
int a1[100], b1[100], c[100];

int main()
{
	int len = 0, tmp, add = 0, cp = 0;
	int alen, blen;
	gets(a);
	gets(b);
	alen = strlen(a);
	blen = strlen(b);
	if(alen > blen) {
		len = alen;
	}
	else len = blen;
	for(int i=0; i<alen; ++i) a1[i] = a[i] - 48;
	for(int i=0; i<blen; ++i) b1[i] = b[i] - 48;
	//cout<<len<<endl;
	//cout<<alen<<" "<<blen<<endl;
	alen-=1;
	blen-=1;
	for(int i = len - 1; i >= 0; --i) {
		int k1, k2;
		if(alen >= 0) k1 = a1[alen];
		else k1 = 0;
		if(blen >= 0) k2 = b1[blen];
		else k2 = 0;
		tmp = k1 + k2 + add;
		cout<<k1<<" "<<k2<<" ";
		cout<<add<<endl;
		if(tmp >= 10) {
			tmp-=10;
			add = 1;
		}
		else {
			add = 0;
		}
		c[cp] = tmp;
		cp++;
		alen--;
		blen--;
	}
	if(add == 1) cout<<'1';
	for(int i=len-1; i>=0; --i) {
		cout<<c[i];
	}
	cout<<endl;
	return 0;
}
