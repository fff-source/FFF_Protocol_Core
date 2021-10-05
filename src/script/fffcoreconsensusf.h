// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2014-2016 The FFF Core developers
// Original code was distributed under the MIT software license.
// Copyright (c) 2014-2019 Coin Sciences Ltd
// FFF_Core code distributed under the GPLv3 license, see COPYING file.

#ifndef FFF_FFFCONSENSUS_H
#define FFF_FFFCONSENSUS_H

#if defined(BUILD_FFF_INTERNAL) && defined(HAVE_CONFIG_H)
#include "config/FFF-config.h"
  #if defined(_WIN32)
    #if defined(DLL_EXPORT)
      #if defined(HAVE_FUNC_ATTRIBUTE_DLLEXPORT)
        #define EXPORT_SYMBOL __declspec(dllexport)
      #else
        #define EXPORT_SYMBOL
      #endif
    #endif
  #elif defined(HAVE_FUNC_ATTRIBUTE_VISIBILITY)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBFFFCONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define FFFCONSENSUS_API_VER 0

typedef enum FFFconsensus_error_t
{
    FFFconsensus_ERR_OK = 0,
    FFFconsensus_ERR_TX_INDEX,
    FFFconsensus_ERR_TX_SIZE_MISMATCH,
    FFFconsensus_ERR_TX_DESERIALIZE,
} FFFconsensus_error;

/** Script verification flags */
enum
{
    FFFconsensus_SCRIPT_FLAGS_VERIFY_NONE      = 0,
    FFFconsensus_SCRIPT_FLAGS_VERIFY_P2SH      = (1U << 0), // evaluate P2SH (BIP16) subscripts
    FFFconsensus_SCRIPT_FLAGS_VERIFY_DERSIG    = (1U << 2), // enforce strict DER (BIP66) compliance
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not NULL, err will contain an error/success code for the operation
EXPORT_SYMBOL int FFFconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, FFFconsensus_error* err);

EXPORT_SYMBOL unsigned int FFFconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // FFF_FFFCONSENSUS_H
