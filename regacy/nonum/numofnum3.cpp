#include <stdio.h>
#include <math.h>

int main(void)
{
	int A, B, C, re, num, K;
	int arr[9] = { 0 };
	int N[10] = { 0 };
	scanf("%d %d %d", &A, &B, &C);
	re = A * B * C;
	num = 1;
	K = re;
	for (int i = 1; i < re; i *= 10)//자릿수 세기
	{
		num++;
	}
	for (int k = 0; k < num; k++)
	{
		arr[k] = K % 10;
		K = K / 10;
	}
	for (int k = 1	; k < num; k++)
	{
		N[arr[k]]++;
	}
	for (int k = 0; k <= 9; k++)
	{
		printf("%d\n", N[k]);
	}
}