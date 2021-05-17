#include<iostream>
#include<ctime>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

typedef pair<int, int> pi;
typedef priority_queue<pi, vector<pi>, greater<pi>> pq;

bool cmp(pair<int, int> &a, pair< int, int> &b) {
	return a.second < b.second;
}//pair<int, int>�� ���� ������ ����


vector<pair<int, int>> transferData(pq& eating_time) {
	vector<pair<int, int>> v;//eating_time���� �Űܿ� ����
	while (eating_time.size()>0) {//�켱���� ť���� ���ͷ� �����͸� �Űܿ��� �ݺ���
		int idx = eating_time.top().first;//�ð���
		int time = eating_time.top().second;//�ε����� ť���� ������
		eating_time.pop();//ť�� ���� �� ������ ����
		v.push_back({ idx, time });//���Ϳ� ����
	}
	return v;//�켱���� ť���� �����͸� �Űܿ� ���� ��ȯ
}

int solution(vector<pi> eating_time, long long k) {
	long long sum = 0;//�ð��� ���� ���� ���� sum
	pq eating_time_pq;
	for (int i = 0; i < eating_time.size(); i++) {
		sum += eating_time[i].first;//�Դ� �ð��� ���� sum�� ����
		eating_time_pq.push(eating_time[i]);//�켱���� ť�� eatingtime 
	}
	if (sum <= k) return -1;//�� �����ؾ� �� ������ ������ -1 ��ȯ
	
	long long prev = 0;//������ �Ծ��� ������ �� �Դµ� �ɸ� �ð�
	sum = 0;//�ð��� ���� 0���� �ʱ�ȭ
	int len = eating_time_pq.size();//���� ������ ����
	
	while (sum + (eating_time_pq.top().first - prev) * len <= k) {//���� �ð����� �� �ð��� �� ���� ���� �ݺ�
		long long now = eating_time_pq.top().first;//���� �԰� �ִ� ���ĸ� ������, ���� �԰� �ִ� ������ �� �Դµ� �ɸ��� �ð�
		eating_time_pq.pop();//�� ���� ������ ť���� ����
		sum += (now - prev) * len;// ���� �ð����� ������ ���� ���Ŀ� �ɸ� �ð��� ����, ���� ������ ������ ������. �׸��� ������ �Ծ��� ���ĵ��� �� �Դµ� �ɸ� �ð��� ���ϸ� ���� �԰��ִ� ������ �� �Դµ� �ɸ��� �ð�
		prev = now;//prev�� ���� now������ ����	
		len--;//���� ������ ������ 1�� ����
	}
	
	vector<pair<int, int>> v = transferData(eating_time_pq);//�켱���� ť���� ���ͷ� ������ �Űܿͼ�
	sort(v.begin(), v.end(), cmp);//cmp�� ����(�ε��� ��)���� �����ϰ�
	return v[(k - sum) % len].second;//�ٽ� ���� ������ ��� �ε��� ��ȯ
}

int main() {
	clock_t start, end;//�ð� ������ ���� ����

	int n; //������ ����
	vector<pi> eating_time;//������ �Դµ� �ʿ��� �ð�
	long long k;//��� ���� �� �� �� �Ŀ� ����� �ߴܵǾ���(2x10^13�����̱� ������ long long)

	cin >> n;//������ ���� �Է�

	for (int i = 0; i < n; i++) {
		int time;//�� ������ �Դµ� �ʿ��� �ð�
		cin >> time;//�ð� �Է�
		eating_time.push_back({ time, i+1 });//�ε����� �Բ� �켱���� ť�� ����
 	}
	cin >> k;//�Թ��� ������ �� �� ��(k) �Ŀ� ����� �ߴܵǾ����� k �� �Է�
 	start = clock();//�ð� ���� ����

	int ans = solution(eating_time, k);//�ٽ� ���� ������ ��� ans�� ����
	cout << ans << endl;//�� �� ���ĺ��� �Ծ�� �ϴ��� ���
	end = clock();//�ð� ���� ����
	double res = (double)(end - start) / CLOCKS_PER_SEC;//���α׷� ����ð� ���
	cout << "����ð�: " << res << "��" << endl;//���α׷� ����ð� ���
	return 0;//���α׷� ����
}