#include<cstdio>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

class TicketTable {
public:
	vector<bool>used;//��� �ߴ��� ���ߴ��� ���¸� ������ �迭
	int length;//���� ����
	TicketTable(int length)//�Ű����� �ִ� ������
	{
		this->length = length;//���� ũ��� �Ű�����
		this->used.assign(length, false);//��� ���´� ���� ��� ����
	}
	int findEmptyIndexByUserId(int userId)//������� ȸ�� ��ȣ�� ���޹ް� �� ���� ��ȣ�� ����ϴ� �Լ�
	{
		int index = userId % length; //�� ó�� �õ� �� ��ȣ
		while (this->isEmpty(index) == true) //�̹� ���ȰŸ� �н�
			index = (index + 1) % length; //���� ��ȣ üũ
		return index;
	}
	bool isEmpty(int ticketIndex)//���� ��ȣ�� �̹� ��������� Ȯ���ϴ� �Լ�
	{
		return this->used[ticketIndex]; //������̸� true, �ƴϸ� false ��ȯ
	}
	void setUsed(int index, bool status)//Ƽ�� ��� ���θ� �����ϱ� ���� �Լ�
	{
		this->used[index] = status;//���¸� �Է�
	}
};
vector<int>getTicketNumbers(int n, int m, const vector<int>& ids)//���� ��ȣ�� ����ϴ� �Լ�
{
	vector<int> tickets;//���� ��ȣ�� ������ �迭
	TicketTable table = TicketTable(n);//������ ������ n��
	for (int i = 0; i < m; i++)
	{
		int userId = ids[i];//userId�� ȸ����ȣ
		int ticketIndex = table.findEmptyIndexByUserId(userId);//ȸ����ȣ�� ���޹ް� �� ���� ��ȣ�� ����ؼ� ticketIndex�� ����
		tickets.push_back(ticketIndex); //ticktets �迭�� tikcetIndex �迭 �߰� 
		table.setUsed(ticketIndex, true);//Ƽ�� ��� ���� ����
	}
	return tickets;//tickets �迭 ��ȯ
}
int main()
{
	int n, m;//��ü Ƽ���Ǽ�, ��û ���� ��
	scanf("%d %d", &n, &m);//��ü Ƽ���� ���� ��û ���� �� �Է�
	vector<int> ids(m);//ȸ����ȣ�� ������ �迭, m���� ���Ҹ� 0���� �ʱ�ȭ
	for (int i = 0; i < m; ++i)//m�� �ݺ�
		scanf("%d", &ids[i]);//ȸ����ȣ �Է�
	vector<int> tickets = getTicketNumbers(n, m, ids);//���� ��ȣ�� ����ؼ� �迭�� ����
	for (int i = 0; i < tickets.size(); ++i)//���� ������ŭ �ݺ�
		printf("%d\n", tickets[i]); //���� ��ȣ ���
}