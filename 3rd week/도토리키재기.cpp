#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;

/*
������ m���� ���� ū Ű�� ���丮�� ã�� �Լ�
@param height �� ���丮�� Ű
@param month �� ���丮�� ��� ��
@param n ���丮�� ��
@param m ã���� �ϴ� ��
@return month[k] == m�� ���� ū height[k]
*/

int getMaximumHeight(int height[], int month[], int n, int m) {
	int max = -1;// ���� �޿� ������ ���丮�� ������ -1 
	for (int i = n-1; i >=0; i++) {
		if (month[i] == m) {//���� �ް� i��° ���丮�� ������ ���� ������
			max = height[i]; //������������ ���ĵǾ��ֱ� ������ ���� ���� ������ ���� ���� ū ���丮�� Ű
			break;//���� ū ���� max�� �����߱� ������ �ٷ� �ݺ����� ��������
		}
	}
	return max;//���� max������ ������ �ʾ�����(���� ���� ������ ���丮�� ������) -1 ��ȯ
	//�׷��� �ʴٸ� ���� ���� ������ ���丮 �� Ű�� ���� ū ���丮�� Ű ��ȯ
}
int main() {
	int n, m;
	int* height;
	int* month;

	scanf("%d", &n);//���丮�� �� �Է�
	height = new int[n];//���丮�� ����ŭ height ������ ���� �޸� �Ҵ�
	month = new int[n];//���丮�� ����ŭ month ������ ���� �޸� �Ҵ� �Ҵ�

	for (int i = 0; i < n; i++) {
		scanf("%d", &height[i]);//���丮�� ����ŭ Ű �Է� - 2��° �� �Է�
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &month[i]);//���丮�� ����ŭ ������ ���� �� �Է� - 3��° �� �Է�
	}

	scanf("%d", &m);//4��°�� �Է�, ���� ��

	int answer = getMaximumHeight(height, month, n, m);

	printf("%d\n", answer);
	delete[] height;//height ������ ���� �Ҵ� ����
	delete[] month;//month ������ ���� �Ҵ� ����
	return 0;
}