void BFSTraverse(ALGraph G)  
{//�����ڽӱ�洢������ͼG����������ȱ���  
    int u,v;  
    CqQueue Q;  
    ArcNode *p;  
    for(v=0;v<G.vexnum;v++)  
        visited[v]=0;  
    InitQueue(Q);  
    for(v=0;v<G.vexnum;v++)  
        if(!visited[v]){  
            printf("%3c",G.vertices[v].data);  
            visited[v]=1;  
            EnQueue(Q,v);  
            while(!QueueEmpty(Q)){  
                DeQueue(Q,u);  
                for(p=G.vertices[u].firstarc;p;p=p->nextarc)  
                    if(!visited[p->adjvex]){  
                        printf("%3c",G.vertices[p->adjvex].data);  
                        visited[p->adjvex]=1;  
                        EnQueue(Q,p->adjvex);  
                    }  
            }  
        }  
}  
