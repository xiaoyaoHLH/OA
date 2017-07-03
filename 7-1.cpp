#include <stdio.h>
#include <stdlib.h>
#define MAX_V_NUM 20

int visited[MAX_V_NUM];  //用于标记该节点是否被访问，已被访问为1，未访问为0 

typedef struct EdgeNode{  //分支节点 
	int adjvex;           //指向节点的下标 
	struct EdgeNode * nextTarc;   //指向下个节点的指针 
}ARENODE, *PARENODE;

typedef struct VNode{  //头节点 
	int data;      //顶点信息
	PARENODE firstarc; //指向第一个依附节点 	
}VNODE, AdjList[MAX_V_NUM];

typedef struct Graph{
	AdjList vertex;
	int vexnum, arcnum; //节点数和边数 
}Graph,*GraphAdjList;

typedef struct Qnode{
	int data;
	struct Qnode * nextNode;
}Qnode, *QNODE;

typedef struct Queue{
	QNODE front;
	QNODE rear;			
}Queue, *QUEUE;

QUEUE init_queue(){
	QNODE p;
	QUEUE Q;
	Q = (QUEUE)malloc(sizeof(Queue));
	p = (QNODE)malloc(sizeof(Qnode));
	
	if(p){
		Q->front = p;
		Q->rear = p;
		Q->front->nextNode = NULL;
		return Q;
	}else{
		printf("队列初始化失败");
		exit(0);
	}
}

int empty_queue(QUEUE Q){
	if(Q->rear == Q->front){
		return 1;
	}else{
		return 0;
	}
}

QUEUE en_queue(QUEUE Q, int val){
	QNODE p;
	p = (QNODE)malloc(sizeof(Qnode));
	
	if(p){
		p->data = val;
		p->nextNode = NULL;
		Q->rear->nextNode = p;
		Q->rear = p;
	}else{
		printf("入队失败");
		exit(0);
	}
	
	return Q;	
}

QUEUE del_queue(QUEUE Q, int *val){	
	QNODE p;
	if(empty_queue(Q)){
		printf("出队失败");
		exit(0);
	}else{
		p = Q->front->nextNode;
		*val = p->data;
		Q->front->nextNode = p->nextNode;
		if(p == Q->rear){
			Q->rear = Q->front;
		}
		free(p);
	}
	
	return Q;
}

void create_graph(GraphAdjList G){
	int i, j, k;
	int vi, vj;
	int m1, m2; 
	
	scanf("%d%d", &G->vexnum, &G->arcnum);
	
	for(j = 0; j < G->vexnum; j++){             //初始化头节点 
		G->vertex[j].data = j+1;
		G->vertex[j].firstarc = NULL;	
	}
	
	for(k = 0; k < G->arcnum; k++){ 
		scanf("%d%d", &vi, &vj);               //输入连接的两条边 
		m1 = vi - 1;
		m2 = vj - 1;
		
		PARENODE S = (PARENODE)malloc(sizeof(ARENODE));       //出度 
		S->adjvex = m2;
		S->nextTarc = G->vertex[m1].firstarc;
		G->vertex[m1].firstarc = S;
		
		PARENODE T = (PARENODE)malloc(sizeof(ARENODE));       //入度
		T->adjvex = m1;
		T->nextTarc = G->vertex[m2].firstarc;
		G->vertex[m2].firstarc = T;
	}
}

void display(GraphAdjList G, int i, int n){
	if(n < G->vexnum){
		printf("%d ", G->vertex[i].data);
	}else{
		printf("%d", G->vertex[i].data);
	}
}

void DFS(GraphAdjList G, int i){
	static int count = 1;
	visited[i] = 1;
	
	display(G,i,count);
	
	PARENODE p = G->vertex[i].firstarc;
	
	while(p){
		if(!visited[p->adjvex]){
			count++;
			DFS(G, p->adjvex);
		}
		
		p = p->nextTarc;
	}
}

void DFS_show(GraphAdjList G){
	int i;
	for(i = 0; i < G->vexnum; i++){
		visited[i] = 0;
	}
	
	for(i = 0; i < G->vexnum; i++){
		if(!visited[i]){
			DFS(G, i);
		}
	}	
}	

void BFS_show(GraphAdjList G){
	int i;
	PARENODE p;
	QUEUE Q;
	Q = init_queue();
	
	for(i = 0; i < G->vexnum; i++){
		visited[i] = 0;
	}
	
	for(i = 0; i < G->vexnum; i++){
		if(!visited[i]){
			printf("%d ", G->vertex[i].data);
			visited[i] = 1;
			Q = en_queue(Q, i);
			
			while(!empty_queue(Q)){
				Q = del_queue(Q, &i);

				for(p = G->vertex[i].firstarc; p; p = p->nextTarc){
					if(!visited[p->adjvex]){
						printf("%d ", G->vertex[p->adjvex].data);
						visited[p->adjvex] = 1;
						Q = en_queue(Q, p->adjvex);	
					}
				
				}
			}
		}	
	}	
}


int main(void){
	GraphAdjList G;
	G = (GraphAdjList)malloc(sizeof(Graph));
	
	create_graph(G);
	DFS_show(G);
	printf("\n");
	BFS_show(G);
		
	return 0;
}
