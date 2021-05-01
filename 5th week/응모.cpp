#include<cstdio>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

const int MAX_N = 1000000;//n�� �ִ� 100��������
vector<int> FIBONACCI_TABLE;//makeFibonacciTable�Լ����� ��ȯ�� ���� ������ �迭

vector<int> makeFibonacciTable(int n) {//�Ǻ���ġ ������ 1~n��° ���� �迭�� �����Ͽ� ��ȯ���ִ� �Լ�
	const int MOD = 100000000;//������ 8�ڸ� ���ڸ� ����ϸ� �Ǳ� ������ MOD ����� ���� 10�� 8��
	
	vector<int> ret(n + 1);//�Ǻ���ġ �迭�� �̸� ����
	ret[1] = 0;//�Ǻ���ġ ������ ù��° ���ڴ� 0
	ret[2] = 1;//�ι�° ���ڴ� 1��

	for (int i = 3; i <= n; ++i) {//�Ǻ���ġ ���� ���
		ret[i] = ret[i - 2] + ret[i - 1];//�Ǻ���ġ ������ �ٷ� �� �� ���ڸ� ���� ����

		ret[i] %= MOD;//������ 8�ڸ� ���ڸ� ���ؼ� ����
	}
	return ret;//������ 8�ڸ� �Ǻ���ġ ���ڸ� ������ ���� �Ǻ���ġ �迭 ret ��ȯ
}

int getFibo(int n) {
	int answer = FIBONACCI_TABLE[n];//answer�� n��° �Ǻ���ġ ����
	return answer;//answer ��ȯ
}

int main() {
	FIBONACCI_TABLE = makeFibonacciTable(MAX_N);//N�� �ִ밪�� 100����° �Ǻ���ġ �������� ����

	int caseSize;//�׽�Ʈ ���̽� ������ �Է¹��� ����
	scanf("%d", &caseSize);//�׽�Ʈ ���̽� ���� �Է�

	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {//�׽�Ʈ ���̽� ������ŭ �ݺ�
		int n;
		scanf("%d", &n);//n��° �Ǻ���ġ ���ڸ� ���ϱ� ���� �Է¹޴� ����

		int answer = getFibo(n);//n��° �Ǻ���ġ ���ڸ� ���ؼ� answer�� ����
		printf("%d\n", answer);//�ش� ���� ���
	}

	FIBONACCI_TABLE.clear();//���ʿ��� �迭 �Ҵ� ����

	return 0;//���α׷� ����
}