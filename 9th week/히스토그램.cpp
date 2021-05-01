#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;

class Histogram {
public:
	int height;//������׷��� ����
	int leftX;//�ε��� Ȥ�� ������׷��� ���� ���� x ��ǥ
	int rightX;//������׷��� ������ ���� x��ǥ

	Histogram() {}
	Histogram(int index, int height) {
		this->height = height;//��ü�� height�� �Ű����� height�� �� ����
		this->leftX = index;//���� ���� x��ǥ�� �Ű����� index�� �� ����
		this->rightX = this->leftX + 1;//������ ���� x ��ǥ�� ���� ���� x��ǥ +1 ����
	}
};

long long getLargeRectangleArea(const vector<Histogram> histograms) {//���̸� ���ϴ� �Լ�
	long long answer = 0;//long long�� ���� answer ����, �ʱⰪ�� 0

	stack<Histogram> stk;//������׷� Ŭ������ ��ü�� ���� ���ú���
	stk.push(Histogram(-1, 0));//������ ���Ǹ� ���� ���� ���ʿ� ���� 0������ ������ ������׷� �߰�

	for (int i = 0; i < histograms.size(); i++) {
		Histogram h;
		if (i < histograms.size()) {//�ε����� ������׷��� �������� ������
			h = histograms[i];//h�� hisograms�� i��° ������׷� ��ü ����

		}
		else {
			h = Histogram(histograms.size(), 0);//������ ���Ǹ� ���� ���� �����ʿ� ���� 0������ ������ ������׷� �߰�
		}
		//������ Ȯ�����̴� ������׷��� ��, h���� ���̰� ���� ������׷�����
		//���̻� Ȯ��� �� ����. => �ִ� ���̰� ������
		while (stk.size() > 1 && stk.top().height > h.height) {
			Histogram lh = stk.top();//�����ϱ� ���� toip�� ���߿� ����ϱ� ����
			stk.pop();//������ ���� �� ���� ����

			Histogram bh = stk.top();//�� ������ ������׷�(���� Ȯ���� ��)

			//���� �߰��� h�� �ٷ� ���ʱ��� Ȯ�����̾���.
			long long width = abs(h.leftX - bh.rightX);//�غ�
			long long height = lh.height;//����
			long long area = width * height;//���̴� �غ�*����

			answer = max(answer, area);//�ִ� �� ����
		}
		stk.push(h);
	}
	return answer;//asnwer ��ȯ
}

void process(int caseIndex) {
	int n;//�׷����� ������ �Է¹��� ����
	cin >> n;// �׷����� ���� �Է�

	vector<Histogram> histograms;//Histogram Ŭ������ ���� ���ͺ���
	for (int i = 0; i < n; i++) {//�׷����� ������ŭ �ݺ�
		int height;//������׷��� ���̸� �Է¹��� ����
		cin >> height;//������׷��� ���̸� �Է�
		histograms.push_back(Histogram(i, height));//���� �ε��� ��ȣ�� �Է¹��� ������׷��� ���̷� ������׷� ��ü�� �����ؼ� ���ͺ����� ����
	}
	long long answer = getLargeRectangleArea(histograms);//���̸� ���ؼ� answer ������ ����
	cout << answer << endl;//answer���� ����ϰ� ����
}

int main() {
	int caseSize;//�׽�Ʈ ���̽� ������ �Է¹��� ����
	cin >> caseSize;//�׽�Ʈ ���̽� ���� �Է�
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {//�׽�Ʈ ���̽� ������ŭ �ݺ�
		process(caseIndex);//�׽�Ʈ ���̽� ������ŭ �ݺ��ؼ� process �Լ� ����
	}
}