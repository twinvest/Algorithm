#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>


using namespace std;
char arr[11];
bool desc(int a, int b) { return a > b; }
long long solution(long long n) {
	long long answer;
	string change = to_string(n); //�շ��� ��Ʈ������
	vector<char> v1; //char�� �ϳ��� �����ؼ� ���Ľ�ų ����

	for (int i = 0; i < change.length(); ++i)
	{
		v1.push_back(change[i]); //���Ϳ� char �ϳ��� ����
	}
	sort(v1.begin(), v1.end(), desc); //���� ����
	//���͸� �ٽ� ��Ʈ������
	for (int i = 0; i < v1.size(); i++)
	{
		arr[i] = v1.at(i);
	}
	//��Ʈ���� �ٽ� �շ�����
	answer = atoll(arr);
	return answer;
}

int main()
{
	long long num = 118372;
	long long ans = solution(num);
	cout << ans;
}