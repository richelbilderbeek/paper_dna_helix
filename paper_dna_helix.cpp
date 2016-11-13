#include "paper_dna_helix.h"

#include <cassert>
#include <cmath>
#include <iostream>

template <class T>
void append(std::vector<T>& v, const std::vector<T>& w)
{
  std::copy(std::begin(w), std::end(w), std::back_inserter(v));
}

paper_dna_helix::paper_dna_helix(
  const double left_chain_angle_rad,
  const int n_nucleotides,
  const double nucleotide_width,
  const double backbone_margin_mm
)
  : m_backbone_margin_mm{backbone_margin_mm},
    m_left_chain_angle_rad{left_chain_angle_rad},
    m_lines{},
    m_n_nucleotides{n_nucleotides},
    m_nucleotide_width{nucleotide_width}

{
  assert(m_n_nucleotides > 0);

  m_lines = create_dna_helix();
  assert(m_lines.size() < 1000);
}

std::vector<line> paper_dna_helix::create_dna_helix() const
{
  assert(m_n_nucleotides > 0);
  std::vector<line> v = create_frame(get_width(), get_height());

  //The width of a nucleotide is set to a length of 1 unit

  //Create left backbone
  const std::vector<line> nucleotides{
    create_nucleotides(
      m_n_nucleotides,
      get_height(),
      m_nucleotide_width,
      m_left_chain_angle_rad,
      m_backbone_margin_mm
    )
  };
  append(v, nucleotides);
  return v;
}

lines create_frame(const double w, const double h)
{
  /*

  0 -- 1
  |    |
  |    |
  3----2

  */
  return
  {
    line(0.0, 0.0,   w, 0.0),
    line(  w, 0.0,   w,   h),
    line(  w,   h, 0.0,   h),
    line(0.0,   h, 0.0, 0.0)
  };
}

std::vector<line> create_nucleotide(
  const double h,
  const double w,
  const double angle

)
{
  /*

  C---------+
  |\        |
  | \       |
  |  \      |
  |   \     |
  |    \    |
  |     \   |
h |      \  |
  |       \ |
  |        \|
  |       _-B
  |   w _-  |
  |   _-    |
  | _- angle|
  A---------+
       dx



  */
  const double ax{0.0};
  const double ay{0.0};
  const double bx{ax + (w * std::cos(angle))};
  const double by{ay - (w * std::sin(angle))};
  const double cx{ax};
  const double cy{ay-h};
  return
  {
    line(ax, ay, bx, by),
    line(bx, by, cx, cy),
    line(cx, cy, ax, ay)
  };
}

lines create_nucleotides(
  const int n_nucleotides,
  const double height,
  const double nucleotide_width,
  const double left_chain_angle_rad,
  const double backbone_margin_mm
)
{
  std::vector<line> v;
  const double dy_heart_heart_distance{height / (n_nucleotides + 2)};
  for (int i=0; i!=n_nucleotides; ++i)
  {
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

    lines nucleotide{
      create_nucleotide(
        dy_heart_heart_distance,
        nucleotide_width,
        left_chain_angle_rad
      )
    };
    translate(nucleotide, 0.0, dy_heart_heart_distance * (i + 2));
    append(v, nucleotide);
  }

  //Add backbone
  {
    const double dx{
      (std::cos(left_chain_angle_rad) * nucleotide_width)
      + backbone_margin_mm
    };
    auto backbone = create_frame(dx, height);
    translate(backbone, -backbone_margin_mm / 2.0, 0.0);
    append(v, backbone);
  }
  translate(v, 20.0 , 0.0);
  return v;
}

std::ostream& operator<<(std::ostream& os, const paper_dna_helix& h) noexcept
{
  //Use A4 format
  os << "<svg width=\"" << h.get_width() << "\" height=\"" << h.get_height() << "\" stroke=\"black\" stroke-width=\"1\">\n";
  assert(h.m_lines.size() < 1000);
  for (const auto& line: h.m_lines)
  {
    os << "  <line x1=\"" << line.x1 << "\" y1=\"" << line.y1
      << "\" x2=\"" << line.x2 << "\" y2=\"" << line.y2 << "\" />\n"
    ;
  }
  os << "</svg>";
  return os;
}
