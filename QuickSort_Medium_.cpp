/*
80. 中位数

给定一个未排序的整数数组，找到其中位数。

中位数是排序后数组的中间值，如果数组的个数是偶数个，则返回排序后数组的第N / 2个数。
您在真实的面试中是否遇到过这个题？
样例

给出数组[4, 5, 1, 2, 3]， 返回 3

给出数组[7, 9, 4, 5]，返回 5

挑战

时间复杂度为O(n)
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
			while (i < j && k >= A[i])
				i++;
			swap(A[i], A[j]);
		}
		quicksort(A, s, i - 1);
		quicksort(A, i + 1, e);
	}


	int median(vector<int> &nums) {
		int len = nums.size();
		quicksort(nums, 0, len - 1);
		int pos = (len + 1) / 2 - 1;
		return nums[pos];
	}
};

int main()
{
    std::cout << "Using Quick Sort to find Medium! \n"; 
}
