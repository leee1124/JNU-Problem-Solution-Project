#include<cstdio>
#pragma warning(disable:4996)
using namespace std;

const int MAX_ROW = 9;//행은 9행
const int MAX_COL = 9;//열도 9열

class SudokuBoard {
public:
	//칸의 번호로 행의 번호를 계산하는 메소드
	int getRowByIndex(int index)
	{
		//칸의 번호에 대해 마디를 가지고 증가하므로 몫으로 계산할 수 있다.
		return(index - 1) / 9 + 1;//배열은 0부터 시작하므로 1빼서 몫을 구하고, 인덱스는 1부터 시작하므로 1 더한 후 반환
	}
	
	//칸의 번호로 열의 번호를 계산하는 메소드
	int getColByIndex(int index)
	{	//칸의 번호에 대해 규칙적으로 순환하므로 나머지로 계산할 수 있다.
		return(index - 1) % 9 + 1;//배열은 0부터 시작하므로 1빼서 나머지을 구하고, 인덱스는 1부터 시작하므로 1 더한 후 반환
	}
	
	//칸의 번호로 그룹 번호를 계산하는 메소드
	int getGroupByIndex(int index)
	{
		int r = getRowByIndex(index);//행의 값을 얻어와 변수 r에 저장
		int c = getColByIndex(index);//열의 값을 얻어와 변수 c에 저장
		return getGroupByPosition(r, c);//그룹 번호를 얻어오는 함수를 호출에 해당 함수가 반환하는 값을 반환
	}
	
	//칸의 위치(행, 열)로 그룹 번호를 계산하는 메소드
	int getGroupByPosition(int row, int column)
	{	//행의 번호를 통해, 해당 행에 존재하는 그룹들 중 가장 왼쪽 그룹의 번호를 알 수 있다.
		int left = ((row - 1) / 3) * 3 + 1;//ex) 1,2,3번 행은 1번 그룹, 4,5,6번 행은 4번 그룹, 7,8,9번 행은 7번그룹
		//열의 번호를 통해, 해당 행에 존재하는 그룹들 중 몇 번째 그룹에 속하는지 알 수 있다.
		int offset = ((column - 1) / 3);//ex)1,2,3번 열은 0(1번째), 4,5,6번 열은 1(2번째), 7,8,9번 열은 2(3번째)
		return left + offset;//해당 그룹의 가장 왼쪽 그룹 번호와 오프셋을 더해 그룹 번호를 계산함
	}
	
	//칸의 위치로 그룹 번호 계산
	int getIndexByPosition(int row, int column)
	{	//행과 열의 번호를 알면 반대로 인덱스도 쉽게 계산할 수 있다.
		return (row - 1) * 9 + (column - 1) % 9 + 1;
	}
};
void process(int caseIndex)
{
	int index;//지수가 말한 칸의 번호
	scanf("%d",&index);//index 변수 입력

	SudokuBoard board = SudokuBoard();
	//칸의 번호로 행, 열, 그룹 번호를 계산한다.
	int row = board.getRowByIndex(index);//칸의 번호로 행의 번호를 계산
	int col = board.getColByIndex(index);//칸의 번호로 열의 번호를 계산
	int group = board.getGroupByIndex(index);//칸의 번호로 그룹 번호를 계산
	
	printf("Case #%d:\n", caseIndex);//Case # 테스트케이스 번호: 출력
	printf("%d %d %d\n", row, col, group);//row, col, group값을 출력
}

int main()
{
	int caseSize;//테스트케이스의 개수를 입력받는 변수
	scanf("%d", &caseSize);//테스트 케이스 개수 입력

	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex)//테스트 케이스 개수만큼 반복
		process(caseIndex);
}