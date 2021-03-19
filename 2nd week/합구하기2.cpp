#include<cstdio>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;

void solve(int data[], int n, int p, int q) {
	int sum = 0, cnt=0;
	for (int i = 0; i < n; i++) {
		if (data[i] <= p) {//���Ƹ� ȸ���� ����ü�� ���϶��
			cnt++;//����ü���� ���� �ʴ� �ο��� ���� ���ϰ�
			sum += data[i];//�׵��� ������ ���� ����
		}
	}
	printf("%d %d\n", cnt, sum);//���� ü���� ���� �ʴ� �ο��� ���ڿ� ������ �� �� ����ϰ� ����
	if (sum < q)//�������� �� ���� �ִ������� ���� ������ YES ���
		printf("YES\n");
	else//�׷��� ������ NO ���
		printf("NO\n");
}

int main() {
	int n, p, q;//n=ȸ���� ��, p=���� ü��, q=�ִ� ����
	int* data;

	scanf("%d %d %d", &n, &p, &q);
	data = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}

	solve(data, n, p, q);//void �Լ��̱� ������ ��ȯ ���� ���� �Լ� ������ ���

	delete[] data;
	return 0;
}