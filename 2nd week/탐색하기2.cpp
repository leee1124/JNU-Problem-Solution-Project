#include<cstdio>
#include<string>
#include<iostream>
#pragma warning(disable: 4996)
using namespace std;

void printIndexes(string school[], int n) {
	int first = -1;//�������� ������ -1
	int last = -1;//�������� ������ -1

	for (int i = 0; i < n; i++) {
		if (school[i] == "AJOU") {//�迭�� i��° ���ҿ� AJOU�� ���ؼ� ������
			if (first == -1)//AJOU�� ó�� �������� 
				first = i + 1;//�迭�� �ε����� 0���� �����ϹǷ� �ε��� + 1�� first�� ����
			last = i+1;//last�� AJOU�� ���� ������ ����ؼ� ����
		}
	}

	printf("%d %d\n", first, last);
}

int main() {
	int n;
	char buff[11];
	string* school;

	scanf("%d", &n);
	school = new string[n];

	for (int i = 0; i < n; i++) {
		scanf("%s", buff);//buff ������ ���ڿ��� �Է¹޾�
		school[i] = buff;//school �迭�� ����
	}

	printIndexes(school, n);//�ε��� ��� �Լ�, void�� �Լ��̱� ������ ��ȯ���� ���� �Լ� ������ ���

	delete[] school;
	return 0;
}
