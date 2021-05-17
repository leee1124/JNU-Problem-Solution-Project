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
}//pair<int, int>의 정렬 기준을 설정


vector<pair<int, int>> transferData(pq& eating_time) {
	vector<pair<int, int>> v;//eating_time에서 옮겨올 벡터
	while (eating_time.size()>0) {//우선순위 큐에서 벡터로 데이터를 옮겨오는 반복문
		int idx = eating_time.top().first;//시간과
		int time = eating_time.top().second;//인덱스를 큐에서 빼오고
		eating_time.pop();//큐의 가장 위 데이터 삭제
		v.push_back({ idx, time });//벡터에 저장
	}
	return v;//우선순위 큐에서 데이터를 옮겨온 벡터 반환
}

int solution(vector<pi> eating_time, long long k) {
	long long sum = 0;//시간의 합을 구할 변수 sum
	pq eating_time_pq;
	for (int i = 0; i < eating_time.size(); i++) {
		sum += eating_time[i].first;//먹는 시간의 합을 sum에 저장
		eating_time_pq.push(eating_time[i]);//우선순위 큐에 eatingtime 
	}
	if (sum <= k) return -1;//더 섭취해야 할 음식이 없으면 -1 반환
	
	long long prev = 0;//이전에 먹었던 음식을 다 먹는데 걸린 시간
	sum = 0;//시간의 합을 0으로 초기화
	int len = eating_time_pq.size();//남은 음식의 개수
	
	while (sum + (eating_time_pq.top().first - prev) * len <= k) {//남은 시간보다 뺄 시간이 더 작을 때만 반복
		long long now = eating_time_pq.top().first;//현재 먹고 있는 음식만 먹으면, 현재 먹고 있는 음식을 다 먹는데 걸리는 시간
		eating_time_pq.pop();//다 먹은 음식은 큐에서 삭제
		sum += (now - prev) * len;// 현재 시간에서 이전에 먹은 음식에 걸린 시간을 빼고, 남은 음식의 개수를 곱해줌. 그리고 이전에 먹었던 음식들을 다 먹는데 걸린 시간을 더하면 현재 먹고있는 음식을 다 먹는데 걸리는 시간
		prev = now;//prev를 현재 now값으로 설정	
		len--;//남은 음식의 개수를 1개 줄임
	}
	
	vector<pair<int, int>> v = transferData(eating_time_pq);//우선순위 큐에서 벡터로 데이터 옮겨와서
	sort(v.begin(), v.end(), cmp);//cmp를 기준(인덱스 순)으로 정렬하고
	return v[(k - sum) % len].second;//다시 먹을 음식을 골라서 인덱스 반환
}

int main() {
	clock_t start, end;//시간 측정을 위한 변수

	int n; //음식의 개수
	vector<pi> eating_time;//음식을 먹는데 필요한 시간
	long long k;//방송 시작 후 몇 초 후에 방송이 중단되었지(2x10^13까지이기 때문에 long long)

	cin >> n;//음식의 개수 입력

	for (int i = 0; i < n; i++) {
		int time;//각 음식을 먹는데 필요한 시간
		cin >> time;//시간 입력
		eating_time.push_back({ time, i+1 });//인덱스와 함께 우선순위 큐에 삽입
 	}
	cin >> k;//먹방을 시작한 후 몇 초(k) 후에 방송이 중단되었는지 k 값 입력
 	start = clock();//시간 측정 시작

	int ans = solution(eating_time, k);//다시 먹을 음식을 골라 ans에 저장
	cout << ans << endl;//몇 번 음식부터 먹어야 하는지 출력
	end = clock();//시간 측정 종료
	double res = (double)(end - start) / CLOCKS_PER_SEC;//프로그램 실행시간 계산
	cout << "실행시간: " << res << "초" << endl;//프로그램 실행시간 출력
	return 0;//프로그램 종료
}