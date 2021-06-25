#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;

bool cmp(int a, int b) {
	return a > b;
}

bool countingLAN(vector<long> v, long long norm) {
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += (v[i] / norm);
	}

	return sum >= K;
}

int main() {
	cin >> N >> K;
	vector<long> v(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), cmp);
	
	// ���� �� ����
	long long high = v[0];
	long long low = 1;
	long long result = 0;

	while (low <= high) {
		long long mid = (low + high) / 2;
		// ���� �ڸ��°� �����ϸ�, ���̸� �ø��� ��ȵ� ����� ���� �ִ�.
		if (countingLAN(v, mid)) {
			// �ڸ��� ���̸� �÷��� result���� ũ�ٸ� ��ü
			if (result < mid)
				result = mid;
			low = mid + 1;
		}
		// �ڸ��°� �Ұ����ϸ�, ���̸� ���δ�.
		else {
			high = mid - 1;
		}
	}
	
	cout << result;

	return 0;

}