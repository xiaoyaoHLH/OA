#include <stdio.h> 
#include <stdlib.h>
#include <malloc.h>

int count = 0;

typedef struct Node{
	int data;
	struct Node * pnext;
}NODE, *PNODE;

PNODE create_list(void){
	int val, i;
	
	PNODE pHead  = (PNODE) malloc (sizeof(NODE));
	
	if(pHead == NULL){
		printf("pHead false of create!");
		exit(-1);	
	}
	
	PNODE Tail = pHead;
	pHead->pnext = NULL;
			
	while(scanf("%d", &val) && val != -1){
		PNODE pNew = (PNODE) malloc (sizeof(NODE));
		
		if(pNew == NULL){
		printf("pHead false of create!");
		exit(-1);	
		}
		
		pNew->data = val;
		Tail->pnext = pNew;
		pNew->pnext = NULL;
		Tail = pNew;	
	}
	
	return pHead;
}

int max(int x, PNODE p){
	if(NULL == p){
		return count;
	}else{
		if(x < p->data){
			x = p->data;
		}
		p = p->pnext;
		 max(x, p);
	}	
}
int length_list(PNODE p){
	if(NULL == p){
		return count;
	}else{
		p = p->pnext;
		count++;
		length_list(p);
	}	
}

int avg(PNODE p, int sum=0){
	if(NULL == p){
		return sum/length_list(p);
	}else{
		sum += p->data;
		p = p->pnext;
		avg(p);
	}	
}

int main(void){
	int count;
	PNODE pHead;
	pHead = create_list();
	PNODE p;
	p = pHead->pnext;
	
	
	printf("%d\n%d\n%d", max(-99999,p), length_list(p), avg(p));
	return 0;
}	
