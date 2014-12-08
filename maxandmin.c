// =====================================================================================
// 
//       Filename:  maxandmin.c
//
//    Description:  求数组中的最大值和最小值
//
//        Version:  1.0
//        Created:  2014年09月29日 21时27分53秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Striver (CuiJiaojiao), cuijiaojiaofendou@gmail.com
//        Company:  Class 1204 of Software Engineering
// 
// =====================================================================================

#include <stdlib.h>
#include <stdio.h>

#define Type int

///方法一：通过传参的方式得到max和min
void Max_Min(Type *array, int left, int right, Type *max, Type *min)
{
	if (left == right){
		*max = array[left];
		*min = array[right];
	} else {
		int mid = (left + right)/2;

		int max1, max2, min1, min2;

		Max_Min(array, left, mid, &max1, &min1);
		Max_Min(array, mid + 1, right, &max2, &min2);

		*max = max1 > max2 ? max1:max2;

		*min = min1 < min2 ? min1:min2;

	}
}

///方法二：通过返回值求得

typedef struct MaxMin{
	int max;
	int min;
}Max_min;

Max_min getMaxandMin(Type *array, int left, int right)
{
	if (left == right){
		Max_min temp;
		temp.max = array[left];
		temp.min = array[right];
		return temp;
	} else {
		int mid = (left + right)/2;
		
		Max_min temp1, temp2, result;
	
		temp1 = getMaxandMin(array, left, mid);
		temp2 = getMaxandMin(array, mid + 1, right);
	
		result.max = temp1.max > temp2.max ? temp1.max :temp2.max;
		result.min = temp1.min < temp2.min ? temp1.min : temp2.min;

		return result;
	}
}
int main(int argc, char *argv[])
{
	int n, i;
	printf("请输入需要输入的元素个数:\n");

	scanf("%d", &n);

	while (n <= 0){
		printf("输入个数有误，请重新输入！");
		scanf("%d", &n);
	}
	Type array[n];

	///将n 作为种子
	srand(n);

	for (i = 0; i < n; i ++){
		///范围为0～100
		array[i] = rand()%100;
	}

	for (i = 0; i < n; i ++){
		printf("%d ", array[i]);
	}

	printf("\n");

	Type max, min;

	Max_Min(array, 0, n - 1, &max, &min);
	
	printf("The first way's result :\n");
	printf("max = %d, min = %d \n\n", max, min);

	Max_min result;
	result = getMaxandMin(array, 0, n -1);

	printf("The second way's result:\n");
	printf("max = %d, min = %d\n", result.max, result.min);

	return 0;
}

