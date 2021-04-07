#include<iostream>
#include<ctime>//clock 함수를 사용하기 위한 헤더파일
#pragma warning(disable:4996)
using namespace std;
/*
-----Parameter
JN: 전남이가 입력받은 모양
friends: 친구들이 입력받은 모양
n: 친구들의 수
r: 라운드
*/
int getScore(string JN, string friends[], int n, int r) {
	int Real_score = 0;//전남이의 실제 점수
	for (int i = 0; i < n; i++) {//친구들의 수만큼
		for (int j = 0; j < r; j++) {//한 사람당 라운드 횟수만큼 반복
			if (JN[j] == 'R') {//전남이가 바위인데
				if (friends[i][j] == 'R') Real_score++;// 친구도 바위이면, 실제점수는 1점
				else if (friends[i][j] == 'S') Real_score += 2;//가위이면 실제 점수는 2점
			}
			if (JN[j] == 'S') {//전남이가 가위인데
				if (friends[i][j] == 'S') Real_score++;// 친구도 가위이면, 실제점수는 1점
				else if (friends[i][j] == 'P') Real_score += 2;//보이면 실제 점수는 2점
			}
			if (JN[j] == 'P') {//전남이가 보인데
				if (friends[i][j] == 'P') Real_score++;// 친구도 보이면, 실제점수는 1점
				else if (friends[i][j] == 'R') Real_score += 2;// 바위이면, 실제점수는 1점
			}//지는경우는 점수에 변화가 없으므로 고려하지 않음
		}
	}
	return Real_score;//계산된 실제 점수를 반환함
}

int main() {
	clock_t start, end;//실행시간을 측정하기 위한 변수, 프로그램의 시작과 끝을 의미함
	
	int n, round;//친구들의 수, 라운드
	string JN, * friends;//전남이의 가위바위보 모양과, 친구들의 가위바위보 모양
	scanf("%d", &round);// 라운드 입력
	cin >> JN;// 전남이의 가위바위보 모양 입력
	scanf("%d", &n);// 친구들의 수 입력

	friends = new string[n+1];//친구들 배열 동적할당

	for (int i = 0; i < n; i++) {
		cin >> friends[i];//친구들의 가위바위보 모양 입력
	}
	start = clock();//프로그램 시작시간 측정

	int score = getScore(JN, friends, n, round);//실제 점수를 계산하는 함수

	printf("%d\n", score);//실제 점수 출력

	int Ideal_score = 0;//이상적인 점수(가능한 가장 높은 점수)를 계산하기 위한 변수

	for (int i = 0; i < round; i++) {//한 라운드에서 점수를 먼저 계산해야 하므로, 라운드가 먼저 반복됨
		int R = 0, S = 0, P = 0;//친구들의 가위바위보의 개수와
		int tmp_score = 0;//이번 라운드에서 가장 높은 점수를 임시 저장

		for (int j = 0; j < n; j++) {//한 라운드에서 모든 친구들과의 점수를 계산하기 위한 반복
			if (friends[j][i] == 'R') R++; // 친구들이 해당 라운드에 낸 모양이 바위이면 R의 개수 증가
			else if (friends[j][i] == 'S') S++;//친구들이 해당 라운드에 낸 모양이 가위이면 S의 개수 증가
			else P++;//둘 다 아니면(보이면) P의 개수 증가
		}
		if(2*S + R >= 2*P+S && 2*S+R>= 2*R+P) tmp_score = 2 * S + R;//주먹을 냈을 때 점수가 최대 점수라면
		else if (2*P+S >= 2*S+R && 2*P + S >= 2*R+P) tmp_score = 2*P+S;//가위을 냈을 때가 최대 점수라면
		else if (2 * R + P >= 2*S+R && 2 * R + P >= 2 * P + S) tmp_score = 2 * R + P;//보를 냈을 때가 최대 점수라면

		Ideal_score += tmp_score;//이번 라운드의 이상점수를 총 이상적인 점수에 추가함
	}

	printf("%d\n", Ideal_score);// 이상적인 점수 출력
	delete[] friends;//친구들 문자열 배열 동적할당 해제

	end = clock();//프로그램이 끝나는 시간 측정
	double result = (double)(end - start)/CLOCKS_PER_SEC;//끝 시간에서 시작시간을 빼서 시간값 계산하고, ms 단위를 초 단위로 변경
	printf("실행시간: %f초\n", result);// 프로그램 실행시간 출력
}