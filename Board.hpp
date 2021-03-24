
#pragma once
#include <string>
#include <map>

#include "Direction.hpp"
using namespace std;

namespace ariel {

    class Board
    {
    
    public:

        Board(/* args */);

        ~Board();

        void post(unsigned int row, unsigned int column, Direction direction, string message);

        std::string read(unsigned int row, unsigned int column, Direction direction, unsigned int length);

        void show();
    };
    
    
    


}