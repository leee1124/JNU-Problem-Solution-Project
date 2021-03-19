#include<iostream>
#include<cstdio>
#pragma warning(disable: 4996)
using namespace std;

int getRangeSumFromOne(int i) {
	int answer = 0;
	for (int j = 1; j <= i; j++)//1이상 i이하의 모든 자연수의 합을 구하는 알고리즘
		answer += j;
	return answer;
}

long long getAnswer(int N) {
	long answer = 0;
	for (int i = 1; i <= N; i++) {
		int rangesum = getRangeSumFromOne(i);//rangesum은 1이상 i이하의 모든 자연수의 합
		answer += rangesum;//(1이상 1이하의 모든 자연수의 합)+(1이상 2이하 모든 자연수의 합) + ... + (1이상 n 이하 모든 자연수의 합)의 값
	}
	return answer;
}

int main() {
	int n;
	scanf("%d", &n);//자연수 n

	long long answer = getAnswer(n);//(1이상 1이하의 모든 자연수의 합)+(1이상 2이하 모든 자연수의 합) + ... + (1이상 n 이하 모든 자연수의 합)의 값을 구하는 함수

	printf("%lld\n", answer);//함수로 구한 값 출력

	return 0;
}