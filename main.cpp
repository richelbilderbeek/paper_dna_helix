#include "paper_dna_helix.h"

#include <fstream>
#include <iostream>

int main()
{
  const paper_dna_helix h(14);
  {
    std::ofstream f("paper_dna_helix.svg");
    f << h << '\n';
  }
  std::cout << h << '\n';

}
