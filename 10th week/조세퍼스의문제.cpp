#include<iostream>
#include<vector>
#include<queue>
#pragma warning(disable:4996)
using namespace std;

class Player { //�÷��̾� Ŭ���� ����
public:
	int index;//�÷��̾��� �ε���

	Player(int index = 0) {//�ε������� ���� �ȵǸ� 0
		this->index = index;//�ε������� �Ű������� ������ �ش� ���� �ε��� ������ �����ϴ� ������
	}
};

vector<Player>getDeadPlayerList(int n, int m, const vector<Player>& players) {//�÷��̾��� ��, �ǳ� �� ����� ��, �÷��̾� ����

	vector <Player> deadPlayers; //���� ���ܵ� �÷��̾� ����Ʈ

	queue<Player> que;//���ܵ��� ���� �÷��̾� ����Ʈ

	for (int i = 0; i < n; i++){
		que.push(players[i]); //ť�� �÷��̾� ������ �ִ´�
	}

	for (int i = 0; i < n; i++) {
		int jump = 1 + (m - 1) % que.size();//m-1���� ������� �ǳ� ��
		for (int j = 0; j < jump - 1; j++) {
			Player p = que.front();//���� �տ� �ִ� ������ p��� ������ �ӽ÷� ������ ����
			que.pop();//ť������ �����ߴٰ�
			que.push(p);//�ٽ� �־� ť�� ���� �ڷ� �ű�
		}
		Player dead = que.front();//���� �ݺ����� �����ϸ� ť�� ���� �տ� �ִ� ������ ���ܵǴ� �÷��̾�
		que.pop(); //���ܵǴ� �÷��̾ ť���� ����

		deadPlayers.push_back(dead);//�̹��� ���ܵ� �÷��̾ ���ܵǴ� �÷��̾� ���Ϳ��� �߰�
	}
	return deadPlayers;//���ܵǴ� �÷��̾� ���� ��ȯ
}

void process(int caseIndex) {
	int n, m;//n���� ���, ���� m
	scanf("%d %d", &n, &m); //n���� �����, �� �ϸ��� �ǳ� �� ����� �� m �Է�

	vector<Player> players;//�÷��̾ ������ ���ͺ���
	for (int i = 0; i < n; i++) {//��� ����ŭ �ݺ�
		players.push_back(Player(i + 1));//�÷��̾��� �ε��� ����
	}

	vector<Player> deadPlayers = getDeadPlayerList(n, m, players);//���ܵǴ� �÷��̾� ���͸� �޾ƿ�

	for (int i = 0; i < n; i++)//���ܵ� �÷��̾� ������� ���
	{
		if (i > 0) {
			printf(" ");//�� ��� �߰��� ���⸦ ���� ���� ���
		}
		Player p = deadPlayers[i];//i��°�� ����� ���ܵ� �÷��̾ �÷��̾� Ŭ���� ��ü p�� ����
		printf("%d", p.index);//p�� �ε��� ���
	}
	printf("\n");//����
}

int main() {
	int caseSize;//�׽�Ʈ ���̽��� ������ �Է� �ޱ� ���� ����
	scanf("%d ", &caseSize);//�׽�Ʈ ���̽� �Է�

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {//�׽�Ʈ ���̽���ŭ �ݺ��ؼ�
		process(caseIndex); //process �Լ� ����
	}
	return 0;//���α׷� ����
}