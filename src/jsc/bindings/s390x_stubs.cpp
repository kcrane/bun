// Stub implementations for s390x port
#include "root.h"
#include <cstddef>
#include <cstdint>

// CPUProfiler stubs (SamplingProfiler disabled on s390x)
namespace Bun {
    bool isCPUProfilerRunning() { return false; }
    void startCPUProfiler(JSC::VM&) {}
    void stopCPUProfiler(JSC::VM&, WTF::String*, WTF::String*) {}
    void setSamplingInterval(int) {}
}

extern "C" {

void Bun__startCPUProfiler(void*) {}
void Bun__stopCPUProfiler(void*, void*, void*) {}
void Bun__setSamplingInterval(int) {}

// TinyCC stubs (no s390x codegen)
void tcc_delete(void*) {}
void* tcc_new(void) { return nullptr; }
int tcc_add_file(void* s, const char* f) { (void)s; (void)f; return -1; }
int tcc_add_library(void* s, const char* n) { (void)s; (void)n; return -1; }
int tcc_add_library_path(void* s, const char* p) { (void)s; (void)p; return -1; }
int tcc_add_symbol(void* s, const char* n, const void* v) { (void)s; (void)n; (void)v; return -1; }
int tcc_add_sysinclude_path(void* s, const char* p) { (void)s; (void)p; return -1; }
int tcc_compile_string(void* s, const char* c) { (void)s; (void)c; return -1; }
void tcc_define_symbol(void* s, const char* n, const char* v) { (void)s; (void)n; (void)v; }
void* tcc_get_symbol(void* s, const char* n) { (void)s; (void)n; return nullptr; }
int tcc_relocate(void* s, void* p) { (void)s; (void)p; return -1; }
int tcc_set_options(void* s, const char* o) { (void)s; (void)o; return -1; }
int tcc_set_output_type(void* s, int t) { (void)s; (void)t; return -1; }

// JSC LLInt boundary symbols (used for stack trace symbolication)
uint8_t jsc_llint_begin = 0;
uint8_t jsc_llint_end = 0;

// Wasm streaming stub
int JSC__Wasm__StreamingCompiler__addBytes(void* c, const void* d, size_t l) {
    (void)c; (void)d; (void)l; return 0;
}

// picohttpparser stub
int phr_decode_chunked_is_in_trailers(void* decoder) { (void)decoder; return 0; }

} // extern "C"

// __real_execve / __real_pthread_create
#include <unistd.h>
#include <pthread.h>

extern "C" {
int __real_execve(const char* pathname, char* const argv[], char* const envp[]) {
    return execve(pathname, argv, envp);
}
int __real_pthread_create(pthread_t* thread, const pthread_attr_t* attr,
                         void* (*start_routine)(void*), void* arg) {
    return pthread_create(thread, attr, start_routine, arg);
}
}
