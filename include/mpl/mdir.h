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
#ifndef _MDIR_H_
#define _MDIR_H_

#include <mpl/mcoredef.h>

MPL_BEGIN_NAMESPACE

class MDir
{
public:
    MDir();
    MDir(const char *s);
    MDir(const std::string &str);
    MDir(const MDir &other);
    virtual ~MDir();

	std::string dir() const { return _dir; }
	bool isDir() const;
	
	MDir &operator=(const MDir &other);
	MDir &operator=(const char *s);
	MDir &operator=(const std::string &str);

	bool operator==(const MDir &d) const
		{ return _dir == d._dir; }
	bool operator!=(const MDir &d) const
		{ return !operator==(d); }

private:
	inline void inner_copy(const MDir &o) {
		_dir = o._dir;
	}
	std::string _dir;
};

std::ostream &operator<<(std::ostream &, const MDir &);
std::istream &operator>>(std::istream &, MDir &);

MPL_END_NAMESPACE

#endif /* _MDIR_H_ */
