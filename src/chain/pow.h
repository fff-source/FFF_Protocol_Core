// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The FFF developers
// Original code was distributed under the MIT/X11 software license.
// Copyright (c) 2014-2019 Coin Sciences Ltd
// FFF_Core code distributed under the GPLv3 license, see COPYING file.

#ifndef FFF_POW_H
#define FFF_POW_H

#include <stdint.h>

class CBlockHeader;
class CBlockIndex;
class uint256;

unsigned int GetNextWorkRequired(const CBlockIndex* pindexLast, const CBlockHeader *pblock);

/** Check whether a block hash satisfies the proof-of-work requirement specified by nBits */
bool CheckProofOfWork(uint256 hash, unsigned int nBits, bool fNoErrorInLog = false);
uint256 GetBlockProof(const CBlockIndex& block);

#endif // FFF_POW_H
