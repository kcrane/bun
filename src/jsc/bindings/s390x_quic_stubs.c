// Stubs for QUIC/HTTP3 functions (not essential for initial s390x port)
#include <stddef.h>
#include <stdint.h>

// lsquic extended API stubs
void lsquic_conn_abort_error(void* c, int i, uint64_t e) { (void)c; (void)i; (void)e; }
void lsquic_conn_abort_silent(void* c) { (void)c; }
void lsquic_conn_ack_now(void* c) { (void)c; }
int lsquic_conn_datagram_early(void* c) { (void)c; return 0; }
void* lsquic_conn_get_ssl(void* c) { (void)c; return NULL; }
void* lsquic_conn_make_uni_stream(void* c) { (void)c; return NULL; }
int lsquic_conn_peer_h3_datagram(void* c) { (void)c; return 0; }
unsigned lsquic_conn_pings_received(void* c) { (void)c; return 0; }
int lsquic_conn_set_ping_period_us(void* c, uint64_t p) { (void)c; (void)p; return -1; }
int lsquic_conn_use_preferred_address(void* c) { (void)c; return 0; }
int lsquic_engine_cid_in_use(void* e, const void* c) { (void)e; (void)c; return 0; }
unsigned lsquic_engine_conn_count(void* e) { (void)e; return 0; }
int lsquic_engine_set_idle_timeout_ms(void* e, uint64_t t) { (void)e; (void)t; return -1; }
void lsquic_engine_sreset_stats(void* e, void* s) { (void)e; (void)s; }
int lsquic_stream_get_error_code(void* s) { (void)s; return 0; }
int lsquic_stream_received_early_data(void* s) { (void)s; return 0; }
int lsquic_stream_reset_received(void* s) { (void)s; return 0; }
int lsquic_stream_send_stop_sending(void* s, uint64_t e) { (void)s; (void)e; return -1; }

// us_quic_* stubs
int us_quic_global_init(void) { return -1; }
void* us_create_quic_client_context(void* l, void* o) { (void)l; (void)o; return NULL; }
void* us_create_quic_socket_context(void* l, void* o, unsigned int s) { (void)l; (void)o; (void)s; return NULL; }
void* us_quic_socket_context_ext(void* c) { (void)c; return NULL; }
void us_quic_socket_context_free(void* c) { (void)c; }
void us_quic_socket_context_shutdown(void* c) { (void)c; }
void* us_quic_socket_context_listen(void* c, const char* h, int p, int b) { (void)c; (void)h; (void)p; (void)b; return NULL; }
void* us_quic_socket_context_connect(void* c, const char* h, int p) { (void)c; (void)h; (void)p; return NULL; }
void* us_quic_socket_context_loop(void* c) { (void)c; return NULL; }
void us_quic_socket_context_add_server_name(void* c, const char* h, void* o) { (void)c; (void)h; (void)o; }
void us_quic_socket_context_on_stream_open(void* c, void* f) { (void)c; (void)f; }
void us_quic_socket_context_on_stream_close(void* c, void* f) { (void)c; (void)f; }
void us_quic_socket_context_on_stream_data(void* c, void* f) { (void)c; (void)f; }
void us_quic_socket_context_on_stream_writable(void* c, void* f) { (void)c; (void)f; }
void us_quic_socket_context_on_stream_headers(void* c, void* f) { (void)c; (void)f; }
void us_quic_socket_context_on_close(void* c, void* f) { (void)c; (void)f; }
void us_quic_socket_context_on_hsk_done(void* c, void* f) { (void)c; (void)f; }
void us_quic_socket_context_on_goaway(void* c, void* f) { (void)c; (void)f; }
void* us_quic_socket_ext(void* s) { (void)s; return NULL; }
void* us_quic_socket_make_stream(void* s) { (void)s; return NULL; }
int us_quic_socket_remote_address(void* s, char* b, int* l) { (void)s; (void)b; (void)l; return -1; }
int us_quic_socket_status(void* s) { (void)s; return 0; }
int us_quic_socket_streams_avail(void* s) { (void)s; return 0; }
void* us_quic_stream_context(void* s) { (void)s; return NULL; }
void* us_quic_stream_ext(void* s) { (void)s; return NULL; }
void* us_quic_stream_socket(void* s) { (void)s; return NULL; }
int us_quic_stream_header(void* s, int i, char** n, int* nl, char** v, int* vl) { (void)s; (void)i; (void)n; (void)nl; (void)v; (void)vl; return -1; }
int us_quic_stream_header_count(void* s) { (void)s; return 0; }
void us_quic_stream_close(void* s) { (void)s; }
void us_quic_stream_reset(void* s, uint64_t e) { (void)s; (void)e; }
void us_quic_stream_shutdown(void* s) { (void)s; }
void us_quic_stream_shutdown_read(void* s) { (void)s; }
int us_quic_stream_send_headers(void* s, void* h, int n, int f) { (void)s; (void)h; (void)n; (void)f; return -1; }
int us_quic_stream_send_informational(void* s, void* h, int n) { (void)s; (void)h; (void)n; return -1; }
int us_quic_stream_write(void* s, const void* d, int l) { (void)s; (void)d; (void)l; return -1; }
void us_quic_stream_want_read(void* s, int w) { (void)s; (void)w; }
void us_quic_stream_want_write(void* s, int w) { (void)s; (void)w; }
int us_quic_listen_socket_port(void* s) { (void)s; return 0; }
int us_quic_listen_socket_local_address(void* s, char* b, int* l) { (void)s; (void)b; (void)l; return -1; }
void us_quic_listen_socket_close(void* s) { (void)s; }
void us_quic_loop_flush_if_pending(void* l) { (void)l; }
void us_quic_loop_process(void* l) { (void)l; }
void* us_quic_pending_connect_addrinfo(void* c) { (void)c; return NULL; }
void us_quic_pending_connect_cancel(void* c) { (void)c; }
void us_quic_pending_connect_resolved(void* c, void* a) { (void)c; (void)a; }

