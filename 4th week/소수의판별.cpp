#include<cstdio>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;

/*
주어진 숫자가 소수인지 판별하는 함수
param N
return true  소수라면
return false 소수가 아니라면
*/
bool isPrime(int N) {//N은 소수인지 구할 수
	if (N == 1) return false;//1은 소수가 아님
	int cnt = 0;//약수의 개수를 세는 변수, 1은 이미 약수이므로 1부터 시작
	for (int i = 2; i*i<= N; i++) {//N=a*b에서 a와 b 둘 중 하나는 제곱근보다 작아야 하므로, N의 제곱근만큼만 반복한다
		if (N % i == 0) {//N의 약수가 있으면 N은 소수가 아님(가지치기)
			return false;//false 반환
		}
	}
	return true;//false가 아니면(소수이면) for문을 빠져나와 true 반환
}
void testcase(int caseIndex) {//테스트 케이스 인덱스와 정답을 출력하는 함수
	int n;//입력받을 숫자를 저장할 변수
	scanf("%d", &n);//n 입력
	
	bool result = isPrime(n);//isPrime 함수의 반환값을 result 변수에 저장
	
	printf("Case#%d\n", caseIndex);
	if (result) {//result값이 참이면
		printf("YES\n");//YES 출력
	}
	else {//거짓이면
		printf("NO\n");//NO출력
	}
}

int main() {
	int caseSize;//테스트 케이스의 개수를 저장할 변수
	scanf("%d", &caseSize);//테스트 케이스의 개수 입력
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {//테스트 케이스 개수만큼 반복
		testcase(caseIndex);//테스트케이스 인덱스를 파라미터로 보내고, testcase함수 실행
	}
	return 0;
}