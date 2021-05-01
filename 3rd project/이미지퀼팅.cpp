#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#pragma warning(disable:4996)
using namespace std;

int solve(int x, int y, int b1[100][100], int b2[100][100], int dp[100][100], int h, int w) {
	if (x == h) //�������� �� �̹����� ���̿� x���� ������
		return 0;// �Լ� ����

	if (dp[x][y] != -1)//dp[x][y]�� ���� -1�� �ƴ� ���
		return dp[x][y];// ret ���� ��ȯ

	dp[x][y] = solve(x + 1, y, b1, b2, dp, h, w);//dp[x][y]�� ���� -1�ΰ�� x�� ���� 1 �������Ѽ� ��ͷ� solve�Լ� ����

	if (y != 0) //y�� 0�� �ƴϸ�
		dp[x][y] = min(dp[x][y], solve(x + 1, y - 1, b1, b2, dp, h, w));//���� dp[x][y]���� x�� 1 ������Ű��, y�� 1 ���ҽ�Ų solve �Լ��� ��ȯ�� �� �������� ret ������ ����

	if (y != w - 1) //y�� w-1�� �ƴϸ�
		dp[x][y] = min(dp[x][y], solve(x + 1, y + 1, b1, b2, dp, h, w));//���� ret���� x�� y�� ���� 1�� ������Ų solve �Լ��� ��ȯ�� �� �������� ret ������ ����

	return dp[x][y] += ((b1[x][y] - b2[x][y]) * (b1[x][y] - b2[x][y]));//b1[x][y]-b2[x][y]�� �������� dp[x][y]�� ���� dp[x][y]�� ����
}

int main() {
	int h, w;//�������� �� �̹����� ���� H, �������� ������ �ʺ� W
	int b1[100][100], b2[100][100];//B1, B2 �̹����� ������ ������ �迭
	int dp[100][100];//dp �迭
	time_t start, end;

	scanf("%d %d", &h, &w);//h�� w �Է¹ޱ�

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &b1[i][j]);//b1�� �̹��� ���� �Է�
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &b2[i][j]);//b2�� �̹��� ���� �Է�
		}
	}
	start = clock();

	memset(dp, -1, sizeof(dp));//dp �迭�� ���� ���� -1�� �ʱ�ȭ

	for (int i = 0; i < w; i++) {
		solve(0, i, b1, b2, dp, h, w);//solve �Լ� ����
	}

	printf("%d\n", *min_element(dp[0], dp[0] + w));//min_element�Լ��� �ּҸ� ��ȯ�ϱ� ������ * �����ڸ� ����ؼ� ���� ��� 
	end = clock();
	double res = (double)(end - start) / CLOCKS_PER_SEC;
	printf("����ð�: %f��\n", res);
	return 0;//���α׷� ����
}