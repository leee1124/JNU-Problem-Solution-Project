#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;

class Point2D {
public:
	int x;//x좌표
	int y;//y좌표
	int index;//데이터의 인덱스

	Point2D(int index, int x, int y) { //인덱스 입력 받았을 경우
		this->index = index; //인덱스 값을 입력 받은 값으로 설정
		this->x = x; //x를 입력 받은 값으로 설정
		this->y = y;//y를 입력 받은 값으로 설정
	}
	Point2D(int x, int y) { //인덱스 입력 안받았을 경우
		this->index = 1;//인덱스 값을 1로 설정
		this->x = x;//x를 입력 받은 값으로 설정
		this->y = y;//y를 입력 받은 값으로 설정
	}
	long long getSquaredDistanceTo(Point2D target) { //두 좌표의 제곱 거리 계산 >>정사각형의 면적
		long long dx = abs(this->x - target.x);//x좌표의 차를 구한 후 절댓값
		long long dy = abs(this->y - target.y);//y좌표의 차를 구한 후 절댓값
		return dx * dx + dy * dy;//정사각형의 면적
	}
	bool operator<(const Point2D& other)const { //대소관계를 비교해 어떻게 정렬할 것인지 설정
		if (this->x != other.x) { //x좌표가 다르면 x좌표 기준으로 비교
			return this->x < other.x;
		}
		return this->y < other.y; //x좌표가 같으면 y좌표를 기준으로 비교
	}
};

long long getMaximumSquareArea(int n, const vector <Point2D>& points) {
	long long answer = 0;//최대 넓이, x좌표와 y좌표가 각각 1억까지 나올 수 있으므로 int형이 아니라 long long 형을 사용한다.

	set<Point2D>pSet; //set변수에 Point2D 클래스를 담을 수 있도록 선언
	for (int i = 0; i < n; i++) {
		pSet.insert(points[i]);//벡터에 담긴 객체를 pSet 변수에 삽입해준다
	}

	for (int i = 0; i < n; i++) {//임의의 a와 b 두 점을 잡는다.
		Point2D pa = points[i];//임의의 점 a
		for (int j = 0; j < n; j++) {
			Point2D pb = points[j];//임의의 점 b
			if (i == j)continue;//같은 점 제외

			long long area = pa.getSquaredDistanceTo(pb); //넓이 계산
			if (area < answer)//넓이가 작으면 작으면
				continue;//건너뛴다.

			int dx = pb.x - pa.x;//pa->pb방향의 x좌표에 대한 거리
			int dy = pb.y - pa.y;//pa->pb방향의 y좌표에 대한 거리
			
			Point2D pd(pa.x - dy, pa.y + dx);//새로운 점 d
			Point2D pc(pb.x - dy, pb.y + dx);//새로운 점 c

			if (pSet.count(pc) > 0 && pSet.count(pd) > 0)//pd와 pc가 pSet에 존재하는 점이면
				answer = max(answer, area);//현재까지 최대 넓이와 현재 정사각형의 넓이중 더 큰 값을 answer에 저장

		}
	}
	return answer;//answer 반환
}

void process(int caseIndex) {
	int n;//좌표의 개수
	cin >> n;//좌표의 개수 입력

	vector<Point2D>points;//Point2D 클래스를 담을 벡터변수

	for (int i = 0; i < n; i++) {
		int x, y;//x좌표와 y좌표
		cin >> x >> y; //x좌표와 y좌표를 입력받는다
		points.push_back(Point2D(i, x, y));//points 벡터변수에 Point2D클래스를 삽입함
	}
	double answer = getMaximumSquareArea(n, points);//넓이 구하는 함수 실행

	cout << fixed << setprecision(2) << answer << endl;//둘째짜리까지 출력
}

int main() {
	int caseSize; //테스트 케이스 개수 받는 변수
	cin >> caseSize;//테스트 케이스 개수 입력

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++) {//테스트 케이스 개수만큼 반복
		process(caseIndex); //케이스 개수만큼 process진행
	}
}