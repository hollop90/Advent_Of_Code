#include "Line.h"

Line::Line(Line::Point p1, Line::Point p2)
{
    begin   = p1;
    end     = p2;
    segment = {p1, p2};

    A_coef  = end.second - begin.second;
    B_coef  = begin.first - end.first;
    C_coef  = (A_coef * begin.first) + (B_coef * begin.second);
}

Line::~Line()
{
}

Line::Point Line::getBegin()
{
    return begin;
}

Line::Point Line::getEnd()
{
    return end;
}

Line::Orientation Line::orientation()
{
    if (this->begin.first == this->end.first)
    {
        return vertical;
    }
    else if (this->begin.second == this->end.second)
    {
        return horizontal;
    }
    else
    {
        return skewed;
    }
}

/// @brief Determines if two lines intersect and returns the intersection point
/// @param _line 
/// @return An optional Point type
/// @link https://www.topcoder.com/thrive/articles/Geometry%20Concepts%20part%202:%20%20Line%20Intersection%20and%20its%20Applications 
std::optional<Line::Point> Line::intersects(const Line& _line) 
{
    double det = this->A_coef * _line.B_coef - _line.A_coef * this->B_coef;
    if (det == 0) {
        return std::nullopt;
    } else {
        double x = (_line.B_coef * this->C_coef - this->B_coef * _line.C_coef) / det;
        double y = (this->A_coef * _line.C_coef - _line.A_coef * this->C_coef) / det;
        return Point {x, y};
    }    
}