// us_nq_* stubs (new QUIC API)
void* us_nq_engine_new(void* s, void* v) { (void)s; (void)v; return NULL; }
void us_nq_enable_logging(void* e) { (void)e; }
void us_nq_hset_free(void* h) { (void)h; }
void* us_nq_hset_pairs(void* h) { (void)h; return NULL; }
void us_nq_loop_drain(void* l) { (void)l; }
void us_nq_loop_flush_if_pending(void* l) { (void)l; }
void us_nq_loop_register(void* l, void* e) { (void)l; (void)e; }
void us_nq_loop_unregister(void* l, void* e) { (void)l; (void)e; }
size_t us_nq_settings_size(void) { return 0; }
void us_nq_settings_init(void* s) { (void)s; }
int us_nq_settings_get_allow_migration(void* s) { (void)s; return 0; }
int us_nq_settings_get_datagrams(void* s) { (void)s; return 0; }
uint64_t us_nq_settings_get_idle_timeout(void* s) { (void)s; return 0; }
uint64_t us_nq_settings_get_idle_timeout_ms(void* s) { (void)s; return 0; }
uint64_t us_nq_settings_get_init_max_data(void* s) { (void)s; return 0; }
uint64_t us_nq_settings_get_init_max_stream_data_bidi_local(void* s) { (void)s; return 0; }
uint64_t us_nq_settings_get_init_max_stream_data_bidi_remote(void* s) { (void)s; return 0; }
uint64_t us_nq_settings_get_init_max_stream_data_uni(void* s) { (void)s; return 0; }
uint64_t us_nq_settings_get_init_max_streams_bidi(void* s) { (void)s; return 0; }
uint64_t us_nq_settings_get_init_max_streams_uni(void* s) { (void)s; return 0; }
uint64_t us_nq_settings_get_max_datagram_frame_size(void* s) { (void)s; return 0; }
uint64_t us_nq_settings_get_max_udp_payload_size_rx(void* s) { (void)s; return 0; }
void us_nq_settings_set_allow_migration(void* s, int v) { (void)s; (void)v; }
void us_nq_settings_set_cc_algo(void* s, int v) { (void)s; (void)v; }
void us_nq_settings_set_datagrams(void* s, int v) { (void)s; (void)v; }
void us_nq_settings_set_delayed_acks(void* s, int v) { (void)s; (void)v; }
void us_nq_settings_set_delay_onclose(void* s, int v) { (void)s; (void)v; }
void us_nq_settings_set_h3_connect_protocol(void* s, int v) { (void)s; (void)v; }
void us_nq_settings_set_h3_datagram(void* s, int v) { (void)s; (void)v; }
void us_nq_settings_set_handshake_to(void* s, uint64_t v) { (void)s; (void)v; }
void us_nq_settings_set_honor_prst(void* s, int v) { (void)s; (void)v; }
void us_nq_settings_set_idle_timeout(void* s, uint64_t v) { (void)s; (void)v; }
void us_nq_settings_set_idle_timeout_ms(void* s, uint64_t v) { (void)s; (void)v; }
void us_nq_settings_set_init_max_data(void* s, uint64_t v) { (void)s; (void)v; }
void us_nq_settings_set_init_max_stream_data_bidi_local(void* s, uint64_t v) { (void)s; (void)v; }
void us_nq_settings_set_init_max_stream_data_bidi_remote(void* s, uint64_t v) { (void)s; (void)v; }
void us_nq_settings_set_init_max_stream_data_uni(void* s, uint64_t v) { (void)s; (void)v; }
void us_nq_settings_set_init_max_streams_bidi(void* s, uint64_t v) { (void)s; (void)v; }
void us_nq_settings_set_init_max_streams_uni(void* s, uint64_t v) { (void)s; (void)v; }
void us_nq_settings_set_max_datagram_frame_size(void* s, uint64_t v) { (void)s; (void)v; }
void us_nq_settings_set_max_h3_header_bytes(void* s, uint64_t v) { (void)s; (void)v; }
void us_nq_settings_set_max_h3_header_pairs(void* s, uint64_t v) { (void)s; (void)v; }
void us_nq_settings_set_max_udp_payload_size_rx(void* s, uint64_t v) { (void)s; (void)v; }
void us_nq_settings_set_origin_blob(void* s, const void* d, size_t l) { (void)s; (void)d; (void)l; }
void us_nq_settings_set_ping_period(void* s, uint64_t v) { (void)s; (void)v; }
void us_nq_settings_set_ping_period_us(void* s, uint64_t v) { (void)s; (void)v; }
void us_nq_settings_set_preferred_address(void* s, void* a) { (void)s; (void)a; }
void us_nq_settings_set_scid_len(void* s, int v) { (void)s; (void)v; }
void us_nq_settings_set_send_prst(void* s, int v) { (void)s; (void)v; }
void us_nq_settings_set_silent_close(void* s, int v) { (void)s; (void)v; }
void us_nq_settings_set_sreset_burst(void* s, int v) { (void)s; (void)v; }
void us_nq_settings_set_sreset_rate(void* s, int v) { (void)s; (void)v; }
void* us_nq_spec_dest(void* s) { (void)s; return NULL; }
void* us_nq_spec_iov(void* s) { (void)s; return NULL; }
void* us_nq_spec_local(void* s) { (void)s; return NULL; }
size_t us_nq_spec_stride(void) { return 0; }
void us_nq_stream_reset(void* s, uint64_t e) { (void)s; (void)e; }
int us_nq_stream_send_headers(void* s, void* h, int n, int f) { (void)s; (void)h; (void)n; (void)f; return -1; }
void* us_nq_conn_transport_params(void* c) { (void)c; return NULL; }
size_t us_nq_tp_size(void) { return 0; }
size_t us_nq_vtable_size(void) { return 0; }

// sqlite3 session stubs (session extension not built)
void sqlite3session_delete(void* s) { (void)s; }
int sqlite3session_create(void* db, const char* z, void** pp) { (void)db; (void)z; *pp = NULL; return 1; }
int sqlite3session_attach(void* s, const char* z) { (void)s; (void)z; return 1; }
int sqlite3changeset_apply(void* db, int n, void* c, void* f1, void* f2, void* a) {
    (void)db; (void)n; (void)c; (void)f1; (void)f2; (void)a; return 1;
}
int sqlite3session_changeset(void* s, int* pn, void** pp) { (void)s; if(pn) *pn=0; if(pp) *pp=NULL; return 1; }
int sqlite3session_patchset(void* s, int* pn, void** pp) { (void)s; if(pn) *pn=0; if(pp) *pp=NULL; return 1; }

// bun_internal_modules stubs (normally from bundle-modules codegen)

// JSC LLInt boundary symbols
