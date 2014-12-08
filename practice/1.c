// =====================================================================================
// 
//       Filename:  1.c
//
//    Description:  求串的最长单调递增序列
//
//        Version:  1.0
//        Created:  2014年10月28日 19时10分11秒
//       Revision:  none
//       Compiler:  gcc
//
//         Author:  Striver (CuiJiaojiao), cuijiaojiaofendou@gmail.com
//        Company:  Class 1204 of Software Engineering
// 
// =====================================================================================

#include <stdio.h>
#include <stdlib.h>
#define N 100
int main(int argc, char **argv)
{
	int a[N+1],b[N];
	int n, i, j, k;

	printf("Input you need:");
	scanf("%d", &n);
	
	for (i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	b[0] = 1;

	for (i = 1; i <= n; i++){
		k = 0;
		for (j = 0; j < i; j++){
			if (a[j] <= a[i] && k < b[j]){
				k = b[j];
			}
			b[j] = k - 1;
		}
	}

	int max = 0;

	for (i = 1; i <= n; i++){
		if (b[i] > max){
			max = b[i];
		}
	}
}
