/// Assignment: 3
///Author: Daniel Boguslavsky, ID: 207915729
/*
#include <iostream>//using cout cin
#define SIZE 8 //defining max size
void fillarr(int arr[] , int size);//filling the arr function
int equal(int arr1[], int arr2[], int size);//equaling between the two arrays
int main()
{
    int arr1[SIZE];
    int arr2[SIZE];
    std::cout << "Please enter " << SIZE << " integers" << std::endl;
    fillarr(arr1 ,SIZE);//entering a fill array function
    std::cout << "Please enter additional " << SIZE << " integers" << std::endl;
    fillarr(arr2 , SIZE);//entering a fill array function
    std::cout << "There is" << " " << equal(arr1,arr2,SIZE) << " " << "equal index between the two arrays\n";//entering a equal function
    //to equal how much integers are the same
    return 0;
}
void fillarr(int arr[] , int size)//filling the array function
{
    int i;
    for(i = 0;i < size;++i)//for to go over all the size that asked
        std::cin >> arr[i];
}
int equal(int arr1[], int arr2[], int size)
{
    int counter = 0;
    for(int i = 0;i < size;++i)//for so its go over the all integers in the first array
    {
        if(arr1[i] == arr2[i])//equaling the integers between the arrays
        {
            ++counter;//if its found same integers between the arrays count gose up by 1
        }
    }
    return counter;//returning how much equal integers they are
}
*/
/// Assignment: 3
///Author: Daniel Boguslavsky, ID: 207915729
/*
#include <iostream>//using cout cin
#include <cstring>//using strlen
#define SIZE_MAX 21//max string size
#define SPACE ' ' //SPACE define
#define CLEAN_STRING 10//Only 10 places must be cleaned because the maximum number of words that can be 20
//and if I want a length of 10 then it will not receive the next word because it cannot be more than 10
//so that's why I only clean 10 places and not 20 because it affects the running time

int words(char str[],int length);
//searching wanted length and how much words have the wanted length
void clearString (char str[]);
//cleaning string function
using namespace std;
int main() {
    char string[SIZE_MAX] = {};
    int length = 0;
    cout << "please enter a wanted length to search in the string" << endl;
    cin >> length;
    //entering a wanted length to search
    cout << "please enter a string with 20 letters and space in the end" << endl;
    fflush(stdin);
    //buffer clean
    cin.get(string, SIZE_MAX);
    //cin to string
    cout << words(string,length) << " word have " << length << " letters";
    //entering to the function to find how much letters have the asked length
    return 0;
}
int words(char str[],int length)
{
    int i;
    int j = 0;
    int numberofWords = 0;
    char word[SIZE_MAX] = {};//adding another string to fill the words that fill the require length
    for(i = 0; str[i];++i,++j)//Run over all the letters in the original string to find spaces
    {
        word[j] = str[i];//Insert a letter from the original string into the new one
        if(str[i] == SPACE)//waiting when the original string have space to enter the if
        {
            if(strlen(word)-1 == length)//compering the length of the new string to the required length
            {
                cout << "the word " << word << "have " << length << " letters" << endl;//printing the word
                ++numberofWords;
            }
            clearString(word);//entering a cleaning string function
            j = -1;//resting the j interaction to -1 so its goes to the for again and do ++j to 0
        }
    }
    return numberofWords;//returning the number of times the size of the length that required
}
void clearString (char str[])
{
    for(int j = 0;j < CLEAN_STRING;++j)//going all over the array to reset to null
        str[j] = '\0';
}
*/
/// Assignment: 3
///Author: Daniel Boguslavsky, ID: 207915729
///
/*
//sub mean submarine
#include<iostream>
//Array size
#define ROW 10
#define COL 10

#define AVAILABLE_SPACE 1 //place you can put a sub
#define ADD_SPACE 1 //adding more size for the sub
#define EXIT_GAME -1 //exit the game
#define WINNING_GAME_COUNTER 17 //number of x
#define SHIP_SIGN 'S' //sign of a sub on the array
#define FORBIDDEN_SPACE 2//place you cant put a sub
#define HORIZONATAL_SELECTED_RAND 1 //if in the rand the number is 1
#define VERTICAL_SELECTED_RAND 0 //if in the rand the number is 0
#define NUMBER_OF_MUST_BE_SUBS 17//if there is not 17 spaces in the array that have 1 you cant continue
#define OUT_OF_ARRAY 10//if you get a number higher than 9 return false
#define MAX_COORDINAT 9//max array coordinate
#define MIN_COORDINAT 0//min array coordinate
#define EMPTY_SPACE ' '//empty space sigh
#define SUB1 5//sub that fill 5 spaces
#define SUB2 4//sub that fill 4 spaces
#define SUB3 3//sub that fill 3 spaces
#define SUB4 3//sub that fill 3 spaces
#define SUB5 2//sub that fill 2 spaces
void buildTheGame(char[][COL],int ,int);//putting all the subs in the right available places function
int randRowCol();//choosing a random number to select the number of row and column function
void PutSubInAvailableSpace(char [][COL],int,int,int);//choosing the right place to put the sub in the game function
int verticalOrhorizontal();//choosing a random number to select if it will add space vertical or horizontal function
bool CheckAvailableSpaceHorizonatal (char [][COL],int,int,int);//checking horizontali if you can put a sub there function
bool CheckAvailableSpaceVertical (char [][COL],int,int,int);//checking veritcali if you can put a sub there function
bool outOfarray (int,int,int);//checking if the sub is in a row or col above 9 function
void fillUnavaibaleHorizontal (char[][COL],int,int,int);//filling the unavailable spaces horizonatli function
void fillUnavaibaleVertical (char[][COL],int,int,int);//filling the unavailable spaces verticali function
void CorrentGameStatus(char[][COL],int,int);//showing the corrent status of the array function
void ChangeNumbersToSigns (char[][COL],int,int);//changing the signs of 1,2 and 0 to other sign function
void theGame (char[][COL],int,int);//the game to show the array and put coordinates function

int main(){
    srand (time(NULL));
    char theSea[ROW][COL];
    buildTheGame(theSea,ROW,COL);//entering the build the game function
    theGame(theSea,ROW,COL);//entering thegame function
    return 0;
}

void buildTheGame(char array[][COL],int row,int col)
{
        int i, j;
        int rowa = 0;
        int column = 0;
        int counter = 0;
        while (counter != NUMBER_OF_MUST_BE_SUBS)//if the counter goes to 17 it means all the subs are in the right place
        {
            counter = 0;
            //running all over the arr to put 0 in all the spaces
            for (i = 0; i < row; ++i) {
                for (j = 0; j < col; ++j) {
                    array[i][j] = 0;
                }
            }
            PutSubInAvailableSpace(array, SUB1, rowa, column);//entering a function for the sub that takes 5 spaces
            PutSubInAvailableSpace(array, SUB2, rowa, column);//entering a function for the sub that takes 4 spaces
            PutSubInAvailableSpace(array, SUB3, rowa, column);//entering a function for the sub that takes 3 spaces
            PutSubInAvailableSpace(array, SUB4, rowa, column);//entering a function for the sub that takes 3 spaces
            PutSubInAvailableSpace(array, SUB5, rowa, column);//entering a function for the sub that takes 2 spaces
            //running all over the array to find all the 1 sign in the array
            for (i = 0; i < row; ++i) {
                for (j = 0; j < col; ++j) {
                    if (array[i][j] == AVAILABLE_SPACE) {
                        ++counter;
                    }
                }
            }
        }
}
int randRowCol()
{
#define MAX_VALUE 10 //local define
#define MIN_VALUE 0 // local define
    int random;
random = MIN_VALUE + (rand() % (MAX_VALUE - MIN_VALUE));//random number between 0 ~ 9
    return random;
}
void PutSubInAvailableSpace(char arr[][COL],int multi,int row,int col)
{
        int oneorZero;
        bool flag = false;
        bool flag2 = false;
        while (!flag || !flag2) //while out of array true and check available space functions are true
        {
            row = randRowCol();//giving a random number for row between 0 ~ 9
            col = randRowCol();//giving a random number for col between 0 ~ 9
            flag = outOfarray(row, col, multi);//entering the out of array function to give true or false
            oneorZero = verticalOrhorizontal();//giving a random number for horizontal or vertical between 0 ~ 1 to decide if it will add
            //horizontal or vertical
            if (oneorZero == HORIZONATAL_SELECTED_RAND) {
                flag2 = CheckAvailableSpaceHorizonatal(arr, row, col, multi);//giving a true or false to flag2
            } else if (oneorZero == VERTICAL_SELECTED_RAND) {
                flag2 = CheckAvailableSpaceVertical(arr, row, col, multi);//giving a true or false to flag2
            }
        }
        if (oneorZero == HORIZONATAL_SELECTED_RAND) {//if its 1 entering the if
            fillUnavaibaleHorizontal(arr, row, col, multi);//filling the unavailable spaces
            for (int i = 0; i < multi; ++i) {
                arr[row][col += ADD_SPACE] = AVAILABLE_SPACE;//after checking if you can put a sub in those spaces
            }
        } else if (oneorZero == VERTICAL_SELECTED_RAND) {//if its 0 entering the else if
            fillUnavaibaleVertical(arr, row, col, multi);//filling the unavailable spaces
            for (int i = 0; i < multi; ++i) {
                arr[row += ADD_SPACE][col] = AVAILABLE_SPACE;//after checking if you can put a sub in those spaces
            }
        }
}
int verticalOrhorizontal()
{
#define MAX_VALUE 2//local define
#define MIN_VALUE 0//local define
    int random;
    random = MIN_VALUE + (rand() % MAX_VALUE - MIN_VALUE);//random number between 0 ~ 1
    return random;
}
bool CheckAvailableSpaceHorizonatal (char array[][COL],int Row,int Col,int multiSubSize)
{
    for (int i = 0; i < multiSubSize; ++i)
    {
        Col += ADD_SPACE;//adding 1 to check if you hit a unavailable space
        if(array[Row][Col] == FORBIDDEN_SPACE)//if you hit a unavailable space entering the if
        {
            return false;
        }
    }
    return true;
}
bool CheckAvailableSpaceVertical (char array[][COL],int Row,int Col,int multiSubSize)
{
    for (int i = 0; i < multiSubSize; ++i)
    {
        Row += ADD_SPACE;//adding 1 to check if you hit a unavailable space
        if(array[Row][Col] == FORBIDDEN_SPACE)//if you hit a unavailable space entering the if
        {
            return false;
        }
    }
    return true;
}
bool outOfarray (int Row,int Col,int multiSub)
{
    for(int i = 0; i < multiSub; ++i)
    {
        Row += ADD_SPACE;//adding 1 to check if you hit a row equal to 10
        Col += ADD_SPACE;//adding 1 to check if you hit a col equal to 10
        if (Row == OUT_OF_ARRAY || Col == OUT_OF_ARRAY)//if row or col are 10 will give you false
        {
            return false;
        }
    }
    return true;
}
void fillUnavaibaleHorizontal(char array[][COL],int Row,int Col,int multiSubspace)
{
    for(int i = Row-1;i < Row+2;++i)
    {
        for(int j = Col;j < Col + multiSubspace + 2;++j)
        {
            if(array[i][j] == AVAILABLE_SPACE)
            {
                array[i][j] = AVAILABLE_SPACE;//If there is already a submarine then put 1 so that the 2 does not replace it
            }
            else if(array[i][j] == 0 || array[i][j] == FORBIDDEN_SPACE)
            {
                array[i][j] = FORBIDDEN_SPACE;//Put 2 around the submarine so that he knows that it is forbidden to put a submarine there
            }
        }
    }
}
void fillUnavaibaleVertical (char array[][COL],int Row,int Col,int multiSubspace)
{
    for(int i = Row;i < Row + multiSubspace + 2;++i)
    {
        for(int j = Col - 1;j < Col + 2;++j)
        {
            if(array[i][j] == AVAILABLE_SPACE)
            {
                array[i][j] = AVAILABLE_SPACE;//If there is already a submarine then put 1 so that the 2 does not replace it
            }
            else if(array[i][j] == 0 || array[i][j] == FORBIDDEN_SPACE)
            {
                array[i][j] = FORBIDDEN_SPACE;//Put 2 around the submarine so that he knows that it is forbidden to put a submarine there
            }
        }
    }
}
void CorrentGameStatus(char array[][COL],int Row,int Col)
{
    std::cout << "   0" << "  1" << "  2" << "  3" << "  4" << "  5" << "  6" << "  7" << "  8" << "  9\n";//to  know which col you are
    for (int i = 0; i < Row; ++i) {
        std::cout << i << '|';//to  know which row you are
        for (int j = 0; j < Col; ++j) {
            if (array[i][j] == SHIP_SIGN) {//if there is a sub there put a empty space so the player will not know that there is a sub there
                std::cout << "[ " << "]";
            } else
                std::cout << "[" << array[i][j] << "]";//print the the places you not chose
        }
        std::cout << std::endl;
    }
}
void ChangeNumbersToSigns (char array[][COL],int Row,int Col)
{
    for (int i = 0; i < Row; ++i) {
        for (int j = 0; j < Col; ++j) {
            if (array[i][j] == AVAILABLE_SPACE) {//change the sign 1 to S sign
                array[i][j] = SHIP_SIGN;
            }
            if (array[i][j] == FORBIDDEN_SPACE || array[i][j] == 0) {//change the sign 0 and 2 to empty space
                array[i][j] = EMPTY_SPACE;
            }
        }
    }
}
void theGame (char arr[][COL],int row,int col)
{
    int counter = 0;
    ChangeNumbersToSigns(arr,ROW,COL);//entering the change number to sign function
    std::cout << "welcome to the submarine game you must sink all the submarine good luck\n";
    do {
        std::cout<< "please enter coordinates for number of row and than number of col,the number must be between 0 ~ 9\n";
        std::cout << "if you wanna exit the submarine game please press -1 -1\n";
        std::cin >> row;
        std::cin >> col;
            if (row == EXIT_GAME && col == EXIT_GAME) {// if you want to exit the game
                std::cout << "See you next time!";
                break;
            }
            //if you entered a wrong coordinate
            while ((row < MIN_COORDINAT || row > MAX_COORDINAT) || (col < MIN_COORDINAT || col > MAX_COORDINAT)) {
                if (row == EXIT_GAME && col == EXIT_GAME) {
                    std::cout << "See you next time!";
                    break;
                }
                std::cout << "Illegal values, please try again.\n";
                std::cin >> row;
                std::cin >> col;
            }
            if (row == EXIT_GAME && col == EXIT_GAME) {
                break;
            }
            if (arr[row][col] == SHIP_SIGN) {//if you hit a sub change to X
                std::cout << "Hit\n";
                arr[row][col] = 'X';
                ++counter;
            }
            if (arr[row][col] == EMPTY_SPACE) {//if you miss the sub it will show you a sign of the sea
                std::cout << "Miss\n";
                arr[row][col] = '~';
            }
            CorrentGameStatus(arr,ROW,COL);//showing the current game status
        } while (counter != WINNING_GAME_COUNTER);//until you sink all the submarines
        if (counter == WINNING_GAME_COUNTER) {//if the counter is on 17
            std::cout << "Congratulation you win!";
        }
}
*/