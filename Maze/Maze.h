#pragma once
#include "utility.h"
class Maze
{
private:
	int maze[8][8];
	int* dx;
	int* dy;
	int visited[8][8];
	bool res;
	bool needPlay;
	vector<int> ans;
	DoubleBuffer* db;
public:
	Maze(bool flag=false, DoubleBuffer *db=NULL);
	~Maze();
	void build(int flag);
	void dfs(int x=0, int y=0);
	void bfs();
	bool getRes();
	void printAns();
	void printStep();
};

