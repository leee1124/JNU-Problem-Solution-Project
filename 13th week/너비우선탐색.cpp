#include<iostream>
#include<queue> 
using namespace std;

int map[10][10] = { 0 }; //������� ǥ��
int visit[10] = { 0 }; //0���� �ʱ�ȭ
queue<int>q;//ť ����
int num, edge_num;//����, ������ ����

void bfs(int v) {
	cout << v << endl;//���� ������ ��ȣ ���
	q.push(v); //�ϴ� ���� ������ ť�� ����(�ݺ��� ������ ���ؼ�)
	while (!q.empty()) { //ť�� ������� ������ �ݺ�
		int node = q.front(); //���� ������ ��� ������ ����
		q.pop();//�湮�� ������ ť���� ����
		for (int i = 0; i < num; i++) { //������ ���� ��ŭ �ݺ�
			if (map[node][i] == 1 & visit[i] == 0) {//���� �湮�� ������ ������ �����߿��� �湮���� �ʾ�����
				visit[node] = 1;//�湮 üũ �ϰ�
				cout << i << endl;//�湮�� ���� ���
				q.push(i);//ť�� �湮 ��� ����
			}
		}
	}
}

int main() {
	cin >> num >> edge_num;//������ ������ ���� �Է�
	for (int i = 0; i < edge_num; i++) {//������ ������ŭ �ݺ�
		int v1, v2;//������ ����
		cin >> v1 >> v2;//���� ����� ���� �Է�
		map[v1][v2] = map[v2][v1] = 1;//������Ŀ� ����� ���� ǥ��(������)
	}
	bfs(1);//�ʺ�켱Ž��
	return 0;//���α׷� ����
}