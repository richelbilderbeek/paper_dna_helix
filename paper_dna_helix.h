#ifndef PAPER_DNA_HELIX_H
#define PAPER_DNA_HELIX_H

#include <iosfwd>
#include <vector>
#include "lines.h"

///Can be converted to SVG
class paper_dna_helix
{
public:
  paper_dna_helix(
    const double left_chain_angle_rad,
    const int n_nucleotides,
    const double nucleotide_width
  );

  //Height in A4 (portrait) pixels,
  double get_height() const noexcept { return 297; }
  //Width in A4 (portrait) pixels,
  double get_width() const noexcept { return 210; }

private:

  ///Angle the nucleotides have on the left chain in radians
  const double m_left_chain_angle_rad;

  ///Created by this class
  lines m_lines;

  ///Number of nucleotides
  const int m_n_nucleotides;

  ///Width of a nucleotide
  const double m_nucleotide_width;

  lines create_dna_helix() const;
  lines create_frame() const;
  lines create_nucleotide() const;

  friend std::ostream& operator<<(std::ostream& os, const paper_dna_helix& h) noexcept;
};


std::ostream& operator<<(std::ostream& os, const paper_dna_helix& h) noexcept;

#endif // PAPER_DNA_HELIX_H
