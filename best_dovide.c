// =====================================================================================
// 
//       Filename:  best_dovide.c
//
//    Description:  最优分解问题
//
//        Version:  1.0
//        Created:  2014年12月05日 12时26分28秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Striver (CuiJiaojiao), cuijiaojiaofendou@gmail.com
//        Company:  Class 1204 of Software Engineering
// 
// =====================================================================================

/*设n是一个正整数，现在要求将n分解成若干个互不相同的自然数之和，且使这些自然数的乘积最大*/
#include <stdio.h> 
#include <stdlib.h>

long int best_dovide(int n)
{
	int count;   //用来记录当前走到第几个i了
	int sum1 = 0, sum2 = 2, i = 2, max_mul = 1;
	
	
	while (i <= n){
		
		sum1 += i;
		sum2 += i+1;

		if (sum1 <= n && sum2 >= n){
			count = i+1;
			break;
		}
		i++;
	}

	int x = sum2 - n;

	for (i = 2; i <= count; i++){
		if (i != x){
			max_mul = max_mul*i;
		}	
	}
	return max_mul;
}
int main(int argc, char *argv[])
{
	int n, i;
	printf("请输入正整数n：\n");
	scanf("%d", &n);

	int a[n + 1];
	
	long int max_mul = best_dovide(n);

	printf("最大乘积是:%ld\n", max_mul);

	return 0;
}

