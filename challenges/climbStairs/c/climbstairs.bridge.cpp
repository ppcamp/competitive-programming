#include "climbstairs.bridge.h"

#include <iostream>

#include "climbstairs.hpp"

Solution* AsSolution(void* solution) {
  DEBUG_PRINT("[c++ bridge] AsSolution casting (" solution ')' solution);

  return reinterpret_cast<Solution*>(solution);
}

void* LIB_NewSolution() {
  DEBUG_PRINT("[c++ bridge] LIB_NewSolution");

  auto solution = new Solution();
  return solution;
}

void* LIB_DestroySolution(void* solution) {
  DEBUG_PRINT("[c++ bridge] LIB_DestroySolution (" solution ')' solution);

  AsSolution(solution)->~Solution();
  return NULL;
}

int LIB_RunSolution(void* solution, int n) {
  DEBUG_PRINT("[c++ bridge] LIB_RunSolution (" solution ')' solution);

  return AsSolution(solution)->climbStairs(n);
}