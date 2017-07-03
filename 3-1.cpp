#include <stdio.h>

typedef struct BiNode{
	char data;
	struct BiNode * lchild;
	struct BiNode * rchile;
}Tree, *PTree;


void create(root);
void insertL(root, x, parent);
void insertR(root, x, parent);
void deleteL(root, parent);
void deleteR(root, parent);

void NRPreOrder(PTree root){
	PTree p, stack[100];
	int top = 0;
	
	if(root == NULL){
		return;
	}	
	
	p = root;
	
	while(!(p == NULL && top == 0)){
		while(p != NULL){
			printf("%c", )
		}
		
		
	}
	
	
}

int main(void){
	
	
	
	
	return 0;
}
