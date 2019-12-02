#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

//3�� �� 2���� ��. ����, ������ �����ÿ� ���̰� �� ����� �켱������ ����.
bool compare(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b)
{
	if (a.second.first == b.second.first)
	{
		return a.second.second < b.second.second;
	}
	else
		return a.second.first > b.second.first;
}


int main()
{
	vector<pair<string, pair<int, int>>> v;
	v.push_back(make_pair("���¿�", make_pair(90, 26)));
	v.push_back(make_pair("������", make_pair(90, 27)));
	v.push_back(make_pair("������", make_pair(80, 25)));
	v.push_back(make_pair("������", make_pair(70, 26)));

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); ++i)
	{
		cout << "�̸� : " + v[i].first << "   ���� : " << v[i].second.first << endl;
	}
}