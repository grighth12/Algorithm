#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	
	cin >> N >> M;
	vector<bool> v(11, false);

	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		v[temp] = true;
	}

	int min_count = abs(N - 100);

	// 0~500000Ž���ϸ鼭 ��ư Ž��
	for (int i = 0; i <= 1000002; i++) {
		// temp �� 0�� ���� while���� ��ġ�� �ʴ´�.. (����)
		int temp = i;
		bool isPossible = true;
		int button_count = 0;
		// ���� -> 0 �϶� while���� ���ߵǴµ�. ����.
		// 10�� �� 1, 0 �ΰ��� Ž���ؾߵǴµ�. �׷��� ����.
		/*
		while (temp != 0) {
			button_count++;
			int na = temp % 10;
			if (v[na]) {
				isPossible = false;
				break;
			}
			temp /= 10;
		}*/

		do {
			button_count++;
			int na = temp % 10;
			if (v[na]) {
				isPossible = false;
				break;
			}
			temp /= 10;
		} while (temp != 0);


		//���� �����ϴٸ� (������ �̵���)
		// ���ڸ� �Է��ؼ� �̵��� ���ڿ� ��ǥ ä�α����� ����(+,-)�� ���Ѵ�.
		if (isPossible) {
			min_count = min(min_count, abs(N - i) + button_count);
		}
		
		
	}
	
	cout << min_count;

	return 0;
}