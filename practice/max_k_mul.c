/*最大k乘积问题*/

#include <stdio.h>
#include <stdlib.h>

///写文件
void Write(int n, int k, long int I)
{
	FILE *fp;
	fp = fopen("input.txt", "w+");
	
	if (fp == NULL){
		perror("fopen");
		exit(0);
	}
	fprintf(fp, "%d\t %d\n %ld\n", n, k, I);
	
	fclose(fp);
}

long int divode(long int I, int k, int n)
{
	int i, j, z, temp0;
	int temp[n];
	long int mul[n+1][n+1], max;   //存放最大乘积
	long int number[n+1][n+1];     //存放分出来的子序列，如number[i][j]就是代表第i到第j个元素的这个子序列
	
	///提取十进制数中的各位数	
	i = n;
	while (I != 0){
		temp[i - 1] = I%10;
		I =  I/10;
		printf("temp[%d] = %d\n", i-1, temp[i-1]);
		i --;
	}

	///初始化number矩阵,最终结果为一个右上三角型
	for (i = 1; i <= n; i++){
		number[i][i] = temp[i-1];
		for (j = i + 1; j <= n; j++){
			number[i][j] = number[i][j - 1]*10 + temp[j-1];
		}
	}

//	printf("n = %d, k = %d, I = %ld\n", n, k, I);

	///对乘积矩阵的初始化
	for (i = 0; i <= n; i ++){
		for (j = 0; j <= n; j++){
			mul[i][j] = 0;
		}
	}
	
	///对第一列初始化
	for (i = 1; i <= n; i++){
		mul[i][1] = number[1][i];
	}

	//填充最大乘积矩阵
	for (i = 1; i <= n; i++){
		for (j = 2; j <= k; j++){
			for (z = 1, max = 0; z < i; z++){
				temp0 = mul[z][j - 1] *number[z+1][i];
				if (max < temp0){
					max = temp0;
				}	
		//	printf("max = %ld\n", max);	
			}

			mul[i][j] = max;
		}
	}

	return mul[n][k];
}
int main(int argc, char **argv)
{
	long int I, x;
	int n = 0, k;
	FILE *fp;

	printf("请输入一个n位十进制数：(n<= 10):");
	scanf("%ld", &I);
	printf("请输入K(将十进制数划分成k段):");
	scanf("%d", &k);
	
	x = I;
	while (x != 0){
		x = x/10;
		n ++;

	}

	if (n > 10|n < k){
		printf("该十进制数超出了范围!\n");
		exit(0);
	}

	Write(n,k,I);

	long int mul = divode(I, k, n);

	printf("最大乘积结果为:%ld\n", mul);
	fp = fopen("output.txt", "w+");
	if (fp == NULL){
		perror("fopen2");
		exit(0);
	}

	fprintf(fp,"%ld", mul);
	
	fclose(fp);
}
