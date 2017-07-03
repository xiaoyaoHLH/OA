#include <stdio.h>
#include <malloc.h>

typedef struct Bitype{
	int data;
	struct Bitype * lchild;
	struct Bitype * rchild;
}BiNode, *BiTree;

BiTree insert_tree(BiTree T, int val){
	if(T == NULL){
		BiTree S;
		S = (BiTree)malloc(sizeof(BiNode));
		T = S;
		T->lchild = NULL;
		T->rchild = NULL;
		T->data = val;
		return T;
	}else if(val < T->data){
		insert_tree(T->lchild, val);
	}else if(val > T->data){
		insert_tree(T->rchild, val);
	}	
}


BiTree create_tree(){
	BiTree T = NULL;	
	int val;
	
	while((scanf("%d", &val)) && val != -1){
		T = insert_tree(T, val);
	}
	
	return T;
}

void display_tree(BiTree T){
	if(T == NULL){
		return;
	}else{
		display_tree(T->lchild);
		printf("%d ", T->data);
		display_tree(T->rchild);		
	}
}
int main(void){
	BiTree root;
	 
	root = create_tree();
	
	display_tree(root);
	
	
	
	return 0;
}
