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

int height_tree(BiTree root){
	int l_count;
	int r_count;
	
	if(root == NULL){
		return 0;
	}else{
		l_count = height_tree(root->lchild);
		r_count = height_tree(root->rchild);
		
		if(l_count > r_count){
			return 1+l_count;
		}else{
			return 1+r_count;
		}
		
	}
}

int width_tree(BiTree root){
	int static width[30] = {0};
	int static floor;
	int static max = 0;
	int static value = 0;
	
	if(root){
		floor++;
		width[floor]++;
		value = width[floor];
		
		if(max < width[floor]){
			max = width[floor];
		}
		
		width_tree(root->lchild);
		width_tree(root->rchild);
		
		floor--;
		
		return max;
	}
	
	return 0;
	
}


int main(void){
	BiTree root;
	root = Create_tree();
	int h, w; 
	h = height_tree(root);
	w = width_tree(root);
	printf("%d %d", h, w);
	
	return 0;
}
