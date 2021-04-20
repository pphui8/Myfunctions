# include <stdio.h>
# include <malloc.h>
# include <stdlib.h> 

struct Arr
{
	int * pBase;	//数组第一个元素的地址 
	int len;	//数组能容纳的最大元素个数 
	int cnt;	//当前数组有效元素个数 
};

void init_arr(struct Arr * pArr, int length);	//初始化数组
bool append_arr(struct Arr * pArr, int val);	//追加
bool insert_arr(struct Arr * pArr, int pos, int val);	//插入/*把val插入到pArr中的第pos个*/ 
bool delete_arr(struct Arr * pArr, int pos);	//删除/*删除pArr中的第pos个元素*/ 
bool is_empty(struct Arr * pArr);
bool is_full(struct Arr * pArr);
void sort_arr(struct Arr * pArr);	//排序 
void inversion_arr(struct Arr * pArr);	//倒置 
void putout(struct Arr * pArr);		//输出 

int main()
{
	struct Arr arr;
	int val;
	
	init_arr(&arr,6);
	
	putout(&arr);
	
	printf("输入："); 
	append_arr(&arr, 3);
	append_arr(&arr, 8);
	append_arr(&arr, -2);
	append_arr(&arr, 55);
	append_arr(&arr, 17);
	append_arr(&arr, -20);
	putout(&arr);
	
	printf("倒置：");
	inversion_arr(&arr);
	putout(&arr);
	
	printf("排序：");
	sort_arr(&arr);
	putout(&arr);
	
	printf("删除(第四个元素)：");
	delete_arr(&arr, 4);
	putout(&arr);
	
	printf("插入(第二个元素添个77)：");
	insert_arr(&arr, 2, 77);
	putout(&arr);
	
	return 0;
}

void init_arr(struct Arr * pArr, int length)
{
	pArr->pBase = (int *)malloc(sizeof(int) * length);
	if(NULL == pArr->pBase)
	{
		printf("failed to get RAM\n");
		exit(-1);
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}
}

bool is_empty(struct Arr * pArr)
{
	if(0 == pArr->cnt)
		return true;
	else
		return false;
}

bool is_full(struct Arr * pArr)
{
	if(pArr->cnt == pArr->len)
		return true;
	else
		return false;
}

void putout(struct Arr * pArr)
{
	if(is_empty(pArr))
		printf("no available iterm\n");
	else
	{
		for(int i=0; i<pArr->cnt; ++i)
			printf("%d ",pArr->pBase[i]);
		printf("\n");
	}
}

bool append_arr(struct Arr * pArr, int val)
{
	if(is_full(pArr))	//数组已满 
		return false;
	pArr->pBase[pArr->cnt] = val;	//吧val加到数组后 
	(pArr->cnt)++;	//有效值加一 
	return true;
}

void inversion_arr(struct Arr * pArr)
{
	int i = 0;
	int j = pArr->cnt-1;
	int t;
	
	while(i<j)
	{
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		++i;
		--j;
	}
	return;
} 

void sort_arr(struct Arr * pArr)
{
	int i, j, t;
	for(i=0; i<pArr->cnt; ++i)	//冒泡法 
	{
		for(j=i+1; j<pArr->cnt; ++j)
		{
			if(pArr->pBase[i] > pArr->pBase[j])
			{
				t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			}
		}
	}
}

bool insert_arr(struct Arr * pArr, int pos, int val)
{
	int i;
	if(is_full(pArr))
		return false;
	if(pos<1 || pos>pArr->cnt+1)
		 return false; 
	for(i=pArr->cnt-1; i>=pos-1; --i)
	{
		pArr->pBase[i+1] = pArr->pBase[i];
	}
	pArr->pBase[pos-1] = val;
}

bool delete_arr(struct Arr * pArr, int pos)
{
	int i;
	if(is_empty(pArr))
		return false;
	if(pos<1 || pos>pArr->cnt)
		return false;
	for(i=pos; i<pArr->cnt; ++i)	//所有元素向前移一位 
	{
		pArr->pBase[i-1] = pArr->pBase[i];
	}
	pArr->cnt--;
	return true; 
}
