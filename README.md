# mini-http-echo-server
A mini HTTP Echo Server, just for education purpose.

### Compilation
`mkdir build && cd build && cmake .. && cmake --build .`

### Run Server
`./build/main thread_count=4`

### Load Test
`ab -c 50 -n 100 http://127.0.0.1:8080/?num=40`