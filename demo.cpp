#include <iostream>
#include <list>
#include <algorithm>
#include "LCG.h"

int main() {

  std::list<int> randoms;
  const int numberOfRandoms = 1000;
  const int lineLength = 100;

  for (int i = 0; i < numberOfRandoms; i++)
    randoms.emplace_back(LCG::Rand(-10, 10));

  int counter = 0;

  std::for_each(randoms.begin(), randoms.end(), [&](const int random) {
      std::cout << random << " ";
      counter++;

      if (counter == lineLength) {
        std::cout << std::endl;
        counter = 0;
      }
  });

  return 0;
}
