#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int, string> a, pair<int, string> b)
{
	return a.first > b.first;
}

int main()
{
	vector<pair<int, string>>  v;
	v.push_back(make_pair(90, "���¿�"));
	v.push_back(make_pair(85, "������"));
	v.push_back(make_pair(50, "������"));
	v.push_back(make_pair(92, "������"));
	v.push_back(make_pair(75, "������"));
	
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i<v.size(); ++i)
	{
		cout <<"���� : " << v[i].first << "   �̸� : " + v[i].second <<endl;
	}
}