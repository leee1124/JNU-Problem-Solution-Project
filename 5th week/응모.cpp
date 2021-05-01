#include<cstdio>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

const int MAX_N = 1000000;//n은 최대 100만까지임
vector<int> FIBONACCI_TABLE;//makeFibonacciTable함수에서 반환된 값을 저장할 배열

vector<int> makeFibonacciTable(int n) {//피보나치 수열의 1~n번째 항을 배열에 저장하여 반환해주는 함수
	const int MOD = 100000000;//마지막 8자리 숫자만 출력하면 되기 때문에 MOD 상수의 값은 10의 8승
	
	vector<int> ret(n + 1);//피보나치 배열을 미리 선언
	ret[1] = 0;//피보나치 수열의 첫번째 숫자는 0
	ret[2] = 1;//두번째 숫자는 1임

	for (int i = 3; i <= n; ++i) {//피보나치 수열 계산
		ret[i] = ret[i - 2] + ret[i - 1];//피보나치 수열은 바로 앞 두 숫자를 더한 수열

		ret[i] %= MOD;//마지막 8자리 숫자를 구해서 저장
	}
	return ret;//마지막 8자리 피보나치 숫자를 값으로 가진 피보나치 배열 ret 반환
}

int getFibo(int n) {
	int answer = FIBONACCI_TABLE[n];//answer는 n번째 피보나치 숫자
	return answer;//answer 반환
}

int main() {
	FIBONACCI_TABLE = makeFibonacciTable(MAX_N);//N의 최대값인 100만번째 피보나치 수열까지 만듦

	int caseSize;//테스트 케이스 개수를 입력받을 변수
	scanf("%d", &caseSize);//테스트 케이스 개수 입력

	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {//테스트 케이스 개수만큼 반복
		int n;
		scanf("%d", &n);//n번째 피보나치 숫자를 구하기 위해 입력받는 변수

		int answer = getFibo(n);//n번째 피보나치 숫자를 구해서 answer에 저장
		printf("%d\n", answer);//해당 숫자 출력
	}

	FIBONACCI_TABLE.clear();//불필요한 배열 할당 해제

	return 0;//프로그램 종료
}