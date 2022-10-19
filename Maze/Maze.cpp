#include "Maze.h"
#include "Point.h"

Maze::Maze(bool flag, DoubleBuffer *db, int posibility)
{
	memset(maze, 0, sizeof(maze));
	memset(visited, 0, sizeof(visited));
	dx = new int[8]{ 1, -1, 0, 0, -1, -1, 1, 1 };
	dy = new int[8]{ 0, 0, 1, -1, 1, -1, 1, -1 };
	res = false;
	needPlay = flag;
	this->db = db;
	this->posibility = posibility;
}

Maze::~Maze()
{
	delete[] dx;
	delete[] dy;
}

void Maze::build(int flag)
{
	if (flag) {
		// 自动初始化
		for (int i = 0; i < 8; i ++) {
			for (int j = 0; j < 8; j ++) {
				int rnd = rand() % 10;
				if (rnd <= posibility) maze[i][j] = 1;
				else maze[i][j] = 0;
			}
		}
		maze[0][0] = 0;
		maze[7][7] = 0;
	}
	else {
		// 手动初始化
		cout << "请输入8行8列的0-1矩阵：" << endl;
		for (int i = 0; i < 8; i ++) {
			for (int j = 0; j < 8; j ++) {
				cin >> maze[i][j];
			}
		}
	}
}

void Maze::dfs(int x, int y)
{
	//cout << x << " " << y << endl;
	if (x == 0 && y == 0) visited[0][0] = 1;
	if (x == 7 && y == 7) {
		// 找到了合适的路径
		printStep();
		res = true;
		return;
	}

	for (int i = 0; i < 8; i++) {
		int nextx = x + dx[i];
		int nexty = y + dy[i];
		// 下一步走哪里
		if (nextx >= 8 || nextx < 0 || nexty >= 8 || nexty < 0) continue; // 越界
		if (maze[nextx][nexty] == 1) continue; // 撞墙
		if (visited[nextx][nexty]) continue; // 访问过
		visited[nextx][nexty] = 1;
		ans.push_back(i); // 记录路径

		if (needPlay) {
			printStep();
			Sleep(30);
			db->show();
		}

		dfs(nextx, nexty);
		if (res) return;
		// 回溯
		visited[nextx][nexty] = 0;
		ans.pop_back();
	}
}

void Maze::bfs() {
	Point p(0, 0);
	queue<Point> q;
	q.push(p);
	int cnt = 0;
	while (!q.empty()) {
		Point now = q.front();
		q.pop();
		if (visited[now.x][now.y]) continue; // 访问过了就跳过
		visited[now.x][now.y] = 1;
		//cout << now.x << " " << now.y << endl;
		if (now.x == 7 && now.y == 7) {
			// 找到了合适的路径
			printStep();
			ans = now.step;
			res = true;
			return;
		}
		for (int i = 0; i < 8; i ++) {
			int nextx = now.x + dx[i];
			int nexty = now.y + dy[i];
			// 下一步走哪里
			if (nextx >= 8 || nextx < 0 || nexty >= 8 || nexty < 0) continue;
			if (maze[nextx][nexty] == 1) continue;
			if (visited[nextx][nexty]) continue; // 访问过了就跳过
			// 找到下一个点，并记录路径
			Point next = now;
			next.x = nextx;
			next.y = nexty;
			next.step.push_back(i);
			q.push(next);
		}
		cnt++;
		//cout << cnt << endl;
		if (needPlay) {
			printStep();
			Sleep(33);
			db->show();
		}
		
	}
	// 未找到
}

bool Maze::getRes()
{
	return res;
}

void Maze::printAns()
{
	//for (int i = 0; i < ans.size(); i ++) {
	//	cout << s[ans[i]] << " ";
	//}
	//cout << endl;
	Point now(0, 0);
	visited[0][0] = 2;
	for (int k = 0; k < ans.size(); k ++) {
		now.x += dx[ans[k]];
		now.y += dy[ans[k]];
		system("cls");
		for (int i = 0; i < 8; i ++) {
			for (int j = 0; j < 8; j ++) {
				if (maze[i][j]) {
					cout << "×";
					continue;
				}
				if (i == now.x && j == now.y) visited[i][j] = 2;
				if (visited[i][j] == 1) {
					cout << "■";
				}
				else if(visited[i][j] == 0) {
					cout << "□";
				}
				else {
					cout << "★";
				}
			}
			cout << endl;
		}
		Sleep(200);
	}
	cout << endl;
}

void Maze::printStep()
{
	//system("cls");
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (maze[i][j]) cout << "×";
			else cout << (visited[i][j] ? "■" : "□");
		}
		cout << endl;
	}
}
