#include<cstdio>
#include<iostream>
using namespace std;

/*
배열의 N개의 원소가 연속적인 정수 수열로 표현될 수 있는지 판단하는 함수
param data
param n
return
*/

bool isConsecutive(int data[], int n) {
	int max_data = data[0];//임시 최댓값으로 배열의 첫 값
	int min_data = data[0];//임시 최솟값으로 배열의 첫 값

	for (int i = 0; i < n; i++) {
		if (max_data < data[i])//최댓값보다 더 큰 원소가 발견되면
			max_data = data[i];//최댓값 갱신
		if (min_data > data[i])//최솟값보다 더 작은 원소가 발견되면
			min_data = data[i];//최솟값 갱신
	}

	if (max_data - min_data == n - 1) {//에피소드 번호중 최댓값-최솟값 == 에피소드의 개수 - 1이라면(연속적이라면)
		return true;//true 반환
	}
	return false;//아니라면 false 반환
}

int main() {
	int n;//에피소드의 수가 저장될 변수
	int* data;//에피소드 번호가 들어갈 배열

	scanf("%d", &n);//에피소드의 수 입력
	data = new int[n];//에피소드 번호가 들어갈 배열을 에피소드 수만큼 동적할당 

	for (int i = 0; i < n; i++) {//에피소드의 수만큼
		scanf("%d", &data[i]);//에피소드 번호 입력
	}

	bool result = isConsecutive(data, n);//isConsecutive함수에서 반환한 값을 result변수에 저장

	if (result) {//result가 참이면(배열의 N개의 원소가 연속적인 정수 수열로 표현될 수 있으면)
		printf("YES");//YES출력
	}
	else {//아니라면
		printf("NO");//NO출력
	}

	delete[] data;//데이터 동적할당 해제
	return 0;//프로그램 종료
}