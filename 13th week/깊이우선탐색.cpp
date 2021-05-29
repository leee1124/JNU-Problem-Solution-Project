#include<iostream>
using namespace std;
int maps[10][10];//인접행렬
int visited[10] = { 0 };//초기화
int num;//간선의 개수

void init() { //초기화
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			maps[i][j] = 0; //맵 배열을 0으로 초기화 해준다
}

void dfs(int v) {
	cout << v << endl;//현재 정점 출력
	visited[v] = 0; //방문 정점 체크
	for (int i = 0; i <= num; i++) { //간선의 개수만큼 반복해서 dfs 실행
		if (maps[v][i] && visited[i]) //현재 정점과 연결된 정점중에서 방문하지 않은 정점에
			dfs(i);//깊이우선탐색
	}
}

int main() {
	int v1, v2; //정점의 정보 
	init();//맵 배열 초기화
	cin >> num; //간선의 개수 입력
	for (int i = 0; i < num; i++) { //간선 개수만큼 반복
		cin >> v1 >> v2;//정점의 정보 입력
		maps[v1][v2] = maps[v2][v1] = 1; //맵변수에 서로 연결된 정점의 정보 표시, 무방향그래프
		visited[v1] = visited[v2] = 1;//방문한 정점을 체크하기 위해 1로 초기화
	} 
	dfs(1); //깊이 우선 탐색 시작
	return 0;//프로그램 종료
}