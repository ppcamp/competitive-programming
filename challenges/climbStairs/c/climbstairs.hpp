#pragma once

class Solution {
 public:
  /*
   * @example
   * int main() {
   *   Solution s;
   *   std::cout << "> " << s.climbStairs(6) << std::endl;
   * }
   */
  int climbStairs(int n);

 private:
  long long fib(int n) {
    if (n <= 2) {
      return n;
    }

    long long prev = 1, curr = 2, tmp = curr;
    // for (int i = 2; i < n; i++) {
    //   curr += prev;
    //   prev = curr - prev;  // if we used a new var, it would be more
    //   efficient
    // }
    for (int i = 2; i < n; i++) {
      tmp += prev;
      prev = curr;
      curr = tmp;
    }
    return curr;
  }
};
