#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<ctime>
#include<set>
using namespace std;

#define MUL 65536// 곱할 값

map<string, int> fir;//처음 입력받은 문자열을 담을 map 변수
map<string, int> sec;//두번째로 입력받은 문자열을 담을 map 변수
set<string> substrings;//서브스트링들을 담을 set변수

void init(string first, string second) {//맵과 셋을 초기화하는 함수
	string ss;//문자열들의 2글자를 담을 서브스트링

	for (int i = 0; i < max(first.length(), second.length()) - 1; i++) {//first와 second중 더 긴 문자열만큼 반복
		if (i < first.length()-1) {//아직 첫번째 문자열만큼 다 안돌았으면
			ss = first.substr(i, 2);//첫번째 문자열의 서브스트링
			if ('a' <= ss[0] && ss[0] <= 'z')	ss[0] = ss[0] - 32;//ss가 소문자이면
			if ('a' <= ss[1] && ss[1] <= 'z')	ss[1] = ss[1] - 32;//대문자로 바꿈

			bool cond_1 = 'A' <= ss[0] && ss[0] <= 'Z';//ss[0]이 알파벳인지 확인하기 위한 조건
			bool cond_2 = 'A' <= ss[1] && ss[1] <= 'Z';//ss[1]이 알파벳인지 확인하기 위한 조건

			if (fir.find(ss) != fir.end()) {//fir 맵에서 first 문자열의 서브스트링이 있는지 찾아봄
				fir[ss]++;//있으면 value값 증가
			}
			else {//없으면
				if (cond_1 && cond_2) {//ss가 알파벳으로만 이루어졌는지 확인
					fir[ss] = 1;//알파벳으로만 이루어졌으면 value을 1로 초기화
					substrings.insert(ss);//substrings 세트에 ss 현재 서브스트링 추가
				}
			}

		}

		if (i < second.length()-1) {//아직 두번째 문자열만큼 다 안돌았으면
			ss = second.substr(i, 2);//두번째 문자열의 서브스트링
			if ('a'<= ss[0] && ss[0] <= 'z')	ss[0] = ss[0] - 32;//ss가 소문자이면
			if ('a' <= ss[1] && ss[1] <= 'z')	ss[1] = ss[1] - 32;//대문자로 바꿈
			bool cond_1 = 'A' <= ss[0] && ss[0] <= 'Z';//ss[0]이 알파벳인지 확인하기 위한 조건
			bool cond_2 = 'A' <= ss[1] && ss[1] <= 'Z';//ss[1]이 알파벳인지 확인하기 위한 조건

			if (sec.find(ss) != sec.end()) {//sec 맵에서 second 문자열의 서브스트링이 있는지 찾아봄
				sec[ss]++;//있으면 value값 증가
			}
			else {
				if (cond_1 && cond_2) {//ss가 알파벳으로만 이루어졌는지 확인
					sec[ss] = 1;//알파벳으로만 이루어져 있으면 value값을 1로 초기화
					substrings.insert(ss);//substrings 세트에 ss 현재 서브스트링 추가
				}
			}
		}
	}
}

int solution(string first, string second) {
	init(first, second);//맵과 셋변수들을 초기화

	int uni=0;//합집합
	int inter=0;//교집합
	
	for (auto iter : substrings) {//substrings의 iterator를 이용해서 반복
		inter += min(fir[iter], sec[iter]);//둘중 더 적은걸 가져가서 교집합
		uni += max(fir[iter], sec[iter]);//둘중 더 큰 값을 가져가서 합집합
	}
	
	if (inter == 0 && uni == 0) return MUL;//공집합이면 자카드 유사도는 1인데, MUL만큼 곱해서 출력해야 하므로 MUL 반환
	return MUL * inter / uni;//자카드 유사도는 교집합 / 합집합
}


int main() {
	time_t start, end;// 시간 측정을 위한 변수
	string first, second;// 두 문자열을 입력받을 변수
	
	getline(cin, first);// 첫 번째 문자열 입력
	getline(cin, second);// 두 번째 문자열 입력
	start = clock();// 시간 측정 시작

	int res = solution(first, second);//솔루션 함수를 통해 얻은 결과를 res에 저장
	
	cout << res << endl;//결과 출력
	end = clock();//시간 측정 종료
	double result = (double)(end - start) / CLOCKS_PER_SEC;//측정시간 초단위로
	cout << "실행시간: " << result << "초" << endl;//실행시간 출력

	return 0;//프로그램 종료
}