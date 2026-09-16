#include <cstddef>
#include <cstdint>
#include <optional>
#include <climits>

namespace v8 {
class Isolate;
template<class T> class Local { public: T* val_ = nullptr; };
class String;
enum class CpuProfilingNamingMode { kDebugNaming, kStandardNaming };
enum class CpuProfilingLoggingMode { kLazyLogging, kEagerLogging };
enum class CpuProfilingMode { kLeafNodeLineNumbers, kCallerLineNumbers };
enum class CpuProfilingStatus { kStarted, kAlreadyStarted, kErrorTooManyProfilers };
using ProfilerId = uint32_t;
struct CpuProfilingResult { const ProfilerId id; const CpuProfilingStatus status; };

class CpuProfileNode {
public:
    struct LineTick { int line; int column; unsigned int hit_count; };
    Local<String> GetFunctionName() const;
    const char* GetFunctionNameStr() const;
    int GetScriptId() const;
    Local<String> GetScriptResourceName() const;
    int GetLineNumber() const;
    int GetColumnNumber() const;
    unsigned int GetHitLineCount() const;
    bool GetLineTicks(LineTick*, unsigned int) const;
    unsigned GetHitCount() const;
    int GetChildrenCount() const;
    const CpuProfileNode* GetChild(int) const;
};

class CpuProfile {
public:
    Local<String> GetTitle() const;
    const CpuProfileNode* GetTopDownRoot() const;
    int GetSamplesCount() const;
    const CpuProfileNode* GetSample(int) const;
    int64_t GetSampleTimestamp(int) const;
    int64_t GetStartTime() const;
    int64_t GetEndTime() const;
    void Delete();
};

class CpuProfiler {
public:
    static CpuProfiler* New(Isolate*, CpuProfilingNamingMode = CpuProfilingNamingMode::kDebugNaming,
        CpuProfilingLoggingMode = CpuProfilingLoggingMode::kLazyLogging);
    static void CollectSample(Isolate*, const std::optional<uint64_t> = std::nullopt);
    void Dispose();
    void SetSamplingInterval(int);
    CpuProfilingResult Start(Local<String>, CpuProfilingMode, bool = false, unsigned = UINT_MAX);
    CpuProfilingStatus StartProfiling(Local<String>, CpuProfilingMode, bool = false, unsigned = UINT_MAX);
    CpuProfilingStatus StartProfiling(Local<String>, bool = false);
    CpuProfile* Stop(ProfilerId);
    CpuProfile* StopProfiling(Local<String>);
};

Local<String> CpuProfileNode::GetFunctionName() const { return {}; }
const char* CpuProfileNode::GetFunctionNameStr() const { return ""; }
int CpuProfileNode::GetScriptId() const { return 0; }
Local<String> CpuProfileNode::GetScriptResourceName() const { return {}; }
int CpuProfileNode::GetLineNumber() const { return 0; }
int CpuProfileNode::GetColumnNumber() const { return 0; }
unsigned int CpuProfileNode::GetHitLineCount() const { return 0; }
bool CpuProfileNode::GetLineTicks(LineTick*, unsigned int) const { return false; }
unsigned CpuProfileNode::GetHitCount() const { return 0; }
int CpuProfileNode::GetChildrenCount() const { return 0; }
const CpuProfileNode* CpuProfileNode::GetChild(int) const { return nullptr; }

Local<String> CpuProfile::GetTitle() const { return {}; }
const CpuProfileNode* CpuProfile::GetTopDownRoot() const { return nullptr; }
int CpuProfile::GetSamplesCount() const { return 0; }
const CpuProfileNode* CpuProfile::GetSample(int) const { return nullptr; }
int64_t CpuProfile::GetSampleTimestamp(int) const { return 0; }
int64_t CpuProfile::GetStartTime() const { return 0; }
int64_t CpuProfile::GetEndTime() const { return 0; }
void CpuProfile::Delete() {}

CpuProfiler* CpuProfiler::New(Isolate*, CpuProfilingNamingMode, CpuProfilingLoggingMode) { return nullptr; }
void CpuProfiler::CollectSample(Isolate*, const std::optional<uint64_t>) {}
void CpuProfiler::Dispose() {}
void CpuProfiler::SetSamplingInterval(int) {}
CpuProfilingResult CpuProfiler::Start(Local<String>, CpuProfilingMode, bool, unsigned)
    { return {0, CpuProfilingStatus::kErrorTooManyProfilers}; }
CpuProfilingStatus CpuProfiler::StartProfiling(Local<String>, CpuProfilingMode, bool, unsigned)
    { return CpuProfilingStatus::kErrorTooManyProfilers; }
CpuProfilingStatus CpuProfiler::StartProfiling(Local<String>, bool)
    { return CpuProfilingStatus::kErrorTooManyProfilers; }
CpuProfile* CpuProfiler::Stop(ProfilerId) { return nullptr; }
CpuProfile* CpuProfiler::StopProfiling(Local<String>) { return nullptr; }

} // namespace v8
