// Copyright (c) 2014-2019 Coin Sciences Ltd
// FFF_Core code distributed under the GPLv3 license, see COPYING file.

#ifndef FFF_Core_V8FILTER_H_
#define FFF_Core_V8FILTER_H_

#include "json/json_spirit.h"
#include <v8.h>

#define MC_V8W_JS_INJECTION_LIMITED_MATH_SET             0x00000001
#define MC_V8W_JS_INJECTION_FIXED_DATE_FUNCTIONS         0x00000002
#define MC_V8W_JS_INJECTION_DISABLED_DATE_PARSE          0x00000004


namespace mc_v8
{
class V8Engine;

/**
 * Implementation of a filter based on the V8 JS engine.
 */
class V8Filter
{
public:
    ~V8Filter();

    /**
     * Test if the filter fuction is currently executing.
     */
    bool IsRunning() const { return m_isRunning; }

    /**
     * Initialize the filter to run the function @p functionName in the JS @p script.
     *
     * @param script         The filter JS code.
     * @param main_name      The expected name of the filtering function in the script.
     * @param callbackNames  A list of callback function names to register for the filter.
     *                       If empty, register no callback functions.
     * @param strResult      Reason for failure if unsuccessful.
     * @return               MC_ERR_INTERNAL_ERROR if the engine failed,
     * MC_ERR_NOERROR otherwise.
     */
    int Initialize(V8Engine *engine, std::string script, std::string functionName,
                   const std::vector<std::string> &callbackNames, int jsInjectionParams, std::string &strResult);

    /**
     * Run the filter function in the JS script.
     *
     * @param strResult       Reason for script failure or rejection.
     * @param withCallbackLog Indicates that callback tracking will be used.
     * @return                MC_ERR_INTERNAL_ERROR if the engine failed, MC_ERR_NOERROR otherwise.
     */
    int Run(std::string &strResult);

private:
    int CompileAndLoadScript(std::string script, std::string functionName, std::string source, std::string &strResult);
    void ReportException(v8::TryCatch *tryCatch, std::string &strResult);

    V8Engine *m_engine = nullptr;
    v8::Global<v8::Context> m_context;
    v8::Global<v8::Function> m_filterFunction;
    bool m_isRunning = false;
};

} // namespace mc_v8

#endif /* FFF_Core_V8FILTER_H_ */
