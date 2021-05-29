#include<iostream>
using namespace std;
int maps[10][10];//�������
int visited[10] = { 0 };//�ʱ�ȭ
int num;//������ ����

void init() { //�ʱ�ȭ
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			maps[i][j] = 0; //�� �迭�� 0���� �ʱ�ȭ ���ش�
}

void dfs(int v) {
	cout << v << endl;//���� ���� ���
	visited[v] = 0; //�湮 ���� üũ
	for (int i = 0; i <= num; i++) { //������ ������ŭ �ݺ��ؼ� dfs ����
		if (maps[v][i] && visited[i]) //���� ������ ����� �����߿��� �湮���� ���� ������
			dfs(i);//���̿켱Ž��
	}
}

int main() {
	int v1, v2; //������ ���� 
	init();//�� �迭 �ʱ�ȭ
	cin >> num; //������ ���� �Է�
	for (int i = 0; i < num; i++) { //���� ������ŭ �ݺ�
		cin >> v1 >> v2;//������ ���� �Է�
		maps[v1][v2] = maps[v2][v1] = 1; //�ʺ����� ���� ����� ������ ���� ǥ��, ������׷���
		visited[v1] = visited[v2] = 1;//�湮�� ������ üũ�ϱ� ���� 1�� �ʱ�ȭ
	} 
	dfs(1); //���� �켱 Ž�� ����
	return 0;//���α׷� ����
}