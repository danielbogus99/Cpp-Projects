/* authors: Igor Bursov  ID: 327288858
 * authors: Daniel boguslavsky ID: 207915729
 * authors: Sofia tenenbaum ID: 320964026
 *assignmet acaton*/
#include <iostream>//using std::cin,std::cout
#include <fstream>//using to creat file.
#include <chrono>
#include <ctime>
#include <windows.h> // color

enum RESULT { WIN = 9 , LOSS = 10 , EXIT = 11 }; // enum to indicate game mode when it finish.

#define WINNING "WIN"    // define purpose implied in name.
#define LOOS "loss"
#define EXIT_CHAR "Exit"
#define SIZE_FILE 100
#define MINE '*'
#define MIN_BOARD_SIZE 8
#define MIN_MINES_NUM 0.2
#define WHITE 7
#define GREEN 2
#define BLUE 9
#define ORANGE 14
#define RED 4

char** insertfileTobuildBoard(char*,char**,double&,int&,int&); // function creating board.

void fillMinesInBoard(char**,double,int,int); // function to put land mines in board.

void printBoard(char**,int,int); // function to print to user all indexes.

int numberOfMines_around(char**,int,int,int,int); // count number of land mines around the area the user input.

void Game(char**,int,int,int); // checking if the user win/loos/exit.

void deleteAllocGame(char**,int); // function to delete or release pointer.

void log ( const char * ,int & ,int & ,char ); // function to write on file the game move.

int main() // function main from here iam calling to function to work on arr.
{
    srand (time(NULL)); // operator for random numbers.
    char path[SIZE_FILE]; // making a string to take from user the input .
    char**boardGame = NULL; // creat a pointer to make a dynamic board to play on.
    double numberMines = 0; // parameters to take the value from file and save it on tham.
    int row,cols;

    std::cout << "Please enter the path to input row cols and number of mines" << std::endl ; // instruction for user.
    std::cin.getline(path,SIZE_FILE); // taking input from user.
    boardGame = insertfileTobuildBoard(path,boardGame,numberMines,row,cols); // sending parameters to create and fill the board.
    fillMinesInBoard(boardGame,numberMines,row,cols); // sending to fill the empty spaces with mines.
    Game(boardGame,row,cols,numberMines); // the function that play the game unit it ends.
    deleteAllocGame(boardGame,row); // delete pointer to release memory.

    return 0;
}
char**insertfileTobuildBoard(char*file,char**boardGame,double &mines,int&row,int&cols)
{
    std::fstream f; // making a parameter to work on file user game me.
    f.open(file, std::ios::in); // open the file with the path user game me. only read .
    if (!f) //checking if the file is working
    {
        std::cout << "Error opening file in function" << std::endl ;// error message to user.
    }
    while (!f.eof()) // make a loop to go until reach end of file.
    {
        f >> row >> cols >> mines; // taking the file value into a parameters.
    }
    if(row < MIN_BOARD_SIZE) // making an argument if the value taken from file are less than min amount we will fix them manually.
    {
        row = MIN_BOARD_SIZE; // changing the wrong value into min value .
    }
    if(cols< MIN_BOARD_SIZE) // same here but with colum than rows.
    {
        cols = MIN_BOARD_SIZE;
    }
    if((row * cols) * MIN_MINES_NUM > mines) // checking the min value in mines suppose to be 20% from row multiply by columns.
    {
        mines = (int)((row * cols) * MIN_MINES_NUM); // changing value.
    }
    boardGame = new char*[row]; // creat new pointers to work with.
    for(int i = 0;i < row;++i) // making the dynamic board.
    {
        boardGame[i] = new char[cols];
    }
    f.close(); // closing the file path user gave me.
    return boardGame; // return the pointer to main.
}

int numberOfMines_around(char**board,int row,int col,int R,int C) // function check the mines around the index user gave.
{
        int count = 0; // counter to count how many is there around the index.

        for (int i = row - 1; i <= row + 1; i++) // function checking the index around the user input.
        {
            for (int j = col - 1; j <= col + 1; j++)
            {
                if (i >= 0 && i < R && j < C && j >= 0  && board[i][j] == '*') // argument if meet meant there is a land mine.
                {
                    count++;
                }
            }
        }
        return count+48; // return counter with plus 48 to be similar ascii value.
}

void fillMinesInBoard(char**BoardGame,double M,int R,int C) // function fill the empty spaces with '*' indicate mine.
{
    int row = 0 , colum = 0 ; // parameters to work with.
        while ( M != 0 ) // loop will end when value of mines reach end.
        {
            while ( ( colum > C) ||(  row > R ) || BoardGame[row][colum] == '*') // loop will get random number untill argument is meet .
            {
                row = 0 + ( rand () % R ) ; // random row number.
                colum = 0 + ( rand () % C) ; // random colum number.
            }
               BoardGame[row][colum] = '*' ; // place in this index '*' mine.
                --M ; // argument to end loop .
        }
        for(int i = 0;i < R;++i) // loop the change index that are not mines to spaces.
        {
            for(int j = 0;j < C;++j)
            {
                if(BoardGame[i][j] != '*')
                {
                    BoardGame[i][j] = ' ';
                }
            }
        }
}

