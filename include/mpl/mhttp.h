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
#ifndef _MHTTP_H_
#define _MHTTP_H_

#include <mpl/mcoredef.h>
#include <mpl/mthread.h>

struct mg_mgr;
struct mg_connection;
struct http_message;

MPL_BEGIN_NAMESPACE

class MHttp
{
public:
    explicit MHttp();
    virtual ~MHttp();
protected:
	struct mg_mgr *_mgr;
	struct mg_connection *_nc;
};

class MHttpServer : public MHttp
{
public:
    explicit MHttpServer(int msec = 500); // default is 500 milliseconds
    virtual ~MHttpServer();
	bool bind(const std::string &port);
	void start();
	void stop();

	int sleeptime() const { return _msec; }
	void setSleeptime(int msec) { _msec = msec; }
	void interrupt() { MScopedLock locker(_mutex); _interrupt = true; }
	bool isInterrupted() const { return _interrupt; }

	// over-load function
	virtual void handler(struct mg_connection *nc, struct http_message *msg);
private:
	MMutex _mutex;
	bool _interrupt;
	int _msec;
};

class MHttpClient : public MHttp
{
public:
    explicit MHttpClient();
    virtual ~MHttpClient();
};

MPL_END_NAMESPACE

#endif /* _MHTTP_H_ */
