#include<cstdio>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int findIndex(int data[], int n, int m) {
	int index = -1;//배열이 m값을 가지고 있지 않으면 인덱스는 -1
	for (int i = 0; i < n; i++) {//배열이 m값을 가지고 있으면, 몇 번째 인덱스인지 구하는 과정
		if (data[i] == m)//배열에 m값이 존재하면
			index = i;//해당 index 변수에 현재 배열의 인덱스 i 대입
	}
	return index;
}
int main() {
	int n, m;
	int* data;

	scanf("%d %d", &n, &m);
	data = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);//데이터 입력 과정
	}

	int answer = findIndex(data, n, m);//인덱스를 구하는 과정

	printf("%d\n", answer);
	delete[] data;
	return 0;
}