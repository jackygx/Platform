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

#ifndef __EVENT_BASE_HPP__
#define __EVENT_BASE_HPP__

#include <EasyCpp.hpp>

#include <EventImpl.hpp>

namespace Platform {

template <class T>
class CEventBase
{
public:
	virtual ~CEventBase(void)
	{
		/* Does nothing */
	}

	inline void Wait(void)
	{
		((T *)this)->Wait();
	}

	inline bool WaitTimeout(int msec)
	{
		return ((T *)this)->WaitTimeout(msec);
	}

	inline void Wakeup(void)
	{
		((T *)this)->Wakeup();
	}
};

typedef CEventBase<CEventImpl> CEvent;
typedef CSharedPtr<CEvent> CEventPtr;
typedef CWeakPtr<CEvent> CEventWeakPtr;

}

using namespace Platform;

#endif /* __EVENT_BASE_HPP__ */

