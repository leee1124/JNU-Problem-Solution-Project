#include<cstdio>
#include<cmath>
#include<climits>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;

class Point2D {
private:
	int x;//õü�� x��ǥ���� ������ ����
	int y;//õü�� y��ǥ���� ������ ����

public:
	Point2D(int x = 0, int y = 0) {//Ŭ������ ������, ����Ʈ �Ű������� x�� y�� 0�� ������ ���� ������ ������ x�� y�� ���� 0
		this->x = x;//��ü�� x�� ��ǥ�� �������� �Ű������� ���� ���� x������ ����
		this->y = y;//��ü�� y�� ��ǥ�� �������� �Ű������� ���� ���� y������ ����
	}
	/*
	2���� ��� �󿡼� �� this���� �� target���� �Ÿ��� ������ ����ϴ� �Լ�
	param target
	return
	*/
	int getSquaredDistanceTo(const Point2D& target) const {//�Ÿ��� ������ ����ϴ� �Լ�
		int dx = abs(this->x - target.x);//���� õü���� Ÿ�� õü���� x��ǥ�� ��
		int dy = abs(this->y - target.y);//���� õü���� Ÿ�� õü���� y��ǥ�� ��
		return dx * dx + dy * dy;//�Ÿ��� ���ϱ� ���ؼ� x��ǥ�� ���� ������ y��ǥ�� ���� ������ ���� ��(�Ÿ��� ����)�� ��ȯ
	}
	double getDistanceTo(const Point2D& target) const {
		double sqd = (double)this->getSquaredDistanceTo(target);//�Ÿ��� ������ ����ϴ� �Լ��� ���� ��ȯ�� ���� sqd ������ ����
		return sqrt(sqd);//��Ʈ ����� ���� �Ÿ��� ����ϰ�, �ش� �� ��ȯ
	}
};

int main() {
	int n;//õü�� ���� ������ ����
	Point2D* points;//Point2DŬ������ ���� points

	scanf("%d", &n);//õü�� ���� �Է�
	points = new Point2D[n];//õü�� ������ŭ �迭�� �����Ҵ�

	for (int i = 0; i < n; i++) {//õü�� ������ŭ �ݺ�
		int x, y;//x��ǥ�� y��ǥ���� �Է¹��� ����
		scanf("%d %d", &x, &y);//x��ǥ����  y��ǥ�� �Է�

		points[i] = Point2D(x, y);//�����ڸ� �̿��� ��ü�� x��ǥ���� y��ǥ�� �Է�
	}
	
	int min_sqd = INT_MAX;//�Ÿ��� �������� ������ ����
	int min_cnt = 0;//�� �Ÿ���ŭ ������ õü ���� ���� ������ ����

	for (int i = 0; i < n; i++) {//õü�� ������ŭ �ݺ�
		for (int j = 0; j < i; j++) {//i��° õü�� j��° õü�� �Ÿ��� ���ϰ�, �ߺ������ ���ϱ� ���ؼ� j�� i���� �������� ���
			int sqd = points[i].getSquaredDistanceTo(points[j]);//�Ÿ��� ������ �޾ƿͼ� sqd ������ ����
			if (sqd < min_sqd) {//��������� �ּ� �Ÿ����� �� ª�� �ּҰŸ��� �߰ߵǸ�
				min_sqd = sqd;//�ּҰŸ� ����
				min_cnt = 1;//�� �Ÿ���ŭ ������ õü ���� ���� ó������ �ٽ� ��
			}
			else if (sqd == min_sqd) {//�ּ� �Ÿ��� ������ �Ÿ���ŭ ������ õü�� �� �߰ߵǸ�
				min_cnt++;//�� �Ÿ���ŭ ������ õü ���� �� ����
			}
		}
	}

	double distance = sqrt(min_sqd);//sqd�� �Ÿ��� �����̹Ƿ� ��Ʈ ����� ����
	printf("%.1f\n", distance);//�Ÿ��� �Ҽ��� ù°�ڸ� ������ ���
	printf("%d\n", min_cnt);// �� �Ÿ���ŭ ������ õü ���� �� ���

	delete[] points;//�����Ҵ� ����
	return 0;
}