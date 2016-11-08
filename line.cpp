#include "line.h"

void translate(line& l, const double dx, const double dy)
{
  l.x1 += dx;
  l.x2 += dx;
  l.y1 += dy;
  l.y2 += dy;
}

