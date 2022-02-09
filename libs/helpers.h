#ifndef _LIBS_HELPERS
#define _LIBS_HELPERS

#include "structs.h"

int calcFibonacci(int);
int calcDigits(int);
int retrieveGETQueryIntValByKey(char*, const char*);
void wrapStrFromPTR(char*, size_t, const char*, const char*);
void setupServerSettings(int, const char**, serverSettings*);

#endif  // _LIBS_HELPERS
