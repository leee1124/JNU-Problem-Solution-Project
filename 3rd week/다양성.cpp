#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;
/*
�ߺ��� ������ ������ ������ ���� ����ϴ� �Լ�
@param data ���� �迭
@param n ���� �迭�� ũ��
@return ������ ������ ��
*/

int getElementTypeCount(int data[], int n) {
	int countType = 0;
	
	for (int i = 0; i < n-1; i++) {//�迭�� �̹� ������������ �ԷµǾ����Ƿ�
		if (data[i] != data[i + 1])//ȭ���� ������ȣ�� ���� ���� ���(ȭ���� ������ �ٸ� ���)
			countType++;//ȭ���� ������ �� ����
	}
	return countType;//ȭ���� ������ �� ��ȯ
}

int main() {
	int n;// ȭ���� ��
	int* data;//ȭ���� ������ȣ�� �� �迭

	scanf("%d", &n);//ȭ���� �� �Է�
	data = new int[n];//ȭ���� ����ŭ �迭�� �����Ҵ�

	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);//ȭ���� ����ŭ ȭ���� ������ȣ �Է�
	}

	int answer = getElementTypeCount(data, n);//ȭ���� ������ ������ �Լ��� ���� ����

	printf("%d\n", answer);//ȭ���� ������ ���� ���

	delete[] data;//�迭�� �����Ҵ� ����
	return 0;
}