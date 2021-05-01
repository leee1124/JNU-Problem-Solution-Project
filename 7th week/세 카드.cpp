#include<cstdio>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

vector<int> getPossibleTargets(int n, int m, int* cards, int* targets) {
	vector<int> possibleTargets;//���� �� �ִ� ��÷ ��ȣ��

	sort(cards, cards + n);// ��� ī�带 ������������ ����, ���̳ʸ� ��ġ�� ���� ����

	for (int i = 0; i < m; ++i) {
		int k = targets[i];// ��� Ÿ�� k�� ���Ͽ�
		bool possible = false;
		
		for (int j = 0; j < n; ++j) { 
			int x = cards[j];//��� ī���� �ϳ��� x�� ���Ͽ�
			
			for (int p = 0; p <= j; p += 1) {//���������� �ߺ� ���ֱ�
				int y = cards[p];//ī�� �� �ϳ� y�� ����
				int z = k - (x + y);// k=(x+y)+z�� �Ǵ� z�� ���

				if (binary_search(cards, cards + n, z) == true) {//z�� cards �迭�� �����Ѵٸ�
					possible = true;//k=x+y+z�� ������ x,y,z�� �����ϸ� possible�� ���� �����ϰ�
					break;//for�� ��������
				}
			}
			if (possible) {//�̹� ã�Ҵٸ�
				break;//Ż��
			}
		}
		if (possible) {//k=x+y+z�� ������ x,y,z�� �����ϸ�
			possibleTargets.push_back(k);//������ ���� �� �ִ� ��÷��ȣ�� �߰�
		}
	}
	sort(possibleTargets.begin(), possibleTargets.end());//��½� ������������ �����ϴ� ���� �����̱� ������ ������������ ����
	return possibleTargets;//������ ���� �� �ִ� ��÷��ȣ �迭 ��ȯ
}

int main() {
	int n;//ī���� ��
	int m;//�˻� �� �ĺ� ��÷��ȣ�� ��
	scanf("%d %d", &n, &m);//ī���� ��, �ĺ� ��÷��ȣ�� �� �Է�

	int* cards = new int[n];//ī���� ����ŭ �����Ҵ�
	int* targets = new int[m];//�ĺ� ��÷��ȣ�� ����ŭ �����Ҵ�

	for (int i = 0; i < n; i++) {
		scanf("%d", &cards[i]);
	}//�� ī���ȣ �Է�

	for (int i = 0; i < m; i++) {
		scanf("%d", &targets[i]);
	}//�� �ĺ� ��÷��ȣ �Է�

	vector<int> answers = getPossibleTargets(n, m, cards, targets);//answers�� ������ ���� �� �ִ� ��÷��ȣ �迭 ����
	
	if (answers.size() == 0) {
		printf("NO");//������ ��÷��ȣ�� ���ٸ� NO�� ���
	}
	else {//������ ��÷��ȣ�� �����Ѵٸ� �� ����� ���
		for (int i = 0; i < answers.size(); i++) {
			if (i > 0) {
				printf(" ");//�������� ���ڸ� �����ϱ� ���� ���
			}
			printf("%d", answers[i]);//���� ���� �� �ִ� ��÷��ȣ ���
		}
	}

	delete[] cards;//ī�� �迭 �����Ҵ� ����
	delete[] targets;//�ĺ� ��÷��ȣ �迭 �����Ҵ� ����
	return 0;//���α׷� ����
}