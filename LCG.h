#ifndef LCG_LCG_H
#define LCG_LCG_H

#include <chrono>
#include <cassert>

namespace LCG {

    int Rand(int min, int max)
    {
      assert(("Input overflows", !(min > (INT_MAX - max))));

      if (min > max) {
        std::swap(min, max);
      }

      uint64_t d =
              std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()
              .time_since_epoch())
              .count();
      const uint64_t m = std::pow(2, 32);
      const uint64_t a = 1103515245;
      const uint16_t c = 12345;

      d = (a * d + c) % m;

      double random = static_cast<double>(d) / static_cast<double>(m);

      return static_cast<int>((random * ((max + 1) - min)) + min);
    }
}

#endif //LCG_LCG_H
