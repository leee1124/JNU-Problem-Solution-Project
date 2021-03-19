#include<cstdio>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;

/*
주어진 배열이 오름차순인지 검사하는 함수
@param data
@param n 데이터의 수
@return data[0]~ data[n-1]이 오름차순이라면 true, else false
*/

bool isOrdered(int data[], int n) {
	bool chk = true;//맨 처음엔 오름차순을 만족한다고 가정하고 bool타입 변수 chk를 true로 초기화
	for (int i = 0; i < n-1; i++) {//i가 n-1보다 작을 때까지만 반복해야
		if (data[i] > data[i + 1]) {//i+1이 배열의 범위를 넘지 않음
			chk = false;//만약 data[i]>data[i+1}이면, 오름차순을 만족하지 않으므로
			break;//chk변수에 false값을 넣고 반복문을 빠져나옴
		}
	}
	return chk;//만약 오름차순을 만족하면 true를 반환할 것이고, 아니라면 false를 반환
}

int main() {
	int n;//학생의 수
	int* data;//학생들의 키값이 들어갈 데이터 변수

	scanf("%d", &n);//학생의 수 n 입력
	data = new int[n];//data 변수에 학생 수만큼 동적 할당

	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);//학생들의 키 입력받음
	}

	bool result = isOrdered(data, n);//isOrdered 함수를 통해 얻은 결과값으로 result 변수 초기화
	if (result) {//result가 참이면
		printf("YES");//YES 출력
	}
	else {//아니라면
		printf("NO");//NO 출력
	}
	delete[] data;// 동적 할당 해제
	return 0;
}