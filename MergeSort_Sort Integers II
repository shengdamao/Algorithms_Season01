/*
 464. 整数排序 II
 给一组整数，按照升序排序。使用归并排序，快速排序，堆排序或者任何其他 O(n log n) 的排序算法。

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

	void merge(vector<int> &A, int s, int m, int e, vector<int> &B)
	{
		int pb = 0;
		int p1 = s, p2 = m + 1;
		while (p1 <= m && p2 <= e)
		{
			if (A[p1] < A[p2])
				B[pb++] = A[p1++];
			else  B[pb++] = A[p2++]; ;
		}
		while (p1 <= m)
		{
			B[pb++] = A[p1++];
		}
		while (p2 <= e)
		{
			B[pb++] = A[p2++];
		}
		int len = A.size();
		for (int i = 0; i < e - s + 1; i++)
		{
			A[s + i] = B[i];
		}
	}

	void mergeSort(vector <int> &A, int s, int e, vector <int> &B)
	{
		if (s < e)
		{
			int m = s + (e - s) / 2;
			mergeSort(A, s, m, B);
			mergeSort(A, m + 1, e, B);
			merge(A, s, m, e, B);
		}
	}

	/**
	 * @param A: an integer array
	 * @return: nothing
	 */
	void sortIntegers2(vector<int> &A) {

		int len = A.size();
		vector<int> B(len);
		mergeSort(A, 0, len - 1, B);

	}
};

int main()
{
    std::cout << "Basic Merge Sort!\n"; 
}
