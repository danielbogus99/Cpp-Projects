/* Assignment: 5
Author: Daniel Boguslavsky, ID: 207915729
*/
#include <iostream>//using std::cin,std::cout
#include <cstring>//using strcmp and get-line
#include <fstream>//using ios in and binary
#define START_POINT 0 //base of the recursive function
#define SIZE_STR 30 //string size
#define CHANGE_CHAR '0' //changing the open and close bracket to 0
#define OPEN_BRACKET '(' //opening the brackets
#define CLOSE_BRACKET ')' //close the brackets
#define CHANGE_UPPERCASE '32'
void insertCharArr(char*,int);
int num_of_neg(int*,int,int,int); //function to check how much negative numbers they are in the array
int num_of_odd_digits(int,int);//finding the odd digits in the number function
bool equal_strings(char*,char*,int);//true or false if the strings are equal function
void insertIntArr(int*,int);//inserting the array function
void differentials(int*,int,int);//calculating the differential of the index minus the next index function
void balance_parenthesis(char*);//balanced parenthesis function
bool parenthesis_balance_helper (char*,int,int);//checking if the file has parenthesis that are balanced function
int main(){
    //BALANCE PARENTHESIS//
    char path[SIZE_STR];
    std::cout << "please enter the path to see if the parenthesis are balanced\n";
    std::cin.getline(path,SIZE_STR);
    balance_parenthesis(path);
    fflush(stdin);
    //////////////////////////////////////////////////////////////////////////////////////////
    //DECLARATIONS//
    int size;
    int i = 0,counter = 0;
    int num;
    char *str1,*str2;
    //////////////////////////////////////////////////////////////////////////////////////////
    //NUMBER OF NEGATIVE DIGITS IN THE ARRAY//
    std::cout << "please enter a size for the array for the function num of negative\n";
    std::cin >> size;
    int *arr = new int[size];
    insertIntArr(arr,size);
    std::cout << "the number of negative numbers are " << num_of_neg(arr,size,counter,i)<<"\n";
    getchar();
    //////////////////////////////////////////////////////////////////////////////////////////
    //NUMBER OF DIGIT THAT THEY ARE ODD IN THE NUMBER//
    std::cout << "please enter a number to see how much odd numbers there are in the number\n";
    counter = 0;
    std::cin >> num;
    std::cout << "There are " <<num_of_odd_digits(num,counter) << " odd digits in the number"<< std::endl;
    fflush(stdin);
    //////////////////////////////////////////////////////////////////////////////////////////
    //CHECKING IF THE STRINGS ARE EQUAL//
    int size_Str1;
    int size_Str2;
    std::cout << "please enter size of the first string for equal strings function\n";
    std::cin >> size_Str1;
    std::cout << "please enter size of the second string\n";
    std::cin >> size_Str2;
    str1 = new char[size_Str1];
    insertCharArr(str1,size_Str1);
    fflush(stdin);
    str2 = new char[size_Str2];
    insertCharArr(str2,size_Str2);
    fflush(stdin);
    std::cout << equal_strings(str1,str2,START_POINT) << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    //DIFFERENTIALS OF THE NUMBERS IN THE ARRAY//
    std::cout << "please enter a size for the array for the function differentials\n";
    std::cin >> size;
    int *array = new int[size];
    insertIntArr(array,size);
    differentials(array,size,START_POINT);
    //////////////////////////////////////////////////////////////////////////////////////////
    //DELETING DYNAMICS ALLOCATES//
    delete [] str1;
    delete [] str2;
    delete [] array;
    delete [] arr;
    return 0;
}
//balance_parenthesis function//
void balance_parenthesis(char*file)
{
    char*string = NULL;
    std::fstream f;
    f.open(file, std::ios::in);
    if (!f) {//checking if the file is working
        std::cout << "Error opening file in function \n";
        return;
    }
    //checking size of file to enter the size to the string dynamic
    std::ifstream in_file(file, std::ios::binary);//finding size of the file
    in_file.seekg(0, std::ios::end);
    int file_size = in_file.tellg();
    string = new char[file_size];//allocate the size to a new string
    f >> string;//copying the file to the string
    if(parenthesis_balance_helper(string,file_size,START_POINT) == 1)//checking if the file has balanced parenthesis
    {
        std::cout << "True the parenthesis are balanced\n";
    }
    else
        std::cout << "false the parenthesis are not balanced\n";
    delete [] string;
    in_file.close();//closing the binary file
    f.close();//closing the file
}
void insertCharArr(char*string,int size)
{//inserting a char array function
    std::cout << "please enter a string with " << size << " chars\n";
    for(int i = 0;i < size;++i)
        std::cin >> string[i];
}
//inserting the array function//
void insertIntArr(int*array,int size)
{
    std::cout << "please enter " << size << " numbers\n";
    for(int i = 0;i < size;++i)
        std::cin >> array[i];
}
//number of negative numbers function//
int num_of_neg(int *array,int size,int counter,int i)
{
    if(i >= size)//the base of the recursive
    {
        return counter;
    }
    if(array[i] < 0)//statement if the number is negative
    {
        ++counter;
    }
    num_of_neg(array,size,counter,i+1);//recursive with the step i plus one
}
//number of digits that they are odd function//
int num_of_odd_digits(int number,int counter)
{
    if(number == 0)//if the number that entered is 0
    {
        return counter;
    }
    if (number % 2 != 0)//statement if the number is odd
    {
        num_of_odd_digits(number / 10,counter+1);//entering a recursive step
    }
    else
        num_of_odd_digits(number / 10,counter);//entering a recursive step
}
//checking if the strings are equal function//
bool equal_strings(char*string1,char*string2,int i)
{
    for(int j = 0;j < strlen(string1);++j)//not counting if uppercase or lowercase they have the same value
    {
        if(string1[j] >= 'A' && string1[j] <= 'Z')
        {
            string1[j] += CHANGE_UPPERCASE;
        }
    }
    for(int k = 0;k < strlen(string2);++k)
    {
        if(string2[k] >= 'A' && string2[k] <= 'Z')
        {
            string2[k] += CHANGE_UPPERCASE;
        }
    }
    while(i < strlen(string1) || i < strlen(string2))
    {
        equal_strings(string1,string2,i+1);//getting to the end
        if (strcmp(string1,string2) == 0)//checking if the strings are equal
        {
            return true;
        }
        else
            return false;
    }
}
//differentials in the array function//
void differentials(int*array,int size,int i)
{
    if(i + 1 == size)//the base so you will not enter a not allowed address
        return;
    std::cout << array[i] - array [i + 1] << std::endl;//the index minus the next index
    differentials(array,size,i + 1);
}
//checking if the parenthesis are balanced function//
bool parenthesis_balance_helper (char*str,int size,int i)
{
    int counter = 0;
    bool flag;
    if(*str == CLOSE_BRACKET)//false if the string have no parenthesis or the first parenthesis is close bracket
    {
        return false;
    }
    for(int k = 0;k < size;++k)//counting the number of chars that are not parenthesis
    {
        if(str[k] == CHANGE_CHAR)
        {
            ++counter;
        }
    }
    if(counter == size)//statement true if all the string have no brackets
    {
        return true;
    }
    for(int j = i;j < size;++j)//checking if the open bracket has is closing brackets if yes changing to 0
    {
        if(str[i] == CHANGE_CHAR)//statement if the index is change char go throw it
        {
            ++i;
        }
        if(str[i] == OPEN_BRACKET && str[j] == CLOSE_BRACKET)//statement if the open bracket has its own close bracket
        {
            str[i] = CHANGE_CHAR;
            str[j] = CHANGE_CHAR;
            flag = parenthesis_balance_helper(str,size,i+1);//entering the recursive with a step
            if(flag)
            {
                return true;
            }
            else
                return false;
        }
    }
    return false;//return false if the open bracket didnt find is closing bracket
}