# Threading and Parallel Computation Examples in C

This repository contains simple example programs demonstrating multithreading concepts in C using `pthread`. The focus is on thread creation, synchronization with mutexes, and parallel computations including prime number checks and trigonometric calculations.

## Files

### p1-threadcreation.c
Demonstrates basic thread creation using `pthread_create`. Shows how to start multiple threads and pass arguments safely to avoid common pitfalls.

### p2-mutex.c
Illustrates the use of `pthread_mutex_t` to synchronize access to shared data between threads. Prevents race conditions when multiple threads update a global counter.

### x1-primenums.c
Parallel implementation of prime number checking. Uses multiple threads to divide the workload of checking prime numbers and aggregates results safely.

### x2-sin-cos-parallelcalc.c
Computes sine and cosine values in parallel using Taylor series approximations. Each thread calculates values for different inputs independently.

## Usage

Compile each program with `-pthread` flag. For example:

```bash
gcc p1-threadcreation.c -o p1-threadcreation -pthread
./p1-threadcreation
