#include <iostream>
#include <windows.h>
using namespace std;

// ˫������
class DoubleBuffer{
private:
    HANDLE l_buffer1; // ������1
    HANDLE l_buffer2; // ������2
    HANDLE l_stdBuffer; // ԭ����̨������
    TCHAR *_data = NULL; // ���������
    int nowActive; // ��ǰ������ʾ״̬�Ļ�����

    void bufferSwitch(); // �л���ǰ��ʾ�Ļ�����

public:
    DoubleBuffer(); // ��ʼ��
    void show(); // ��ʾ
    void inputMode(); // ����ģʽ
    void reset(); // �ر�����ģʽ
    void close(); // �ر�˫����
    void clear(); // ���������
    void setConsoleWindowSize(int width, int height); // ���ÿ���̨��С Deprecated
    void maxScreen(); // Deprecated
};