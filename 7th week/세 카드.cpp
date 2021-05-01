#include<cstdio>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

vector<int> getPossibleTargets(int n, int m, int* cards, int* targets) {
	vector<int> possibleTargets;//만들 수 있는 당첨 번호들

	sort(cards, cards + n);// 모든 카드를 오름차순으로 정렬, 바이너리 서치를 위한 조건

	for (int i = 0; i < m; ++i) {
		int k = targets[i];// 모든 타켓 k에 대하여
		bool possible = false;
		
		for (int j = 0; j < n; ++j) { 
			int x = cards[j];//모든 카드중 하나인 x에 대하여
			
			for (int p = 0; p <= j; p += 1) {//숫자조합의 중복 없애기
				int y = cards[p];//카드 중 하나 y를 선택
				int z = k - (x + y);// k=(x+y)+z가 되는 z를 계산

				if (binary_search(cards, cards + n, z) == true) {//z가 cards 배열에 존재한다면
					possible = true;//k=x+y+z가 가능한 x,y,z가 존재하면 possible에 참을 저장하고
					break;//for문 빠져나감
				}
			}
			if (possible) {//이미 찾았다면
				break;//탈출
			}
		}
		if (possible) {//k=x+y+z가 가능한 x,y,z가 존재하면
			possibleTargets.push_back(k);//실제로 만들 수 있는 당첨번호에 추가
		}
	}
	sort(possibleTargets.begin(), possibleTargets.end());//출력시 오름차순으로 정렬하는 것이 조건이기 때문에 오름차순으로 정렬
	return possibleTargets;//실제로 만들 수 있는 당첨번호 배열 반환
}

int main() {
	int n;//카드의 수
	int m;//검사 할 후보 당첨번호의 수
	scanf("%d %d", &n, &m);//카드의 수, 후보 당첨번호의 수 입력

	int* cards = new int[n];//카드의 수만큼 동적할당
	int* targets = new int[m];//후보 당첨번호의 수만큼 동적할당

	for (int i = 0; i < n; i++) {
		scanf("%d", &cards[i]);
	}//각 카드번호 입력

	for (int i = 0; i < m; i++) {
		scanf("%d", &targets[i]);
	}//각 후보 당첨번호 입력

	vector<int> answers = getPossibleTargets(n, m, cards, targets);//answers에 실제로 만들 수 있는 당첨번호 배열 저장
	
	if (answers.size() == 0) {
		printf("NO");//가능한 당첨번호가 없다면 NO를 출력
	}
	else {//가능한 당첨번호가 존재한다면 그 목록을 출력
		for (int i = 0; i < answers.size(); i++) {
			if (i > 0) {
				printf(" ");//공백으로 숫자를 구분하기 위한 출력
			}
			printf("%d", answers[i]);//실제 만들 수 있는 당첨번호 출력
		}
	}

	delete[] cards;//카드 배열 동적할당 해제
	delete[] targets;//후보 당첨번호 배열 동적할당 해제
	return 0;//프로그램 종료
}