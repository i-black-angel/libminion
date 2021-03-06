#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <locale>
#include <cerrno>
#include <mpl.h>
#include <sys/epoll.h>

using namespace std;

class MouseServer : public mpl::MTcpServer
{
public:
    explicit MouseServer() { }
    virtual ~MouseServer() { }
protected:
	virtual void connection(int clientfd, const mpl::MHostAddress &addr) {
	}
	virtual void process(int clientfd, const uint8_t *data, size_t len) {
		char buf[1024] = {0x00};
		memcpy(buf, data, len);
		printf("clientfd:%d -- %s", clientfd, buf);
	}
};

int main(int argc, char *argv[])
{
	MouseServer server;
	server.bind(12700);
	server.start();
	
	MouseServer ftpserver;
	ftpserver.bind(12780);
	ftpserver.start();

	while (true) {
		sleep(1);
	}
    return 0;
}
