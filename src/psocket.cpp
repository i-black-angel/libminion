/**
 * Copyright 2017 Shusheng Shao <iblackangel@163.com>
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <punica/psocket.h>

PUNICA_BEGIN_NAMESPACE

PSocket::PSocket(SocketType socketType)
{
	int type = SOCK_STREAM;
	
	_socketType = socketType;
	switch (_socketType) {
	case TcpSocket:
		type = SOCK_STREAM;
		break;
	case UdpSocket:
		type = SOCK_DGRAM;
		break;
	case SctpSocket:
		type = SOCK_SEQPACKET;
	default:
		type = SOCK_RAW;
		break;
	}
	_sockfd = socket(AF_INET, type, 0);
	if (_sockfd < 0) {
		perror("socket error");
	}
}

PSocket::~PSocket()
{
	if (_sockfd != -1)
		::close(_sockfd);
}

bool PSocket::bind(uint16_t port)
{
	PHostAddress address(PHostAddress::Any, port);
	return bind(address);
}

bool PSocket::bind(const PHostAddress &address)
{
	if (_sockfd < 0) return false;
	
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(address.ipv4());
	addr.sin_port = htons(address.port());
	int res = ::bind(_sockfd, (const sockaddr *)&addr, sizeof(addr));
	if (res < 0) {
		perror("bind error");
		return false;
	}
	return true;
}

PTcpSocket::PTcpSocket()
	: PSocket(TcpSocket)
{
}

PTcpSocket::~PTcpSocket()
{
}

PUdpSocket::PUdpSocket()
	: PSocket(UdpSocket)
{
}

PUdpSocket::~PUdpSocket()
{
}

int64_t PUdpSocket::sendto(const uint8_t *data, size_t len)
{
}

int64_t PUdpSocket::sendto(const uint8_t *data, size_t len, const PHostAddress &host)
{
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(host.ipv4());
	addr.sin_port = htons(host.port());

	return ::sendto(_sockfd, data, len, 0, (const sockaddr *)&addr, sizeof(addr));
}

PUNICA_END_NAMESPACE
