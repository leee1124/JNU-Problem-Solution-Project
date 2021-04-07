#include<cstdio>
#include<cmath>
#include<climits>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;

class Point2D {
private:
	int x;//천체의 x좌표값을 저장할 변수
	int y;//천체의 y좌표값을 저장할 변수

public:
	Point2D(int x = 0, int y = 0) {//클래스의 생성자, 디폴트 매개변수로 x와 y에 0을 저장해 값이 들어오지 않으면 x와 y의 값은 0
		this->x = x;//객체의 x의 좌표는 생성자의 매개변수를 통해 들어온 x값으로 저장
		this->y = y;//객체의 y의 좌표는 생성자의 매개변수를 통해 들어온 y값으로 저장
	}
	/*
	2차원 평면 상에서 점 this부터 점 target까지 거리의 제곱을 계산하는 함수
	param target
	return
	*/
	int getSquaredDistanceTo(const Point2D& target) const {//거리의 제곱을 계산하는 함수
		int dx = abs(this->x - target.x);//현재 천체에서 타겟 천체까지 x좌표의 차
		int dy = abs(this->y - target.y);//현재 천체에서 타겟 천체까지 y좌표의 차
		return dx * dx + dy * dy;//거리를 구하기 위해서 x좌표의 차의 제곱과 y좌표의 차의 제곱을 더한 값(거리의 제곱)을 반환
	}
	double getDistanceTo(const Point2D& target) const {
		double sqd = (double)this->getSquaredDistanceTo(target);//거리의 제곱을 계산하는 함수를 통해 반환된 값을 sqd 변수에 저장
		return sqrt(sqd);//루트 계산을 통해 거리를 계산하고, 해당 값 반환
	}
};

int main() {
	int n;//천체의 수를 저장할 변수
	Point2D* points;//Point2D클래스형 변수 points

	scanf("%d", &n);//천체의 개수 입력
	points = new Point2D[n];//천체의 개수만큼 배열의 동적할당

	for (int i = 0; i < n; i++) {//천체의 개수만큼 반복
		int x, y;//x좌표와 y좌표값을 입력받을 변수
		scanf("%d %d", &x, &y);//x좌표값과  y좌표값 입력

		points[i] = Point2D(x, y);//생성자를 이용해 객체에 x좌표값과 y좌표값 입력
	}
	
	int min_sqd = INT_MAX;//거리의 제곱값을 저장할 변수
	int min_cnt = 0;//그 거리만큼 떨어진 천체 쌍의 수를 저장할 변수

	for (int i = 0; i < n; i++) {//천체의 개수만큼 반복
		for (int j = 0; j < i; j++) {//i번째 천체와 j번째 천체의 거리를 구하고, 중복계산을 피하기 위해서 j가 i보다 작을때만 계산
			int sqd = points[i].getSquaredDistanceTo(points[j]);//거리의 제곱을 받아와서 sqd 변수에 저장
			if (sqd < min_sqd) {//현재까지의 최소 거리보다 더 짧은 최소거리가 발견되면
				min_sqd = sqd;//최소거리 갱신
				min_cnt = 1;//그 거리만큼 떨어진 천체 쌍의 수는 처음부터 다시 셈
			}
			else if (sqd == min_sqd) {//최소 거리와 동일한 거리만큼 떨어진 천체가 또 발견되면
				min_cnt++;//그 거리만큼 떨어진 천체 쌍의 수 증가
			}
		}
	}

	double distance = sqrt(min_sqd);//sqd는 거리의 제곱이므로 루트 계산을 해줌
	printf("%.1f\n", distance);//거리를 소수점 첫째자리 까지만 출력
	printf("%d\n", min_cnt);// 그 거리만큼 떨어진 천체 쌍의 수 출력

	delete[] points;//동적할당 해제
	return 0;
}