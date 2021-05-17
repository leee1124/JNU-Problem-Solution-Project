#include<iostream>
#include<set>
#pragma warning(disable:4996)
using namespace std;

int main() {
	int n;//입력받을 정수의 개수
	scanf("%d", &n);//입력받을 정수의 개수 입력
	set<int>s; //int형 변수를 담을 set변수 선언

	for (int i = 0; i < n; i++) {
		int x;//set변수에 담을 int형 변수
		scanf("%d",&x); //set변수에 담을 int형 변수 입력

		if (s.count(x) > 0) { //만약 같은 값이 존재하면
			printf("DUPLICATED\n");//Duplicated 출력
		}
		else { //같은 값이 존재하지 않으면
			s.insert(x); //그 값을 set에 넣은 후
			printf("OK\n");//OK 출력
		}
	}
	return 0;//프로그램 종료
}