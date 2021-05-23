#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	int n; //��ǥ������ ��
	cin >> n;//��ǥ������ �� �Է�

	map<string, int> frequencyMap;//�ĺ��� �̸��� ��ǥ�� �����ϴ� �ʺ���
	int maxFrequency = 0;//�ִ� ��ǥ��

	for (int i = 0; i < n; i++) {//��ǥ������ �� ��ŭ �ݺ�
		string st;//�ĺ��� �̸��� �Է¹��� ����
		cin >> st;//�̸� �Է�
		frequencyMap[st]++; //�ش� �ĺ��� ��ǥ�� ������Ŵ
		int k = frequencyMap[st];//��ǥ���� ���� k�� ����
		if (k > maxFrequency) {//���� ��ǥ���� �ִ� ��ǥ������ ũ��
			maxFrequency = k;//�ִ� ��ǥ���� �ٲ���
		}
	}
	cout << maxFrequency << endl; //�ִ� ��ǥ�� ���

	map<string, int>::iterator it; //�ĺ� ����ϱ� ���� iterator ���� ����
	for (it = frequencyMap.begin(); it != frequencyMap.end(); it++){//frequencyMap�� ó������ ������ �ݺ�
		if (it->second == maxFrequency) //�ִ� ��ǥ���� ����
			printf("%s ", it->first.c_str());//�ĺ��� �̸��� ����Ѵ�.
	}
}