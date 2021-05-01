#include<cstdio>
#include<vector>
#include<algorithm>
#include<ctime>
#pragma warning(disable: 4996)
using namespace std;

int solve(int** arr, int x, int y) {//�ι�°�� ū ���� ��ȯ�ϴ� �Լ�
	vector<int> v;//2x2 ����� ���� �迭
	for (int i = x; i < x + 2; i++) {
		for (int j = y; j < y + 2; j++) {
			v.push_back(arr[i][j]);//2x2 ����� v�� ����
		}
	}
	sort(v.begin(), v.end(), greater<int>());//�������� ����
	return v[1];//�ι�°�� ū ���� ��ȯ
}

int main() {
	time_t start, end;//�ð� ������ ���� ����
	int n;//2�� �ŵ����� ���� �� n
	int** arr;//n x n ��� arr

	scanf("%d", &n);

	arr = new int* [n];//2���� �迭
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];//�����Ҵ�
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);//n x n ��� �Է�
		}
	}
	start = clock();// ���α׷� ����ð� ���� ����

	while (n != 1) {//n�� 1�� �ƴѰ��(1 x 1 ����� �ƴ� ���)
		for (int i = 0; i < n; i += 2) {
			for (int j = 0; j < n; j += 2) {
				arr[i / 2][j / 2] = solve(arr, i, j);//����, ���� 2ĭ�� �����̸� arr ����
			}
		}
		n /= 2;// n�� 2�� ����
	}

	printf("%d\n", arr[0][0]);//���� �ϳ� 

	for (int i = 0; i < n; i++)
		delete[] arr[i];//n x n 2���� �迭
	delete[] arr;//�����Ҵ� ����

	end = clock();//���� ����
	double res = (double)(end -start) / CLOCKS_PER_SEC;//�����ð��� �ʴ����� ��ȯ
	printf("����ð�: %f��\n", res);//�����ð� ���
	return 0;//���α׷� ����
}