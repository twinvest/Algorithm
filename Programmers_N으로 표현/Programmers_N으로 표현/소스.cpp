#include <string>
#include <vector>

using namespace std;
static int answer = -1;

int increment(int value, int N)
{
	return value * 10 + N;
}

//cnt�� ���̸� �ǹ�. ���̴� ���ڰ� ���� ������ �ǹ�.
void dfs(int N, int number, int cnt, int prev)
{
	int temp_N = N;
	//���� ���ǿ� ���� 8�� �̻� ���̰� ���µ�(5�� ����ߴµ�) ã�Ƴ��� ���Ѵٸ� -1�� ����
	if (cnt > 8)
	{
		answer = -1;
		return;
	}
	//prev�� number�� ���ٴ� ���� dfs�� �����ϸ鼭 ��Ģ������ �����ϴ� ��� ���� prev�� number�� �������� ��츦 ã�Ҵ� ����.
	if (number == prev)
	{
		//�׶� answer == -1 ������ ó������ answer�� �ʱ�ȭ �Ǵ� �����̰�, answer>cnt ������ �����ϸ� ������ answer���� �� ª�� N�� ����ؼ� ���ϴ� number�� ��������.
		if (answer == -1 || answer > cnt)
			answer = cnt;
		return;
	}
	//�� �κ��� �� ������ �ٽ��ڵ���. for������ ��ü���� ����(cnt)�� �����ϰ� �ְ� ���ڷ� cnt + i + 1�� �ѱ�°� �λ���.
	for (int i = 0; i < 8 - cnt; i++)
	{
		dfs(N, number, cnt + i + 1, prev - temp_N);
		dfs(N, number, cnt + i + 1, prev + temp_N);
		dfs(N, number, cnt + i + 1, prev * temp_N);
		dfs(N, number, cnt + i + 1, prev / temp_N);
		
		//��� dfs�� ����ͼ� �ٽ� �� �ڸ�. 5�� 55�� 2�� 22�� temp_N�� �ʱ�ȭ. 
		//�� �ڵ尡 ����� �� for���� i�� 0���� 1�� �����Ǹ鼭 cnt�� �� ���̸� �ϳ� �ø�ȿ���� �� �� ����.
		temp_N = increment(temp_N, N); 
	}
}

int solution(int N, int number) {
	dfs(N, number, 0, 0);
	return answer;
}

int main()
{
	int N = 5;
	int number = 12;
	int ans = solution(N, number);
	printf("%d", ans);
}