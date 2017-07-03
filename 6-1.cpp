#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct Bitype{
	ElemType date;
	struct Bitype * lchild;
	struct Bitype * rchild;	
}BiTNode, *BiTree;

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

void pre_show(BiTree root){
	if(root == NULL){
		return;
	}
	
	printf("%c", root->date);
	pre_show(root->lchild);
	pre_show(root->rchild);	
}

void middle_show(BiTree root){
	BiTree p, stack[100];
	int top = 0;
	
	if(root == NULL){
		return;
	}
	
	p = root;
	
	while(!(p == NULL && top == 0)){	
		while(p != NULL){
			if(top < 100-1){
				stack[top] = p;
				top++;
			}else{
				printf("Õ»Òç³ö");
				return; 
			}
			
			p = p->lchild;
			 
		}
		
		if(top <= 0){
			return;
		}else{
			top--;
			p = stack[top];
			printf("%c", p->date);
			p = p->rchild;
		}	
	}	
}

void post_show(BiTree root){
	if(root == NULL){
		return;
	}
	
	post_show(root->lchild);
	post_show(root->rchild);
	printf("%c", root->date);	
}

int main(void){
	BiTree root;
	
	root = Create_tree();
	
	pre_show(root);
	printf("\n");
	middle_show(root);
	printf("\n");
	post_show(root);
	
	return 0;

}
