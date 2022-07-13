#include <iostream>
#include <vector>

int main()
{
  int number, pow, mod;
  while (std::cin >> number >> pow >> mod) {
    std::vector<int> pow2;
    while (pow > 0) {
      pow2.push_back(pow % 2);
      pow /= 2;
    }

    int r = 1;
    for (int& p : pow2) {
      if (p == 1) {
        r = (r * number) % mod;
      }
      number = (number * number) % mod;
    }
    std::cout << r << '\n';
  }
}