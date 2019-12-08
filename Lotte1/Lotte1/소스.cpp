#include<iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <utility>
#pragma warning(disable : 4996)
using namespace std;
int N; //����� ����
int Case; // 1�Ǵ� 2�� �Է¹���� ���� ���� Case
vector< pair<long long, string> > p; //pair�� �̿��� ������ ��� ����


int main()
{
	scanf("%d", &N);    //����� ��
	scanf("%d", &Case); // 1 or 2
	vector<int> v(N); //�ڷ��� ������ŭ ���ͻ����� ����

	//���Ϳ��ٰ� ���ڵ� �ʱ�ȭ
	for (int i = 0; i < v.size(); ++i)
	{
		v[i] = i + 1;
	}

	//������ �� ��ȣ�� ���������� ����� ���Ϳ��ٰ� ����
	long long count = 0;
	do {
		string tmp = "";
		for (int i = 0; i < v.size(); ++i)
		{
			tmp += to_string(v[i]);
		}
		p.push_back(make_pair(++count, tmp));
	} while (next_permutation(v.begin(), v.end()));

	
	if (Case == 1)
	{
		//������ ���°���� k�� �Է°����� �޴´�.
		long long k;
		scanf("%u", &k);


		//��ġ�ϴ� ��ȣã�Ƽ� second���
		for (long long i = 0; i < p.size(); ++i)
		{
			if (p[i].first == k)
			{
				//��, ��ġ�ϴ� ��ȣ�� ã���� �����̽��� �߰�
				for (long long j = 0; j < p[i].second.size(); ++j)
				{
					cout << p[i].second[j] <<" ";
				}
				
			}
		}
	}
	else
	{
		vector<int> test2(N); //2��° ������� ���ڵ� �Է�(����� ����)���� �迭
		
		//Case�� 2�϶� ���ڵ� �Է¹��� ����
		for (int i = 0; i < N; ++i)
		{
			cin >> test2[i];
		}

		//string���� ��ȯ
		string tmp = "";
		for (int i = 0; i < v.size(); ++i)
		{
			tmp += to_string(test2[i]);
		}
		//��ġ�ϴ� ����ã�Ƽ� first���
		for (long long i = 0; i < p.size(); ++i)
		{
			if (tmp == p[i].second)
				cout << p[i].first;
		}
	}
}