#include <stdlib.h>
#include <string.h>
#include <tgmath.h>
#include <uriparser/Uri.h>
#include "helpers.h"
#include "structs.h"

int __calcFibTCO(int n, int x, int y) {
  if (n == 0)
    return x;
  if (n == 1)
    return y;
  return __calcFibTCO(n - 1, y, x + y);
}

int __calcFibRecursion(int n) {
  if (n <= 1)
    return n;
  return __calcFibRecursion(n - 1) + __calcFibRecursion(n - 2);
}

int calcFibonacci(int n) {
  // return __calcFibTCO(n, 0, 1);  // TCO version. 
  return __calcFibRecursion(n);  // recursion version.
}

int calcDigits(int n) {
  return (int) floor(log10(abs(n))) + 1;
}

void wrapStrFromPTR(char* str, size_t len, const char* head, const char* tail) {
  for (size_t i = 0; head != tail; head++)
    str[i++] = *head;
  str[len - 1] = '\0';
}

int retrieveGETQueryIntValByKey(char* req, const char* key) {
  int result = 0;

  // extract uri;
  const char* uriHead = strchr(req, ' ') + 1;
  const char* uriTail = strchr(uriHead, ' ');
  size_t uriLen = uriTail - uriHead + 1;
  char strUri[uriLen];
  wrapStrFromPTR(strUri, uriLen, uriHead, uriTail);

  // parse uri;
  UriUriA uri;
  UriQueryListA* queryList;
  int itemCount;
  const char* errorPos;
  if (uriParseSingleUriA(&uri, strUri, &errorPos) == URI_SUCCESS) {
    if (uriDissectQueryMallocA(&queryList, &itemCount, uri.query.first, uri.query.afterLast) == URI_SUCCESS) {
      while (itemCount--) {
        if (strcmp(queryList->key, key) == 0) {
          result = atoi(queryList->value);
          break;
        }
        queryList = queryList->next;
      }
      uriFreeQueryListA(queryList);
    }
  }
  return result;
}

void setupServerSettings(int argc, const char** argv, serverSettings* ss) {
  while (argc-- > 1) {
    // process key.
    const char* keyHead = argv[argc];
    const char* keyPos = strchr(keyHead, '=');
    const size_t keyLen = keyPos - keyHead + 1;
    char key[keyLen];
    wrapStrFromPTR(key, keyLen, keyHead, keyPos);
    // process value.
    const char* valHead = keyHead + keyLen;
    const char* valPos = strchr(valHead, '\0');
    const size_t valLen = valPos - valHead + 1;
    char val[valLen];
    for (size_t i = 0; valHead <= valPos; valHead++)
      val[i++] = *valHead;
    if (strcmp(key, "thread_count") == 0) {
      ss->thread_count = atoi(val);
    }
  }
}
