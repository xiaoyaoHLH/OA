#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct Bitype{
	ElemType date;
	struct Bitype * lchild;
	struct Bitype * rchild;	
}BiTNode, *BiTree;

typedef struct queuenode{
	BiTree data;
	struct queuenode * next;
}QUEUENODE, *PQUEUENODE;

typedef struct queue{
	PQUEUENODE front;
	PQUEUENODE rear;
}LinkQueue, *QUEUE;

QUEUE init_queue(){
	QUEUE q;
	PQUEUENODE s;
	
	s = (PQUEUENODE)malloc(sizeof(QUEUENODE));
	q = (QUEUE)malloc(sizeof(LinkQueue));
	
	if(s == NULL){
		printf("error");
		exit(0);
	}else{
		q->front = s;
		q->rear = s;
		q->front->next = NULL;
		return q;
	}
	
}

int empty_queue(QUEUE q){
	if(q->front == q->rear){
		return 1;
	}
	
	return 0;
}

BiTree get_head(QUEUE q){
	if(!empty_queue(q))
	return q->front->next->data;
}

void en_queue(QUEUE q, BiTree t){
	PQUEUENODE s;
	
	s = (PQUEUENODE)malloc(sizeof(QUEUENODE));
	
	s->data = t;
	s->next = NULL;
	q->rear->next = s;
	q->rear = s;
}

void out_queue(QUEUE q){
	PQUEUENODE s;
	
	if(empty_queue(q)){
		exit(0);
	}else{
		s = q->front->next;
		q->front->next = s->next;
		
		if(s->next == NULL){
			q->rear = q->front;
		}
		
		free(s);
		
		
	}
}



BiTree Create_tree(){
	char c;
	BiTree T;
	
	scanf("%c", &c);
	
	if(c == '#'){
		T = NULL;
	}else{
		T = (BiTree)malloc(sizeof(BiTNode));
		if(T == NULL){
			exit(0);
		}
		
		T->date = c;
		T->lchild = Create_tree();
		T->rchild = Create_tree();
	}
	
	return T;	
}

void level_show(BiTree root){
	QUEUE q;
	BiTree t;
	
	q = init_queue();
	
	if(root == NULL){
		return;
	}else{
		en_queue(q, root);
		
		while(!empty_queue(q)){
			t = get_head(q);
			out_queue(q);
			
			printf("%c",t->date);
			
			if(t->lchild != NULL){
				en_queue(q, t->lchild);	
			} 
			
			if(t->rchild != NULL){
				en_queue(q, t->rchild);	
			}			
		}	
	}
	
}

int main(void){
	BiTree root;
	
	root = Create_tree();
	level_show(root);
	
	return 0;
}
