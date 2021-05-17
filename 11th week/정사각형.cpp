#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;

class Point2D {
public:
	int x;//x��ǥ
	int y;//y��ǥ
	int index;//�������� �ε���

	Point2D(int index, int x, int y) { //�ε��� �Է� �޾��� ���
		this->index = index; //�ε��� ���� �Է� ���� ������ ����
		this->x = x; //x�� �Է� ���� ������ ����
		this->y = y;//y�� �Է� ���� ������ ����
	}
	Point2D(int x, int y) { //�ε��� �Է� �ȹ޾��� ���
		this->index = 1;//�ε��� ���� 1�� ����
		this->x = x;//x�� �Է� ���� ������ ����
		this->y = y;//y�� �Է� ���� ������ ����
	}
	long long getSquaredDistanceTo(Point2D target) { //�� ��ǥ�� ���� �Ÿ� ��� >>���簢���� ����
		long long dx = abs(this->x - target.x);//x��ǥ�� ���� ���� �� ����
		long long dy = abs(this->y - target.y);//y��ǥ�� ���� ���� �� ����
		return dx * dx + dy * dy;//���簢���� ����
	}
	bool operator<(const Point2D& other)const { //��Ұ��踦 ���� ��� ������ ������ ����
		if (this->x != other.x) { //x��ǥ�� �ٸ��� x��ǥ �������� ��
			return this->x < other.x;
		}
		return this->y < other.y; //x��ǥ�� ������ y��ǥ�� �������� ��
	}
};

long long getMaximumSquareArea(int n, const vector <Point2D>& points) {
	long long answer = 0;//�ִ� ����, x��ǥ�� y��ǥ�� ���� 1����� ���� �� �����Ƿ� int���� �ƴ϶� long long ���� ����Ѵ�.

	set<Point2D>pSet; //set������ Point2D Ŭ������ ���� �� �ֵ��� ����
	for (int i = 0; i < n; i++) {
		pSet.insert(points[i]);//���Ϳ� ��� ��ü�� pSet ������ �������ش�
	}

	for (int i = 0; i < n; i++) {//������ a�� b �� ���� ��´�.
		Point2D pa = points[i];//������ �� a
		for (int j = 0; j < n; j++) {
			Point2D pb = points[j];//������ �� b
			if (i == j)continue;//���� �� ����

			long long area = pa.getSquaredDistanceTo(pb); //���� ���
			if (area < answer)//���̰� ������ ������
				continue;//�ǳʶڴ�.

			int dx = pb.x - pa.x;//pa->pb������ x��ǥ�� ���� �Ÿ�
			int dy = pb.y - pa.y;//pa->pb������ y��ǥ�� ���� �Ÿ�
			
			Point2D pd(pa.x - dy, pa.y + dx);//���ο� �� d
			Point2D pc(pb.x - dy, pb.y + dx);//���ο� �� c

			if (pSet.count(pc) > 0 && pSet.count(pd) > 0)//pd�� pc�� pSet�� �����ϴ� ���̸�
				answer = max(answer, area);//������� �ִ� ���̿� ���� ���簢���� ������ �� ū ���� answer�� ����

		}
	}
	return answer;//answer ��ȯ
}

void process(int caseIndex) {
	int n;//��ǥ�� ����
	cin >> n;//��ǥ�� ���� �Է�

	vector<Point2D>points;//Point2D Ŭ������ ���� ���ͺ���

	for (int i = 0; i < n; i++) {
		int x, y;//x��ǥ�� y��ǥ
		cin >> x >> y; //x��ǥ�� y��ǥ�� �Է¹޴´�
		points.push_back(Point2D(i, x, y));//points ���ͺ����� Point2DŬ������ ������
	}
	double answer = getMaximumSquareArea(n, points);//���� ���ϴ� �Լ� ����

	cout << fixed << setprecision(2) << answer << endl;//��°¥������ ���
}

int main() {
	int caseSize; //�׽�Ʈ ���̽� ���� �޴� ����
	cin >> caseSize;//�׽�Ʈ ���̽� ���� �Է�

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++) {//�׽�Ʈ ���̽� ������ŭ �ݺ�
		process(caseIndex); //���̽� ������ŭ process����
	}
}