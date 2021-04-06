
#include <iostream>
#include <string>
#include <climits>
#include "Board.hpp"
#include <map>

using namespace std;


namespace ariel {

    

    Board::Board()
    {
        this->m_down = this-> m_right= 0;
        this-> m_up = this-> m_left = UINT_MAX;
             
    }
    
    Board::~Board()
    {
    }

    void Board::post (unsigned int row, unsigned int column, Direction direction, const string &message){

        if (direction== Direction::Horizontal)
        {
            this->m_left = min(m_left,column);
            this->m_right = max(m_right, (column+ (unsigned int)message.length()) );
            this->m_up = min(m_up,row);
            this->m_down = max(m_down, row +1);
            
        }
        else{
            this->m_left = min(m_left,column);
            this->m_right = max(m_right, column+1);
            this->m_up = min(m_up,row);
            this->m_down = max(m_down, row +(unsigned int)message.length());
        }
        
        for ( char c : message)
        {
            this->board[row][column].data = c ;
            (direction == Direction::Vertical)? row++ : column++;
        }

    }

    string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int length){
        
        string message;

        for ( int i = 0; i < length; i++)
        {
            message+= this->board[row][column].data;
            (direction == Direction::Vertical)? row++ : column++;
        }
        return message;
    }

    void Board::show(){
        
        if(this->board.empty()){
            cout << "1: ____________\n.\n.\n.\nUNIT_MAX: ____________"<< endl;
        }
        for (unsigned int row = m_up; row <= m_down; row++)
        {
            //cout << "\n" << row << ": ";
            for (unsigned int col = m_left ; col <= m_right; col++)
             {
                cout << board[row][col].data ;
             }
             cout << "\n";
        }
        
    }

}