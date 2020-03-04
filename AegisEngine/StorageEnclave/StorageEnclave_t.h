#ifndef STORAGEENCLAVE_T_H__
#define STORAGEENCLAVE_T_H__

#include <stdint.h>
#include <wchar.h>
#include <stddef.h>
#include "sgx_edger8r.h" /* for sgx_ocall etc. */


#define SGX_CAST(type, item) ((type)(item))

#ifdef __cplusplus
extern "C" {
#endif

void set_secret4(unsigned char secret[16]);
void print_secret(void);
void copy_secret_to_device(void* devicePtr);
void copy_secret_to_device_with_rsa(int* rsa_e, int* rsa_n, void* devicePtr);

sgx_status_t SGX_CDECL ocall_print_secret(unsigned char value[16]);
sgx_status_t SGX_CDECL ocall_send_to_device(unsigned char value[176], void* devicePtr);
sgx_status_t SGX_CDECL ocall_send_to_device_rsa(int value[176], void* devicePtr);
sgx_status_t SGX_CDECL sgx_oc_cpuidex(int cpuinfo[4], int leaf, int subleaf);
sgx_status_t SGX_CDECL sgx_thread_wait_untrusted_event_ocall(int* retval, const void* self);
sgx_status_t SGX_CDECL sgx_thread_set_untrusted_event_ocall(int* retval, const void* waiter);
sgx_status_t SGX_CDECL sgx_thread_setwait_untrusted_events_ocall(int* retval, const void* waiter, const void* self);
sgx_status_t SGX_CDECL sgx_thread_set_multiple_untrusted_events_ocall(int* retval, const void** waiters, size_t total);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
