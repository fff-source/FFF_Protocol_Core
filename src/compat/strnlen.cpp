// Copyright (c) 2009-2014 The FFF developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
// Copyright (c) 2014-2019 Coin Sciences Ltd
// FFF_Core code distributed under the GPLv3 license, see COPYING file.

#if defined(HAVE_CONFIG_H)
#include "config/FFF-config.h"
#endif

#include <cstring>

#if HAVE_DECL_STRNLEN == 0
size_t strnlen( const char *start, size_t max_len)
{
    const char *end = (const char *)memchr(start, '\0', max_len);

    return end ? (size_t)(end - start) : max_len;
}
#endif // HAVE_DECL_STRNLEN
