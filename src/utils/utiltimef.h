// Copyright (c) www.fff.network
// FFF_Core code distributed under the GPLv3 license, see COPYING file.

#ifndef FFF_UTILTIME_H
#define FFF_UTILTIME_H

#include <stdint.h>
#include <string>

int64_t GetTime();
int64_t GetTimeMillis();
int64_t GetTimeMicros();
void SetMockTime(int64_t nMockTimeIn);
void MilliSleep(int64_t n);

std::string DateTimeStrFormat(const char* pszFormat, int64_t nTime);

#endif // FFF_UTILTIME_H
