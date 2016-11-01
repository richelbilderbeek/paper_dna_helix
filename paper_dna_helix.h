#ifndef PAPER_DNA_HELIX_H
#define PAPER_DNA_HELIX_H

#include <iosfwd>
#include <vector>

struct line
{
  line(const double any_x1, const double any_y1, const double any_x2, const double any_y2)
    : x1{any_x1}, y1{any_y1}, x2{any_x2}, y2{any_y2}
  {
  }
  double x1, y1, x2, y2;
};

///Can be converted to SVG
class paper_dna_helix
{
public:
  paper_dna_helix(const int n_nucleotides);

private:
  ///The number of nucleotides
  const int m_n_nucleotides;
  const std::vector<line> m_lines;


  std::vector<line> create_lines(const int n_nucleotides);

  friend std::ostream& operator<<(std::ostream& os, const paper_dna_helix& h) noexcept;
};

std::ostream& operator<<(std::ostream& os, const paper_dna_helix& h) noexcept;

#endif // PAPER_DNA_HELIX_H
