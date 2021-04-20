# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;

char a1[100], b1[100];
int a[100], b[100], c[100];
int is_neg(int, int, int*, int*);

int main()
{
	int len, alen, blen, sub = 0, tmp;
	int k1, k2, i1 = 0;
	gets(a1);
	gets(b1);
	alen = strlen(a1);
	blen = strlen(b1);
	if(alen > blen) len = alen;
	else len = blen;
	for(int i=alen-1; i>=0; --i) a[i] = a1[i] - 48;
	for(int i=blen-1; i>=0; --i) b[i] = b1[i] - 48;
	if(is_neg(alen, blen, a, b) == -1) {	//为正数 
		alen--;
		blen--;
		for(int i=len-1; i>=0; --i) {
			if(alen >= 0) k1 = a[alen];
			else k1 = 0; 
			if(blen >= 0) k2 = b[blen];
			else k2 = 0;
			tmp = k1 - k2 - sub;
			if(tmp < 0) {	//要借一 
				tmp = 10 - tmp;
				sub = 0;
			}
			else sub = 0;
			c[i1] = tmp;
			i1++;
			alen--;
			blen--;
		}
	}
	else if(is_neg(alen, blen, a, b) == 1) {	//为负数 
		cout<<'-';
		alen--;
		blen--;
		for(int i=len-1; i>=0; --i) {
			if(alen >= 0) k2 = a[alen];
			else k2 = 0; 
			if(blen >= 0) k1 = b[blen];
			else k1 = 0;
			tmp = k1 - k2 - sub;
			if(tmp < 0) {	//要借一 
				tmp = 10 - tmp;
				sub = 0;
			}
			else sub = 0;
			c[i1] = tmp;
			i1++;
			alen--;
			blen--;
		}
		
	}
	else {
		cout<<'0'<<endl;
		return 0;
	}
	bool is_val = true; 
	for(int i=i1-1; i>=0; --i) {
		if(c[i] == 0 && is_val) continue;
		else {
			cout<<c[i];
			is_val = false;
		} 
	}
	cout<<endl;
	return 0;
}

int is_neg(int alen,int blen, int* a, int* b)
{
	if(alen > blen) return -1;
	else if(alen < blen) return 1;
	else {
		for(int i=0; i<alen; ++i) {
			if(a[i] == b[i]) continue;
			else if(a[i] > b[i]) return -1;
			else return 1;
		}
		return 0;
	}
}
