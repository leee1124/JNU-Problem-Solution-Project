#include<cstdio>
#include<vector>
#pragma warning(disable: 4996)
using namespace std;

vector<long long>factorize(long long n) //자연수 n을 구성하는 모든 소인수를 반환하는 함수
{
	vector<long long> factors;//factors 배열 생성
	for (long long div = 2; div * div <= n; div += 1)//div가 2일때부터  n의 제곱근보다 작을때까지 div를 1씩 증가하면서 반복
		while (n % div == 0) //나머지가 0이면(나누어 떨어지면) 반복
		{
			factors.push_back(div); //배열에 원소 넣음
			n /= div;//n을 div로 나눈 몫을 n에 저장
		}
	if (n > 1)//위의 반복문을 수행하고도 n이 1보다 크면
		factors.push_back(n);//남은 값도 n의 소인수이므로 배열에 넣음
	return factors;//소인수 배열 반환
}
void process(int caseIndex)//테스트 케이스 진행
{
	long long n;//소인수분해를 할 자연수 n
	scanf("%lld", &n);//n 입력
	vector<long long>factors = factorize(n);//n의 소인수를 모두 구해서 factors배열에 저장
	printf("#%d:\n", caseIndex);//몇번째 테스트케이스인지 출력
	for (int i = 0; i < factors.size(); ++i)//소인수의 개수만큼 반복
	{
		if (i > 0)
			printf(" ");//소인수들 사이의 띄어쓰기를 위한 출력
		printf("%lld", factors[i]);//소인수 값 출력
	}
	printf("\n");//이번 테스트 케이스가 끝나면 개행
}
int main()
{
	int caseSize;//테스트 캐이스의 개수
	scanf("%d", &caseSize);//테스트 케이스의 수 입력
	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex)//테스트 케이스의 수만큼 반복
		process(caseIndex);//프로그램 진행하는 함수 실행

	return 0;//프로그램 종료
}