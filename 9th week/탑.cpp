#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Tower {
public:
	int index;//Ÿ���� �ε���
	int height;//Ÿ���� ����
	int targetTowerIndex;//Ÿ���� �������� �����ϴ� ��� Ÿ��

	Tower(int index, int height) {//Tower Ŭ������ ������
		this->index = index;//��ü�� index�� �Ű����� index�� ���� ����
		this->height = height;//��ü�� height�� �Ű����� height�� ���� ����
		this->targetTowerIndex = 0;//��ü�� targetTowerIndex�� 0 ����
	}
	void setTargetTowerIndex(int targetTowerIndex) {//targetTowerIndex�� ���� �����ϴ� �Լ�
		this->targetTowerIndex = targetTowerIndex;//��ü�� targetTowerIndex�� �Ű����� targetToewerIndex�� ���� ���� 
	}
	int getTargetTowerIndex() {//targetTowerIndex ��ȯ�ϴ� �Լ�
		return this->targetTowerIndex;//targetTowerIndex ��ȯ
	}
};

void findTargetTowers(vector<Tower>& towers) {	
	stack<Tower> stk;//���� �ٸ� Ÿ���� ��ȣ�� ������ ���ɼ��� �ִ� Ÿ����

	for (int i = 0; i < towers.size(); i++) {//Ÿ���� ������ŭ �ݺ�
		Tower& t = towers[i];//�� Ÿ�� t�� ���� ���ʷ� ���
		int targetTowerIndex = 0;// Ÿ�� t�� ��ȣ�� ������ �ĺ�(�ʱⰪ NULL)

		while (stk.empty() == false && stk.top().height < t.height) {//t���� ���̰� ���� Ÿ������ ���Ŀ��� ���� ���ɼ��� �����Ƿ� ����
			stk.pop();
		}
		if (stk.size() > 0) {
			//t�̻��� ���̸� ���� Ÿ���� �ִٸ�
			targetTowerIndex = stk.top.index;
			//t�� �ش� Ÿ���� Ÿ������ ����
		}
		t.setTargetTowerIndex(targetTowerIndex);//����� Ÿ�� ������ ����

		stk.push(t);//t�� �������� ���������Ƿ� �ٸ� Ÿ���� ��ȣ�� ������ �� ����.
	}
}

int main() {
	int n;//ž�� ����
	cin >> n;//ž�� ���� �Է�

	vector<Tower> towers;//Tower Ŭ���� �迭 towers

	for (int i = 0; i < n; ++i) {//ž�� ������ŭ �ݺ�
		int hi;//ž�� ����
		cin >> hi;//ž�� ���� �Է�
		towers.push_back(Tower(i + 1, hi));//towers �迭�� �ε���(1����), ž�� ���� ����
	}

	findTargetTowers(towers);//�� Ÿ���� �۽��ϴ� �������� ���� Ÿ���� ��� ���

	for (int i = 0; i < n; i++) {//ž�� ������ŭ �ݺ�
		if (i > 0) {//ó�� ���� �ε����� �ƴϸ�
			cout << " ";//����
		}
		Tower t = towers[i];//TowerŬ���� ��ü t�� towers�迭�� i��° ���� ����
		int targetIndex = t.getTargetTowerIndex();//getTargetIndex�Լ��� ���� t�� Ÿ���ε����� �����ͼ� ������
		cout << targetIndex;//Ÿ�� �ε��� ���
	}
}