#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Boggle
{
public:
	// ������ ����
	vector<string> board;

	Boggle()
	{
		// ������ ����
		board.push_back("URLPM");
		board.push_back("XPRET");
		board.push_back("GIAET");
		board.push_back("XTNZY");
		board.push_back("HOQRS");
	}

	// 5x5 �����ǿ��� �־��� �ܾ �����ϴ��� ��ȯ.
	bool hasWord(int x, int y, const string& word)
	{
		// ������ �Ѿ�� ����.
		if (x < 0 || y < 0 || x >= 5 || y >= 5) return false;
		// �ܾ��� ù��°�� �ȸ����� ����;
		if (board[x][y] != word[0]) return false;
		// �ܾ��� ù��°�� �¾Ҵµ� ���̰� 1�̸� ����.
		if (word.size() == 1) return true;
		// ���� ��ġ �߽����� �ֺ��� �˻��Ѵ�.
		for (int dx = -1; dx <= 1; dx++)
		{
			for (int dy = -1; dy <= 1; dy++)
			{
				if (hasWord(x + dx, y + dy, word.substr(1)))
					return true;
			}
		}
		return false;
	}
};

int main()
{
	Boggle boggle;

	string target = "";
	cout << "ã�� ���ڿ� �Է�" << endl;
	cin >> target;
	bool bFound = false;

	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			if (boggle.hasWord(x, y, target))
			{
				bFound = true;
				break;
			}
		}
		if (bFound) break;
	}
	cout << "ã�� ���ڿ� " << target << " ���� : " << (bFound ? "YES" : "NO") << endl;
	system("pause");
}