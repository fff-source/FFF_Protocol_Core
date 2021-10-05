// Copyright (c) www.fff.network
// FFF_Core code distributed under the GPLv3 license, see COPYING file.

#ifndef FFF_INIT_H
#define FFF_INIT_H

#include <string>

class CWallet;
struct mc_WalletTxs;
struct mc_RelayManager;
struct mc_FilterEngine;
struct mc_FFF_CoreFilterEngine;
struct mc_EnterpriseFeatures;


class CInitNodeStatus
{
public:
    bool fInitialized;
    uint32_t tStartConnectTime;
    std::string sSeedIP;
    int nSeedPort;
    std::string sAddress;
    std::string sLastError;
    
    CInitNodeStatus();
};


namespace boost
{
class thread_group;
} // namespace boost

extern CWallet* pwalletMain;
extern mc_WalletTxs* pwalletTxsMain;
extern mc_RelayManager* pRelayManager;
extern mc_FilterEngine* pFilterEngine;
extern mc_FFF_CoreFilterEngine* pFFF_CoreFilterEngine;
extern mc_EnterpriseFeatures* pEF;
extern CInitNodeStatus *pNodeStatus;


void StartShutdown();
bool ShutdownRequested();
void Shutdown();

/* MCHN START */
#ifndef STDOUT_FILENO
#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2
#endif
/* MCHN END */



bool AppInit2(boost::thread_group& threadGroup,int OutputPipe=STDOUT_FILENO);

/** The help message mode determines what help message to show */
enum HelpMessageMode {
    HMM_FFFD,
    HMM_FFF_QT
};

/** Help for options shared between UI and daemon (for -help) */
std::string HelpMessage(HelpMessageMode mode);
/** Returns licensing information (for -version) */
std::string LicenseInfo();

#endif // FFF_INIT_H
