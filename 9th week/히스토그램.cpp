#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;

class Histogram {
public:
	int height;//히스토그램의 높이
	int leftX;//인덱스 혹은 히스토그램의 왼쪽 변의 x 좌표
	int rightX;//히스토그램의 오른쪽 변의 x좌표

	Histogram() {}
	Histogram(int index, int height) {
		this->height = height;//객체의 height에 매개변수 height의 값 저장
		this->leftX = index;//왼쪽 변의 x좌표에 매개변수 index의 값 저장
		this->rightX = this->leftX + 1;//오른쪽 변의 x 좌표에 왼쪽 변의 x좌표 +1 저장
	}
};

long long getLargeRectangleArea(const vector<Histogram> histograms) {//넓이를 구하는 함수
	long long answer = 0;//long long형 변수 answer 선언, 초기값은 0

	stack<Histogram> stk;//히스토그램 클래스의 객체를 담을 스택변수
	stk.push(Histogram(-1, 0));//구현상 편의를 위해 가장 왼쪽에 높이 0까지의 가상의 히스토그램 추가

	for (int i = 0; i < histograms.size(); i++) {
		Histogram h;
		if (i < histograms.size()) {//인덱스가 히스토그램의 개수보다 적으면
			h = histograms[i];//h에 hisograms의 i번째 히스토그램 객체 저장

		}
		else {
			h = Histogram(histograms.size(), 0);//구현상 편의를 위해 가장 오른쪽에 높이 0까지의 가상의 히스토그램 추가
		}
		//이전에 확장중이던 히스토그램들 중, h보다 높이가 높은 히스토그램들은
		//더이상 확장될 수 없다. => 최대 넓이가 결정됨
		while (stk.size() > 1 && stk.top().height > h.height) {
			Histogram lh = stk.top();//삭제하기 전의 toip을 나중에 사용하기 위함
			stk.pop();//스택의 가장 위 원소 삭제

			Histogram bh = stk.top();//그 이전의 히스토그램(왼쪽 확장의 끝)

			//현재 추가된 h의 바로 왼쪽까지 확장중이었다.
			long long width = abs(h.leftX - bh.rightX);//밑변
			long long height = lh.height;//높이
			long long area = width * height;//넓이는 밑변*높이

			answer = max(answer, area);//최대 값 갱신
		}
		stk.push(h);
	}
	return answer;//asnwer 반환
}

void process(int caseIndex) {
	int n;//그래프의 개수를 입력받을 변수
	cin >> n;// 그래프의 개수 입력

	vector<Histogram> histograms;//Histogram 클래스를 담을 벡터변수
	for (int i = 0; i < n; i++) {//그래프의 개수만큼 반복
		int height;//히스토그램의 높이를 입력받을 변수
		cin >> height;//히스토그램의 높이를 입력
		histograms.push_back(Histogram(i, height));//현재 인덱스 번호와 입력받은 히스토그램의 높이로 히스토그램 객체를 생성해서 벡터변수에 저장
	}
	long long answer = getLargeRectangleArea(histograms);//넓이를 구해서 answer 변수에 저장
	cout << answer << endl;//answer변수 출력하고 개행
}

int main() {
	int caseSize;//테스트 케이스 개수를 입력받을 변수
	cin >> caseSize;//테스트 케이스 개수 입력
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {//테스트 케이스 개수만큼 반복
		process(caseIndex);//테스트 케이스 개수만큼 반복해서 process 함수 실행
	}
}