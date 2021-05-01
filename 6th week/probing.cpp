#include<cstdio>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

class TicketTable {
public:
	vector<bool>used;//사용 했는지 안했는지 상태를 저장할 배열
	int length;//행운권 개수
	TicketTable(int length)//매개변수 있는 생성자
	{
		this->length = length;//행운권 크기는 매개변수
		this->used.assign(length, false);//사용 상태는 아직 사용 안함
	}
	int findEmptyIndexByUserId(int userId)//사용자의 회원 번호로 지급받게 될 행운권 번호를 계산하는 함수
	{
		int index = userId % length; //맨 처음 시도 할 번호
		while (this->isEmpty(index) == true) //이미 사용된거면 패스
			index = (index + 1) % length; //다음 번호 체크
		return index;
	}
	bool isEmpty(int ticketIndex)//행운권 번호가 이미 사용중인지 확인하는 함수
	{
		return this->used[ticketIndex]; //사용중이면 true, 아니면 false 반환
	}
	void setUsed(int index, bool status)//티켓 사용 영부를 갱신하기 위한 함수
	{
		this->used[index] = status;//상태를 입력
	}
};
vector<int>getTicketNumbers(int n, int m, const vector<int>& ids)//행운권 번호를 계산하는 함수
{
	vector<int> tickets;//행운권 번호를 저장할 배열
	TicketTable table = TicketTable(n);//행운권의 개수는 n개
	for (int i = 0; i < m; i++)
	{
		int userId = ids[i];//userId는 회원번호
		int ticketIndex = table.findEmptyIndexByUserId(userId);//회원번호로 지급받게 될 행운권 번호를 계산해서 ticketIndex에 저장
		tickets.push_back(ticketIndex); //ticktets 배열에 tikcetIndex 배열 추가 
		table.setUsed(ticketIndex, true);//티켓 사용 여부 갱신
	}
	return tickets;//tickets 배열 반환
}
int main()
{
	int n, m;//전체 티켓의수, 요청 고객의 수
	scanf("%d %d", &n, &m);//전체 티켓의 수와 요청 고객의 수 입력
	vector<int> ids(m);//회원번호를 저장할 배열, m개의 원소를 0으로 초기화
	for (int i = 0; i < m; ++i)//m번 반복
		scanf("%d", &ids[i]);//회원번호 입력
	vector<int> tickets = getTicketNumbers(n, m, ids);//행운권 번호를 계산해서 배열에 저장
	for (int i = 0; i < tickets.size(); ++i)//행운권 개수만큼 반복
		printf("%d\n", tickets[i]); //행운권 번호 출력
}