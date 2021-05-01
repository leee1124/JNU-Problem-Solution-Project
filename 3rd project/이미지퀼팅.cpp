#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#pragma warning(disable:4996)
using namespace std;

int solve(int x, int y, int b1[100][100], int b2[100][100], int dp[100][100], int h, int w) {
	if (x == h) //포개어진 두 이미지의 높이와 x값이 같으면
		return 0;// 함수 종료

	if (dp[x][y] != -1)//dp[x][y]의 값이 -1이 아닌 경우
		return dp[x][y];// ret 변수 반환

	dp[x][y] = solve(x + 1, y, b1, b2, dp, h, w);//dp[x][y]의 값이 -1인경우 x의 값을 1 증가시켜서 재귀로 solve함수 실행

	if (y != 0) //y가 0이 아니면
		dp[x][y] = min(dp[x][y], solve(x + 1, y - 1, b1, b2, dp, h, w));//현재 dp[x][y]값과 x를 1 증가시키고, y를 1 감소시킨 solve 함수의 반환값 중 작은값을 ret 변수에 저장

	if (y != w - 1) //y가 w-1이 아니면
		dp[x][y] = min(dp[x][y], solve(x + 1, y + 1, b1, b2, dp, h, w));//현재 ret값과 x와 y를 각각 1씩 증가시킨 solve 함수의 반환값 중 작은값을 ret 변수에 저장

	return dp[x][y] += ((b1[x][y] - b2[x][y]) * (b1[x][y] - b2[x][y]));//b1[x][y]-b2[x][y]의 제곱값과 dp[x][y]을 더해 dp[x][y]에 저장
}

int main() {
	int h, w;//포개어진 두 이미지의 높이 H, 포개어진 영역의 너비 W
	int b1[100][100], b2[100][100];//B1, B2 이미지의 색상값을 저장할 배열
	int dp[100][100];//dp 배열
	time_t start, end;

	scanf("%d %d", &h, &w);//h와 w 입력받기

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &b1[i][j]);//b1의 이미지 색상값 입력
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &b2[i][j]);//b2의 이미지 색상값 입력
		}
	}
	start = clock();

	memset(dp, -1, sizeof(dp));//dp 배열의 값을 전부 -1로 초기화

	for (int i = 0; i < w; i++) {
		solve(0, i, b1, b2, dp, h, w);//solve 함수 실행
	}

	printf("%d\n", *min_element(dp[0], dp[0] + w));//min_element함수는 주소를 반환하기 때문에 * 연산자를 사용해서 값을 출력 
	end = clock();
	double res = (double)(end - start) / CLOCKS_PER_SEC;
	printf("실행시간: %f초\n", res);
	return 0;//프로그램 종료
}