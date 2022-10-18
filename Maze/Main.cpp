#include "utility.h"
#include "Maze.h"

void instructor(int &flag0, int &flag1, int &flag2) {
	cout << "��ӭ�������Թ�\n"
		<< "�����������Թ����������㿴�ų������Թ�\n"
		<< "�Թ��Ĵ�СΪ8x8\n"
		<< "�����ṩ�������Թ����㷨��DFS�����������������BFS���������������\n"
		<< "�����о�������дһ���㷨��A*�������Ҳ��ᣩ\n"
		<< "�����ѡ������һ���㷨������������˭�Եø�����" << endl;
	cout << "��ѡ������㷨��\n"
		<< "1. DFS\n"
		<< "2. BFS" << endl;
	cin >> flag0;
	cout << "�Ƿ���Ҫ�Զ���ʼ�����8x8���Թ�����Y/N��";
	char res;
	cin >> res;
	if (res == 'Y' || res - 32 == 'Y') flag2 = 1;
	else flag2 = 0;
	cout << "�Ƿ�Ҫ�ۿ��������Թ��Ĺ��̣���Y/N��";
	cin >> res;
	if (res == 'Y' || res - 32 == 'Y') flag1 = 1;
	else flag1 = 0;
	return;
}

int main() {

	srand((unsigned)time(NULL));
	
	int flag0, flag1, flag2; // 1 - �Ƿ��Զ����� 2 - �Ƿ������ʼ��
    instructor(flag0, flag1, flag2);
	
	DoubleBuffer* db = NULL;
	if (flag1) db = new DoubleBuffer();
	Maze m(flag1, db);
	m.build(flag2);
	db->inputMode();
	m.printStep();
	system("pause");
	system("cls");
	db->reset();

	if (flag0 == 1) {
		m.dfs();
	}
	else if(flag0 == 2) {
		m.bfs();
	}
	db->close();
	bool res = m.getRes();
	if (res) {
		m.printAns();
	}
	else {
		cout << "δ�ҵ����ʵ�·��" << endl;
	}

	delete db;

	return 0;
}