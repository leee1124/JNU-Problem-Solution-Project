#include<cstdio>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int getMinIndexInRange(int data[], int n, int begin, int end) {
	int index = begin;
	for (int i = begin; i <= end; i++) {//�迭�� �ּڰ��� �ε����� ã�� ����
		if (data[i] < data[index])//i��° ������ ������ index��° ������ ���� �� ũ��
			index = i;//index�� i�� �ٲ㼭 index��° �����Ͱ� �ּҰ��� ����Ű���� ��
	}
	return index;
}

void selectionSort(int data[], int n) {
	for (int i = 0; i < n; i++) {
		int minIndex = getMinIndexInRange(data, n, i, n - 1);//�ּҰ��� �ε����� ã�Ƽ�
		int tmp = data[i];//���� �ε����� ��ȯ.
		data[i] = data[minIndex];//tmp������ ������� ������
		data[minIndex] = tmp;//�������� �ҽ� ������ ����
	}
}

int main() {
	int n;
	int* data;

	scanf("%d", &n);
	data = new int[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);//������ �Է�
	}

	selectionSort(data, n);

	for (int i = 0; i < n; i++) {
		if (i > 0) {
			printf(" ");//��� �����Ͱ� �� ĭ�� ���������.
		}
		printf("%d", data[i]);//���ĵ� �� ���
	}

	delete[] data;
	return 0;
}