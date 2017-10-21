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
#ifndef _PWAITCONDITION_H_
#define _PWAITCONDITION_H_

#include <punica/pcoredef.h>
#include <punica/pmutex.h>
#include <limits.h>

PUNICA_BEGIN_NAMESPACE

class PWaitCondition
{
public:
    /*explicit */PWaitCondition();
    virtual ~PWaitCondition();

	bool wait(PMutex *mutex, unsigned long time = ULONG_MAX);

	void wake();
	void wakeAll();

private:
	P_DISABLE_COPY(PWaitCondition)

	pthread_cond_t _cond;
};

PUNICA_END_NAMESPACE

#endif /* _PWAITCONDITION_H_ */