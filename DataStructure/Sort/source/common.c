#include "../header/sort.h" 

void print(SqList L)
{
	int i;
	for (i = 1; i <= L.length; i++)
	{
		printf("(%d,%d)", L.r[i].key, L.r[i].otherinfo);
	}
	printf("\n");
}