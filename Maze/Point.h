#pragma once
#include <vector>

// �㣬��¼һ�������������ߵ�·��
struct Point {
	int x, y;
	vector<int> step;
	Point(int x=0, int y=0) {
		this->x = x;
		this->y = y;
	}
};