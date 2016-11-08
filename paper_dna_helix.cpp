#include "paper_dna_helix.h"

#include <cassert>
#include <cmath>
#include <iostream>

paper_dna_helix::paper_dna_helix(const int n_nucleotides)
  : m_n_nucleotides{n_nucleotides},
    m_lines{create_dna_helix(n_nucleotides)}
{
  assert(n_nucleotides > 0);
  assert(m_lines.size() < 1000);
}

std::vector<line> paper_dna_helix::create_dna_helix(const int n_nucleotides)
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
    lines nucleotide{create_nucleotide()};
    translate(nucleotide, 0.0, 10.0 * i);
    std::copy(
      std::begin(nucleotide),
      std::end(nucleotide),
      std::back_inserter(v)
    );
  }

  v.push_back(line(n_nucleotides, n_nucleotides * 2, 100, 200));
  return v;
}

std::vector<line> paper_dna_helix::create_nucleotide()
{
  /*
      C
  |  / \
  | /   \
  |/     D
  B     /
  |\   /
  | \ /  angle is angle of corner EAD
  |  A-----------E



  */
  const double pi{3.1415};
  const double hi{pi / 2.0};
  const double angle{pi * 0.25};
  const double ax{0.0};
  const double ay{0.0};
  const double bx{ax + (1.0 * std::cos( hi + angle))};
  const double by{ay - (1.0 * std::sin( hi + angle))};
  const double dx{ax + (2.0 * std::cos(0.0 + angle))};
  const double dy{ay - (2.0 * std::sin(0.0 + angle))};
  const double cx{dx + (1.0 * std::cos( hi + angle))};
  const double cy{dy - (1.0 * std::sin( hi + angle))};
  return
  {
    line(ax, ay, bx, by),
    line(bx, by, cx, cy),
    line(cx, cy, dx, dy),
    line(dx, dy, ax, ay)
  };
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
