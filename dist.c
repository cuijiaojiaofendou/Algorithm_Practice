/*编辑距离问题*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

///求最小值
int min(int x, int y)
{
	return (x < y)?x:y;
}

int dist(char *a, char *b)
{
	int m = strlen(a);
	int n = strlen(b);
	int i, j, x, y;
	int d[m + 1][n + 1];       //二位数组，存放数组a,b中元素对应的编辑距离

	printf("m = %d, n = %d\n", m, n);	
	///字符串中某个为空，则返回不为空的字符串长度
	if (n == 0){
		return m;
	}
	if (m == 0){
		return n;
	}

	for (i = 0; i <= m; i++){
		d[i][0] = i;
	}
	for (j = 0; j <= n; j++){
		d[0][j] = j;
	}
	
	for (i = 1; i <= m; i++){
		for (j = 1; j <= n; j++){
			int del = (a[i - 1] == b[j - 1]) ? 0:1;
			d[i][j] = min(min(d[i - 1][j - 1]+ del, d[i - 1][j]+1), d[i][j - 1]+1);
		}
	}

	return d[m][n];
}

/*
 *写入内容后会出现乱码情况
 * */
/*void WriteFile(int n)
{
	int fd;

	printf("n = %d\n", n);
	fd = open("./output.txt", O_CREAT|O_WRONLY, 0644);

	write(fd, n, sizeof(n));

	close(fd);
}
*/

void WriteFile(int n)
{
	FILE *fp;

	fp = fopen("./output.txt", "w+");

	fprintf(fp, "%d\n", n);
	
	fclose(fp);
}
int main(int argc, char *argv[])
{
	char a[128];
	char b[128];
	FILE *fp;
	printf("选择0：直接读文件\n选择1：用户自己输入文件内容,\n请选择：");
	int i;
	scanf("%d", &i);
	if (i == 0){
		fp = fopen("./input.txt", "r+");

		fscanf(fp, "%s\n", a);

		fscanf(fp, "%s\n", b);

		fclose(fp);
	} else if (i == 1){
		fp = fopen("./input.txt", "w+");
		printf("字符串1为");
		scanf("%s", a);

		fprintf(fp, "%s\n", a);
		printf("字符串2为");
		scanf("%s", b);

		fprintf(fp, "%s\n", b);

		fclose(fp);
	}

	int n = dist(a, b);
	WriteFile(n);
	printf("它们的编辑距离为%d\n", n);
}
