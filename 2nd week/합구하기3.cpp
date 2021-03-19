#include<iostream>
#include<cstdio>
#pragma warning(disable: 4996)
using namespace std;

int getRangeSumFromOne(int i) {
	int answer = 0;
	for (int j = 1; j <= i; j++)//1�̻� i������ ��� �ڿ����� ���� ���ϴ� �˰���
		answer += j;
	return answer;
}

long long getAnswer(int N) {
	long answer = 0;
	for (int i = 1; i <= N; i++) {
		int rangesum = getRangeSumFromOne(i);//rangesum�� 1�̻� i������ ��� �ڿ����� ��
		answer += rangesum;//(1�̻� 1������ ��� �ڿ����� ��)+(1�̻� 2���� ��� �ڿ����� ��) + ... + (1�̻� n ���� ��� �ڿ����� ��)�� ��
	}
	return answer;
}

int main() {
	int n;
	scanf("%d", &n);//�ڿ��� n

	long long answer = getAnswer(n);//(1�̻� 1������ ��� �ڿ����� ��)+(1�̻� 2���� ��� �ڿ����� ��) + ... + (1�̻� n ���� ��� �ڿ����� ��)�� ���� ���ϴ� �Լ�

	printf("%lld\n", answer);//�Լ��� ���� �� ���

	return 0;
}