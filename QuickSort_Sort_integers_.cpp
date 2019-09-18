/*给一组整数，按照升序排序。使用归并排序，快速排序，堆排序或者任何其他 O(n log n) 的排序算法。

样例
给出[3, 2, 1, 4, 5],

排序后的结果为[1, 2, 3, 4, 5]。
*/


#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

	void quicksort(vector<int> &A, int s, int e)
	{
		if (s >= e)
			return;
		int k = A[s];
		int i = s, j = e;
		while (i != j)
		{
			while (i < j && k <= A[j])
				j--;
			swap(A[i], A[j]);


			while (i < j && A[i] <= k)
				i++;
			swap(A[i], A[j]);
		}
		quicksort(A, s, i - 1);
		quicksort(A, i + 1, e);
	}

	void sortIntegers2(vector<int> &A) {
		int len = A.size();
		quicksort(A, 0, len - 1);
	}
};
int main()
{
    std::cout << "Quick Sort!\n"; 
}


/* 易错点笔记：
1. while (i < j && k <= A[j])    27行
   while (i < j && A[i] <= k)    32行    
   
   不能遗漏 i < j
   
2. 第36，37行，  
		quicksort(A, s, i - 1);
		quicksort(A, i + 1, e);
		
   必须使用 i-1, i+1, 不然就会死循环。 
   
3. 记得要递归。

*/
