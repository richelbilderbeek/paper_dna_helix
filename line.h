#ifndef LINE_H
#define LINE_H

struct line
{
  line(const double any_x1, const double any_y1, const double any_x2, const double any_y2)
    : x1{any_x1}, y1{any_y1}, x2{any_x2}, y2{any_y2}
  {
  }
  double x1, y1, x2, y2;
};

void translate(line& l, const double dx, const double dy);

#endif // LINE_H
