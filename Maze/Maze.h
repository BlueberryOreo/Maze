#pragma once
#include "utility.h"
class Maze
{
private:
	int maze[8][8]; // ��ά���飬��ʾ�Թ�
	int* dx; // �����ƶ�
	int* dy; // �����ƶ�
	int visited[8][8]; // ��¼�Ƿ��ѷ��ʹ�
	int posibility; // һ���������ϰ���ĸ���
	bool res; // �Ƿ����ҵ�·��
	bool needPlay; // �Ƿ���Ҫ����ÿһ������
	vector<int> ans; // ���е�·��
	DoubleBuffer* db; // ˫����
public:
	Maze(bool flag=false, DoubleBuffer *db=NULL, int posibility=3);
	~Maze();
	void build(int flag); // �����Թ���flag=0 �ֶ����� flag=1 �Զ�����
	void dfs(int x=0, int y=0); // �����������
	void bfs(); // �����������
	bool getRes(); // ��ȡ�Ƿ��ҵ�·��
	void printAns(); // ��ӡ���ս��
	void printStep(); // ��ӡһ��
};

