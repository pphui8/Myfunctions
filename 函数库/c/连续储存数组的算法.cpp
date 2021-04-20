# include <stdio.h>
# include <malloc.h>
# include <stdlib.h> 

struct Arr
{
	int * pBase;	//�����һ��Ԫ�صĵ�ַ 
	int len;	//���������ɵ����Ԫ�ظ��� 
	int cnt;	//��ǰ������ЧԪ�ظ��� 
};

void init_arr(struct Arr * pArr, int length);	//��ʼ������
bool append_arr(struct Arr * pArr, int val);	//׷��
bool insert_arr(struct Arr * pArr, int pos, int val);	//����/*��val���뵽pArr�еĵ�pos��*/ 
bool delete_arr(struct Arr * pArr, int pos);	//ɾ��/*ɾ��pArr�еĵ�pos��Ԫ��*/ 
bool is_empty(struct Arr * pArr);
bool is_full(struct Arr * pArr);
void sort_arr(struct Arr * pArr);	//���� 
void inversion_arr(struct Arr * pArr);	//���� 
void putout(struct Arr * pArr);		//��� 

int main()
{
	struct Arr arr;
	int val;
	
	init_arr(&arr,6);
	
	putout(&arr);
	
	printf("���룺"); 
	append_arr(&arr, 3);
	append_arr(&arr, 8);
	append_arr(&arr, -2);
	append_arr(&arr, 55);
	append_arr(&arr, 17);
	append_arr(&arr, -20);
	putout(&arr);
	
	printf("���ã�");
	inversion_arr(&arr);
	putout(&arr);
	
	printf("����");
	sort_arr(&arr);
	putout(&arr);
	
	printf("ɾ��(���ĸ�Ԫ��)��");
	delete_arr(&arr, 4);
	putout(&arr);
	
	printf("����(�ڶ���Ԫ�����77)��");
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
	if(is_full(pArr))	//�������� 
		return false;
	pArr->pBase[pArr->cnt] = val;	//��val�ӵ������ 
	(pArr->cnt)++;	//��Чֵ��һ 
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
	for(i=0; i<pArr->cnt; ++i)	//ð�ݷ� 
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
	for(i=pos; i<pArr->cnt; ++i)	//����Ԫ����ǰ��һλ 
	{
		pArr->pBase[i-1] = pArr->pBase[i];
	}
	pArr->cnt--;
	return true; 
}
