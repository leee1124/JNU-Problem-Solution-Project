#include<cstdio>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;

void solve(int data[], int n, int p, int q) {
	int sum = 0, cnt=0;
	for (int i = 0; i < n; i++) {
		if (data[i] <= p) {//동아리 회원이 제한체중 이하라면
			cnt++;//제한체중이 넘지 않는 인원의 수를 더하고
			sum += data[i];//그들의 몸무게 합을 구함
		}
	}
	printf("%d %d\n", cnt, sum);//제한 체중을 넘지 않는 인원의 숫자와 몸무게 총 합 출력하고 개행
	if (sum < q)//몸무게의 총 합이 최대하중을 넘지 않으면 YES 출력
		printf("YES\n");
	else//그렇지 않으면 NO 출력
		printf("NO\n");
}

int main() {
	int n, p, q;//n=회원의 수, p=제한 체중, q=최대 하중
	int* data;

	scanf("%d %d %d", &n, &p, &q);
	data = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}

	solve(data, n, p, q);//void 함수이기 때문에 반환 값이 없고 함수 내에서 출력

	delete[] data;
	return 0;
}