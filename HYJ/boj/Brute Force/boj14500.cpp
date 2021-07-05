#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> m;

class Point {

public:
	int x;
	int y;

	Point() {

	}

	Point(int y, int x) {
		this->x = x;
		this->y = y;
	}

	bool isPossible(int i, int j) {
		//cout << "i : " << i << " y : " << y << " j : " << j << " x : " << x << "\n";
		if ((i + y) >= 0 && (i + y) < N && (j + x) >= 0 && (j + x) < M) {
			return true;
		}
		else return false;
	}

};

class Tetromino {
	vector<Point> points;

public:
	Tetromino(vector<Point> ps) {
		this->points = ps;

	}

	bool isPossible(int y, int x) {
		bool flag = true;
		for (int i = 0; i < points.size(); i++) {
			if (!points[i].isPossible(y,x)) {
				flag = false;
				break;
			}
		}

		return flag;
	}

	// ������ x, y���� ���� ����
	int sum(int y, int x) {
		int sum = 0;
		for (int i = 0; i < points.size(); i++) {
			int pos_y = y + points[i].y;
			int pos_x = x + points[i].x;


			sum += m[pos_y][pos_x];
		}
		return sum;
	}
};

int main() {
	cin >> N >> M;
	m = vector<vector<int>>(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> m[i][j];
		}
	}

	vector<Tetromino> tetrominos;
	
	//Point(y, x)
	// ���� �۴��
	vector<Point> points = { Point(0,0), Point(0, 1), Point(0,2), Point(0,3) };
	Tetromino t = Tetromino(points);
	tetrominos.push_back(t);

	// ���� �۴��
	points = { Point(0,0), Point(1, 0), Point(2,0), Point(3,0) };
	t = Tetromino(points);
	tetrominos.push_back(t);

	// �׸�
	points = { Point(0,0), Point(1, 0), Point(0,1), Point(1,1) };
	t = Tetromino(points);
	tetrominos.push_back(t);


	// �� ��� 
	points = { Point(0,0), Point(0, -1), Point(0,1), Point(-1,0) };
	t = Tetromino(points);
	tetrominos.push_back(t);

	// �� ��� 
	points = { Point(0,0), Point(0, -1), Point(0,1), Point(1,0) };
	t = Tetromino(points);
	tetrominos.push_back(t);


	// �� ��� 
	points = { Point(0,0), Point(-1, 0), Point(1,0), Point(0,-1) };
	t = Tetromino(points);
	tetrominos.push_back(t);


	// �� ��� 
	points = { Point(0,0), Point(-1, 0), Point(1,0), Point(0,1) };
	t = Tetromino(points);
	tetrominos.push_back(t);


	// �� ��� 
	points = { Point(0,0), Point(1, 0), Point(1,1), Point(1,2) };
	t = Tetromino(points);
	tetrominos.push_back(t);

	// �� ��� �¿� ��Ī
	points = { Point(0,0), Point(1, 0), Point(1,-1), Point(1,-2) };
	t = Tetromino(points);
	tetrominos.push_back(t);


	// �� ��� ���� ��Ī
	points = { Point(0,0), Point(1, 0), Point(0,1), Point(0,2) };
	t = Tetromino(points);
	tetrominos.push_back(t);


	// �� ���
	points = { Point(0,0), Point(1, 0), Point(0,-1), Point(0,-2) };
	t = Tetromino(points);
	tetrominos.push_back(t);

	// �� ���簢��
	points = { Point(0,0), Point(1, 0), Point(2,0), Point(0,1) };
	t = Tetromino(points);
	tetrominos.push_back(t);

	points = { Point(0,0), Point(0, 1), Point(1,1), Point(2,1) };
	t = Tetromino(points);
	tetrominos.push_back(t);


	points = { Point(0,0), Point(1,0), Point(2,0), Point(2,1) };
	t = Tetromino(points);
	tetrominos.push_back(t);


	points = { Point(0,0), Point(1,0), Point(2,0), Point(2,-1) };
	t = Tetromino(points);
	tetrominos.push_back(t);

	// ��������
	points = { Point(0,0), Point(1,0), Point(1,1), Point(2,1) };
	t = Tetromino(points);
	tetrominos.push_back(t);


	points = { Point(0,0), Point(1,0), Point(1,-1), Point(2,-1) };
	t = Tetromino(points);
	tetrominos.push_back(t);


	points = { Point(0,0), Point(0,1), Point(1,0), Point(1,-1) };
	t = Tetromino(points);
	tetrominos.push_back(t);


	points = { Point(0,0), Point(0,1), Point(1,1), Point(1,2) };
	t = Tetromino(points);
	tetrominos.push_back(t);

	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < tetrominos.size(); k++) {
				if (tetrominos[k].isPossible(i, j)) {
					result = max(result, tetrominos[k].sum(i, j));
				}
				
			}
		}
	}

	cout << result << "\n";

	return 0;
}