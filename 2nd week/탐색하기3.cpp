#include<cstdio>
#include<cmath>
#include<iostream>
#pragma warning(disable: 4996)
using namespace std;

int findIndex(int data[], int n) {
	int sum = 0, x =0;

	for (int i = 0; i < n; i++) 
		sum += data[i];//모든 데이터의 총합을 구하는 과정

	for (int i = 0; i < n; i++) {//평균과 가장 가까운 데이터를 찾는 과정
		int dx = abs(n * data[x] - sum);//절대값을 사용해 평균값과의 거리를 측정함
		int di = abs(n * data[i] - sum);//int형 데이터이기 때문에 /연산자를 사용하면 데이터를 잃어버릴 위험이 있으므로 sum 값을 사용하고 데이터에도 개수 n을 곱해서 거리를 구함
		if (dx > di)
			x = i;
	}
	return x+1;//인덱스가 1번부터 시작하기 때문에 x+1을 반환
}

int main() {
	int n;
	int* data;

	scanf("%d", &n);
	data = new int[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);//데이터 입력
	}

	int answer = findIndex(data, n);
	printf("%d %d\n", answer, data[answer-1]);//x+1을 반환 했으므로, answer값에서 1을 빼야 평균과 가장 가까운 데이터를 가리킴
	delete[] data;
	return 0;
}