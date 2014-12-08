// =====================================================================================
// 
//       Filename:  2.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年10月28日 19时22分08秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Striver (CuiJiaojiao), cuijiaojiaofendou@gmail.com
//        Company:  Class 1204 of Software Engineering
// 
// =====================================================================================

#include<iostream>
#include<ctime>
using namespace std;
#define N 10
void LCSL(int m,int n,int *x,int *y,int **c,int **b);//计算最长公共子序列长度。
void LCS(int i,int j,int *x,int **b);//根据b[i][j]的内容打印a,x数组的最长公共子序列。
void QuickSort(int a[],int p,int r);//快速排序。
int Partition(int a[],int p,int t);//数组划分，将小于等于x的元素移到x左边，大于x的元素移到x右边。
void Swap(int &x,int &y);//交换元素x和y。
//计算最长公共子序列长度
void LCSL(int m,int n,int *x,int *y,int c[][N],int b[][N])
{
c[0][0]=0;
int i,j;
for(i=1;i<=m;i++)
c[i][0]=0;
for(i=1;i<=n;i++)
c[0][i]=0;
for(i=1;i<=m;i++)
for(j=1;j<=m;j++)
{
if(x[i]==y[j])
{
c[i][j]=c[i-1][j-1]+1;
b[i][j]=1;
}
else if(c[i-1][j]>=c[i][j-1])
{
c[i][j]=c[i-1][j];
b[i][j]=2;
}
else
{
c[i][j]=c[i][j-1];
b[i][j]=3;
}
}
cout<<c[m][m]<<endl;
}
//根据b[i][j]的内容打印a,x数组的最长公共子序列
void LCS(int i,int j,int *x,int b[][N])
{
if(i==0||j==0) return;
if(b[i][j]==1)
{
LCS(i-1,j-1,x,b);
for(int y=1;y<i;y++)
if(x[y]==x[i])
return;
cout<<x[i]<<" ";
}
else if(b[i][j]==2)
{
LCS(i-1,j,x,b);
}
else
LCS(i,j-1,x,b);
}
void QuickSort(int a[],int p,int r)
{
if(p<r)
{
int q=Partition(a,p,r);
QuickSort(a,p,q-1);//对左半段排序
QuickSort(a,q+1,r);//对右半段排序
}
}
int Partition(int a[],int p,int r)
{
int i=p,
j=r+1;
int x=a[p];
//将<x的元素交换到左边区域
//将>x的元素交换到右边区域
while(true)
{
while(a[--j]>x);
while((i<j)&&a[++i]<x);
if(i>=j)break;
Swap(a[i],a[j]);
}
a[p]=a[j];
a[j]=x;
return j;
}
void Swap(int &x,int &y)
{
int t;
t=x;
x=y;
y=t;
}
int main(void)
{
int *a,*x;
a=new int[N];
x=new int[N];
int b[N][N];
int c[N][N];
cout<<"请输入十个数："<<endl;
for(int i=1;i<N;i++)
{
cin>>a[i];
x[i]=a[i];
}
QuickSort(x,1,N-1);
LCSL(N-1,N-1,a,x,c,b);
LCS(N-1,N-1,a,b);
	return 0;
}

