#include<iostream>
#include<ctime>//clock �Լ��� ����ϱ� ���� �������
#pragma warning(disable:4996)
using namespace std;
/*
-----Parameter
JN: �����̰� �Է¹��� ���
friends: ģ������ �Է¹��� ���
n: ģ������ ��
r: ����
*/
int getScore(string JN, string friends[], int n, int r) {
	int Real_score = 0;//�������� ���� ����
	for (int i = 0; i < n; i++) {//ģ������ ����ŭ
		for (int j = 0; j < r; j++) {//�� ����� ���� Ƚ����ŭ �ݺ�
			if (JN[j] == 'R') {//�����̰� �����ε�
				if (friends[i][j] == 'R') Real_score++;// ģ���� �����̸�, ���������� 1��
				else if (friends[i][j] == 'S') Real_score += 2;//�����̸� ���� ������ 2��
			}
			if (JN[j] == 'S') {//�����̰� �����ε�
				if (friends[i][j] == 'S') Real_score++;// ģ���� �����̸�, ���������� 1��
				else if (friends[i][j] == 'P') Real_score += 2;//���̸� ���� ������ 2��
			}
			if (JN[j] == 'P') {//�����̰� ���ε�
				if (friends[i][j] == 'P') Real_score++;// ģ���� ���̸�, ���������� 1��
				else if (friends[i][j] == 'R') Real_score += 2;// �����̸�, ���������� 1��
			}//���°��� ������ ��ȭ�� �����Ƿ� ������� ����
		}
	}
	return Real_score;//���� ���� ������ ��ȯ��
}

int main() {
	clock_t start, end;//����ð��� �����ϱ� ���� ����, ���α׷��� ���۰� ���� �ǹ���
	
	int n, round;//ģ������ ��, ����
	string JN, * friends;//�������� ���������� ����, ģ������ ���������� ���
	scanf("%d", &round);// ���� �Է�
	cin >> JN;// �������� ���������� ��� �Է�
	scanf("%d", &n);// ģ������ �� �Է�

	friends = new string[n+1];//ģ���� �迭 �����Ҵ�

	for (int i = 0; i < n; i++) {
		cin >> friends[i];//ģ������ ���������� ��� �Է�
	}
	start = clock();//���α׷� ���۽ð� ����

	int score = getScore(JN, friends, n, round);//���� ������ ����ϴ� �Լ�

	printf("%d\n", score);//���� ���� ���

	int Ideal_score = 0;//�̻����� ����(������ ���� ���� ����)�� ����ϱ� ���� ����

	for (int i = 0; i < round; i++) {//�� ���忡�� ������ ���� ����ؾ� �ϹǷ�, ���尡 ���� �ݺ���
		int R = 0, S = 0, P = 0;//ģ������ ������������ ������
		int tmp_score = 0;//�̹� ���忡�� ���� ���� ������ �ӽ� ����

		for (int j = 0; j < n; j++) {//�� ���忡�� ��� ģ������� ������ ����ϱ� ���� �ݺ�
			if (friends[j][i] == 'R') R++; // ģ������ �ش� ���忡 �� ����� �����̸� R�� ���� ����
			else if (friends[j][i] == 'S') S++;//ģ������ �ش� ���忡 �� ����� �����̸� S�� ���� ����
			else P++;//�� �� �ƴϸ�(���̸�) P�� ���� ����
		}
		if(2*S + R >= 2*P+S && 2*S+R>= 2*R+P) tmp_score = 2 * S + R;//�ָ��� ���� �� ������ �ִ� �������
		else if (2*P+S >= 2*S+R && 2*P + S >= 2*R+P) tmp_score = 2*P+S;//������ ���� ���� �ִ� �������
		else if (2 * R + P >= 2*S+R && 2 * R + P >= 2 * P + S) tmp_score = 2 * R + P;//���� ���� ���� �ִ� �������

		Ideal_score += tmp_score;//�̹� ������ �̻������� �� �̻����� ������ �߰���
	}

	printf("%d\n", Ideal_score);// �̻����� ���� ���
	delete[] friends;//ģ���� ���ڿ� �迭 �����Ҵ� ����

	end = clock();//���α׷��� ������ �ð� ����
	double result = (double)(end - start)/CLOCKS_PER_SEC;//�� �ð����� ���۽ð��� ���� �ð��� ����ϰ�, ms ������ �� ������ ����
	printf("����ð�: %f��\n", result);// ���α׷� ����ð� ���
}