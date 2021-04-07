#include<iostream>
#include<cstdio>
#pragma warning(disable: 4996)
using namespace std;

/*왼쪽 아래 좌표가 (x,y)인 픽셀이 반지름 R인 원에 포함되는가?
param x
param y
param R
return 포함된다면 true, else false*/

bool isInside(long long x, long long y, long long R) {//int형의 범위를 넘어서기 때문에 long long 형으로 파라미터를 잡음
	//원의 방정식을 따라서 픽셀이 원의 내부에 존재하려면 x*x+y*y<r*r을 만족해야함
	long long sqd = x * x + y * y;//픽셀이 원의 내부에 있는지 구하기 위해 사용하는 변수
	if (sqd < R * R)//거리의 제곱이 반지름의 제곱보다 작으면(원의 방정식, 픽셀이 원의 내부에 있으면)
		return true;//true 반환
	return false;//원의 내부에 있지 않으면 false 반환
}
void testcase(int caseIndex) {//테스트 케이스를 수행할 함수, 케이스 인덱스는 테스트케이스의 첫번째 줄에 출력
	long long R;//원의 반지름의 픽셀 수 R을 저장하는 변수
	scanf("%lld", &R);//픽셀 수 입력받음

	long long sum = 0;// 1사분면에 존재하는 총 픽셀의 수
	long long y = R;//y가 원의 반지름일때부터 시작
	for (long long x = 0; x <= R; x++) {//x는 0부터 시작해서 반지름의 길이만큼 반복해나감
		long long height = 0;//높이는 0
		for (; y >= 0; y--) {
			if (isInside(x, y, R)) {//isInside가 참이면 아래의 픽셀은 전부 포함된다.
				height = (y + 1);
				break;
			}
		}
		sum += height;//개수를 더해준다
	}
	printf("#%d\n", caseIndex);//테스트 케이스의 첫번째 줄에 케이스 인덱스 출력
	printf("%lld\n", sum * 4);//sum에는 1사분면의 픽셀값만 저장되어있으므로 4를 곱해준다
}
int main() {
	int caseSize;//테스트 케이스의 개수를 저장할 변수
	scanf("%d", &caseSize);//테스트 케이스 개수 입력
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {//테스트 케이스 개수만큼 반복
		testcase(caseIndex);//테스트 케이스 함수 호출
	}
	return 0;//프로그램 종료
}