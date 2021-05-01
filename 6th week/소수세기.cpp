#include<cstdio>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

class Sieve//에라토스테네스의 체 클래스
{
public:
	int maximumValue;//에라토스테네스의 체에서 다룰 가장 큰 값
	vector<bool> isPrime; //각숫자별 소수 여부
	Sieve(int maximumValue)//매개변수가 있는 생성자
	{
		this->maximumValue = maximumValue;//에라토스테네스의 체에서 다룰 가장 큰 값은 매개변수로
		this->isPrime.assign(maximumValue + 1, false); //초기화
		this->fillSieve();//isPrime 배열의 값을 채우는 함수 호출
	}
	bool isPrimeNumber(int num)const {
		return this->isPrime[num];//num이 소수라면 true, 아니라면 false 반환
	}
	void fillSieve()//isPrime 배열의 값을 채우는 함수
	{
		isPrime.assign(this->maximumValue, true); //모두 소수로 저장
		isPrime[0] = isPrime[1] = false; //0,1 소수 아니라고 저장
		for (int num = 2; num <= maximumValue; num += 1)
		{
			if (isPrime[num] == false) //이미 소수 아니라고 체크되면 패스
				continue;
			for (long long mul = (long long)num * num; mul <= maximumValue; mul += num)//num의 제곱부터 최댓값까지 확인
			{
				int index = (int)mul;//num의 배수들을 index에 저장
				isPrime[index] = false;//소수의 배수는 소수가 아니므로 false 저장
			}
		}
	}
};
vector<int> getAllPrimeNumbers(int from, int to, const Sieve& sieve)//모든 소수를 구하는 함수
{
	vector<int>primes;//소수를 저장할 배열
	for (int num = from; num <= to; num += 1)//from부터 to까지 1씩 증가하면서 반복
	{
		if (sieve.isPrimeNumber(num))//num이 소수이면
		{
			primes.push_back(num);//primes 배열에 저장
		}
	}
	return primes;//primes 배열 반환
}
void process(int caseIndex, const Sieve& sieve)
{
	int L, R;//L과 R은 자연수이며 L은 항상 R보다 작음 
	scanf("%d %d", &L, &R);//L, R 입력
	vector<int> allPrimeNumbers = getAllPrimeNumbers(L, R, sieve);//모든 소수를 구해와 배열에 저장
	printf("Case #%d:\n", caseIndex );//몇번째 테스트 케이스인지 출력
	printf("%d\n", (int)allPrimeNumbers.size());//모든 소수 배열로부터 소수가 몇 개인지 출력
}
int main()
{
	const int MAX_VALUE = 1000000; //범위 지정
	Sieve sieve = Sieve(MAX_VALUE);//최대값을 1000000으로 가진 에라토스 테네스의 체 생성자 호출
	int caseSize;//테스트 케이스의 개수
	scanf("%d", &caseSize);//테스트 케이스의 개수 입력
	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex)//테스트 케이스의 수만큼 반복
		process(caseIndex, sieve);//process함수 호출
	return 0;//프로그램 종료
}