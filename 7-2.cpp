#include <stdio.h>
#include <stdlib.h>
#define MAX_V_NUM 20

int visited[MAX_V_NUM];  //���ڱ�Ǹýڵ��Ƿ񱻷��ʣ��ѱ�����Ϊ1��δ����Ϊ0 

typedef struct EdgeNode{  //��֧�ڵ� 
	int adjvex;           //ָ��ڵ���±� 
	struct EdgeNode * nextTarc;   //ָ���¸��ڵ��ָ�� 
}ARENODE, *PARENODE;

typedef struct VNode{  //ͷ�ڵ� 
	int data;      //������Ϣ
	PARENODE firstarc; //ָ���һ�������ڵ� 	
}VNODE, AdjList[MAX_V_NUM];

typedef struct Graph{
	AdjList vertex;
	int vexnum, arcnum; //�ڵ����ͱ��� 
}Graph,*GraphAdjList;

typedef struct Stack{
	int data;
	struct Stack * next;
}GraphStack, *SqStack;

SqStack init_stack(void){
	SqStack top;
	top = NULL;
	
	return top;
}

int empty_stack(SqStack S){
	if(S == NULL){
		return 1; 
	} 
	
	return 0;
}

SqStack push_stack(SqStack S, int i){
	SqStack t;
	t = (SqStack)malloc(sizeof(GraphStack));
	
	if(t == NULL){
		printf("��ջʧ��");
		exit(0); 
	}
	
	t->data = i;
	t->next = S;
	S = t;
	
	return S;
}

SqStack pop_stack(SqStack S, int *i){
	SqStack teml;
	
	if(empty_stack(S)){
		printf("��ջʧ��");
		exit(0); 
	}
	
	teml = S;
	*i = S->data;
	S = S->next;
	free(teml);
	
	return S;	
}



void create_graph(GraphAdjList G){
	int i, j, k;
	int m1, m2;
	int vi, vj;
	
	scanf("%d%d", &(G->vexnum), &(G->arcnum));
	
	for(j = 0; j < G->vexnum; j++){             //��ʼ��ͷ�ڵ� 
		G->vertex[j].data = j+1;
		G->vertex[j].firstarc = NULL;	
	}
	
	for(k = 0; k < G->arcnum; k++){ 
		scanf("%d%d", &vi, &vj);               //�������ӵ������� 
		m1 = vi - 1;
		m2 = vj - 1;
		PARENODE S = (PARENODE)malloc(sizeof(ARENODE));       //���� 
		S->adjvex = m2;
		S->nextTarc = G->vertex[m1].firstarc;
		G->vertex[m1].firstarc = S;

	}
}

void FindInDegree(GraphAdjList G, int *indegree){
	int i, teml, teml2, teml3;
	PARENODE p;
	
	for(i = 0; i < G->vexnum; i++){
		indegree[i] = 0;
	}
	
	for(i = 0; i < G->vexnum; i++){
		p = G->vertex[i].firstarc;
		
		while(p){
			indegree[p->adjvex]++;
			teml2 = p->adjvex;
			teml = indegree[p->adjvex];
			p = p->nextTarc;
		}	
	}	
}

int TopologicalSort(GraphAdjList G){
	int i, j = 0;
	int k, x, m1, m2;
	int t; 
	int count = 0;
	int point[MAX_V_NUM];
	int indegree[MAX_V_NUM]; 
	SqStack S;
	PARENODE p;
	
	FindInDegree(G, indegree);
	
	S = init_stack();
	
	for(i = 0; i < G->vexnum; i++){
		if(indegree[i] == 0){
			point[j] = i;
			j++;
		}
	}
	
	for(i = 0; i < j-1; i++){
		for(k = i+1; k < j; k++){
			m1 = point[i];
			m2 = point[k];
			if(G->vertex[m1].data < G->vertex[m2].data){
				x = point[i];
				point[i] = point[k];
				point[k] = x;
			}
		}
	}
	
	for(i = 0; i < j; i++){
		S = push_stack(S, point[i]);
	}
	
	j = 0;
	
	while(!empty_stack(S)){
		S = pop_stack(S, &i);
		p = G->vertex[i].firstarc;
		printf("%d ", G->vertex[i].data);
		count++;	
		
		while(p){
			t = --indegree[p->adjvex];
			if(t == 0){
				point[j] = p->adjvex;
				x = p->adjvex;
				j++;
			}
			p = p->nextTarc;
		}
		
		for(i = 0; i < j-1; i++){
				for(k = i+1; k < j; k++){
					m1 = point[i];
					m2 = point[k];
					if(G->vertex[m1].data > G->vertex[m2].data){
						x = point[i];
						point[i] = point[k];
						point[k] = x;
					}
				}
			}	
		
		if(j > 0){
			S = push_stack(S, point[0]);
			j--;
			for(i = 0; i < j; i++){
			point[i] = point[i+1];
			}
		}
		
				
	}
	
	if(count < G->vexnum){
		return 0; 
	}else{
		return 1; 
	}
}

int main(void){
	GraphAdjList G;
	G = (GraphAdjList)malloc(sizeof(Graph));
	create_graph(G);
	TopologicalSort(G);
	return 0;
}

