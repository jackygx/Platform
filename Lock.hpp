/*
 * Copyright (c) 2018 Guo Xiang
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __LOCK_BASE_HPP__
#define __LOCK_BASE_HPP__

#include <EasyCpp.hpp>

#include <LockImpl.hpp>

namespace Platform {

template <class T>
class CLockBase
{
public:
	virtual ~CLockBase(void)
	{
		/* Does nothing */
	}

	inline void Lock(void)
	{
		((T *)this)->Lock();
	}

	inline void Unlock(void)
	{
		((T *)this)->Unlock();
	}
};

typedef CLockBase<CLockImpl> CLock;
typedef CWeakPtr<CLock> CLockWeakPtr;
typedef CSharedPtr<CLock> CLockPtr;

class CAutoLock
{
public:
	inline CAutoLock(CLock &lock) :
		mLock(lock)
	{
		mLock.Lock();
	}

	inline ~CAutoLock(void)
	{
		Release();
	}

	inline void Release(void)
	{
		mLock.Unlock();
	}

private:
	CLock &mLock;
};

}

using namespace Platform;

#endif /* __LOCK_BASE_HPP__ */

