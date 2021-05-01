#include<cstdio>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

class Sieve//�����佺�׳׽��� ü Ŭ����
{
public:
	int maximumValue;//�����佺�׳׽��� ü���� �ٷ� ���� ū ��
	vector<bool> isPrime; //�����ں� �Ҽ� ����
	Sieve(int maximumValue)//�Ű������� �ִ� ������
	{
		this->maximumValue = maximumValue;//�����佺�׳׽��� ü���� �ٷ� ���� ū ���� �Ű�������
		this->isPrime.assign(maximumValue + 1, false); //�ʱ�ȭ
		this->fillSieve();//isPrime �迭�� ���� ä��� �Լ� ȣ��
	}
	bool isPrimeNumber(int num)const {
		return this->isPrime[num];//num�� �Ҽ���� true, �ƴ϶�� false ��ȯ
	}
	void fillSieve()//isPrime �迭�� ���� ä��� �Լ�
	{
		isPrime.assign(this->maximumValue, true); //��� �Ҽ��� ����
		isPrime[0] = isPrime[1] = false; //0,1 �Ҽ� �ƴ϶�� ����
		for (int num = 2; num <= maximumValue; num += 1)
		{
			if (isPrime[num] == false) //�̹� �Ҽ� �ƴ϶�� üũ�Ǹ� �н�
				continue;
			for (long long mul = (long long)num * num; mul <= maximumValue; mul += num)//num�� �������� �ִ񰪱��� Ȯ��
			{
				int index = (int)mul;//num�� ������� index�� ����
				isPrime[index] = false;//�Ҽ��� ����� �Ҽ��� �ƴϹǷ� false ����
			}
		}
	}
};
vector<int> getAllPrimeNumbers(int from, int to, const Sieve& sieve)//��� �Ҽ��� ���ϴ� �Լ�
{
	vector<int>primes;//�Ҽ��� ������ �迭
	for (int num = from; num <= to; num += 1)//from���� to���� 1�� �����ϸ鼭 �ݺ�
	{
		if (sieve.isPrimeNumber(num))//num�� �Ҽ��̸�
		{
			primes.push_back(num);//primes �迭�� ����
		}
	}
	return primes;//primes �迭 ��ȯ
}
void process(int caseIndex, const Sieve& sieve)
{
	int L, R;//L�� R�� �ڿ����̸� L�� �׻� R���� ���� 
	scanf("%d %d", &L, &R);//L, R �Է�
	vector<int> allPrimeNumbers = getAllPrimeNumbers(L, R, sieve);//��� �Ҽ��� ���ؿ� �迭�� ����
	printf("Case #%d:\n", caseIndex );//���° �׽�Ʈ ���̽����� ���
	printf("%d\n", (int)allPrimeNumbers.size());//��� �Ҽ� �迭�κ��� �Ҽ��� �� ������ ���
}
int main()
{
	const int MAX_VALUE = 1000000; //���� ����
	Sieve sieve = Sieve(MAX_VALUE);//�ִ밪�� 1000000���� ���� �����佺 �׳׽��� ü ������ ȣ��
	int caseSize;//�׽�Ʈ ���̽��� ����
	scanf("%d", &caseSize);//�׽�Ʈ ���̽��� ���� �Է�
	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex)//�׽�Ʈ ���̽��� ����ŭ �ݺ�
		process(caseIndex, sieve);//process�Լ� ȣ��
	return 0;//���α׷� ����
}