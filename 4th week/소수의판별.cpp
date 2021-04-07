#include<cstdio>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;

/*
�־��� ���ڰ� �Ҽ����� �Ǻ��ϴ� �Լ�
param N
return true  �Ҽ����
return false �Ҽ��� �ƴ϶��
*/
bool isPrime(int N) {//N�� �Ҽ����� ���� ��
	if (N == 1) return false;//1�� �Ҽ��� �ƴ�
	int cnt = 0;//����� ������ ���� ����, 1�� �̹� ����̹Ƿ� 1���� ����
	for (int i = 2; i*i<= N; i++) {//N=a*b���� a�� b �� �� �ϳ��� �����ٺ��� �۾ƾ� �ϹǷ�, N�� �����ٸ�ŭ�� �ݺ��Ѵ�
		if (N % i == 0) {//N�� ����� ������ N�� �Ҽ��� �ƴ�(����ġ��)
			return false;//false ��ȯ
		}
	}
	return true;//false�� �ƴϸ�(�Ҽ��̸�) for���� �������� true ��ȯ
}
void testcase(int caseIndex) {//�׽�Ʈ ���̽� �ε����� ������ ����ϴ� �Լ�
	int n;//�Է¹��� ���ڸ� ������ ����
	scanf("%d", &n);//n �Է�
	
	bool result = isPrime(n);//isPrime �Լ��� ��ȯ���� result ������ ����
	
	printf("Case#%d\n", caseIndex);
	if (result) {//result���� ���̸�
		printf("YES\n");//YES ���
	}
	else {//�����̸�
		printf("NO\n");//NO���
	}
}

int main() {
	int caseSize;//�׽�Ʈ ���̽��� ������ ������ ����
	scanf("%d", &caseSize);//�׽�Ʈ ���̽��� ���� �Է�
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {//�׽�Ʈ ���̽� ������ŭ �ݺ�
		testcase(caseIndex);//�׽�Ʈ���̽� �ε����� �Ķ���ͷ� ������, testcase�Լ� ����
	}
	return 0;
}