void printBoard(char**board,int row,int col) // function to print the current index .
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // operator to call color.
    for(int i = 0;i < row;++i) // loop to print all indexes to user base on the last result.
    {
        std::cout << i << "|";
        for(int j = 0;j < col;++j)
        {
            if(board[i][j] == MINE) // argument if the index is mine hide it from uer by print empty space to it.
            {
                   std::cout << "[" <<" " << "]";
            }
            if(board[i][j] == ' ')
            {
                std::cout << "[" << board[i][j] << "]";
            }
            if(board[i][j] != ' ' && board[i][j] != MINE)
            {
                    if(board[i][j] == '0') // argument if the index is '0' change color to green .
                    {
                        SetConsoleTextAttribute(h, GREEN); // print with the color intended.
                        std::cout << "[" << board[i][j] << "]";
                        SetConsoleTextAttribute(h, WHITE);
                    }
                    if(board[i][j] >= '1' && board[i][j] <= '3')
                    {
                        SetConsoleTextAttribute(h, BLUE);
                        std::cout << "[" << board[i][j] << "]";
                        SetConsoleTextAttribute(h, WHITE);
                    }
                    if(board[i][j] >= '4' && board[i][j] <= '6')
                    {
                        SetConsoleTextAttribute(h, ORANGE);
                        std::cout << "[" << board[i][j] << "]";
                        SetConsoleTextAttribute(h, WHITE);
                    }
                    if(board[i][j] >= '7' && board[i][j] <= '8')
                    {
                        SetConsoleTextAttribute(h, RED);
                        std::cout << "[" << board[i][j] << "]";
                        SetConsoleTextAttribute(h, WHITE);
                    }
            }
        }
        std::cout << std::endl; // end line.
    }
}

void Game(char**board,int R,int C,int mines) // function to play.
{
    int counter = 0;
    int row = 0, col = 0;
    std::cout << "hey welcome to the game if you wanna leave please enter not valid coordinates" << std::endl ; // introducing to user.
    do // loop to play will end when user meet the right arguments.
    {
        printBoard(board,R,C); // call to function print.
        std::cout << "please enter coordinates for number of row the number must be between 0 ~ " << R-1 << std::endl; // instruction .
        std::cin >> row; // user input .
        std::cout << "please enter coordinates for number of col the number must be between 0 ~ " << C-1 << std::endl ;
        std::cin >> col; // user input .
        if ((row < 0 || row >= R) || (col < 0 || col >= C)) // argument if the coordinate wrong enter here.
        {
            std::cout << "you entered wrong coordinates goodbye" << std::endl ; // massage to user he did a mistake.
            log ( "log" , row , col , EXIT ) ; // calling function to write this move.
            break; // break from loop.
        }
        while(board[row][col] >= '0' && board[row][col] <= '8') // argument if user did the same coordinates try again.
        {
            std::cout << "you already tired this place please try to enter the coordinates again:" << std::endl ;           // instruction and massage.
            std::cout << "please enter coordinates for number of row the number must be between 0 ~ " << R-1 << std::endl ;
            std::cin >> row;
            std::cout << "please enter coordinates for number of col the number must be between 0 ~ " << C-1 << std::endl ;
            std::cin >> col;
        }
        if(board[row][col] == MINE) // argument if true mean player loss .
        {
            std::cout << "you hit a mine game over" << std::endl ; // massage
            board[row][col] = 'X';
            log ( "log" , row , col , board[row][col] ); // sending the information about the game to write in file log.
            log ( "log" , row , col , LOSS );
            break; // end loop break from it.
        }

        board[row][col] = numberOfMines_around(board,row,col,R,C); // send to check and get back the value .
        log ( "log" , row , col , board[row][col] ) ; // again information all moves are safe on log file.
        ++counter; // rise counter plus one need to end loop.

    } while (counter != (R*C) - mines);

    if ( counter == (R*C) - mines ) // when the argument true player win.
    {
        std::cout << "congrats you won" << std::endl ; // message.
        log ( "log" , row , col , WIN ) ; // save information.
    }
}

void deleteAllocGame(char**board,int size) // delete the pointer to release dynamic memory.
{
    for(int i = size - 1;i <= 0;--i) // release by loop from end to start.
    {
        delete[] board[i];
    }
    delete [] board;
}

void log( const char *file2 , int &R , int &C , char result ) // function is calling a file and save all information of game on it.
{

    auto curr_time = std::chrono::system_clock::now();  // taking the time and date.
    std::time_t c_time = std::chrono::system_clock::to_time_t(curr_time);

    std::fstream f2 ; // pharameter to wotk on the file.
    f2.open (file2 , std::ios::app ) ; // open the file and add to it new lines.
    if ( !file2 ){
        std::cout << "Could not open file!" << std::endl ; // if the file did not open print this.
    }
    else if ( result != LOSS && result != WIN && result != EXIT )  // if argument true enter and write addition line to file.
    {
        f2 << "Row:" << R << "  " << "Colum:" << C << "  " << "  " << "Result:" << result << "  " << "Time & Date:"
           << ctime(&c_time) << std::endl;
    }
    switch ( result ) // swith case to indicate the end of game and what happen on it.
    {
        case LOSS : // case for loos write on file loos.
            f2 << "Game Over!" << "  " << "Result:" << LOOS << std::endl ;
            break ;
        case WIN : // case for win write on file win.
            f2 << "Game Over!" << "  " << "Result:" << WINNING << std::endl ;
            break ;
        case EXIT : // case exit write on file exit.
            f2 << "Game Over!" << "  " << "Result:" << EXIT_CHAR << std::endl ;
            break ;
    }
    f2.close(); // close the file .
}