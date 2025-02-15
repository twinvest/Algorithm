#include <string>
#include <vector>
#include <algorithm>
#include <functional>
/*
문제접근
맨처음 가장 큰 수를 내림차순을 이용해서 만들어내고
2부터 가장 큰 수 310까지 해당수가 소수인지 판별 + 주어진 종이로 만들 수 있는지 확인
주어진 종이를 사용했는지 안했는지는 visit배열을 이용해 판별한다.
*/

using namespace std;
bool checkNumber(int i, string numbers);

int solution(string numbers) {
	int answer = 0;
	sort(numbers.begin(), numbers.end(), greater<int>());
	vector<bool> temp(stoi(numbers) + 1);
	for (int i = 2; i <= stoi(numbers); i++) 
	{
		if (temp[i] == false && checkNumber(i, numbers)) 
		{
			answer++;
		}
		if (temp[i] == false) //에라토스테네스의 체
		{
			for (int j = i; j <= stoi(numbers); j += i) 
			{
				temp[j] = true;
			}
		}
	}
	return answer;
}

bool checkNumber(int i, string numbers) 
{
	bool flag = false;
	vector<bool> visit(numbers.length());
	while (i != 0)
	{
		flag = false;
		int temp = i % 10;
		for (int j = 0; j <= numbers.length(); j++) 
		{
			if (temp == numbers[j] - '0' && visit[j] == 0) 
			{
				flag = true;
				visit[j] = 1;
				break;
			}
		}
		if (flag == false)
			return false;
		i /= 10;
	}
	return true;
}

int main()
{
	string a = "17";
	int ans = solution(a);
	printf("%d", ans);
}