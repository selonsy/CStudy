#include<stdio.h>
#include<malloc.h>
#define MaxVerNum 100 /*�������ڵ���*/
int visited[MaxVerNum];
typedef char VertexType;
typedef struct node
{
	int adjvex;
	struct node *next; //ָ����һ���ڽӽڵ���
} EdgeNode;
typedef struct vnode
{
	VertexType vertex[3]; //������
	EdgeNode *firstedge; //�߱�ͷָ��
} VertexNode;
typedef VertexNode AdjList[MaxVerNum];
/*
*�������ڽӱ�Ϊ�洢���͵�ͼ
*/
typedef struct
{
	AdjList adjList; //�ڽӱ�
	int n, e; //�����������
} ALGraph;
/*
*�������е����ݽṹ������й�����ȱ���
*/
typedef struct
{
	int data[MaxVerNum];
	int head, tail; //��ͷ���β
} Quene;
/*
*��������ͼ���ڽӱ�洢
*/
void CreateALGraph(ALGraph *G)
{
	int i, j, k;
	EdgeNode *s;
	printf("�����붥����������������ʽΪ������������������ ");
	scanf("%d,%d", &G->n, &G->e);
	printf("�����붥����Ϣ�������ʽΪ�������<CR>����\n");
	for (i = 0; i < G->n; i++)
	{
		scanf("%s", G->adjList[i].vertex);
		G->adjList[i].firstedge = NULL; //������ı߱�ͷָ������Ϊ��
	}
	printf("������ߵ���Ϣ�������ʽΪ��i,j����\n");
	for (k = 0; k < G->e; k++)
	{
		scanf("%d,%d", &i, &j);
		s = (VertexNode*)malloc(sizeof(VertexNode));
		//���ϵĵ�һ���ڵ�
		s->adjvex = j;
		s->next = G->adjList[i].firstedge;
		G->adjList[i].firstedge = s;
		//���ϵĵڶ����ڵ�
		s = (VertexNode*)malloc(sizeof(VertexNode));
		s->adjvex = i;
		s->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = s;
	}
}
/*
*����ͼ�����������������
*/
void DFSAL(ALGraph *G, int i)
{
	//��ViΪ�������ͼ���б���
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
*���й��������������
*/
void BFSG(ALGraph *G, int k)
{
	int i, j;
	Quene q;
	EdgeNode *p;
	q.head = 0;
	q.tail = 0; //���ж��еĳ�ʼ��
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
*����ͼ�Ĳ���
*/
void BFS_DFS_Test()
{
	ALGraph *G;
	EdgeNode *p = NULL;
	int i;
	G = (ALGraph*)malloc(sizeof(ALGraph));
	CreateALGraph(G);
	printf("����������ȱ���\n");
	DFSTraverseAL(G);
	printf("���й�����ȱ���\n");
	BFSTraverseAL(G);
}