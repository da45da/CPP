// MathLibrary.h - Contains declarations of math functions
#pragma once

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

extern "C" MATHLIBRARY_API void fibonacci_init(const unsigned long long a, const unsigned long long b);

extern "C" MATHLIBRARY_API bool fibonacci_next();// Produce the next value in the sequence.

extern "C" MATHLIBRARY_API unsigned long long fibonacci_current();// Get the current value in the sequence.

extern "C" MATHLIBRARY_API unsigned fibonacci_index();// Get the position of the current value in the sequence.