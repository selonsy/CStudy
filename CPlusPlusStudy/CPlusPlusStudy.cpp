// CPlusPlusStudy.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;
/*
���������ļ�������ļ�����ȡ�����ļ���ÿ�е����޸�������������������Сֵ������ļ�
�ļ����ݾ���:
1 2 3 4 5 6 7
2 3 4 5
6 7 8 9
�������Ϊ:
<1>Max:7,Min:1
*/
struct max_min
{
	int max;
	int min;
};
void file_read_write1()
{
	FILE* file_r, *file_d;
	file_r = fopen("D:\\99Workspace\\90Test\\����.txt", "r");//��ֻ��ģʽ���ļ�
	file_d = fopen("D:\\99Workspace\\90Test\\���ִ�С.txt", "w+");//�Զ�дģʽ,���������½�
	if (file_r == NULL) //����ļ���ʧ��
	{
		printf("cannot open file!\n");
		return;
	}
	char row[100];
	//char* res;
	int max = -100, min = 100;
	int i = 0, j;
	struct max_min res[10];
	while (!feof(file_r))
	{
		fgets(row, 100, file_r);
		char* temp = strtok(row, " ");
		int t_int = atoi(temp);
		if (t_int > max)max = t_int;
		if (t_int < min)min = t_int;
		while (temp)
		{
			temp = strtok(NULL, " ");
			if (temp)
			{
				t_int = atoi(temp);
				if (t_int > max)max = t_int;
				if (t_int < min)min = t_int;
			}
		}
		res[i].max = max;
		res[i].min = min;
		max = -100; min = 100;
		i++;
	}
	for (j = 0; j < i; j++)
	{
		fprintf(file_d, "<%d>Max:%d,Min:%d\n", j, res[j].max, res[j].min);
	}
	fclose(file_r);
	fclose(file_d);
	cout << "you fuck" << endl;
}

int main()
{
	file_read_write1();
    return 0;
}

