/*数字三角形问题*/
/*给定一个由n行数字组成的数字三角形，设计算法，计算出从三角形的顶至底的一条路经，使该路径经过的数字总和最大*/

#include <stdio.h>
#include <stdlib.h>
#define N 100
int max(int x, int y)
{
	return x > y? x:y;
}
/*
int MAX_SUM(int x, int y, int n)
{
	if (n == 1) return(a[x][y]);
	if (n != 1 && n <= N){
		return (a[x][y] + max(MAX_SUM(x+1,y+1, n - 1), MAX_SUM(x+1,y, n - 1)));
	}
}
*/
int main(int argc, char **argv)
{
	int n;
	printf("请输入三角形的行号(1~100)：\n");
	scanf("%d", &n);
	if (n < 1 || n > 100){
		printf("输入行号无法完成任务!\n");
		exit(0);
	}
	printf("请输入%d个数:\n", n*(n - 1)/2);
	int a[n+1][n+1], i, j;
	
	FILE *fp1, *fp2;
	fp1 = fopen("input.txt", "w");
	for (i = 1; i <= n; i++){
		for (j = 1; j <= i; j++){
			a[i][j] = rand()%100 + 1;
			fprintf(fp1,"%d ", a[i][j]);		
		}
		fprintf(fp1,"\n");
	}

	fclose(fp1);
	
	int sum;
//	sum = MAX_SUM(1, 1, n);

	int dist[n+1][n+1];
	
	dist[1][1] = a[1][1];
	///如果是行首元素
	for (i = 2; i <= n; i++){
		dist[i][1] = dist[i-1][1] + a[i][1];
	}

	///如果是行尾元素
	for (i = 2; i <= n; i++){
		dist[i][i] = dist[i-1][i-1] + a[i][i];
	}
	///如果在行中任意位置
	for (i = 2; i <= n; i++){
		for (j = 2; j <= i; j++){
			if (i != j)
			dist[i][j] = max(dist[i-1][j-1], dist[i-1][j]) + a[i][j];
		}
	}

	int max_sum = 0;
	for (i = 1; i <= n; i++){
		if (dist[n][i] > max_sum){
			max_sum = dist[n][i];
		}
	}
	printf("the last result is : %d\n", max_sum);
	fp2 = fopen("output.txt", "w");
	fprintf(fp2,"%d", max_sum);
	fclose(fp2);	
	
}
