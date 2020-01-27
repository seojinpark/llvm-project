/*
 * Copyright (c) 2020 Massachusetts Institute of Technology.
 * All rights reserved.
 */

#ifndef __MEOW_INTERFACE_H
#define __MEOW_INTERFACE_H

#include <stdio.h>
#include <stdint.h>

namespace llvm {
namespace Meow {

__inline __attribute__((always_inline))
uint64_t rdtsc()
{
    uint32_t lo, hi;
    __asm__ __volatile__("rdtsc" : "=a" (lo), "=d" (hi));
    return (((uint64_t)hi << 32) | lo);
}

void recordWithTime(uint64_t timestamp, const char* format,
        uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3);

inline void record(const char* format, uint32_t arg0,
        uint32_t arg1, uint32_t arg2, uint32_t arg3) {
    recordWithTime(rdtsc(), format, arg0, arg1, arg2, arg3);
}

void printTrace(const char *filename);

} // namespace Meow
} // namespace llvm

#endif