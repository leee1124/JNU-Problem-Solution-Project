#include <queue>
#include <cstring>
#include <ctime>
#include <vector>
#include <iostream>
using namespace std;

#define UP 0//상
#define RIGHT 1//우
#define DOWN 2//하
#define LEFT 3//좌
//방향성을 표현

typedef struct Point {
	int row, col, dir, time;//행렬 위치정보, 방향성, 시간
}point;
typedef vector<vector<int>> vvi;//typedef을 통해 선언을 짧게 할 수 있게 줄임
queue<pair<point, point>> q;//포인트 타입 큐
bool isVIsited[100][100][4];//방문여부

int Move[4][2] = { {-1,0}, {1,0},{0,-1},{0,1} };//상하좌우 움직임
int Rot[2][4][2] = { {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}},//시계방향 회전시 움직임
					 {{1, -1}, {-1, -1}, {-1, 1}, {1, 1}} };//반시계방향 회전시 움직임
// ccw(시계/반시계), 방향성, 행/열 순서
int corner[2][4][2] = { {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}},//시계방향
						{{-1, -1}, {-1, 1}, {1, 1}, {1, -1}} };//반시계방향
//회전시킬 때 대각선 코너가 벽인지 아닌지 확인하기 위해 사용
//ccw(시계/반시계), 방향성, 행/열 순서



bool isValid(vvi board, point pt[2], int n) {//가려고 하는 새로운 좌표가 유효한지 확인하는 함수
	for (int i = 0; i < 2; i++) {
		if (pt[i].row < 0 || pt[i].row > n - 1 || pt[i].col < 0 || pt[i].col > n - 1) //보드를 벗어나거나
			return false;
		if (board[pt[i].row][pt[i].col] == 1)//벽이거나
			return false;
		if(isVIsited[pt[i].row][pt[i].col][pt[i].dir])//이미 방문한 곳이면
			return false;//false 반환
	}
	return true;//아니면 유효하다고 판단, true 반환
}
int rotate(vvi board, int n, point curPoint[2], int ccw, int idx) {//현재위치, 0이면 시계방향/ 1이면 반시계방향, 회전축
	point newPoint[2];//새로운 좌표
	int a = idx, b = (idx+1)%2;//회전축 결정
	int dir = curPoint[a].dir;//회전축의 방향성
	newPoint[0] = {curPoint[a].row, curPoint[a].col, 
					(curPoint[a].dir+((ccw == 0 )? 1 : 3))%4, curPoint[a].time+1};
	//새로운 좌표계산. ccw가 1이면 반시계방향이므로 -1(0에서 -1을 하면 음수가 되므로 3을 더해줌), ccw가 0이면 시계방향이므로 1을 더해줌.
	//방향성이 상, 우, 하, 좌(우측으로 90도씩 회전) 0,1,2,3이기 때문에 나머지연산자를 사용해서 0, 1, 2, 3이 유지 될 수 있도록 함

	newPoint[1] = { curPoint[b].row + Rot[ccw][dir][0], curPoint[b].col+Rot[ccw][dir][1], 
					(curPoint[b].dir + ((ccw == 0) ? 1 : 3)) % 4, curPoint[b].time+1 };
	//새로운 좌표계산. ccw가 1이면 반시계방향이므로 -1(0에서 -1을 하면 음수가 되므로 3을 더해줌), ccw가 0이면 시계방향이므로 1을 더해줌.
	//방향성이 상, 우, 하, 좌(우측으로 90도씩 회전) 0,1,2,3이기 때문에 나머지연산자를 사용해서 0, 1, 2, 3이 유지 될 수 있도록 함
	if (!isValid(board, newPoint, n))//유효하지 않으면
		return 0;//0 반환
	if (board[curPoint[a].row + corner[ccw][dir][0]][curPoint[a].col + corner[ccw][dir][1]])//대각선 코너가 벽이면(0이 아니면- 1이면)
		return 0;//0 반환
	for (int i = 0; i < 2; i++) {
		if (newPoint[i].row == n - 1 && newPoint[i].col == n - 1)//목적지에 도착했으면
			return newPoint[i].time;//걸린 시간 반환
		isVIsited[newPoint[i].row][newPoint[i].col][newPoint[i].dir] = true;//아니면 방문표시
	}
	q.push({ newPoint[a], newPoint[b] });//큐에 넣어서 탐색 진행
	return 0;

}

int solution(vvi board) { 
	memset(isVIsited, false, sizeof(isVIsited));//isVIsited행렬을 전부 false로 초기화
	int n = board.size();//n은 board의 크기

	q.push({ point{0,0,RIGHT,0}, point{0,1,LEFT,0} });//큐에 초기값 삽입
	isVIsited[0][0][RIGHT] = true;//초기값을 통해 방문했으니
	isVIsited[0][1][LEFT] = true;//방문했다고 표시
	
	while (!q.empty()) {//bfs
		point curPoint[2], newPoint[2];//현재좌표, 새로운 좌표(이동 할 좌표)
		curPoint[0] = q.front().first;//큐에서 현재 좌표를 가져옴
		curPoint[1] = q.front().second;//pair로 묶어놨기 때문에 first와 second 둘 다 가져옴

		q.pop();//큐에서 삭제

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 2; j++) {
				newPoint[j] = { curPoint[j].row + Move[i][0], curPoint[j].col + Move[i][1], 
								curPoint[j].dir, curPoint[j].time+1 };//새로운 좌표 계산
			}
			if (!isValid(board, newPoint, n))//유효하지 않으면
				continue;//스킵
			
			for (int j = 0; j < 2; j++) {
				if (newPoint[j].row == n - 1 && newPoint[j].col == n - 1)//목적지에 도착했으면
					return newPoint[j].time;//시간 반환
				isVIsited[newPoint[j].row][newPoint[j].col][newPoint[j].dir] = true;//새로운 좌표에 방문했다고 표시
			}
			q.push({ newPoint[0],newPoint[1] });
		}
		for (int i = 0; i < 2; i++) {//i가 0이면 시계방향, 1이면 반시계방향 회전
			for (int j = 0; j < 2; j++) {//두개의 회전축 사용
				int answer = rotate(board, n, curPoint,i, j);//회전한 후 answer에 저장
				if (answer) {//answer값이 0이 아니면
					return answer;//answer값 반환
				}
			}
		}
	}
	return 0;
}

int main() {
	clock_t start, end;//시간 측정위한 변수

	int n;//board 한 변의 길이
	vvi board;
	cin >> n;//n입력

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
	cout << "실행시간: " << res << "초" << endl;
}