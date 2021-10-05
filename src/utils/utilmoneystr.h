// Copyright (c) www.fff.network
// FFF_Core code distributed under the GPLv3 license, see COPYING file.

/**
 * Money parsing/formatting utilities.
 */
#ifndef FFF_UTILMONEYSTR_H
#define FFF_UTILMONEYSTR_H

#include <stdint.h>
#include <string>

#include "structs/amount.h"

std::string FormatMoney(const CAmount& n, bool fPlus=false);
bool ParseMoney(const std::string& str, CAmount& nRet);
bool ParseMoney(const char* pszIn, CAmount& nRet);

#endif // FFF_UTILMONEYSTR_H
