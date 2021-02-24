#include <iostream>
#include <list>
#include <algorithm>
#include "LCG.h"

int main() {

  std::list<int> randoms;
  const int numberOfRandoms = 1000;

  for (int i = 0; i < numberOfRandoms; i++)
    randoms.emplace_back(LCG::Rand(-1000, 1000));

  std::for_each(randoms.begin(), randoms.end(), [&](const int random) {
      std::cout << random << " ";
  });

  return 0;
}
