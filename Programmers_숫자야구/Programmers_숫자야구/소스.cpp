#include <string>
#include <vector>

using namespace std;
vector<vector<int>> v;

int solution(vector<vector<int>> baseball) {
	int answer = 0;

	// ���� ���� ���� : 123 / ���� ū ���� : 987 ���� ���ϸ鼭 ��Ʈ����ũ ���� �´� ���� ã�ư���. 
	//�� �񱳴� string���� �ٲ㼭 �ص� �ɵ� (�� �׷��� 10 ������ mod ���� �ؾ��ϴϱ� )

	for (int i = 123; i <= 987; i++) {
		string tmp = to_string(i);
		bool flag = true;

		if (tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[0] == tmp[2]) continue;// ���� �ߺ� ����� 
		if (tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0') continue; //���� 0 ����� 

		for (int j = 0; j < baseball.size(); j++) {
			int strike = 0, ball = 0;
			for (int a = 0; a < 3; a++) {
				for (int b = 0; b < 3; b++) {
					string num = to_string(baseball[j][0]); //�Ź� ���� ������ 
					if (a == b && tmp[a] == num[b]) {
						//��Ʈ���
						strike++;
						continue;
					}
					else if (tmp[a] == num[b]) {
						ball++;
						continue;
					}
				}
			}//for a

			//�� ���ڸ� �� ���캽 
			if (strike != baseball[j][1] || ball != baseball[j][2]) {
				//i�� �˸��� ���ڰ� �ƴ� 
				flag = false;
				break;
			}
		}//for j(baseball)
		if (flag) answer++;
	}
	return answer;
}
int main()
{
	vector<int> v1;
	v1.push_back(123);
	v1.push_back(1);
	v1.push_back(1);

	vector<int> v2;
	v2.push_back(356);
	v2.push_back(1);
	v2.push_back(0);

	vector<int> v3;
	v3.push_back(489);
	v3.push_back(0);
	v3.push_back(1);

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	int ans = solution(v);
	printf("%d", ans);
}