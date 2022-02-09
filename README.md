# tiny-http-echo-server
A simple HTTP Echo Server, just for educational purposes. 

If you send the HTTP request with a query param named "num" and an integer value N, then the server will respond to you with the Nth value in the standard Fibonacci sequence.

### Compilation
```
mkdir build && cd build && cmake .. && cmake --build .
```

### Run Server
```
./build/main thread_count=4
```

### Load Test
```
ab -c 50 -n 100 http://127.0.0.1:8080/?num=40
```
