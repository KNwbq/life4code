#include <iostream>
#include <windows.h>
#include <ctime>
#include <conio.h>
using namespace std;
#define BUFSIZE 5
 
 
int main()
{
 
	printf("命名管道:客户端上线\n");
	printf("按任意键以开始连接命名管道\n");
	_getch();
	printf("开始等待命名管道\n");
 
	if (WaitNamedPipe(L"\\\\.\\Pipe\\mypipe", NMPWAIT_WAIT_FOREVER) == FALSE)
		return 0;
 
	printf("打开命名管道\n");
	HANDLE hPipe = CreateFile(L"\\\\.\\Pipe\\mypipe", GENERIC_READ | GENERIC_WRITE, 0,
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
 
	if ((long)hPipe == -1)
		return 0;
 
 
	//接收服务端发回的数据
	BOOL fSuccess = false;
	DWORD len = 0;
	char buffer[BUFSIZE];
	string recvData = "";
	do
	{
		fSuccess = ReadFile(hPipe, buffer, BUFSIZE * sizeof(char), &len, NULL);
		char buffer2[BUFSIZE + 1] = { 0 };
		memcpy(buffer2, buffer, len);
		recvData.append(buffer2);
		if (!fSuccess || len < BUFSIZE)
			break;
	} while (true);
 
	cout << "recv data:" << endl << recvData.c_str() << endl << endl;
 
	FlushFileBuffers(hPipe);
	DisconnectNamedPipe(hPipe);
	CloseHandle(hPipe);
 
	system("pause");
	return 0;
}
 