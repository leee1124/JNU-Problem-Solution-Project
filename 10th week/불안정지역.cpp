#include<iostream>
#include<vector>
#include<queue>
#pragma warning(disable: 4996)
using namespace std;

class City {
public:
	int index; //���� �ε���
	int income; //���� �ҵ�

	City(int index, int income) { //���� ������
		this->index = index;//index �Ű������� ��ü�� �Ű�����
		this->income = income;//income �Ű������� ��ü�� �Ű�����
	}
	bool operator<(const City& o)const {//��Ұ��� �߰�
		return this->income < o.income;
	}
	bool operator>(const City& o)const {//��Ұ��� �߰�
		return this->income > o.income;
	}
	//������ �����ε��� ���� income���� ���� ���������� ���������� ������
};

int getMaximumRangeDifference(int n, int k, const vector<City>& cities) {
	int answer = 0;//������ ���� ����

	priority_queue<City, vector<City>, greater<City>> rangeMinimum;//�ҵ��� ���� ���ú��� pop�ϴ� �켱���� ť(��������)

	priority_queue<City> rangeMaximum; //�ҵ� ���� ���ú��� pop�ϴ� �켱���� ť(����Ʈ��(vector<City>, less<City>�� ������� ������)�� ��������)

	for (int i = 0; i < k - 1; i++) {//i�� 0���� k-2���� �ݺ�
		rangeMaximum.push(cities[i]);//���������� �켱���� ť(front�� �ҵ��� ū ����)�� cities ���� ������ i��° �� �Է�
		rangeMinimum.push(cities[i]);//���������� �켱����ť(front�� �ҵ��� ���� ����)�� cities ���� ������ i��° �� �Է�
	}
	for (int i = k - 1; i < n; i++) {//k-1 ������ ���� ó���ϱ� ���� �ݺ���
		rangeMaximum.push(cities[i]);//���������� �켱���� ť(front�� �ҵ��� ū ����)�� cities ���� ������ i��° �� �Է�
		rangeMinimum.push(cities[i]);//���������� �켱���� ť(front�� �ҵ��� ���� ����)�� cities ���� ������ i��° �� �Է�
		while (rangeMaximum.top().index < i - k + 1)rangeMaximum.pop();//������ ���� ���� ����
		while (rangeMinimum.top().index < i - k + 1)rangeMinimum.pop(); //������ ���� ���� ����
		answer = max(answer, rangeMaximum.top().income - rangeMinimum.top().income);//�ִ� �ҵ����� ������Ʈ
	}
	return answer; //�� ��ȯ
}

void process(int caseIndex) {
	int n, k;//������ ��, ������ ������ ��
	cin >> n >> k; //������ ��,������ ������ �� �Է�
	vector<City>cities;//������ ������ ���� ���ͺ���

	for (int i = 0; i < n; i += 1) {
		int income;//���� �ҵ�
		cin >> income;//�ҵ� �Է�
		cities.push_back(City(i, income)); //cities ���� ������ ������ ������ ����
	}

	int answer = getMaximumRangeDifference(n, k, cities); //getMaximumRangeDifference() �Լ��� ������� ���� ū �ҵ��� �� ����

	cout << answer << endl; //�� ���
}

int main() {
	int caseSize; //�׽�Ʈ ���̽� ����
	cin >> caseSize;//�׽�Ʈ ���̽� ���� �Է�

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1)
		process(caseIndex); //�׽�Ʈ ���̽� ������ŭ process �Լ� ����

	return 0;//���α׷� ����
}