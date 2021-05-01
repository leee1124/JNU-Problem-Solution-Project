#include<cstdio>
#pragma warning(disable:4996)
using namespace std;

const int MAX_ROW = 9;//���� 9��
const int MAX_COL = 9;//���� 9��

class SudokuBoard {
public:
	//ĭ�� ��ȣ�� ���� ��ȣ�� ����ϴ� �޼ҵ�
	int getRowByIndex(int index)
	{
		//ĭ�� ��ȣ�� ���� ���� ������ �����ϹǷ� ������ ����� �� �ִ�.
		return(index - 1) / 9 + 1;//�迭�� 0���� �����ϹǷ� 1���� ���� ���ϰ�, �ε����� 1���� �����ϹǷ� 1 ���� �� ��ȯ
	}
	
	//ĭ�� ��ȣ�� ���� ��ȣ�� ����ϴ� �޼ҵ�
	int getColByIndex(int index)
	{	//ĭ�� ��ȣ�� ���� ��Ģ������ ��ȯ�ϹǷ� �������� ����� �� �ִ�.
		return(index - 1) % 9 + 1;//�迭�� 0���� �����ϹǷ� 1���� �������� ���ϰ�, �ε����� 1���� �����ϹǷ� 1 ���� �� ��ȯ
	}
	
	//ĭ�� ��ȣ�� �׷� ��ȣ�� ����ϴ� �޼ҵ�
	int getGroupByIndex(int index)
	{
		int r = getRowByIndex(index);//���� ���� ���� ���� r�� ����
		int c = getColByIndex(index);//���� ���� ���� ���� c�� ����
		return getGroupByPosition(r, c);//�׷� ��ȣ�� ������ �Լ��� ȣ�⿡ �ش� �Լ��� ��ȯ�ϴ� ���� ��ȯ
	}
	
	//ĭ�� ��ġ(��, ��)�� �׷� ��ȣ�� ����ϴ� �޼ҵ�
	int getGroupByPosition(int row, int column)
	{	//���� ��ȣ�� ����, �ش� �࿡ �����ϴ� �׷�� �� ���� ���� �׷��� ��ȣ�� �� �� �ִ�.
		int left = ((row - 1) / 3) * 3 + 1;//ex) 1,2,3�� ���� 1�� �׷�, 4,5,6�� ���� 4�� �׷�, 7,8,9�� ���� 7���׷�
		//���� ��ȣ�� ����, �ش� �࿡ �����ϴ� �׷�� �� �� ��° �׷쿡 ���ϴ��� �� �� �ִ�.
		int offset = ((column - 1) / 3);//ex)1,2,3�� ���� 0(1��°), 4,5,6�� ���� 1(2��°), 7,8,9�� ���� 2(3��°)
		return left + offset;//�ش� �׷��� ���� ���� �׷� ��ȣ�� �������� ���� �׷� ��ȣ�� �����
	}
	
	//ĭ�� ��ġ�� �׷� ��ȣ ���
	int getIndexByPosition(int row, int column)
	{	//��� ���� ��ȣ�� �˸� �ݴ�� �ε����� ���� ����� �� �ִ�.
		return (row - 1) * 9 + (column - 1) % 9 + 1;
	}
};
void process(int caseIndex)
{
	int index;//������ ���� ĭ�� ��ȣ
	scanf("%d",&index);//index ���� �Է�

	SudokuBoard board = SudokuBoard();
	//ĭ�� ��ȣ�� ��, ��, �׷� ��ȣ�� ����Ѵ�.
	int row = board.getRowByIndex(index);//ĭ�� ��ȣ�� ���� ��ȣ�� ���
	int col = board.getColByIndex(index);//ĭ�� ��ȣ�� ���� ��ȣ�� ���
	int group = board.getGroupByIndex(index);//ĭ�� ��ȣ�� �׷� ��ȣ�� ���
	
	printf("Case #%d:\n", caseIndex);//Case # �׽�Ʈ���̽� ��ȣ: ���
	printf("%d %d %d\n", row, col, group);//row, col, group���� ���
}

int main()
{
	int caseSize;//�׽�Ʈ���̽��� ������ �Է¹޴� ����
	scanf("%d", &caseSize);//�׽�Ʈ ���̽� ���� �Է�

	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex)//�׽�Ʈ ���̽� ������ŭ �ݺ�
		process(caseIndex);
}