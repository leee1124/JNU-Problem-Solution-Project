#include<cstdio>
#include<string>
#include<iostream>
#pragma warning(disable: 4996)
using namespace std;

void printIndexes(string school[], int n) {
	int first = -1;//존재하지 않으면 -1
	int last = -1;//존재하지 않으면 -1

	for (int i = 0; i < n; i++) {
		if (school[i] == "AJOU") {//배열의 i번째 원소와 AJOU와 비교해서 같으면
			if (first == -1)//AJOU가 처음 나왔으면 
				first = i + 1;//배열의 인덱스는 0부터 시작하므로 인덱스 + 1을 first에 대입
			last = i+1;//last는 AJOU가 나올 때마다 계속해서 갱신
		}
	}

	printf("%d %d\n", first, last);
}

int main() {
	int n;
	char buff[11];
	string* school;

	scanf("%d", &n);
	school = new string[n];

	for (int i = 0; i < n; i++) {
		scanf("%s", buff);//buff 변수에 문자열을 입력받아
		school[i] = buff;//school 배열에 대입
	}

	printIndexes(school, n);//인덱스 출력 함수, void형 함수이기 때문에 반환값이 없고 함수 내에서 출력

	delete[] school;
	return 0;
}
