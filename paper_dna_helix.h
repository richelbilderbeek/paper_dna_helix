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
    const double nucleotide_width,
    const double backbone_margin_mm
  );

  //Height in A4 (portrait) pixels,
  double get_height() const noexcept { return 297; }
  //Width in A4 (portrait) pixels,
  double get_width() const noexcept { return 210; }

private:

  ///The horizontal margin of the backbone
  const double m_backbone_margin_mm;

  ///Angle the nucleotides have on the left chain in radians
  const double m_left_chain_angle_rad;

  ///Created by this class
  lines m_lines;

  ///Number of nucleotides
  const int m_n_nucleotides;

  ///Width of a nucleotide
  const double m_nucleotide_width;

  lines create_dna_helix() const;

  friend std::ostream& operator<<(std::ostream& os, const paper_dna_helix& h) noexcept;
};



//Creates the rectangle everything must fit in
lines create_frame(const double width, const double height);

/*

  +---------+
  |\        |
  | \       |
  |  \      |
  |   \     |
  |    \    |
  |     \   |
h |      \  |
  |       \ |
  |        \|
  |       _-*
  |   w _-  |
  |   _-    |
  | _- angle|
  +---------+

*/
/// Create the lines of a nucleotide connection
lines create_nucleotide(
  const double h,
  const double w,
  const double angle
);

lines create_nucleotides(
  const int n_nucleotides,
  const double height,
  const double nucleotide_width,
  const double left_chain_angle_rad,
  const double backbone_margin_mm
);


std::ostream& operator<<(std::ostream& os, const paper_dna_helix& h) noexcept;

#endif // PAPER_DNA_HELIX_H
