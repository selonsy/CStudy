#pragma once
#include "head.h"
#include "lib.h"
#include <string.h>
#include <stdlib.h>
void c_test_for_study();

void fn1()
{
	extern int x;
	printf("fn1(): x=%d\n", x);
}

//�ļ���д,��������
typedef struct Grade {
	char *name;
	float score;
	struct Grade* next;
}SGrade;
void file_read_write()
{
	//���ļ��ж�ȡѧ�������Ͷ�Ӧ�ɼ�������ѧ���ɼ��ߵͽ�������Ȼ��ѧ����Ϣ���ճɼ���С���������һ���ļ��С�
	//ԭʼ�ļ�·��:"D:\99Workspace\90Test\ѧ���ɼ�.txt"
	//��ʽ:�����:99  ���� �����,99
	//Ŀ���ļ�·��:"D:\99Workspace\90Test\ѧ���ɼ�����.txt"
	/*
	name:�����,score:99.00
	name:ΤС��,score:96.00
	name:���޼�,score:92.00
	name:������,score:89.00
	name:¬����,score:87.00
	name:����ľС����,score:59.00
	*/	
	FILE* file_r, *file_d;
	file_r = fopen("D:\\99Workspace\\90Test\\ѧ���ɼ�.txt", "r");//��ֻ��ģʽ���ļ�
	file_d = fopen("D:\\99Workspace\\90Test\\ѧ���ɼ�����.txt", "w+");//�Զ�дģʽ,���������½�
	if (file_r == NULL) //����ļ���ʧ��
	{
		printf("cannot open file!\n");
		return;
	}
	char t_name[20];
	float t_score;
	int i;
	fscanf(file_r,"%s",&t_name);
	fscanf(file_r, "%f", &t_score);
	SGrade* head = (SGrade*)malloc(sizeof(SGrade));
	//fread(&head, sizeof(SGrade), 1, file_r);	
	SGrade* p = head;
	if (t_name != NULL && t_score >= 0)//�ȴ���ͷָ��
	{
		head->name =strdup(t_name);//strdup�����������ַ����ĳ��ȣ�Ȼ�����malloc�����ڶ���������Ӧ�Ŀռ䣬�����ַ����������ַ����Ƶ�����
		head->score = t_score;
		head->next = NULL;
	}		
	while (!feof(file_r)) //��������ļ��Ľ�β
	{
		char _name[20];
		float _score;
		fscanf(file_r, "%s", &_name);
		fscanf(file_r, "%f", &_score);
		SGrade* node = (SGrade*)malloc(sizeof(SGrade));//�����½��
		node->name = strdup(_name);;
		node->score = _score;
		node->next = NULL;
		SGrade* pre=NULL;//ǰ�����
		while (p!=NULL)
		{			
			if (node->score > p->score)//����������ڵ�ǰ���
			{
				if (pre == NULL)//�����ǰ���Ϊͷ���
				{
					node->next = p;
					head = node;					
				}
				else
				{
					node->next = pre->next;
					pre->next = node;				
				}	
				break;
			}
			else
			{
				if (p->next == NULL)//�����ǰ���Ϊβ���,��nextΪ��
				{
					p->next = node;
					break;
				}
				else
				{
					pre = p;
					p = p->next;
				}				
			}
		}		
		p = head;
	}	
	while (p != NULL)
	{
		printf("name:%s,score:%.2f\n", p->name, p->score);
		fprintf(file_d, "%s %.2f\n", p->name, p->score);
		p = p->next;

	}
		
	int is_close_r = fclose(file_r);
	int is_cloes_d = fclose(file_d);
	return;
}

int main() 
{
	file_read_write();

	system("pause");
	return 0;
#pragma region History

	//printf("Hello World!\n");

	//printf("%d��%s����\n",1900,is_leap_year(1900)==1?"��":"����");

	//triangle_print(10);

	//multi_9();

	//su_shu(1000);

	//the_day_of_year(2008, 8, 8);

	//monkey_eat_peach(1);	

	//printf("��5���˵�������%d��\n", factorial_test(5));

	//xiaoming_dache(12, 9, 18);

	//array_test();

	//paixu_maopao();

	//my_test1();

	//printf("hello world!\n");

	//c_test_for_study();

#pragma endregion	
}

//�﷨����У��
void c_test_for_study() 
{
	int x = 10;
	if (x>0)
	{
		int  x = 100;
		x /= 2;
		printf("if�����, x=%d\n", x);
	}
	printf("main������, x=%d\n", x);
	fn1();
	return 0;

//	int input;
//	scanf("%d", &input);
//	if (input > 10) goto OVER10;
//	else goto LESS10;
//OVER10:
//	printf(">10\n"); c_test_for_study(); return;
//LESS10:
//	printf("<10\n"); c_test_for_study(); return;
}

int x = 77;





