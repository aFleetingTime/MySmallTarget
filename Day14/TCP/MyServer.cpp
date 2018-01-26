#include <iostream>
#include <winsock2.h>
#include <exception>
#include <string>

#pragma comment(lib, "ws2_32.lib")
using namespace std;

class MySocket
{
public:
	MySocket(WORD request, int port)
	{
		mRequestVersion = request;
		errNum = WSAStartup(mRequestVersion, &mData);
		if (errNum)
			throw exception("Socket����ʧ��...");
		mSocket = socket(AF_INET, SOCK_STREAM, 0);
		addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		bind(mSocket, reinterpret_cast<const sockaddr*>(&addr), sizeof(SOCKADDR));
		listen(mSocket, 5);
	}
	void socketInit()
	{
		srSocket = accept(mSocket, reinterpret_cast<sockaddr*>(&mClient), &mClientLen);
		cout << "�յ���������" << endl;
	}
	string socketRecv() const
	{
		char recvBuf[1024]{};
		recv(srSocket, recvBuf, sizeof(recvBuf) / sizeof(*recvBuf), 0);
		cout << "�յ�����!" << endl;
		return string(recvBuf);
	}
	void socketSend(string sendStr)
	{
		if (sendStr.length() == 0)
		{
			cout << "��������Ϊ��" << endl;
			return;
		}
		send(srSocket, sendStr.c_str(), sendStr.length() + 1, 0);
		cout << "�����ѷ���!" << endl;
	}


private:
	WORD mRequestVersion;
	WSADATA mData;
	SOCKET mSocket;
	SOCKET srSocket;
	SOCKADDR_IN addr;
	SOCKADDR_IN mClient;
	int mClientLen;
	int errNum;
};

int main()
{
	try
	{
		MySocket socket(MAKEWORD(1, 1), 6666);
		string data;

		while (true)
		{
			socket.socketInit();
			cout << "��������:" << endl;
			cin >> data;
			if (!data.compare("over"))
				break;
			socket.socketSend(data);
			string ret = socket.socketRecv();
			cout << ret << endl;
		}
		WSACleanup();
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
	

	system("pause");
	return 0;
}