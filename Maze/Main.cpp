#include "utility.h"
#include "Maze.h"

void instructor(int &flag0, int &flag1, int &flag2) {
	cout << "欢迎来到走迷宫\n"
		<< "不是让你走迷宫，而是让你看着程序走迷宫\n"
		<< "迷宫的大小为8x8\n"
		<< "这里提供两种走迷宫的算法：DFS（深度优先搜索）和BFS（广度优先搜索）\n"
		<< "（大佬卷王还会写一种算法叫A*，但是我不会）\n"
		<< "你可以选择其中一个算法，来看看它们谁显得更聪明" << endl;
	cout << "请选择你的算法：\n"
		<< "1. DFS\n"
		<< "2. BFS" << endl;
	cin >> flag0;
	cout << "是否需要自动初始化这个8x8的迷宫？（Y/N）";
	char res;
	cin >> res;
	if (res == 'Y' || res - 32 == 'Y') flag2 = 1;
	else flag2 = 0;
	cout << "是否要观看程序走迷宫的过程？（Y/N）";
	cin >> res;
	if (res == 'Y' || res - 32 == 'Y') flag1 = 1;
	else flag1 = 0;
	return;
}

int main() {

	srand((unsigned)time(NULL));
	
	int flag0, flag1, flag2; // 1 - 是否自动播放 2 - 是否随机初始化
    instructor(flag0, flag1, flag2);
	
	DoubleBuffer* db = NULL;
	if (flag1) db = new DoubleBuffer();
	Maze m(flag1, db);
	m.build(flag2);
	if(db) db->inputMode();
	m.printStep();
	system("pause");
	system("cls");
	if(db) db->reset();

	if (flag0 == 1) {
		m.dfs();
	}
	else if(flag0 == 2) {
		m.bfs();
	}
	if (db) {
		db->close();
		delete db;
	}
	bool res = m.getRes();
	if (res) {
		m.printAns();
	}
	else {
		cout << "未找到合适的路径" << endl;
	}

	return 0;
}