#include<cstdio>
#include<iostream>
using namespace std;

/*
�迭�� N���� ���Ұ� �������� ���� ������ ǥ���� �� �ִ��� �Ǵ��ϴ� �Լ�
param data
param n
return
*/

bool isConsecutive(int data[], int n) {
	int max_data = data[0];//�ӽ� �ִ����� �迭�� ù ��
	int min_data = data[0];//�ӽ� �ּڰ����� �迭�� ù ��

	for (int i = 0; i < n; i++) {
		if (max_data < data[i])//�ִ񰪺��� �� ū ���Ұ� �߰ߵǸ�
			max_data = data[i];//�ִ� ����
		if (min_data > data[i])//�ּڰ����� �� ���� ���Ұ� �߰ߵǸ�
			min_data = data[i];//�ּڰ� ����
	}

	if (max_data - min_data == n - 1) {//���Ǽҵ� ��ȣ�� �ִ�-�ּڰ� == ���Ǽҵ��� ���� - 1�̶��(�������̶��)
		return true;//true ��ȯ
	}
	return false;//�ƴ϶�� false ��ȯ
}

int main() {
	int n;//���Ǽҵ��� ���� ����� ����
	int* data;//���Ǽҵ� ��ȣ�� �� �迭

	scanf("%d", &n);//���Ǽҵ��� �� �Է�
	data = new int[n];//���Ǽҵ� ��ȣ�� �� �迭�� ���Ǽҵ� ����ŭ �����Ҵ� 

	for (int i = 0; i < n; i++) {//���Ǽҵ��� ����ŭ
		scanf("%d", &data[i]);//���Ǽҵ� ��ȣ �Է�
	}

	bool result = isConsecutive(data, n);//isConsecutive�Լ����� ��ȯ�� ���� result������ ����

	if (result) {//result�� ���̸�(�迭�� N���� ���Ұ� �������� ���� ������ ǥ���� �� ������)
		printf("YES");//YES���
	}
	else {//�ƴ϶��
		printf("NO");//NO���
	}

	delete[] data;//������ �����Ҵ� ����
	return 0;//���α׷� ����
}