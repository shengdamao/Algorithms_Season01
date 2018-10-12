/*846. 多关键字排序

给定 n 个学生（ 1 到 n 编号）以及他们的考试成绩，这里有两个关键字，考试成绩以及学生学号。
根据第一关键字对数组进行排序(降序)，如果第一关键字相同则根据第二关键字进行排序(升序).

样例

给出 [[2,50],[1,50],[3,100]]，

返回 [[3,100],[1,50],[2,50]]

*/
#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void merge(vector<vector<int>> & A, int s, int m, int e, vector<vector<int>> & B)
	{
		int pb = 0;
		int p1 = s, p2 = m + 1;
		while (p1 <= m && p2 <= e) {
			if (A[p1][1] > A[p2][1])
				B[pb++] = A[p1++];

			else if (A[p1][1] < A[p2][1])
				B[pb++] = A[p2++];

			else if (A[p1][1] == A[p2][1]) {
				if (A[p1][0] < A[p2][0])
					B[pb++] = A[p1++];
				else B[pb++] = A[p2++];
			}
		}
		while (p1 <= m)
			B[pb++] = A[p1++];
		while (p2 <= e)
			B[pb++] = A[p2++];


		for (int i = 0; i < e - s + 1; i++)
		{
			A[s + i] = B[i];
		}
	}
	void mergeSort(vector<vector<int>> & A, int s, int e, vector<vector<int>> &B)
	{
		if (s < e)
		{
			int m = s + (e - s) / 2;
			mergeSort(A, s, m, B);
			mergeSort(A, m + 1, e, B);
			merge(A, s, m, e, B);
		}
	}

	vector<vector<int>> multiSort(vector<vector<int>> &array) {
		int len = array.size();

		vector<vector<int>> temp(len);
		mergeSort(array, 0, len - 1, temp);
		return array;
	}
};


int main()
{
	std::cout << "Multi-Keyword Sort by Merge Sort \n";
}
