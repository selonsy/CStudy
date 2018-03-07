// CPlusPlusStudy.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;
/*
给定输入文件与输出文件，读取输入文件中每行的有限个整数，输出该行最大最小值到输出文件
文件内容举例:
1 2 3 4 5 6 7
2 3 4 5
6 7 8 9
输出内容为:
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
	file_r = fopen("D:\\99Workspace\\90Test\\数字.txt", "r");//以只读模式打开文件
	file_d = fopen("D:\\99Workspace\\90Test\\数字大小.txt", "w+");//以读写模式,不存在则新建
	if (file_r == NULL) //如果文件打开失败
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

