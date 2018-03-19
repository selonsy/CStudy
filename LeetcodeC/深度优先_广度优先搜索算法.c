#include<stdio.h>
#include<malloc.h>
#define MaxVerNum 100 /*定义最大节点数*/
int visited[MaxVerNum];
typedef char VertexType;
typedef struct node
{
	int adjvex;
	struct node *next; //指向下一个邻接节点域
} EdgeNode;
typedef struct vnode
{
	VertexType vertex[3]; //顶点域
	EdgeNode *firstedge; //边表头指针
} VertexNode;
typedef VertexNode AdjList[MaxVerNum];
/*
*定义以邻接边为存储类型的图
*/
typedef struct
{
	AdjList adjList; //邻接表
	int n, e; //顶点数与边数
} ALGraph;
/*
*建立队列的数据结构方便进行广度优先遍历
*/
typedef struct
{
	int data[MaxVerNum];
	int head, tail; //队头与队尾
} Quene;
/*
*建立无向图的邻接表存储
*/
void CreateALGraph(ALGraph *G)
{
	int i, j, k;
	EdgeNode *s;
	printf("请输入顶点数与边数（输入格式为：顶点数，边数）： ");
	scanf("%d,%d", &G->n, &G->e);
	printf("请输入顶点信息（输入格式为：顶点号<CR>）：\n");
	for (i = 0; i < G->n; i++)
	{
		scanf("%s", G->adjList[i].vertex);
		G->adjList[i].firstedge = NULL; //将顶点的边表头指针设置为空
	}
	printf("请输入边的信息（输入格式为：i,j）：\n");
	for (k = 0; k < G->e; k++)
	{
		scanf("%d,%d", &i, &j);
		s = (VertexNode*)malloc(sizeof(VertexNode));
		//边上的第一个节点
		s->adjvex = j;
		s->next = G->adjList[i].firstedge;
		G->adjList[i].firstedge = s;
		//边上的第二个节点
		s = (VertexNode*)malloc(sizeof(VertexNode));
		s->adjvex = i;
		s->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = s;
	}
}
/*
*进行图的深度优先搜索遍历
*/
void DFSAL(ALGraph *G, int i)
{
	//以Vi为出发点对图进行遍历
	EdgeNode *p;
	printf("visit vertex : %s \n", G->adjList[i].vertex);
	visited[i] = 1;
	p = G->adjList[i].firstedge;
	while (p)
	{
		if (!visited[p->adjvex])
		{
			DFSAL(G, p->adjvex);
		}
		p = p->next;
	}
}
void DFSTraverseAL(ALGraph *G)
{
	int i;
	for (i = 0; i < G->n; i++)
	{
		visited[i] = 0;
	}
	for (i = 0; i < G->n; i++)
	{
		if (!visited[i])
		{
			DFSAL(G, i);
		}
	}
}
/*
*进行广度优先搜索遍历
*/
void BFSG(ALGraph *G, int k)
{
	int i, j;
	Quene q;
	EdgeNode *p;
	q.head = 0;
	q.tail = 0; //进行队列的初始化
	printf("visit vertex : %s \n", G->adjList[k].vertex);
	visited[k] = 1;
	q.data[q.tail++] = k;
	while (q.head % (MaxVerNum - 1) != q.tail % (MaxVerNum - 1))
	{
		i = q.data[q.head++];
		p = G->adjList[i].firstedge;
		while (p)
		{
			if (!visited[p->adjvex])
			{
				printf("visit vertex : %s \n", G->adjList[p->adjvex].vertex);
				visited[p->adjvex] = 1;
				q.data[q.tail++] = p->adjvex;
			}
			p = p->next;
		}
	}
}
void BFSTraverseAL(ALGraph *G)
{
	int i;
	for (i = 0; i < G->n; i++)
	{
		visited[i] = 0;
	}
	for (i = 0; i < G->n; i++)
	{
		if (!visited[i])
		{
			BFSG(G, i);
		}
	}
}
/*
*进行图的测试
*/
void BFS_DFS_Test()
{
	ALGraph *G;
	EdgeNode *p = NULL;
	int i;
	G = (ALGraph*)malloc(sizeof(ALGraph));
	CreateALGraph(G);
	printf("进行深度优先遍历\n");
	DFSTraverseAL(G);
	printf("进行广度优先遍历\n");
	BFSTraverseAL(G);
}