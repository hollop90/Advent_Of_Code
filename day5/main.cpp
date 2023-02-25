#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <sstream>
#include "Line.h"

// ori::Orientation checkOri(const Line &_line)
// {
//     const auto begin = _line.getBegin();
//     const auto end = _line.getEnd();

//     if (begin.first == end.first)
//         return ori::horizontal;

//     else if (begin.second == end.second)
//         return ori::vertical;

//     else
//         return ori::invalid;
// }

void
update_intersections    (std::vector<Line::Point> &_list,
                         std::vector<Line::Point> _line_a,
                         std::vector<Line::Point> _line_b)
{
    for (auto elem : _line_a)
    {
        auto index = std::find(_line_b.begin(), _line_b.end(), elem);
        if ((index != _line_b.end()) && (std::find(_list.begin(), _list.end(), elem) == _list.end()))
        {
            _list.emplace_back(elem);
        }
    }
}

std::vector<Line::Point> 
get_line_points(Line _line)
{
    Line::Point curr_point = _line.getBegin();
    auto& [x_val, y_val] = curr_point;
    std::vector<Line::Point> ret_list;

    while(curr_point != _line.getEnd())
    {
        ret_list.emplace_back(curr_point);
        if (_line.orientation() == Line::horizontal)
        {
            x_val++;
        }
        else
        {
            y_val++;
        }
    }
    ret_list.emplace_back(curr_point);

    return ret_list;
}

template <typename T>
std::string 
pairToStr(std::pair<T, T> _pair)
{
    std::stringstream out;
    std::string outstr;
    out << "[" << _pair.first << ", " << _pair.second << "]";
    std::getline(out, outstr);

    return outstr;
}

Line::LineSeg 
parseLine(const std::string &_line)
{
    // Example of input line: "0,9 -> 5,9"
    Line::Point begin;
    Line::Point end;
    std::size_t posTrack = 0;
    std::string delim = "->";
    std::string tmp_string;

    tmp_string = _line.substr(0, _line.find(delim));
    begin.first = std::stoi(tmp_string, &posTrack);
    tmp_string = tmp_string.substr(posTrack + 1);
    begin.second = std::stoi(tmp_string);

    tmp_string = _line.substr(_line.find(delim) + delim.length());
    end.first = std::stoi(tmp_string, &posTrack);
    tmp_string = tmp_string.substr(posTrack + 1);
    end.second = std::stoi(tmp_string);

    return Line::LineSeg{begin, end};
}

// List of lines
std::vector<Line> myLines;

int main(void)
{
    const std::string Filename = "../input.txt";
    std::ifstream inFile(Filename);
    
    if (!inFile)
    {
        std::string errMsg = "Failed to open: " + ("\"" + Filename + "\"");
        throw std::runtime_error(errMsg);
    }        

    // Read in all the horizontal and verticals
    std::string inString;
    std::vector<Line> myLines;
    while (!inFile.eof())
    {
        std::getline(inFile, inString);
        std::cout << inString << "\n";
        if (!inString.compare(""))
            break;
        auto [begin, end] = parseLine(inString); // structured bindings ftw!
        if (begin.first == end.first || begin.second == end.second)
            myLines.emplace_back(begin, end);
    }

    // Print out the lines (currently prints too much)
    std::cout << "Lines Read: " << myLines.size() << "\n";
    std::cout << "Line Coords:\n";
    for (auto line : myLines)
    {
        std::cout << "Begin:\t" << pairToStr(line.getBegin()) << "\n";
        std::cout << "End:\t" << pairToStr(line.getEnd()) << "\n";
        std::cout << "Orientation: " << line.orientation() << "\n\n";
    }

    std::vector<Line::Point> intersections; // List of points of intersection

    std::vector<Line::Point> line_a_points; // List of points in lineA
    std::vector<Line::Point> line_b_points; // List of points in lineB

    
    // Fill out a list of points for line_a

    line_a_points = get_line_points(myLines.at(0));
    
    // Fill out a list of points for line_a

    line_b_points = get_line_points(myLines.at(1));

    // Checnk for intersections
    update_intersections    (intersections,
                             line_a_points,
                             line_b_points);


    for (auto elem : myLines)
    {
        
    }
}
