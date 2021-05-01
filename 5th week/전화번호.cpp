#include<cstdio>
#pragma warning(disable:4996)
using namespace std;

const int MAX_TABLE_LENGTH = 10000;//0000~ 9999���� �̹Ƿ� ��ȭ��ȣ ���ڸ��� ���� 10000��

void fillFrequnecyTable(int data[], int n, int table[]) {//data[0] ~ data[n-1]�� ������ ��ȣ�鿡 ���� �󵵼� ���̺��� ä��� �Լ�
	int frequent_number = 0;//data�迭�� ����ִ� ��ȭ��ȣ ���ڸ��� ������ �迭
	for (int i = 0; i < n; i++) {//��ȭ��ȣ ������ŭ �ݺ�
		frequent_number = data[i];//data�迭�� ����ִ� ��ȭ��ȣ ���ڸ��� ����
		table[frequent_number]++;//��ȭ��ȣ�� �ش��ϴ� �󵵼� ���̺��� ���� ����
	}//frequent_table�� ������� �ʾƵ�, table[data[i]]++;���� ��� ����
}

int getFrequentNumber(int data[], int n) {
	int frequent_number = 0;//���� ���� ���� ��ȭ��ȣ ���ڸ��� �Է¹��� ����
	int table[MAX_TABLE_LENGTH] = { 0 };//��ȭ��ȣ�� �ִ� ����ŭ �󵵼� ���̺��� 0���� �ʱ�ȭ��

	fillFrequnecyTable(data, n, table);

	for (int i = 0; i < 10000; i++) {//0000~9999���� �ݺ�
		if (table[i] > table[frequent_number])//i�� ���� ������ �����ϱ� ������ Ƚ���� ���� ��ȣ�� 2���� ���, ���� ���ڰ� ���� ����
			frequent_number = i;//���� �ִ� �󵵼����� �� ���� ���� ���ڰ� ������ �ִ� �󵵼��� ���� ��ȭ��ȣ ������Ʈ
	}

	return frequent_number;//�ִ� �󵵼��� ���� ��ȭ��ȣ ���ڸ� ��ȯ
}

int main() {
	int n;//��ȭ��ȣ�� ������ �Է¹��� ����
	
	scanf("%d", &n);//��ȭ��ȣ ���� �Է�
	int* data = new int[n];//data�迭�� ��ȭ��ȣ ������ŭ ���� �Ҵ�

	for (int i = 0; i < n; ++i) {
		scanf("%d", &data[i]);//n���� ��ȭ��ȣ �Է�
	}
	int answer = getFrequentNumber(data, n);//0000~9999�� ���� ���� ���� ��ȭ��ȣ�� answer�� ����

	printf("%04d", answer);//%04d�� �̿��� 4�ڸ� ���ڰ� ����

	delete[] data;//data�迭 �����Ҵ� ����
	return 0;//���α׷� ����
}