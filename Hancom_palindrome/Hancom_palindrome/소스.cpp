#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int flag = 0;

bool is_palindrome(string s) {

	if (s.size() == 1) return false;
	string s_reverse = s;
	reverse(s_reverse.begin(), s_reverse.end());
	return s == s_reverse ? true : false;

}

void dq(string s)
{
	//�� �̻� ���� �� ���� �������
	if (s.size() == 1) return; 
	
	int mid = s.size() / 2;
	int check = s.size() % 2;

	//��� �и���� Ȯ��
	int i = 1;
	while (1)
	{
		if (!check)//���ڿ� ���̰� ¦��
		{
			if (is_palindrome(s.substr(mid - i, 2 * i)))
			{
				++flag;
			}
			++i;
		}
		else//���ڿ� ���̰� Ȧ��
		{
			if (is_palindrome(s.substr(mid - i, 2*i+1)))
			{
				++flag;
			}
			++i;
		}
		if (mid - i + 1 == 0) break;
	}

	if (!check)
	{
		dq(s.substr(0, mid));//���� �и���� Ȯ��
		dq(s.substr(mid, mid));//������ �и���� Ȯ��
	}
	else
	{
		dq(s.substr(0, mid+1));//���� �и���� Ȯ��
		dq(s.substr(mid, mid+1));//������ �и���� Ȯ��
	}
	

}


int main() {

	string s = "abaabax";
	dq(s);

	printf("%d", flag);
	return 0;

}