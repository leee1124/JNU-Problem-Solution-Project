#include<iostream>
#include<set>
#pragma warning(disable:4996)
using namespace std;

int main() {
	int n;//�Է¹��� ������ ����
	scanf("%d", &n);//�Է¹��� ������ ���� �Է�
	set<int>s; //int�� ������ ���� set���� ����

	for (int i = 0; i < n; i++) {
		int x;//set������ ���� int�� ����
		scanf("%d",&x); //set������ ���� int�� ���� �Է�

		if (s.count(x) > 0) { //���� ���� ���� �����ϸ�
			printf("DUPLICATED\n");//Duplicated ���
		}
		else { //���� ���� �������� ������
			s.insert(x); //�� ���� set�� ���� ��
			printf("OK\n");//OK ���
		}
	}
	return 0;//���α׷� ����
}