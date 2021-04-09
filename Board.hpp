
#pragma once
#include <string>
#include <map>

#include "Direction.hpp"
using namespace std;

struct square
{
    char data='_';
};

namespace ariel {

    class Board
    {
    
    private:

        unsigned int m_up, m_down, m_left ,m_right;

        map<unsigned int, map< unsigned int, square > > board;
    
    public:

        Board();

        ~Board();

        void post(unsigned int row, unsigned int column, Direction direction, const string &message);

        std::string read(unsigned int row, unsigned int column, Direction direction, unsigned int  length);

        void show();

        void getLimits() const ;
    };
    
    
    
    
}