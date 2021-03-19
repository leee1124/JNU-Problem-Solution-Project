#include<cstdio>
#include<cmath>
#include<iostream>
#pragma warning(disable: 4996)
using namespace std;

int findIndex(int data[], int n) {
	int sum = 0, x =0;

	for (int i = 0; i < n; i++) 
		sum += data[i];//��� �������� ������ ���ϴ� ����

	for (int i = 0; i < n; i++) {//��հ� ���� ����� �����͸� ã�� ����
		int dx = abs(n * data[x] - sum);//���밪�� ����� ��հ����� �Ÿ��� ������
		int di = abs(n * data[i] - sum);//int�� �������̱� ������ /�����ڸ� ����ϸ� �����͸� �Ҿ���� ������ �����Ƿ� sum ���� ����ϰ� �����Ϳ��� ���� n�� ���ؼ� �Ÿ��� ����
		if (dx > di)
			x = i;
	}
	return x+1;//�ε����� 1������ �����ϱ� ������ x+1�� ��ȯ
}

int main() {
	int n;
	int* data;

	scanf("%d", &n);
	data = new int[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);//������ �Է�
	}

	int answer = findIndex(data, n);
	printf("%d %d\n", answer, data[answer-1]);//x+1�� ��ȯ �����Ƿ�, answer������ 1�� ���� ��հ� ���� ����� �����͸� ����Ŵ
	delete[] data;
	return 0;
}