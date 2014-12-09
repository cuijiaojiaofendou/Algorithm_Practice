// =====================================================================================
// 
//       Filename:  min_weight.c
//
//    Description:  回溯法求最小重量机器设计问题,用排列树解题
//
//        Version:  1.0
//        Created:  2014年12月09日 20时33分56秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Striver (CuiJiaojiao), cuijiaojiaofendou@gmail.com
//        Company:  Class 1204 of Software Engineering
// 
// =====================================================================================

#include <stdio.h>
#include <stdlib.h>

#define N 100

int c[N][N], w[N][N];//定义存放价格和重量的数组
int cur_price = 0, cur_weight = 0;
int n, m, d;     //部件个数，供应商个数，价格上限
int sum = 0;     //用来记录最终重量
int savex[N];     //用来存放第i个部件所选的供应商是哪一个的最佳路径
int bestx[N];   //相当于筛选
void  min_weight(int i)
{
	int j;
	if (i > n){
		if (cur_weight < sum){
			sum = cur_weight;
			
			for (j = 1; j <= n; j++){
				savex[j] = bestx[j];
			}
		}
		return;
	}
	for (j = 1; j <= m; j++){
		cur_weight += w[i][j];
		cur_price += c[i][j];

		bestx[i] = j;  //说明第i个零件由第j个供应商提供

		///如果当前价格小于总价格最大上限并且当前重量小于总重量，
		//则进行下一层筛选
		if (cur_price <= d && cur_weight < sum){
			min_weight(i+1);
		}
		
		bestx[i] = -1;   //第i个零件不由第j个供应商提供     
		cur_weight -= w[i][j];
		cur_price -= c[i][j];
	}
}
int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;

	int i,j;

	fp1 = fopen("input.txt", "w+");

	printf("请分别输入部件数，供应商数目，价格上限:\n");

	scanf("%d%d%d", &n, &m, &d);
	fprintf(fp1, "%d %d %d\n", n, m, d);

//	int c[n+1][m+1], w[n+1][m+1];
	
	printf("请输入部件的价格：\n");

	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			scanf("%d", &c[i][j]);
			fprintf(fp1, "%d ", c[i][j]);
		}
		fprintf(fp1,"\n");
	}

	printf("请输入部件的重量:\n");
	
	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			scanf("%d", &w[i][j]);
			fprintf(fp1, "%d ", c[i][j]);
		}
		fprintf(fp1,"\n");
		sum += w[i][1];
	}
	
	fclose(fp1);
	min_weight(1);

	fp2 = fopen("output.txt", "w+");

	fprintf(fp2, "%d\n", sum);
	printf("最优解为:\n");
	for (i = 1; i <= n; i++){
		printf("%d  ", savex[i]);	
		fprintf(fp2, "%d ", savex[i]);
	}

	fprintf(fp2, "\n");

	fclose(fp2);
	printf("\n");
	printf("最终重量为:%d\n", sum);
	return 0;
}

