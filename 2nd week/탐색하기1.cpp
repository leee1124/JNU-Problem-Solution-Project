#include<cstdio>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int findIndex(int data[], int n, int m) {
	int index = -1;//�迭�� m���� ������ ���� ������ �ε����� -1
	for (int i = 0; i < n; i++) {//�迭�� m���� ������ ������, �� ��° �ε������� ���ϴ� ����
		if (data[i] == m)//�迭�� m���� �����ϸ�
			index = i;//�ش� index ������ ���� �迭�� �ε��� i ����
	}
	return index;
}
int main() {
	int n, m;
	int* data;

	scanf("%d %d", &n, &m);
	data = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);//������ �Է� ����
	}

	int answer = findIndex(data, n, m);//�ε����� ���ϴ� ����

	printf("%d\n", answer);
	delete[] data;
	return 0;
}