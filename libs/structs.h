#ifndef _LIBS_STRUCTS
#define _LIBS_STRUCTS

#include <sys/socket.h>

// self-defined types.
typedef struct sockaddr_in sockaddr_in;
typedef struct sockaddr sockaddr;
typedef struct {
  int thread_count;
} serverSettings;
typedef struct {
  int serverFd;
  sockaddr* addr;
  socklen_t* addrLen;
} acceptParams;

#endif  // _LIBS_STRUCTS
