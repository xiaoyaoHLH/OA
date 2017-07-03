#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node * pNext;
}NODE, *PNODE;

PNODE create_list();
void traverse(PNODE);
bool insert(PNODE, int, int);
bool delete_val(PNODE, int, int *);
bool is_empty(PNODE);
int length_list(PNODE);
void sort_list(PNODE);

bool insert_one(PNODE pHead, int len, int coef){
	PNODE Tail = pHead;
	int i;
	
	for(i = 0; i < len; i++){
		Tail = Tail->pNext;
	}
	
	PNODE pNew = (PNODE) malloc(sizeof(NODE));
	pNew->data = coef;
	Tail->pNext = pNew;
	pNew->pNext = NULL;
	Tail = NULL;
	
	return true;	
}


int main(void){
	PNODE pHead;
	int  p;
	
	pHead = create_list();
	
//	delete_val(pHead, 2, &p);
	
//	printf("%d", length_list(pHead)); 
	
	insert_one(pHead, length_list(pHead), 3);

	traverse(pHead);

	return 0;
}

PNODE create_list(void){
	int val, len, i;
	
	PNODE pHead = (PNODE) malloc(sizeof(NODE));
	if(NULL == pHead){
		printf("pHead false of create!");
		exit(-1);
	}
	
	PNODE Tail = pHead;
	pHead->pNext = NULL;
	
	printf("Please enter length:");
	scanf("%d", &len);
	
	for(i = 0; i < len; i++){
		PNODE pNew = (PNODE) malloc(sizeof(NODE));
		
		if(NULL == pNew){
		printf("pNew false of create!");
		exit(-1);
		}
		
		printf("Please enter %d value:", i+1);
		scanf("%d", &val);
		
		pNew->data = val;
		Tail->pNext = pNew;
		pNew->pNext = NULL;
		Tail = pNew;
		
	}	
	
	return pHead;
}

void traverse(PNODE pHead){
	PNODE t;
	
	t = pHead->pNext;
	
	while(t != NULL){
		printf("%d ", t->data);
		t = t->pNext;
	}
	
	return;	
}

bool is_empty(PNODE P){
	if(NULL == P){
		return true;
	}
	
	return false;
}

int length_list(PNODE pHead){
	int count = 0;
	PNODE p = pHead->pNext;
	
	while(!(is_empty(p))){
		p = p->pNext;
		count++;
	}
	
	return count;
}



void sort_list(PNODE pHead){
	PNODE sign1,sign2;
	int i, j, teml;
	int len = length_list(pHead);
	
	for(sign1 = pHead->pNext; i < len - 1; sign1 = sign1->pNext)
		for(sign2 = sign1->pNext; j < len; sign2 = sign2->pNext)
			if(sign1->data < sign2->data){
				teml = sign1->data;
				sign1->data = sign2->data;
				sign2->data = teml;
			}
	
	return;
}

bool insert(PNODE pHead, int pos, int val){
	PNODE p = pHead;
	PNODE q;
	int i = 0;
	
	while(p != NULL && i < pos-1){
		p = p->pNext;
		i++;
	}
	
	if(i > pos-1 || NULL == p)
		return false;
		
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
	
	q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;
	
	return true;	
}

bool delete_val(PNODE pHead, int pos, int * pVal){
	int i = 0;
	PNODE p = pHead;

	while (NULL!=p->pNext && i<pos-1)
	{
		p = p->pNext;
		++i;
	}

	if (i>pos-1 || NULL==p->pNext)
		return false;
	
	//如果程序能执行到这一行说明p已经指向了第pos-1个结点，并且第pos个节点是存在的
	PNODE q = p->pNext;  //q指向待删除的结点
	*pVal = q->data;  

	//删除p节点后面的结点
	p->pNext = p->pNext->pNext;
	
	//释放q所指向的节点所占的内存
	free(q);
	q = NULL;
	
	return true;
	
}










