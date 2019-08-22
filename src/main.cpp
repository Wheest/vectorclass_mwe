#include <assert.h>
#include <iostream>
#include <chrono>
#include "vectorclass.h"

// Initializes vector to store values
void init_vector(float* a, float* b, size_t size)
{
    for (int i=0; i<size; i++)
    {
        a[i] = i * 1.0;
        b[i] = (size * 1.0) - i - 1;
    }
}

// Test result of operations on vector
void test_result(float* result, size_t size)
{
    for (int i=0; i<size; i++)
        assert(result[i] == size - 1);
}


int main(int argc, char *argv[])
{
    const unsigned long SIZE = 8 * 40000;

    float vec_a[SIZE];
    float vec_b[SIZE];
    float result[SIZE];

    // standard version
    init_vector(vec_a, vec_b, SIZE);
    auto t1 = std::chrono::high_resolution_clock::now();

#pragma loop(no_vector)
    for (auto i = 0; i < SIZE; i++)
        result[i] = vec_a[i]  + vec_b[i];

    auto t2 = std::chrono::high_resolution_clock::now();
    auto total = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();

    test_result(result, SIZE);
    std::cout << "Baseline: " << total << " ms\n";

    // SIMD version
    init_vector(vec_a, vec_b, SIZE);

    Vec8f avec[SIZE / 8], bvec[SIZE / 8], resvec[SIZE / 8];

    for (auto i = 0; i < SIZE; i+=8)
    {
	avec[i/8].load(&vec_a[i]);
	bvec[i/8].load(&vec_b[i]);
    }

    t1 = std::chrono::high_resolution_clock::now();

    for (auto i = 0; i < SIZE/8; i++)
	resvec[i] = avec[i] + bvec[i];

    t2 = std::chrono::high_resolution_clock::now();

    for (auto i = 0; i < SIZE; i+=8)
	resvec[i/8].store(&result[i]);

    total = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
    test_result(result, SIZE);
    std::cout << "SIMD: " << total << " ms\n";

    return 0;
}
