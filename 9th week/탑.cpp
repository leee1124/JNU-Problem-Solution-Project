#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Tower {
public:
	int index;//타워의 인덱스
	int height;//타워의 높이
	int targetTowerIndex;//타워의 레이저를 수신하는 대상 타워

	Tower(int index, int height) {//Tower 클래스의 생성자
		this->index = index;//객체의 index에 매개변수 index의 값을 저장
		this->height = height;//객체의 height에 매개변수 height의 값을 저장
		this->targetTowerIndex = 0;//객체의 targetTowerIndex에 0 저장
	}
	void setTargetTowerIndex(int targetTowerIndex) {//targetTowerIndex의 값을 설정하는 함수
		this->targetTowerIndex = targetTowerIndex;//객체의 targetTowerIndex에 매개변수 targetToewerIndex의 값을 저장 
	}
	int getTargetTowerIndex() {//targetTowerIndex 반환하는 함수
		return this->targetTowerIndex;//targetTowerIndex 반환
	}
};

void findTargetTowers(vector<Tower>& towers) {	
	stack<Tower> stk;//현재 다른 타워의 신호를 수신할 가능성이 있는 타워들

	for (int i = 0; i < towers.size(); i++) {//타워의 개수만큼 반복
		Tower& t = towers[i];//각 타워 t에 대해 차례로 고려
		int targetTowerIndex = 0;// 타워 t의 신호를 수신할 후보(초기값 NULL)

		while (stk.empty() == false && stk.top().height < t.height) {//t보다 높이가 낮은 타워들은 이후에도 수신 가능성이 없으므로 제거
			stk.pop();
		}
		if (stk.size() > 0) {
			//t이상의 높이를 가진 타워가 있다면
			targetTowerIndex = stk.top.index;
			//t는 해당 타워를 타겟으로 정함
		}
		t.setTargetTowerIndex(targetTowerIndex);//계산한 타겟 정보를 저장

		stk.push(t);//t는 마지막에 등장했으므로 다른 타워의 신호를 수신할 수 있음.
	}
}

int main() {
	int n;//탑의 개수
	cin >> n;//탑의 개수 입력

	vector<Tower> towers;//Tower 클래스 배열 towers

	for (int i = 0; i < n; ++i) {//탑의 개수만큼 반복
		int hi;//탑의 높이
		cin >> hi;//탑의 높이 입력
		towers.push_back(Tower(i + 1, hi));//towers 배열에 인덱스(1부터), 탑의 높이 저장
	}

	findTargetTowers(towers);//각 타워가 송신하는 레이저에 대해 타겟을 모두 계산

	for (int i = 0; i < n; i++) {//탑의 개수만큼 반복
		if (i > 0) {//처음 나온 인덱스가 아니면
			cout << " ";//띄어쓰기
		}
		Tower t = towers[i];//Tower클래스 객체 t에 towers배열의 i번째 원소 저장
		int targetIndex = t.getTargetTowerIndex();//getTargetIndex함수를 통해 t의 타겟인덱스를 가져와서 저장함
		cout << targetIndex;//타겟 인덱스 출력
	}
}