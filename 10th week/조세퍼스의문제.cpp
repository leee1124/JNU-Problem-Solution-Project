#include<iostream>
#include<vector>
#include<queue>
#pragma warning(disable:4996)
using namespace std;

class Player { //플래이어 클래스 선언
public:
	int index;//플레이어의 인덱스

	Player(int index = 0) {//인덱스값이 설정 안되면 0
		this->index = index;//인덱스값이 매개변수로 들어오면 해당 값을 인덱스 값으로 설정하는 생성자
	}
};

vector<Player>getDeadPlayerList(int n, int m, const vector<Player>& players) {//플레이어의 수, 건너 뛸 사람의 수, 플레이어 정보

	vector <Player> deadPlayers; //현재 제외된 플레이어 리스트

	queue<Player> que;//제외되지 않은 플레이어 리스트

	for (int i = 0; i < n; i++){
		que.push(players[i]); //큐에 플레이어 정보를 넣는다
	}

	for (int i = 0; i < n; i++) {
		int jump = 1 + (m - 1) % que.size();//m-1명의 사람들을 건너 뜀
		for (int j = 0; j < jump - 1; j++) {
			Player p = que.front();//가장 앞에 있는 변수를 p라는 변수가 임시로 가지고 있음
			que.pop();//큐에서는 삭제했다가
			que.push(p);//다시 넣어 큐의 가장 뒤로 옮김
		}
		Player dead = que.front();//위의 반복문을 수행하면 큐의 가장 앞에 있는 변수는 제외되는 플레이어
		que.pop(); //제외되는 플레이어를 큐에서 삭제

		deadPlayers.push_back(dead);//이번에 제외된 플레이어를 제외되는 플레이어 벡터에에 추가
	}
	return deadPlayers;//제외되는 플레이어 벡터 반환
}

void process(int caseIndex) {
	int n, m;//n명의 사람, 간격 m
	scanf("%d %d", &n, &m); //n명의 사람들, 매 턴마다 건너 뛸 사람의 수 m 입력

	vector<Player> players;//플레이어를 저장할 벡터변수
	for (int i = 0; i < n; i++) {//사람 수만큼 반복
		players.push_back(Player(i + 1));//플레이어의 인덱스 설정
	}

	vector<Player> deadPlayers = getDeadPlayerList(n, m, players);//제외되는 플레이어 벡터를 받아옴

	for (int i = 0; i < n; i++)//제외된 플레이어 순서대로 출력
	{
		if (i > 0) {
			printf(" ");//값 출력 중간에 띄어쓰기를 위한 공백 출력
		}
		Player p = deadPlayers[i];//i번째에 저장된 제외된 플레이어를 플레이어 클래스 객체 p에 저장
		printf("%d", p.index);//p의 인덱스 출력
	}
	printf("\n");//개행
}

int main() {
	int caseSize;//테스트 케이스의 개수를 입력 받기 위한 변수
	scanf("%d ", &caseSize);//테스트 케이스 입력

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {//테스트 케이스만큼 반복해서
		process(caseIndex); //process 함수 실행
	}
	return 0;//프로그램 종료
}