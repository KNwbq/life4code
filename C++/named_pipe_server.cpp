#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;
 
int main()
{
	printf("创建命名管道并等待连接\n");
 
	HANDLE hPipe = CreateNamedPipe(L"\\\\.\\Pipe\\mypipe", PIPE_ACCESS_DUPLEX, PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT
		, PIPE_UNLIMITED_INSTANCES, 0, 0, NMPWAIT_WAIT_FOREVER, 0);
 
 
	//waiting to be connected
	if (ConnectNamedPipe(hPipe, NULL) != NULL)
	{
		printf("连接成功，开始发送数据\n");
 
		DWORD  dwWrite;
		const char *pStr = "data from server";
		if (!WriteFile(hPipe, pStr, strlen(pStr), &dwWrite, NULL))
		{
			cout << "write failed..." << endl << endl;
			return 0;
		}
		cout << "sent data: " << endl << pStr << endl << endl;
	}
 
	DisconnectNamedPipe(hPipe);
	CloseHandle(hPipe);//关闭管道
	printf("关闭管道\n");
	system("pause");
}
 