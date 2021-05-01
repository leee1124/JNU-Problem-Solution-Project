#include<cstdio>
#include<ctime>
#pragma warning(disable: 4996)
using namespace std;

void rotation(int gear[][8], int n, int dir)//톱니바퀴를 회전하는 함수
{
	int tmp;//12시의 상태를 저장하기 위한 임시 변수
	if (dir == 1) {//시계방향으로 회전
		for (int j = 7; j >= 0; j--) {	
			if (j != 0) {
				if (j == 7) tmp = gear[n][j];//12시 방향의 상태로 이동할 기존 마지막 상태를 tmp 변수에 저장
				gear[n][j] = gear[n][j - 1];//12시 방향의 상태를 제외한 상태들은 자신의 이전 상태	
				
			}
			else {//톱니바퀴의 12시의 상태는
				gear[n][j] = tmp;//기존 마지막 상태
			}
		}
	}
	else {//반시계 방향으로 회전
		for (int j = 0; j < 8; j++) {
			if (j != 7) {
				if (j == 0) tmp = gear[n][j];//마지막 상태로 이동할 12시 방향의 상태를 tmp 변수에 저장
				gear[n][j] = gear[n][j + 1];//마지막을 제외한 상태들은 자신의 다음 상태
			}
			else {//톱니바퀴의 마지막 상태는
				gear[n][j] = tmp;//기존 12시 방향의 상태
			}
		}
	}
}

void check_gear(int gear[][8], int n, int dir, int chk[]) {//서로 맞닿은 톱니바퀴를 회전시킬 수 있는지 확인하는 함수
	if (chk[n] == 1) return;//만약 이미 확인한 톱니바퀴라면 함수 반환
	chk[n] = 1;//n번째 톱니바퀴를 확인했다고 확인함 
	if (n == 0) {//n이 0이면(좌측 끝 톱니바퀴이면) 우측 톱니바퀴밖에 없으므로
		if (gear[n][2] != gear[n + 1][6])//우측에 맞닿은 톱니바퀴만 확인함
			check_gear(gear, n+1, (dir == 1) ? -1 : 1, chk);//맞닿은 톱니바퀴의 극이 다르다면 우측 톱니바퀴 확인
	}
	else if (n == 3) {//n이 3이면(우측 끝 톱니바퀴이면) 좌측 톱니바퀴밖에 없으므로
		if (gear[n][6] != gear[n - 1][2])//좌측에 맞닿은 톱니바퀴만 확인함
			check_gear(gear, n - 1, (dir == 1) ? -1 : 1, chk);//맞닿은 톱니바퀴의 극이 다르다면 좌측 톱니바퀴 확인
	}
	else {//만약 좌측끝 톱니바퀴도, 우측 끝 톱니바퀴도 아니라면
		if (gear[n][2] != gear[n + 1][6])//우측에 맞닿은 톱니바퀴 확인
			check_gear(gear, n + 1, (dir == 1) ? -1 : 1, chk);//맞닿은 톱니바퀴의 극이 다르다면 우측 톱니바퀴 확인

		if (gear[n][6] != gear[n - 1][2])//그리고 좌측 톱니바퀴도 확인함
			check_gear(gear, n - 1, (dir == 1) ? -1 : 1, chk);//맞닿은 톱니바퀴의 극이 다르다면 우측 톱니바퀴 확인
	}
	rotation(gear, n, dir);//현재 톱니바퀴 회전시키는 함수 호출
}

int get_score(int gear[][8]) {//점수를 계산하는 함수
	int score = 0;//첫 점수는 0점으로 초기화
	for (int i = 0; i < 4; i++) {//톱니바퀴 4개 전부 검사
		if (gear[i][0] == 1) {//12시 방향의 톱니바퀴가 S극이면
			if (i == 0)//1번 톱니바퀴일경우
				score += 1;//1점
			else if(i == 1)//2번 톱니바퀴일 경우
				score += 2;//2점
			else if (i == 2)//3번 톱니바퀴일 경우
				score += 4;//8점
			else//그 외일경우(4번 톱니바퀴일 경우)
				score += 8;//8점
		}
	}
	return score;//점수 반환
}

int main() {
	clock_t start, end;//실행시간을 측정하기 위한 변수, 프로그램의 시작과 끝을 의미함
	double result=0;//시간을 초단위로 바꾸기 위한 변수
	int gear[4][8];//톱니바퀴의 상태를 담을 배열

	for (int i = 0; i < 4; i++) {//톱니바퀴는 4개이고
		for (int j = 0; j < 8; j++) {//상태는 각각 8개의 정수로 이루어짐
			scanf("%1d", &gear[i][j]);//톱니바퀴 상태 입력
		}
	}

	int k, n, dir;//회전횟수, 회전시킨 톱니바퀴 번호, 방향
	int ans = 0;//점수를 저장하는 함수
	scanf("%d", &k);//회전 횟수 k를 입력받음

	for (int i = 0; i < k; i++) {//회전횟수만큼 반복
		int chk[4] = { 0 };//톱니바퀴의 확인상태를 저장하는 배열. 0이면 아직 확인전, 1이면 확인함
		scanf("%d %d", &n, &dir);//회전시킨 톱니바퀴 번호와 회전 방향을 입력
		start = clock();//함수 시작시간 측정
		check_gear(gear, n - 1, dir, chk);//서로 맞닿은 톱니바퀴를 회전시킬 수 있는지 확인
		end = clock();//함수 끝나는 시간 측정
		result = result + (double)(end - start);//반복적으로 함수를 실행시키기 때문에, 살향시간을 더함
	}
	start = clock();//get_score 함수와 점수값 출력 시간 측정 시작
	ans = get_score(gear);//점수를 계산하는 함수를 이용해 점수를 계산
	printf("%d\n", ans);//계산한 점수값 출력
	end = clock();//get_score 함수와 점수값 출력 시간 측정 종료
	
	result = result + (double)(end - start);//입력 이후 프로그램 시간 계산
	result = result / CLOCKS_PER_SEC;//ms 단위를 초 단위로 변경
	printf("실행시간 : %f초\n", result);//프로그램 실행시간 출력

	return 0;//프로그램 종료
}	