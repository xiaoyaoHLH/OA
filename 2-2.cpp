#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int QueueElementType;

typedef struct Node{
	QueueElementType data;
	struct Node * pNext;
}NODE, *PNODE;

typedef struct queue{
	PNODE front;
	PNODE rear;
}LINKQUEUE;

LINKQUEUE init_queue(){
	LINKQUEUE Q;
	PNODE p;
	p = (PNODE)malloc(sizeof(NODE));
	
	if(p = NULL){
		printf("初始化失败");
		exit(0);
	}
	
	Q.front = p;
	Q.rear = p;
	Q.front->pNext = NULL;
	
	return Q;
}

int is_empty(LINKQUEUE Q){
	if(Q.front == Q.rear){
		return 1;
	}
	
	return 0;
}

LINKQUEUE en_queue(LINKQUEUE Q, QueueElementType x){
	PNODE p;
	p = (PNODE)malloc(sizeof(NODE));
	
	if(p = NULL){
		printf("初始化失败");
		exit(0);
	}
	
	p->data = x;
	p->pNext = NULL;
	Q.rear->pNext = p;
	Q.rear = p;
	
}

LINKQUEUE de_queue(LINKQUEUE Q, QueueElementType * e){
	PNODE p;
	
	if(is_empty(Q)){
		printf("队空");
		exit(0);
	}
	
	p = Q.front->pNext;
	*e = p->data;
	Q.front->pNext = p->pNext;
	
	if(Q.rear == p){
		Q.front = Q.rear;
	}
	
	free(p);
	
	return Q;
}

QueueElementType get_head(LINKQUEUE Q){
	if(is_empty(Q)){
		printf("队空");
		exit(0);	
	}
	
	return Q.front->pNext->data;
}

int main(void){
	
	
	
	return 0;
}
