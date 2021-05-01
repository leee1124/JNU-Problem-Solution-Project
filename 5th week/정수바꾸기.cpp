#include<cstdio>
#include<ctime>
#pragma warning(disable:4996)
using namespace std;

int main() {
	clock_t start, end;//실행시간을 측정하기 위한 변수, 프로그램의 시작과 끝을 의미함
	int a, b;//a와 b. 10의 9승까지인 정수이므로 int 자료형에 포함된다.
	scanf("%d %d", &a, &b);//a와 b 입력
	start = clock();

	int cnt = 0;//연산횟수

	while (a<b) {//a가 b보다 작을때만 반복
		if (b % 10 == 1) {//b가 1로 나눠지면
			b = (b - 1) / 10;//1을 제거함
			cnt++;//연산횟수 증가
		}
		else if (b % 2 == 0) {//b가 2로 나눠지면
			b /= 2;//b를 2로 나눔
			cnt++;//연산횟수
		}
		else
			break;//일의자리수가 1이 아니면 반복문 빠져나옴(가지치기)
	}
	printf("%d\n", (a == b) ? cnt+1 : -1);//a와b가 같으면(연산에 성공하면) 연산횟수에 1을 더한값을 출력, 만들 수 없는 경우에는 -1 출력
	end = clock();
	double result = (double)(end - start) / CLOCKS_PER_SEC;//끝 시간에서 시작시간을 빼서 시간값 계산하고, ms 단위를 초 단위로 변경
	printf("실행시간: %f초\n", result);// 프로그램 실행시간 출력
	return 0;//프로그램 종료
}