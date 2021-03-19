#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;
/*
중복을 제외한 숫자의 종류의 수를 계산하는 함수
@param data 원본 배열
@param n 원본 배열의 크기
@return 숫자의 종류의 수
*/

int getElementTypeCount(int data[], int n) {
	int countType = 0;
	
	for (int i = 0; i < n-1; i++) {//배열이 이미 오름차순으로 입력되었으므로
		if (data[i] != data[i + 1])//화보의 고유번호가 같지 않은 경우(화보의 종류가 다른 경우)
			countType++;//화보의 종류의 수 증가
	}
	return countType;//화보의 종류의 수 반환
}

int main() {
	int n;// 화보의 수
	int* data;//화보의 고유번호가 들어갈 배열

	scanf("%d", &n);//화보의 수 입력
	data = new int[n];//화보의 수만큼 배열의 동적할당

	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);//화보의 수만큼 화보의 고유번호 입력
	}

	int answer = getElementTypeCount(data, n);//화보의 종류의 개수를 함수를 통해 얻음

	printf("%d\n", answer);//화보의 종류의 개수 출력

	delete[] data;//배열의 동적할당 해제
	return 0;
}