#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	int n; //투표용지의 수
	cin >> n;//투표용지의 수 입력

	map<string, int> frequencyMap;//후보의 이름과 득표수 저장하는 맵변수
	int maxFrequency = 0;//최대 득표수

	for (int i = 0; i < n; i++) {//투표용지의 수 만큼 반복
		string st;//후보자 이름을 입력받을 변수
		cin >> st;//이름 입력
		frequencyMap[st]++; //해당 후보의 득표수 증가시킴
		int k = frequencyMap[st];//득표수를 변수 k에 저장
		if (k > maxFrequency) {//만약 득표수가 최대 득표수보다 크면
			maxFrequency = k;//최대 득표수를 바꿔줌
		}
	}
	cout << maxFrequency << endl; //최대 득표수 출력

	map<string, int>::iterator it; //후보 출력하기 위한 iterator 변수 선언
	for (it = frequencyMap.begin(); it != frequencyMap.end(); it++){//frequencyMap을 처음부터 끝까지 반복
		if (it->second == maxFrequency) //최대 득표수를 가진
			printf("%s ", it->first.c_str());//후보의 이름을 출력한다.
	}
}