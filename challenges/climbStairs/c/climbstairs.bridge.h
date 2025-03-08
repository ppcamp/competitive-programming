#pragma once

#if defined(ENABLE_DEBUG) && ENABLE_DEBUG
#define DEBUG_PRINT(args) std::cout << #args << std::endl;
#else
#define DEBUG_PRINT(args) ;
#endif

#ifdef __cplusplus
extern "C" {
#endif

void* LIB_NewSolution();
void* LIB_DestroySolution(void* solution);
int LIB_RunSolution(void* foo, int n);

#ifdef __cplusplus
}  // extern "C"
#endif