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

#ifndef __TIMER_HPP__
#define __TIMER_HPP__

#include <EasyCpp.hpp>
#include <IMultiThread.hpp>

namespace Platform {

static const char *day[] = {
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thuresday",
	"Friday",
	"Saturday",
	"Sunday"
};

static const char *month[] = {
	"Janurday",
	"Febrary",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December",
};

void Sleep(uint32_t sec);
void MSleep(uint32_t ms);
void USleep(uint32_t us);

ITimerPtr CreateTimer(uint32_t timeout, const RunnableFn &run);

struct SysTime
{
	uint16_t msec;
	uint8_t sec;
	uint8_t min;
	uint8_t hour;
	uint8_t day;
	uint8_t month;
	uint8_t dayweek;
	uint16_t year;
};

void GetSysTime(struct SysTime &sysTime);

}

using namespace Platform;

#endif /* __TIMER_HPP__ */

