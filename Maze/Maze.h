#pragma once
#include "utility.h"
class Maze
{
private:
	int maze[8][8]; // 二维数组，表示迷宫
	int* dx; // 上下移动
	int* dy; // 左右移动
	int visited[8][8]; // 记录是否已访问过
	int posibility; // 一行中生成障碍物的概率
	bool res; // 是否有找到路径
	bool needPlay; // 是否需要播放每一步过程
	vector<int> ans; // 可行的路径
	DoubleBuffer* db; // 双缓冲
public:
	Maze(bool flag=false, DoubleBuffer *db=NULL, int posibility=3);
	~Maze();
	void build(int flag); // 创建迷宫，flag=0 手动输入 flag=1 自动生成
	void dfs(int x=0, int y=0); // 深度优先搜索
	void bfs(); // 广度优先搜索
	bool getRes(); // 获取是否找到路径
	void printAns(); // 打印最终结果
	void printStep(); // 打印一步
};

