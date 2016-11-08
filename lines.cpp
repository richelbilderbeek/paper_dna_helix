#include "lines.h"

void translate(lines& any_lines, const double dx, const double dy)
{
  for (auto& this_line: any_lines)
  {
    translate(this_line, dx, dy);
  }
}


