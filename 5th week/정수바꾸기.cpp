#include<cstdio>
#include<ctime>
#pragma warning(disable:4996)
using namespace std;

int main() {
	clock_t start, end;//����ð��� �����ϱ� ���� ����, ���α׷��� ���۰� ���� �ǹ���
	int a, b;//a�� b. 10�� 9�±����� �����̹Ƿ� int �ڷ����� ���Եȴ�.
	scanf("%d %d", &a, &b);//a�� b �Է�
	start = clock();

	int cnt = 0;//����Ƚ��

	while (a<b) {//a�� b���� �������� �ݺ�
		if (b % 10 == 1) {//b�� 1�� ��������
			b = (b - 1) / 10;//1�� ������
			cnt++;//����Ƚ�� ����
		}
		else if (b % 2 == 0) {//b�� 2�� ��������
			b /= 2;//b�� 2�� ����
			cnt++;//����Ƚ��
		}
		else
			break;//�����ڸ����� 1�� �ƴϸ� �ݺ��� ��������(����ġ��)
	}
	printf("%d\n", (a == b) ? cnt+1 : -1);//a��b�� ������(���꿡 �����ϸ�) ����Ƚ���� 1�� ���Ѱ��� ���, ���� �� ���� ��쿡�� -1 ���
	end = clock();
	double result = (double)(end - start) / CLOCKS_PER_SEC;//�� �ð����� ���۽ð��� ���� �ð��� ����ϰ�, ms ������ �� ������ ����
	printf("����ð�: %f��\n", result);// ���α׷� ����ð� ���
	return 0;//���α׷� ����
}