#include<iostream>
#include<cstdio>
#pragma warning(disable: 4996)
using namespace std;

/*���� �Ʒ� ��ǥ�� (x,y)�� �ȼ��� ������ R�� ���� ���ԵǴ°�?
param x
param y
param R
return ���Եȴٸ� true, else false*/

bool isInside(long long x, long long y, long long R) {//int���� ������ �Ѿ�� ������ long long ������ �Ķ���͸� ����
	//���� �������� ���� �ȼ��� ���� ���ο� �����Ϸ��� x*x+y*y<r*r�� �����ؾ���
	long long sqd = x * x + y * y;//�ȼ��� ���� ���ο� �ִ��� ���ϱ� ���� ����ϴ� ����
	if (sqd < R * R)//�Ÿ��� ������ �������� �������� ������(���� ������, �ȼ��� ���� ���ο� ������)
		return true;//true ��ȯ
	return false;//���� ���ο� ���� ������ false ��ȯ
}
void testcase(int caseIndex) {//�׽�Ʈ ���̽��� ������ �Լ�, ���̽� �ε����� �׽�Ʈ���̽��� ù��° �ٿ� ���
	long long R;//���� �������� �ȼ� �� R�� �����ϴ� ����
	scanf("%lld", &R);//�ȼ� �� �Է¹���

	long long sum = 0;// 1��и鿡 �����ϴ� �� �ȼ��� ��
	long long y = R;//y�� ���� �������϶����� ����
	for (long long x = 0; x <= R; x++) {//x�� 0���� �����ؼ� �������� ���̸�ŭ �ݺ��س���
		long long height = 0;//���̴� 0
		for (; y >= 0; y--) {
			if (isInside(x, y, R)) {//isInside�� ���̸� �Ʒ��� �ȼ��� ���� ���Եȴ�.
				height = (y + 1);
				break;
			}
		}
		sum += height;//������ �����ش�
	}
	printf("#%d\n", caseIndex);//�׽�Ʈ ���̽��� ù��° �ٿ� ���̽� �ε��� ���
	printf("%lld\n", sum * 4);//sum���� 1��и��� �ȼ����� ����Ǿ������Ƿ� 4�� �����ش�
}
int main() {
	int caseSize;//�׽�Ʈ ���̽��� ������ ������ ����
	scanf("%d", &caseSize);//�׽�Ʈ ���̽� ���� �Է�
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {//�׽�Ʈ ���̽� ������ŭ �ݺ�
		testcase(caseIndex);//�׽�Ʈ ���̽� �Լ� ȣ��
	}
	return 0;//���α׷� ����
}