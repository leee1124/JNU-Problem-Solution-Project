#include<cstdio >
#include<map>
using namespace std;

int main()
{
	int n; //�Էµ� �������� �� ����
	scanf("%d", &n); //�Էµ� �������� ���� �Է�

	map<int, int>frequencyMap; //������ �Էµ� �������� �󵵼��� ������ �ʺ���

	for (int i = 0; i < n; i++) { //������ ������ŭ �ݺ�
		int x;//�Էµ� ����
		scanf("%d", &x); //x �Է�
		frequencyMap[x]++; //x�� �󵵼� ����
		printf("%d %d\n", frequencyMap.size(), frequencyMap[x]);//������� �Է����� �־��� ������ ������ ������ �̹��� �Է¹��� x�� �󵵼�
	}
	return 0;//���α׷� ����
}