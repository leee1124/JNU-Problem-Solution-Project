#include<cstdio>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int getMinIndexInRange(int data[], int n, int begin, int end) {
	int index = begin;
	for (int i = begin; i <= end; i++) {//배열의 최솟값의 인덱스를 찾는 과정
		if (data[i] < data[index])//i번째 데이터 값보다 index번째 데이터 값이 더 크면
			index = i;//index를 i로 바꿔서 index번째 데이터가 최소값을 가리키도록 함
	}
	return index;
}

void selectionSort(int data[], int n) {
	for (int i = 0; i < n; i++) {
		int minIndex = getMinIndexInRange(data, n, i, n - 1);//최소값의 인덱스를 찾아서
		int tmp = data[i];//현재 인덱스와 교환.
		data[i] = data[minIndex];//tmp변수를 사용하지 않으면
		data[minIndex] = tmp;//데이터의 소실 위험이 있음
	}
}

int main() {
	int n;
	int* data;

	scanf("%d", &n);
	data = new int[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);//데이터 입력
	}

	selectionSort(data, n);

	for (int i = 0; i < n; i++) {
		if (i > 0) {
			printf(" ");//출력 데이터가 한 칸씩 띄워져야함.
		}
		printf("%d", data[i]);//정렬된 값 출력
	}

	delete[] data;
	return 0;
}