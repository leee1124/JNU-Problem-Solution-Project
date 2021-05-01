#include<cstdio>
#include<vector>
#include<algorithm>
#include<ctime>
#pragma warning(disable: 4996)
using namespace std;

int solve(int** arr, int x, int y) {//두번째로 큰 수를 반환하는 함수
	vector<int> v;//2x2 행렬을 담을 배열
	for (int i = x; i < x + 2; i++) {
		for (int j = y; j < y + 2; j++) {
			v.push_back(arr[i][j]);//2x2 행렬을 v에 담음
		}
	}
	sort(v.begin(), v.end(), greater<int>());//내림차순 정렬
	return v[1];//두번째로 큰 수를 반환
}

int main() {
	time_t start, end;//시간 측정을 위한 변수
	int n;//2의 거듭제곱 꼴인 수 n
	int** arr;//n x n 행렬 arr

	scanf("%d", &n);

	arr = new int* [n];//2차원 배열
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];//동적할당
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);//n x n 행렬 입력
		}
	}
	start = clock();// 프로그램 실행시간 측정 시작

	while (n != 1) {//n이 1이 아닌경우(1 x 1 행렬이 아닌 경우)
		for (int i = 0; i < n; i += 2) {
			for (int j = 0; j < n; j += 2) {
				arr[i / 2][j / 2] = solve(arr, i, j);//가로, 세로 2칸씩 움직이며 arr 갱신
			}
		}
		n /= 2;// n을 2로 나눔
	}

	printf("%d\n", arr[0][0]);//남은 하나 

	for (int i = 0; i < n; i++)
		delete[] arr[i];//n x n 2차원 배열
	delete[] arr;//동적할당 해제

	end = clock();//측정 종료
	double res = (double)(end -start) / CLOCKS_PER_SEC;//측정시간을 초단위로 변환
	printf("실행시간: %f초\n", res);//측정시간 출력
	return 0;//프로그램 종료
}