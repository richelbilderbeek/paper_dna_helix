#ifndef LINES_H
#define LINES_H

#include <vector>
#include "line.h"

using lines = std::vector<line>;

void translate(lines& l, const double dx, const double dy);

#endif // LINE_H
