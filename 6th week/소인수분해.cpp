#include<cstdio>
#include<vector>
#pragma warning(disable: 4996)
using namespace std;

vector<long long>factorize(long long n) //�ڿ��� n�� �����ϴ� ��� ���μ��� ��ȯ�ϴ� �Լ�
{
	vector<long long> factors;//factors �迭 ����
	for (long long div = 2; div * div <= n; div += 1)//div�� 2�϶�����  n�� �����ٺ��� ���������� div�� 1�� �����ϸ鼭 �ݺ�
		while (n % div == 0) //�������� 0�̸�(������ ��������) �ݺ�
		{
			factors.push_back(div); //�迭�� ���� ����
			n /= div;//n�� div�� ���� ���� n�� ����
		}
	if (n > 1)//���� �ݺ����� �����ϰ� n�� 1���� ũ��
		factors.push_back(n);//���� ���� n�� ���μ��̹Ƿ� �迭�� ����
	return factors;//���μ� �迭 ��ȯ
}
void process(int caseIndex)//�׽�Ʈ ���̽� ����
{
	long long n;//���μ����ظ� �� �ڿ��� n
	scanf("%lld", &n);//n �Է�
	vector<long long>factors = factorize(n);//n�� ���μ��� ��� ���ؼ� factors�迭�� ����
	printf("#%d:\n", caseIndex);//���° �׽�Ʈ���̽����� ���
	for (int i = 0; i < factors.size(); ++i)//���μ��� ������ŭ �ݺ�
	{
		if (i > 0)
			printf(" ");//���μ��� ������ ���⸦ ���� ���
		printf("%lld", factors[i]);//���μ� �� ���
	}
	printf("\n");//�̹� �׽�Ʈ ���̽��� ������ ����
}
int main()
{
	int caseSize;//�׽�Ʈ ĳ�̽��� ����
	scanf("%d", &caseSize);//�׽�Ʈ ���̽��� �� �Է�
	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex)//�׽�Ʈ ���̽��� ����ŭ �ݺ�
		process(caseIndex);//���α׷� �����ϴ� �Լ� ����

	return 0;//���α׷� ����
}