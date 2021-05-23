#include<cstdio >
#include<map>
using namespace std;

int main()
{
	int n; //입력될 정수들의 총 개수
	scanf("%d", &n); //입력될 정수들의 개수 입력

	map<int, int>frequencyMap; //이전에 입력된 정수들의 빈도수를 저장할 맵변수

	for (int i = 0; i < n; i++) { //정수의 개수만큼 반복
		int x;//입력될 변수
		scanf("%d", &x); //x 입력
		frequencyMap[x]++; //x의 빈도수 증가
		printf("%d %d\n", frequencyMap.size(), frequencyMap[x]);//현재까지 입력으로 주어진 숫자의 종류의 개수와 이번에 입력받은 x의 빈도수
	}
	return 0;//프로그램 종료
}