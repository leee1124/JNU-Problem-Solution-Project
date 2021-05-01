#include<cstdio>
#include<algorithm>
#pragma warning(disable: 4996)
using namespace std;

int get_area(int la, int ra, int ta, int ba, int lb, int rb, int tb, int bb) {
	int l, r, t, b;//����, ������, ��, �Ʒ�
	 l = max(la, lb);//�� ���簢���� ���� x��ǥ �߿��� �� ū ���� ���� x��ǥ
	 r = min(ra, rb);//�� ���簢���� ������ x��ǥ �߿��� �� ���� ���� ������ x��ǥ
	 t = min(ta, tb);//�� ���簢���� ���� y��ǥ �߿��� �� ���� ���� ���� y��ǥ
	 b = max(ba, bb);//�� ���簢���� �Ʒ��� y��ǥ�߿��� �� ū ���� �Ʒ��� y��ǥ

	 if(l<=r && b<=t)//�� ���簢���� ��ġ��
		 return (r - l) * (t - b);//���簢���� ���� ����*���θ� ��ȯ
	 return 0;//�׷��� ������ 0 ��ȯ
}
void test_case() {
	int ax, ay, bx, by;//���簢�� a�� A,B,P,Q�� ���� ��ǥ
	int px, py, qx, qy;//���簢�� b�� A,B,P,Q�� ���� ��ǥ
	scanf("%d %d %d %d", &ax, &ay, &bx, &by);
	scanf("%d %d %d %d", &px, &py, &qx, &qy);

	int la, ra, ba, ta;//���簢�� a
	la = min(ax, bx);//���簢�� a�� ���� x��ǥ
	ra = max(ax, bx);//���簢�� a�� ������ x��ǥ
	ta = max(ay, by);//���簢�� a�� ���� y��ǥ
	ba = min(ay, by);//���簢�� a�� �Ʒ��� y��ǥ

	int lb, rb, bb, tb;//���簢�� b
	lb = min(px, qx);//���簢�� a�� ���� x��ǥ
	rb = max(px, qx);//���簢�� a�� ������ x��ǥ
	tb = max(py, qy);//���簢�� a�� ���� y��ǥ
	bb = min(py, qy);//���簢�� a�� �Ʒ��� y��ǥ

	int answer = get_area(la, ra, ta, ba, lb, rb, tb, bb);//answer ������ �� ���簢���� ��ġ�� ���̸�, ��ġ�� ������ 0�� ����

	printf("%d\n", answer);//�� ���簢���� ��ġ�� ���̸�, ��ġ�� ������ 0�� ���
}

int main() {
	int t;//�׽�Ʈ���̽��� ����
	scanf("%d", &t);//�׽�Ʈ���̽��� ���� �Է�

	for (int i = 0; i < t; i++)//�׽�Ʈ���̽� ������ŭ �ݺ�
		test_case();//�׽�Ʈ���̽� �Լ� ����

	return 0;//���α׷� ����
}