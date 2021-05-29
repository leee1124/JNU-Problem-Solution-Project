#include<iostream>
#include<queue> 
using namespace std;

int map[10][10] = { 0 }; //인접행렬 표현
int visit[10] = { 0 }; //0으로 초기화
queue<int>q;//큐 선언
int num, edge_num;//정점, 간선의 개수

void bfs(int v) {
	cout << v << endl;//현재 정점의 번호 출력
	q.push(v); //일단 현재 정점을 큐에 삽입(반복문 실행을 위해서)
	while (!q.empty()) { //큐가 비어있지 않으면 반복
		int node = q.front(); //현재 정점을 노드 변수에 저장
		q.pop();//방문한 정점을 큐에서 삭제
		for (int i = 0; i < num; i++) { //간선의 개수 만큼 반복
			if (map[node][i] == 1 & visit[i] == 0) {//현재 방문한 정점과 인접한 정점중에서 방문하지 않았으면
				visit[node] = 1;//방문 체크 하고
				cout << i << endl;//방문한 정점 출력
				q.push(i);//큐에 방문 노드 삽입
			}
		}
	}
}

int main() {
	cin >> num >> edge_num;//정점과 간선의 개수 입력
	for (int i = 0; i < edge_num; i++) {//간선의 개수만큼 반복
		int v1, v2;//연결할 정점
		cin >> v1 >> v2;//서로 연결된 정점 입력
		map[v1][v2] = map[v2][v1] = 1;//인접행렬에 연결된 정점 표시(무방향)
	}
	bfs(1);//너비우선탐색
	return 0;//프로그램 종료
}