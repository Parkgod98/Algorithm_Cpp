#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

//int main(void)
//{
//	int n, m;
//	scanf("%d %d", &n, &m);
//
//	int* column = (int*)malloc(sizeof(int) * n);
//}

int main(void)
{
	double a, b;
	scanf("%lf %lf", &a, &b);
	printf("%.9lf", a / b);
}