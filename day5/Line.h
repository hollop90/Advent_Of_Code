#ifndef UGO_AOC_LINE
#define UGO_AOC_LINE

#include <tuple>
#include <optional>

class Line
{
public:
    using Point = std::pair<int, int>;
    using LineSeg = std::pair<Point, Point>;

    enum Orientation
    {
        horizontal,
        vertical,
        skewed,
    };

    Line(Point p1, Point p2);
    ~Line();

    std::optional<Point> intersects(const Line &_line);
    Point getBegin();
    Point getEnd();
    Orientation orientation();

    bool operator==(const Line& rhs) { 
        if ((begin == rhs.begin) && (end == rhs.end)){
            return 1;
        }
        else {
            return 0;
        }
    }

private:    
    Point   begin;
    Point   end;
    LineSeg segment;
 
    float A_coef;
    float B_coef;
    float C_coef;
};

#endif // UGO_AOC_LINE