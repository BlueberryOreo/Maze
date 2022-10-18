#pragma once
#include <vector>

// 点，记录一个点的坐标和所走的路径
struct Point {
	int x, y;
	vector<int> step;
	Point(int x=0, int y=0) {
		this->x = x;
		this->y = y;
	}
};