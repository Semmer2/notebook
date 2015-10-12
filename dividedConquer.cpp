#include<iostream>

using namespace std;
#define THRESHOLD 28
void MergeSort(int r[],  int s, int t);				// 二路归并分组排序
void Merge(int r[], int r1[], int s, int m, int t);	// 合并每两组


int main()
{
    int r[11]={12,3,54,7,32,56,98,3,7,34,3};
	MergeSort(r,0,10);
	for(int i=0;i<11;i++)
		cout<<r[i]<<" ";
    return 0;
}

/*
 * 合并两个有序数组
 * 两个数组分别为r[s]-r[m],r[m+1],r[t]
 * 将排序结果存储与r1
 */
void Merge(int r[], int r1[], int s, int m, int t)
{
   int i = s, j = m + 1, k = s;
   while (i <= m && j <= t)
   {   
	   if (r[i] <= r[j])			// 取r[i]和r[j]中较小者放入r1[k]
		   r1[k++] = r[i++]; 
	   else 
		   r1[k++] = r[j++]; 
   }
   while (i <= m) {					// 若第一个子序列没处理完，则进行收尾处理
      r1[k++] = r[i++]; 
   }
   while (j <= t) {                 // 若第二个子序列没处理完，则进行收尾处理
      r1[k++] = r[j++]; 
   }
 }

/*
 * 对r[s]-r[t]进行二路归并排序
 * 先分组，逐级递归回溯
 */
void MergeSort(int r[], int s, int t) 
{
  int m;
  int r1[1000] = {0};
  if (s == t) return;				// 递归的边界条件
  else if(s + 1 == t) {				// 如果只有两个元素，直接交换
	int tmp = r[t];
	r[t] = r[s];
	r[s] = tmp;
  }
  //else if(t - s == THRESHOLD) {
	//InsertSort(int[] list,int low,high);
  //}
  else { 
    m = (s + t)/2;                  // 划分
    MergeSort(r, s, m);				// 求解子问题1，归并排序前半个子序列
	MergeSort(r, m+1, t);			// 求解子问题2，归并排序后半个子序列
	Merge(r, r1, s, m, t);          // 合并解，合并相邻有序子序列
	for (int i = s; i <= t; i++)
		r[i] = r1[i];
  } 
}

/*
 * 插入排序
 */
void InsertSort(int[] list,int low,int high)
{
	for (int i = low; i < high; i++)
	{
		int t = list[i];
		int j = i;
		while ((j > 0) && (list[j - 1] > t))
		{
			list[j] = list[j - 1];
			--j;
		}
		list[j] = t;
	}
}



