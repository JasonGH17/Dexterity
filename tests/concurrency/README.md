# Concurrency Test

This test benchmarks the multi-processessing capability of the server.

The route being tested has a `sleep(1)` statement to slow down requests.

The test script is trying to send 150 requests at once, so without multi-processessing the server should take at least 150 seconds to finish responding to all those requests.

## Results

Server configuration:

```
N. Threads: 16 (Default number of threads)
Route:      "/test"
```

Results:

```
real: 0m12.383s
user: 0m16.905s
sys:  0m4.228s
```
