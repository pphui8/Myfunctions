# include <stdio.h>

void hui(int *n, int cnt);

int main()
{
	int n[5];
	for(int i=0; i<5; ++i){
		scanf("%d",&n[i]);
	}
	hui(n, 5);
	for(int i=0; i<5; ++i){
		printf("%d ",n[i]);
	}
	
	return 0;
}

void hui(int *n, int cnt)
{
	for(int i=0; i<cnt-1; ++i){
		for(int j=0; j<cnt-1-i; ++j){
			if(n[j]>n[j+1]){
				int k = n[j];
				n[j] = n[j+1];
				n[j+1] = k;
			}
		}
	}
	return;
}
