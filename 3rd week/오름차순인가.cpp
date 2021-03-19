#include<cstdio>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;

/*
�־��� �迭�� ������������ �˻��ϴ� �Լ�
@param data
@param n �������� ��
@return data[0]~ data[n-1]�� ���������̶�� true, else false
*/

bool isOrdered(int data[], int n) {
	bool chk = true;//�� ó���� ���������� �����Ѵٰ� �����ϰ� boolŸ�� ���� chk�� true�� �ʱ�ȭ
	for (int i = 0; i < n-1; i++) {//i�� n-1���� ���� �������� �ݺ��ؾ�
		if (data[i] > data[i + 1]) {//i+1�� �迭�� ������ ���� ����
			chk = false;//���� data[i]>data[i+1}�̸�, ���������� �������� �����Ƿ�
			break;//chk������ false���� �ְ� �ݺ����� ��������
		}
	}
	return chk;//���� ���������� �����ϸ� true�� ��ȯ�� ���̰�, �ƴ϶�� false�� ��ȯ
}

int main() {
	int n;//�л��� ��
	int* data;//�л����� Ű���� �� ������ ����

	scanf("%d", &n);//�л��� �� n �Է�
	data = new int[n];//data ������ �л� ����ŭ ���� �Ҵ�

	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);//�л����� Ű �Է¹���
	}

	bool result = isOrdered(data, n);//isOrdered �Լ��� ���� ���� ��������� result ���� �ʱ�ȭ
	if (result) {//result�� ���̸�
		printf("YES");//YES ���
	}
	else {//�ƴ϶��
		printf("NO");//NO ���
	}
	delete[] data;// ���� �Ҵ� ����
	return 0;
}