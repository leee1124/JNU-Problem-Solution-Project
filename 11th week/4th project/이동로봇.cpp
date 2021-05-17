#include <queue>
#include <cstring>
#include <ctime>
#include <vector>
#include <iostream>
using namespace std;

#define UP 0//��
#define RIGHT 1//��
#define DOWN 2//��
#define LEFT 3//��
//���⼺�� ǥ��

typedef struct Point {
	int row, col, dir, time;//��� ��ġ����, ���⼺, �ð�
}point;
typedef vector<vector<int>> vvi;//typedef�� ���� ������ ª�� �� �� �ְ� ����
queue<pair<point, point>> q;//����Ʈ Ÿ�� ť
bool isVIsited[100][100][4];//�湮����

int Move[4][2] = { {-1,0}, {1,0},{0,-1},{0,1} };//�����¿� ������
int Rot[2][4][2] = { {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}},//�ð���� ȸ���� ������
					 {{1, -1}, {-1, -1}, {-1, 1}, {1, 1}} };//�ݽð���� ȸ���� ������
// ccw(�ð�/�ݽð�), ���⼺, ��/�� ����
int corner[2][4][2] = { {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}},//�ð����
						{{-1, -1}, {-1, 1}, {1, 1}, {1, -1}} };//�ݽð����
//ȸ����ų �� �밢�� �ڳʰ� ������ �ƴ��� Ȯ���ϱ� ���� ���
//ccw(�ð�/�ݽð�), ���⼺, ��/�� ����



bool isValid(vvi board, point pt[2], int n) {//������ �ϴ� ���ο� ��ǥ�� ��ȿ���� Ȯ���ϴ� �Լ�
	for (int i = 0; i < 2; i++) {
		if (pt[i].row < 0 || pt[i].row > n - 1 || pt[i].col < 0 || pt[i].col > n - 1) //���带 ����ų�
			return false;
		if (board[pt[i].row][pt[i].col] == 1)//���̰ų�
			return false;
		if(isVIsited[pt[i].row][pt[i].col][pt[i].dir])//�̹� �湮�� ���̸�
			return false;//false ��ȯ
	}
	return true;//�ƴϸ� ��ȿ�ϴٰ� �Ǵ�, true ��ȯ
}
int rotate(vvi board, int n, point curPoint[2], int ccw, int idx) {//������ġ, 0�̸� �ð����/ 1�̸� �ݽð����, ȸ����
	point newPoint[2];//���ο� ��ǥ
	int a = idx, b = (idx+1)%2;//ȸ���� ����
	int dir = curPoint[a].dir;//ȸ������ ���⼺
	newPoint[0] = {curPoint[a].row, curPoint[a].col, 
					(curPoint[a].dir+((ccw == 0 )? 1 : 3))%4, curPoint[a].time+1};
	//���ο� ��ǥ���. ccw�� 1�̸� �ݽð�����̹Ƿ� -1(0���� -1�� �ϸ� ������ �ǹǷ� 3�� ������), ccw�� 0�̸� �ð�����̹Ƿ� 1�� ������.
	//���⼺�� ��, ��, ��, ��(�������� 90���� ȸ��) 0,1,2,3�̱� ������ �����������ڸ� ����ؼ� 0, 1, 2, 3�� ���� �� �� �ֵ��� ��

	newPoint[1] = { curPoint[b].row + Rot[ccw][dir][0], curPoint[b].col+Rot[ccw][dir][1], 
					(curPoint[b].dir + ((ccw == 0) ? 1 : 3)) % 4, curPoint[b].time+1 };
	//���ο� ��ǥ���. ccw�� 1�̸� �ݽð�����̹Ƿ� -1(0���� -1�� �ϸ� ������ �ǹǷ� 3�� ������), ccw�� 0�̸� �ð�����̹Ƿ� 1�� ������.
	//���⼺�� ��, ��, ��, ��(�������� 90���� ȸ��) 0,1,2,3�̱� ������ �����������ڸ� ����ؼ� 0, 1, 2, 3�� ���� �� �� �ֵ��� ��
	if (!isValid(board, newPoint, n))//��ȿ���� ������
		return 0;//0 ��ȯ
	if (board[curPoint[a].row + corner[ccw][dir][0]][curPoint[a].col + corner[ccw][dir][1]])//�밢�� �ڳʰ� ���̸�(0�� �ƴϸ�- 1�̸�)
		return 0;//0 ��ȯ
	for (int i = 0; i < 2; i++) {
		if (newPoint[i].row == n - 1 && newPoint[i].col == n - 1)//�������� ����������
			return newPoint[i].time;//�ɸ� �ð� ��ȯ
		isVIsited[newPoint[i].row][newPoint[i].col][newPoint[i].dir] = true;//�ƴϸ� �湮ǥ��
	}
	q.push({ newPoint[a], newPoint[b] });//ť�� �־ Ž�� ����
	return 0;

}

int solution(vvi board) { 
	memset(isVIsited, false, sizeof(isVIsited));//isVIsited����� ���� false�� �ʱ�ȭ
	int n = board.size();//n�� board�� ũ��

	q.push({ point{0,0,RIGHT,0}, point{0,1,LEFT,0} });//ť�� �ʱⰪ ����
	isVIsited[0][0][RIGHT] = true;//�ʱⰪ�� ���� �湮������
	isVIsited[0][1][LEFT] = true;//�湮�ߴٰ� ǥ��
	
	while (!q.empty()) {//bfs
		point curPoint[2], newPoint[2];//������ǥ, ���ο� ��ǥ(�̵� �� ��ǥ)
		curPoint[0] = q.front().first;//ť���� ���� ��ǥ�� ������
		curPoint[1] = q.front().second;//pair�� ������� ������ first�� second �� �� ������

		q.pop();//ť���� ����

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 2; j++) {
				newPoint[j] = { curPoint[j].row + Move[i][0], curPoint[j].col + Move[i][1], 
								curPoint[j].dir, curPoint[j].time+1 };//���ο� ��ǥ ���
			}
			if (!isValid(board, newPoint, n))//��ȿ���� ������
				continue;//��ŵ
			
			for (int j = 0; j < 2; j++) {
				if (newPoint[j].row == n - 1 && newPoint[j].col == n - 1)//�������� ����������
					return newPoint[j].time;//�ð� ��ȯ
				isVIsited[newPoint[j].row][newPoint[j].col][newPoint[j].dir] = true;//���ο� ��ǥ�� �湮�ߴٰ� ǥ��
			}
			q.push({ newPoint[0],newPoint[1] });
		}
		for (int i = 0; i < 2; i++) {//i�� 0�̸� �ð����, 1�̸� �ݽð���� ȸ��
			for (int j = 0; j < 2; j++) {//�ΰ��� ȸ���� ���
				int answer = rotate(board, n, curPoint,i, j);//ȸ���� �� answer�� ����
				if (answer) {//answer���� 0�� �ƴϸ�
					return answer;//answer�� ��ȯ
				}
			}
		}
	}
	return 0;
}

int main() {
	clock_t start, end;//�ð� �������� ����

	int n;//board �� ���� ����
	vvi board;
	cin >> n;//n�Է�

	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < n; j++)
		{
			int k;
			cin >> k;
			v.push_back(k);
		}
		board.push_back(v);
	}

	cout << endl;

	start = clock();
	int ans = solution(board);

	cout << ans << endl;
	end = clock();
	double res = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "����ð�: " << res << "��" << endl;
}