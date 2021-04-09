
#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;
using namespace ariel ;

enum {EXIT, POST , READ , SHOW};

int main(int argc, char const *argv[])
{
    int command ;
    unsigned int row , col , direction , length ;
    bool first_post = true;
    string message; 
    Board board;


    cout << "Welcome to the Neighborhood Message Board !!"<<endl ;
    cout << "Since this is the first time you are posting the board is still blank."<< endl;
    cout << "So you can post everywhere on the board."<<endl;
    cout << "But next time some restrictions on the board will be given to you. "<< endl;
    cout << "Please try to respect them."<< endl;
    cout << "ps: you can make an \"overposting\": post on another post. " << endl;
    cout << "Menu :\n post press 1 \n read press 2 \n show press 3 \n exit press 0 \n"<< endl;
    
    cin >> command;


    while (command != 0)
    {
        switch (command)
        {
        case POST :
            if (first_post){
                cout << "\nPosting: \nYou can start to post everywhere: " << endl;
                first_post =false; 
            }
            else{
                cout << "\nPosting : \nThis is the limits, please don't post so far from them: "<< endl;
                board.getLimits();
            }
            
            cout << "\nChoose a row : ";
            cin >> row ; 
            cout << "\nChoose a column : ";
            cin >> col ;
            cout << "\nChoose a direction (Horizontal- 0, Vertical- 1) : ";
            cin >> direction ;
            cout << "\nPlease enter a message to post : (use _ instead space)\n"<< endl ;
            cin >> message ;

            board.post(row, col, (Direction)direction , message); 
            break;
        
        case READ :
            cout << "\nReading: \nChoose a row : ";
            cin >> row ; 
            cout << "\nChoose a column : ";
            cin >> col ;
            cout << "\nChoose a direction (Horizontal- 0, Vertical- 1) : ";
            cin >> direction ;
            cout << "\nChoose the number of characters to read : ";
            cin >> length ;
            cout << "\n" <<board.read(row, col,(Direction)direction , length )<< endl;
            break;

        case SHOW :
            cout << "\nShow :" << endl;
            board.show();
            break;
        default :
            cout << "\nincorrect command :"<< endl;

        }
        cout << "\nMenu :\n post press 1 \n read press 2 \n show press 3 \n exit press 0 \n"<< endl;
        cin >> command;
    }
    
    cout << "Thanks for using the the Neighborhood Message Board! Hope to see you soon :)"<< endl;

    return 0;
}
