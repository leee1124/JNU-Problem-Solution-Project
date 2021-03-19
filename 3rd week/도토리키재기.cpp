#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;

/*
생일이 m월인 가장 큰 키의 도토리를 찾는 함수
@param height 각 도토리의 키
@param month 각 도토리의 출생 월
@param n 도토리의 수
@param m 찾고자 하는 달
@return month[k] == m인 가장 큰 height[k]
*/

int getMaximumHeight(int height[], int month[], int n, int m) {
	int max = -1;// 현재 달에 생일인 도토리가 없으면 -1 
	for (int i = n-1; i >=0; i++) {
		if (month[i] == m) {//현재 달과 i번째 도토리의 생일인 달이 같으면
			max = height[i]; //오름차순으로 정렬되어있기 때문에 가장 먼저 나오는 값이 가장 큰 도토리의 키
			break;//가장 큰 값을 max에 저장했기 때문에 바로 반복문을 빠져나감
		}
	}
	return max;//만약 max변수가 변하지 않았으면(현재 달이 생일인 도토리가 없으면) -1 반환
	//그렇지 않다면 현재 달이 생일인 도토리 중 키가 가장 큰 도토리의 키 반환
}
int main() {
	int n, m;
	int* height;
	int* month;

	scanf("%d", &n);//도토리의 수 입력
	height = new int[n];//도토리의 수만큼 height 변수에 동적 메모리 할당
	month = new int[n];//도토리의 수만큼 month 변수에 동적 메모리 할당 할당

	for (int i = 0; i < n; i++) {
		scanf("%d", &height[i]);//도토리의 수만큼 키 입력 - 2번째 줄 입력
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &month[i]);//도토리의 수만큼 생일이 속한 달 입력 - 3번째 줄 입력
	}

	scanf("%d", &m);//4번째줄 입력, 현재 달

	int answer = getMaximumHeight(height, month, n, m);

	printf("%d\n", answer);
	delete[] height;//height 변수의 동적 할당 해제
	delete[] month;//month 변수의 동적 할당 해제
	return 0;
}