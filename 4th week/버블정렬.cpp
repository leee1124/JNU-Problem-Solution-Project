#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;

void bubbleSort(int data[], int n) {//���������� �����ϴ� �Լ�
	for (int i = 0; i < n; i++) {//�������� ����ŭ �ݺ�
		int negativecount = 0;//���������� �����ϴ� ���� �� �� �������� ���� ����
		for (int j = 0; j < n-1; j++) {//data�� j��° ��� j+1��° ���� ���� ���ϱ� ������ n-1�� �ݺ���
			if (data[j] > data[j+1]) {//���������� �����ϴ� ���� ������ data[j]�� data[j+1]�� �ڸ��� ��ȯ��
				int tmp = data[j];//��ȯ �˰����� tmp������ data[j]�ǰ��� ������ �� 
				data[j] = data[j+1];//data[j]�� data[j+1]�� ������ ������
				data[j+1] = tmp;//�׸��� data[j+1]���� data[j]�� ���� ����ִ� tmp ������ ���� ������. �̷��� ��ȯ �Ϸ� 
				negativecount++;//���������� �����ϴ� ���� ������ ������
			}
		}
		if (negativecount == 0)//�迭�� ������������ ���ĵ� ���¶��
			break;//�ݺ����� �������� �Լ��� ������
	}
}
int main() {
	int n;//�������� ���� �Է¹��� ����
	int* data;//�����Ͱ� �� �迭
	scanf("%d", &n);//�������� ���� �Է¹���
	data = new int[n];//�������� ����ŭ data�迭 �����Ҵ�
	
	for (int i = 0; i < n; i++) {//�ռ� �Է¹��� �������� ����ŭ
		scanf("%d", &data[i]);//�����͸� �Է¹���
	}

	bubbleSort(data, n);//�������� ����

	for (int i = 0; i < n; i++) {//�������� ����ŭ �ݺ�
		if (i > 0) {//i�� 0���� ũ�� �ݺ�, ó������ ������ ������ �ȵǱ� ������ i�� 0�϶��� �������� ����
			printf(" ");//��°��� �� ĭ �������� ����
		}
		printf("%d", data[i]);//������������ ���ĵ� �迭�� ���� ���
	}

	delete[] data;//data�迭�� �����Ҵ� ����
	return 0;//���α׷� ����
}