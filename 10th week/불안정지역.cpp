#include<iostream>
#include<vector>
#include<queue>
#pragma warning(disable: 4996)
using namespace std;

class City {
public:
	int index; //도시 인덱스
	int income; //도시 소득

	City(int index, int income) { //도시 생성자
		this->index = index;//index 매개변수가 객체의 매개변수
		this->income = income;//income 매개변수가 객체의 매개변수
	}
	bool operator<(const City& o)const {//대소관계 추가
		return this->income < o.income;
	}
	bool operator>(const City& o)const {//대소관계 추가
		return this->income > o.income;
	}
	//연산자 오버로딩을 통해 income값에 따라 오름차순과 내림차순을 결정함
};

int getMaximumRangeDifference(int n, int k, const vector<City>& cities) {
	int answer = 0;//정답을 넣을 변수

	priority_queue<City, vector<City>, greater<City>> rangeMinimum;//소득이 작은 도시부터 pop하는 우선순위 큐(오름차순)

	priority_queue<City> rangeMaximum; //소득 높은 도시부터 pop하는 우선순위 큐(디폴트값(vector<City>, less<City>을 사용하지 않으면)이 내림차순)

	for (int i = 0; i < k - 1; i++) {//i가 0부터 k-2까지 반복
		rangeMaximum.push(cities[i]);//내림차순인 우선순위 큐(front가 소득이 큰 도시)에 cities 벡터 변수의 i번째 값 입력
		rangeMinimum.push(cities[i]);//오름차순인 우선순위큐(front가 소득이 작은 도시)에 cities 벡터 변수의 i번째 값 입력
	}
	for (int i = k - 1; i < n; i++) {//k-1 이후의 값을 처리하기 위한 반복문
		rangeMaximum.push(cities[i]);//내림차순인 우선순위 큐(front가 소득이 큰 도시)에 cities 벡터 변수의 i번째 값 입력
		rangeMinimum.push(cities[i]);//오름차순인 우선순위 큐(front가 소득이 작은 도시)에 cities 벡터 변수의 i번째 값 입력
		while (rangeMaximum.top().index < i - k + 1)rangeMaximum.pop();//범위에 없는 내용 삭제
		while (rangeMinimum.top().index < i - k + 1)rangeMinimum.pop(); //범위에 없는 내용 삭제
		answer = max(answer, rangeMaximum.top().income - rangeMinimum.top().income);//최대 소득차로 업데이트
	}
	return answer; //답 반환
}

void process(int caseIndex) {
	int n, k;//도시의 수, 연속한 도시의 수
	cin >> n >> k; //도시의 수,연속한 도시의 수 입력
	vector<City>cities;//도시의 정보를 가질 벡터변수

	for (int i = 0; i < n; i += 1) {
		int income;//도시 소득
		cin >> income;//소득 입력
		cities.push_back(City(i, income)); //cities 벡터 변수에 도시의 정보를 넣음
	}

	int answer = getMaximumRangeDifference(n, k, cities); //getMaximumRangeDifference() 함수를 실행시켜 가장 큰 소득차 값 구함

	cout << answer << endl; //답 출력
}

int main() {
	int caseSize; //테스트 케이스 개수
	cin >> caseSize;//테스트 케이스 개수 입력

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1)
		process(caseIndex); //테스트 케이스 개수만큼 process 함수 실행

	return 0;//프로그램 종료
}