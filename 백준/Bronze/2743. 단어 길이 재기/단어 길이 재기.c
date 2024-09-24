#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#define SIZE 100
int main(void)
{
	char arr[SIZE];
	scanf("%s", arr);
	printf("%d", strlen(arr));
}