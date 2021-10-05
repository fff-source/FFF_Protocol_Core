// Copyright (c) 2009-2014 The FFF developers
// Original code was distributed under the MIT software license.
// Copyright (c) 2014-2019 Coin Sciences Ltd
// FFF_Core code distributed under the GPLv3 license, see COPYING file.

#ifndef FFF_CHECKPOINTS_H
#define FFF_CHECKPOINTS_H

#include "structs/uint256.h"

#include <map>

class CBlockIndex;

/** 
 * Block-chain checkpoints are compiled-in sanity checks.
 * They are updated every release or three.
 */
namespace Checkpoints
{
typedef std::map<int, uint256> MapCheckpoints;

struct CCheckpointData {
    const MapCheckpoints *mapCheckpoints;
    int64_t nTimeLastCheckpoint;
    int64_t nTransactionsLastCheckpoint;
    double fTransactionsPerDay;
};

//! Returns true if block passes checkpoint checks
bool CheckBlock(int nHeight, const uint256& hash);

//! Return conservative estimate of total number of blocks, 0 if unknown
int GetTotalBlocksEstimate();

//! Returns last CBlockIndex* in mapBlockIndex that is a checkpoint
CBlockIndex* GetLastCheckpoint();

double GuessVerificationProgress(CBlockIndex* pindex, bool fSigchecks = true);

extern bool fEnabled;

} //namespace Checkpoints

#endif // FFF_CHECKPOINTS_H
