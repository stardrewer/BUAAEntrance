﻿#include "CSKaoyan.hpp"

// 直接插入排序
void InsertSort(int A[], int n) {
	int j;
	int a0;
	for (int i = 1; i < n; i++)
		if (A[i] < A[i - 1]) {
			a0 = A[i];
			for (j = i - 1; a0 < A[j]; j--) // *
				A[j + 1] = A[j];
			A[j + 1] = a0;
		}
}

// 折半插入排序
void InsertSortMid(int A[], int n) {
	int j, left, mid, right, a0;
	for (int i = 1; i < n; i++) {
		if (A[i] < A[i - 1]) {
			a0 = A[i];

			left = 1;
			right = i - 1;
			while (left <= right) { // *
				mid = (left + right) / 2;
				if (A[mid] > a0)
					right = mid - 1;
				else
					left = mid + 1;
			}

			for (j = i - 1; a0 < A[j]; j--)
				A[j + 1] = A[j];
			A[j + 1] = a0;
		}
	}
}

// TODO: 希尔排序
void ShellSort(int A[], int n) {}

// 冒泡排序
void BubbleSort(int A[], int n) {
	for (int i = 0; i < n; i++)
	{
		bool is_sorted = true;
		for (int j = n - 1; j > i; j--)
		{
			if (A[j - 1] > A[j]) {
				int tmp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = tmp;
				is_sorted = false;
			}
		}
		if (is_sorted)
			return;
	}
}

// 快速排序
void QuickSort(int A[], int low, int high) {}
int Partition(int A[], int low, int high);

// 选择排序
void SelectSort_(int A[], int n) {
	for (int i = 0; i < n; i++) {
		int min_index = i;
		for (int j = i + 1; j < n; j++)
			if (A[j] < A[min_index])
				min_index = j;
		if (min_index != i) {
			int temp = A[i];
			A[i] = A[min_index];
			A[min_index] = temp;
		}
	}
}

// 建立大根堆
// HeadAdjust 将元素k为根的子树进行调整
void HeadAdjust(int A[], int k, int len) {
	A[0] = A[k]; // 暂存子树的根节点(0位置不存储元素)
	for (int i = 2 * k; i <= len; i *= 2) { // 沿key较大的子节点向下筛选
		if (i < len && A[i] < A[i + 1])
			i++; // 取key较大的子节点的下标
		if (A[0] >= A[i])
			break;// 筛选结束
		else {
			A[k] = A[i];// 将A[i]调整到双亲节点上
			k = i;// 修改k值, 以便继续向下筛选
		}
	}
	A[k] = A[0]; // 被筛选节点的值放入最终位置
}
void BuildMaxHeap(int A[], int len) {
	for (int i = len / 2; i > 0; i--)// 反复调整堆
		HeadAdjust(A, i, len);
}
// 堆排序
void HeapSort(int A[], int len) {
	BuildMaxHeap(A, len); // 初始建大根堆

	// 用堆实现排序(堆的数组表示法 ==> 排好序的结果
	for (int i = len; i >1; i--)
	{
		// 输出堆顶元素(和堆底元素做交换, 把最大的丢到数组底部)
		int tmp = A[i];
		A[i] = A[1];
		A[1] = tmp;
		// 调整, 把剩余的i-1个元素整理成堆
		HeadAdjust(A, 1, i - 1);
	}
}

// 归并排序
void Merge(int A[], int low, int mid, int high) {}
void MergeSort(int A[], int low, int high) {}

int main() {
	int A[] = { 5, 4, 1, 3, 2 };
	SelectSort_(A, 5);

	for (int v : A)
		cout << v << " ";
	cout << endl;
}