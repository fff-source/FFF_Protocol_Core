// Copyright (c) 2014-2019 Coin Sciences Ltd
// FFF_Core code distributed under the GPLv3 license, see COPYING file.

#ifndef FFF_CoreVERSION_H
#define	FFF_CoreVERSION_H

#define FFF_Core_VERSION_MAJOR     1
#define FFF_Core_VERSION_MINOR     0
#define FFF_Core_VERSION_REVISION  0
#define FFF_Core_VERSION_STAGE     2
#define FFF_Core_VERSION_BUILD     2

#define FFF_Core_PROTOCOL_VERSION 10008
#define FFF_Core_PROTOCOL_SUPPORTED "10004 - 10008, 20001"


#ifndef STRINGIZE
#define STRINGIZE(X) DO_STRINGIZE(X)
#endif

#ifndef DO_STRINGIZE
#define DO_STRINGIZE(X) #X
#endif

#define FFF_Core_BUILD_DESC_WITH_SUFFIX(maj, min, rev, build, suffix) \
    DO_STRINGIZE(maj) "." DO_STRINGIZE(min) "." DO_STRINGIZE(rev) "." DO_STRINGIZE(build) "-" DO_STRINGIZE(suffix)

#define FFF_Core_BUILD_DESC_FROM_UNKNOWN(maj, min, rev, build) \
    DO_STRINGIZE(maj) "." DO_STRINGIZE(min) "." DO_STRINGIZE(rev) "." DO_STRINGIZE(build)


#define FFF_Core_BUILD_DESC "1.0 beta 2"
#define FFF_Core_BUILD_DESC_NUMERIC 10000202


#ifndef FFF_Core_BUILD_DESC
#ifdef BUILD_SUFFIX
#define FFF_Core_BUILD_DESC FFF_Core_BUILD_DESC_WITH_SUFFIX(FFF_Core_VERSION_MAJOR, FFF_Core_VERSION_MINOR, FFF_Core_VERSION_REVISION, FFF_Core_VERSION_BUILD, BUILD_SUFFIX)
#else
#define FFF_Core_BUILD_DESC FFF_Core_BUILD_DESC_FROM_UNKNOWN(FFF_Core_VERSION_MAJOR, FFF_Core_VERSION_MINOR, FFF_Core_VERSION_REVISION, FFF_Core_VERSION_BUILD)
#endif
#endif

#define FFF_Core_FULL_DESC(build, protocol) \
    "build " build " protocol " DO_STRINGIZE(protocol)


#ifndef FFF_Core_FULL_VERSION
#define FFF_Core_FULL_VERSION FFF_Core_FULL_DESC(FFF_Core_BUILD_DESC, FFF_Core_PROTOCOL_VERSION)
#endif


#define FFF_Core_VERSION_CODE_PROTOCOL_THIS              0
#define FFF_Core_VERSION_CODE_PROTOCOL_MIN               1
#define FFF_Core_VERSION_CODE_PROTOCOL_MIN_DOWNGRADE     2
#define FFF_Core_VERSION_CODE_PROTOCOL_MIN_NO_DOWNGRADE  3
#define FFF_Core_VERSION_CODE_PROTOCOL_FOR_RELEVANCE     4
#define FFF_Core_VERSION_CODE_BUILD                     16
#define FFF_Core_VERSION_CODE_MIN_VALID               1000

#endif	/* FFF_CoreVERSION_H */

