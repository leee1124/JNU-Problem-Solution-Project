#include<cstdio>
#include<algorithm>
#pragma warning(disable: 4996)
using namespace std;

int get_area(int la, int ra, int ta, int ba, int lb, int rb, int tb, int bb) {
	int l, r, t, b;//왼쪽, 오른쪽, 위, 아래
	 l = max(la, lb);//두 직사각형의 왼쪽 x좌표 중에서 더 큰 값이 왼쪽 x좌표
	 r = min(ra, rb);//두 직사각형의 오른쪽 x좌표 중에서 더 작은 값이 오른쪽 x좌표
	 t = min(ta, tb);//두 직사각형의 위쪽 y좌표 중에서 더 작은 값이 위쪽 y좌표
	 b = max(ba, bb);//두 직사각형의 아래쪽 y좌표중에서 더 큰 값이 아래쪽 y좌표

	 if(l<=r && b<=t)//두 직사각형이 겹치면
		 return (r - l) * (t - b);//직사각형의 넓이 가로*세로를 반환
	 return 0;//그렇지 않으면 0 반환
}
void test_case() {
	int ax, ay, bx, by;//직사각형 a의 A,B,P,Q에 대한 좌표
	int px, py, qx, qy;//직사각형 b의 A,B,P,Q에 대한 좌표
	scanf("%d %d %d %d", &ax, &ay, &bx, &by);
	scanf("%d %d %d %d", &px, &py, &qx, &qy);

	int la, ra, ba, ta;//직사각형 a
	la = min(ax, bx);//직사각형 a의 왼쪽 x좌표
	ra = max(ax, bx);//직사각형 a의 오른쪽 x좌표
	ta = max(ay, by);//직사각형 a의 위쪽 y좌표
	ba = min(ay, by);//직사각형 a의 아래쪽 y좌표

	int lb, rb, bb, tb;//직사각형 b
	lb = min(px, qx);//직사각형 a의 왼쪽 x좌표
	rb = max(px, qx);//직사각형 a의 오른쪽 x좌표
	tb = max(py, qy);//직사각형 a의 위쪽 y좌표
	bb = min(py, qy);//직사각형 a의 아래쪽 y좌표

	int answer = get_area(la, ra, ta, ba, lb, rb, tb, bb);//answer 변수에 두 직사각형이 겹치면 넓이를, 겹치지 않으면 0을 저장

	printf("%d\n", answer);//두 직사각형이 겹치면 넓이를, 겹치지 않으면 0을 출력
}

int main() {
	int t;//테스트케이스의 개수
	scanf("%d", &t);//테스트케이스의 개수 입력

	for (int i = 0; i < t; i++)//테스트케이스 개수만큼 반복
		test_case();//테스트케이스 함수 실행

	return 0;//프로그램 종료
}