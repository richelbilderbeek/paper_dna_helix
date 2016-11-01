#include "paper_dna_helix.h"

#include <cassert>
#include <iostream>

paper_dna_helix::paper_dna_helix(const int n_nucleotides)
  : m_n_nucleotides{n_nucleotides},
    m_lines{create_lines(n_nucleotides)}
{
  assert(n_nucleotides > 0);
  assert(m_lines.size() < 1000);
}

std::vector<line> paper_dna_helix::create_lines(const int n_nucleotides)
{
  assert(n_nucleotides > 0);
  std::vector<line> v;
  //The width of a nucleotide is set to a length of 1 unit

  //Create left backbone
  for (int i=0; i!=n_nucleotides; ++i)
  {
    /*
        C
    |  / \
    | /   \
    |/     D
    B     /
    |\   /
    | \ /
    |  A



    */

    const double
  }

  v.push_back(line(n_nucleotides, n_nucleotides * 2, 100, 200));
  return v;
}


std::ostream& operator<<(std::ostream& os, const paper_dna_helix& h) noexcept
{
  //Use A4 format
  os << "<svg width=\"210\" height=\"297\" stroke=\"black\" stroke-width=\"1\">\n";
  assert(h.m_lines.size() < 1000);
  for (const auto& line: h.m_lines)
  {
    os << "  <line x1=\"" << line.x1 << "\" y1=\"" << line.y1
      << "\" x2=\"" << line.x2 << "\" y2=\"" << line.y2 << "\" />\n"
    ;
    //os << "  <line x1=\"50\" y1=\"50\" x2=\"50\" y2=\"200\" />\n";
    //os << "  <line x1=\"50\" y1=\"150\" x2=\"200\" y2=\"300\" />\n";
  }
  os << "</svg>";
  return os;
}
