// Copyright (c) 2014-2019 Coin Sciences Ltd
// FFF_Core code distributed under the GPLv3 license, see COPYING file.

#ifndef FFF_CoreFILTER_H
#define FFF_CoreFILTER_H

#include "core/init.h"
#include "core/main.h"
#include "utils/util.h"
#include "utils/utilparse.h"
#include "FFF_Core/FFF_Core.h"
#include "json/json_spirit_value.h"
//#include "filters/filter.h"

#define MC_FLT_TYPE_BAD                    0xFFFFFFFF
#define MC_FLT_TYPE_TX                     0
#define MC_FLT_TYPE_STREAM                 1

#define MC_FLT_MAIN_NAME_TX                "filtertransaction"
#define MC_FLT_MAIN_NAME_STREAM            "filterstreamitem"
#define MC_FLT_MAIN_NAME_TEST              "_FFF_Core_library_test_"

#define MC_FLT_LIBRARY_GLUE                "\n\n"

std::vector <uint160>  mc_FillRelevantFilterEntitities(const unsigned char *ptr, size_t value_size);

class mc_Filter;

typedef struct mc_FFF_CoreFilter
{
    std::vector <uint160> m_RelevantEntities;
    std::vector <uint160> m_Libraries;
    std::vector <uint32_t> m_CachedUpdateIDs;
    
    mc_Filter *m_CachedWorker;
    mc_EntityDetails m_Details;
    std::string m_CreateError;
    std::string m_MainName;
    std::string m_FilterCaption;
    uint32_t m_FilterType;
    int m_FilterCodeRow;
    uint160 m_FilterAddress;
    bool m_AlreadyUsed;
    
    
    mc_FFF_CoreFilter()
    {
        Zero();
    }
    
    ~mc_FFF_CoreFilter()
    {
        Destroy();
    }
    
    int Initialize(const unsigned char* short_txid);
    
    int Zero();
    int Destroy();   

    bool HasRelevantEntity(std::set <uint160>& sRelevantEntities);
    
} mc_FFF_CoreFilter;

typedef struct mc_FFF_CoreLibrary
{
    mc_EntityDetails m_Details;
    std::string m_CreateError;
    std::string m_LibraryCaption;
    int m_LibraryCodeRow;
    uint32_t m_ActiveUpdate;
    uint32_t m_MaxLoadedUpdate;
    uint160 m_Hash;
    std::string m_Code;
    
    mc_FFF_CoreLibrary()
    {
        Zero();
    }
    
    ~mc_FFF_CoreLibrary()
    {
        Destroy();
    }
    
    int Initialize(const unsigned char* short_txid,uint32_t index);
    
    int Zero();
    int Destroy();   
    
} mc_FFF_CoreLibrary;

typedef struct mc_FFF_CoreFilterParams
{
    int m_MaxShownData;
    int m_Compatibility;
    mc_FFF_CoreFilterParams()
    {
        Zero();
    }
    
    ~mc_FFF_CoreFilterParams()
    {
        Destroy();
    }
    
    int Zero();
    int Destroy();  
    int Init();
    int Close();
}mc_FFF_CoreFilterParams;

typedef struct mc_FFF_CoreFilterEngine
{
    std::vector <mc_FFF_CoreFilter> m_Filters;
    std::vector <std::vector <std::string>> m_CallbackNames;
    std::map<uint160,mc_FFF_CoreLibrary> m_Libraries;
    
    mc_Buffer *m_Workers;
    mc_Script *m_CodeLibrary;
    uint256 m_TxID;
    uint256 m_EntityTxID;
    CTransaction m_Tx;
    int m_Vout;
    mc_FFF_CoreFilterParams m_Params;
    void *m_CoinsCache;
    
    void *m_Semaphore;
    uint64_t m_LockedBy;
    
    mc_FFF_CoreFilterEngine()
    {
        Zero();
    }
    
    ~mc_FFF_CoreFilterEngine()
    {
        Destroy();
    }
    
    int Initialize();
    void SetCallbackNames();
    int GetAcceptTimeout();
    int GetSendTimeout();
    int SetTimeout(int timeout);    
    int AddFilter(const unsigned char* short_txid,int for_block);
    int Reset(int block,int for_block);
    int RunTxFilters(const CTransaction& tx,std::set <uint160>& sRelevantEntities,std::string &strResult,mc_FFF_CoreFilter **lppFilter,int *applied,bool only_once);            
    int RunStreamFilters(const CTransaction& tx,int vout, unsigned char *stream_short_txid,int block,int offset,std::string &strResult,mc_FFF_CoreFilter **lppFilter,int *applied);            
    int RunFilter(const CTransaction& tx,mc_Filter *filter,std::string &strResult);            
    int RunFilterWithCallbackLog(const CTransaction& tx,int vout,uint256 stream_txid,mc_Filter *filter,std::string &strResult, json_spirit::Array& callbacks);
    int NoStreamFilters();
    int LoadLibrary(uint160 hash,bool *modified);
    uint160 ActiveUpdateID(uint160 hash);
    int CheckLibraries(std::set <uint160>* lpAffectedLibraries,int for_block);
    int RebuildFilter(int row,int for_block);
    mc_Filter *StreamFilterWorker(int row,bool *modified);
    
    int InFilter();
    int Zero();
    int Destroy();   
    void Lock(int write_mode);
    void UnLock();
    int SetTimeoutInternal(int timeout);    
    int CheckLibrariesInternal(std::set <uint160>* lpAffectedLibraries,int for_block);
    int AddFilterInternal(const unsigned char* short_txid,int for_block);
    int ResetInternal(int block,int for_block);
    void SetCallbackNamesInternal();
    
} mc_FFF_CoreFilterEngine;

#endif /* FFF_CoreFILTER_H */

