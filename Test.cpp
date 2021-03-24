#include "doctest.h"
#include "Board.hpp"
#include <iostream>
#include <ctime>
#include <stdexcept>
#include <string>

using namespace ariel;
using namespace std;

const int TEST_NUMBER= 20;
const int MAX_LENGTH = 200;

TEST_CASE("Creating and Empty Board"){
    Board board;

    for (size_t i = 0; i < TEST_NUMBER; i++)
    {
        unsigned int row = (unsigned int)rand();
        unsigned int columns = (unsigned int) rand();
        Direction direction= (Direction)(rand()%2) ;

        string empty_message(rand()%MAX_LENGTH, '_');

        CHECK(board.read(row,columns, direction, empty_message.length())== empty_message);
    }
    
    
}

TEST_CASE("simple Post and Read"){
        Board board;
        const unsigned int NUM_OF_POST =10;

        for (unsigned int i = 0; i < NUM_OF_POST; i++)
        {   
            string post( to_string(i) + "post on the board");
           
           board.post(i , 0 , Direction::Horizontal , post);
            
           CHECK(board.read(i , 0 , Direction::Horizontal ,post.length() )== post );
 
        }

        unsigned int rand_row = (unsigned int)rand()% NUM_OF_POST;
        string post(to_string(rand_row) + "post on the board");
        CHECK(board.read(rand_row, 0 , Direction::Horizontal ,post.length() )== post);
 
        string numbers ("0123456789");
        CHECK(board.read(0, 0 , Direction::Vertical , NUM_OF_POST)== numbers);

}

TEST_CASE("Overiting Post and Read"){

    Board board ;

    board.post(0,0, Direction::Horizontal,"aaa");
    CHECK(board.read(0, 0 , Direction::Horizontal , 3 )== "aaa");
    CHECK(board.read(0, 0 , Direction::Horizontal , 6 )== "aaa___");

    board.post(0,3, Direction::Horizontal,"bbb");
    CHECK(board.read(0, 0 , Direction::Horizontal , 6 )== "aaabbb");

    board.post(1,0, Direction::Horizontal,"cccccc");
    board.post(2,0, Direction::Horizontal,"dddddd");
    CHECK(board.read(1, 0 , Direction::Horizontal , 6 )== "cccccc");
    CHECK(board.read(2, 0 , Direction::Horizontal , 6 )== "dddddd");

    board.post(0,0, Direction::Vertical,"abcd");
    CHECK(board.read(0, 0 , Direction::Vertical , 4 )== "abcd");
    CHECK(board.read(0, 0 , Direction::Horizontal , 6 )== "aaabbb");
    CHECK(board.read(1, 0 , Direction::Horizontal , 6 )== "bccccc");
    CHECK(board.read(2, 0 , Direction::Horizontal , 6 )== "cddddd");
    CHECK(board.read(3, 0 , Direction::Horizontal , 6 )== "d_____");

    board.post(3,1, Direction::Horizontal,"vwxyz");
    CHECK(board.read(3, 0 , Direction::Horizontal , 6 )== "dvwxyz");
    CHECK(board.read(0, 1 , Direction::Vertical , 6 )== "acdv__");
    CHECK(board.read(0, 5 , Direction::Vertical , 6 )== "bcdz__");



}