/* Assignment: 4
Author: Daniel Boguslavsky, ID: 207915729
*/
#include <iostream>
#include <cstring>
#define WORD_MAX_SIZE 80 //max word size
#define DEFINITION_MAX_SIZE 200 //max definition size
#define DEFINITION_WORD_ARRAY 2 //define,word array
#define FIRST_LETTER 0 //first letter of a word
#define SPACE ' ' //space
#define WORD 0 //the place of a word in the dictionary
#define DEFINITION 1 //the place of a definition in the dictionary
#define EXIT 5 //exit the dictionary
#define DOT '.' //dot
#define START_POINT 0
void dictionaryMake();//the making of the dictionary function
void Rules();
char* allocString(char*);//allocating to dictionary function
void wordDefinitionCorrectSpelling(char*,int,int);//correcting the word and definition function
void sortDictionaryLexicographic(char***dict,int,int);//sorting the dictionary lexicographic
int separation (char***,int,int);//separating the dictionary words
void SwapRows (char***,int,int);//swaps rows lexicographic function
void removeDuplicates(char***,int);//removing duplicate words
char*** creatNewDictionary(char***,int,char***,int&);//putting a new dictionary without the duplicate words function
void dictSearch(char***,int);//search a word in the dictionary
void freeDict(char***,int); //releasing the dynamic memory allocation function

int main() {
    Rules();
    dictionaryMake();

    return 0;
}
void dictionaryMake() {
    char ***dictionary = nullptr, word[WORD_MAX_SIZE], definition[DEFINITION_MAX_SIZE], ***newDictionary = nullptr;
    int i, j, size;
    int sizeNewDict = 0;
    std::cout << "please enter a size of the dictionary" << std::endl;
    std::cin >> size;
    dictionary = new char **[size];//allocate memory char**, size of words
    for (i = 0; i < size; ++i) {
        dictionary[i] = new char *[DEFINITION_WORD_ARRAY];//array for word and definition
        for (j = 0; j < DEFINITION_WORD_ARRAY; ++j) {
            if (j == WORD) {
                std::cout << "please enter a word you want to define for the " << "[" << i + 1 << "]" << " word\n";
                fflush(stdin);//buffer clean
                std::cin >> word;
                wordDefinitionCorrectSpelling(word, strlen(word) + 1,START_POINT);
                dictionary[i][j] = allocString(word);
            }
            if (j == DEFINITION) {
                std::cout << "please enter a definitions to the word " << "[" << dictionary[i][WORD] << "]"<< std::endl;
                fflush(stdin);
                std::cin.getline(definition, DEFINITION_MAX_SIZE);
                wordDefinitionCorrectSpelling(definition, strlen((definition) + 1),START_POINT);
                dictionary[i][j] = allocString(definition);
            }
        }
    }
    removeDuplicates(dictionary, size);
    newDictionary = creatNewDictionary(dictionary, size, newDictionary, sizeNewDict);
    sortDictionaryLexicographic(newDictionary,START_POINT,sizeNewDict-1);
    freeDict(dictionary, size);
    dictSearch(newDictionary,sizeNewDict);
    freeDict(newDictionary,sizeNewDict);
}
char* allocString(char* source) {
    char* str = new char[strlen(source)+1];
    strcpy(str, source);
    return str;
}
/* WORD DEFINITION CORRECTION FUNCTION */
void wordDefinitionCorrectSpelling(char*str,int size,int i)
{
    if(i < size+1) {
        if (str[i] >= 'A' && str[i] <= 'Z')//check for lowercase in string changing to uppercase
        {
            str[i] += 'a' - 'A';
        }
        if (str[FIRST_LETTER] >= 'a' && str[FIRST_LETTER] <= 'z')//check for uppercase in string changing to lower
        {
            str[FIRST_LETTER] -= 'a' - 'A';
        }
        if (str[i - 1] == SPACE && str[i - 2] == DOT) {//check definition dot than space and then change to uppercase
            if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] -= 'a' - 'A';
            }
        }
        //bonus
        wordDefinitionCorrectSpelling(str,size,i+1);
    }

}
/* SORTING FUNCTION*/
void sortDictionaryLexicographic(char***dict,int pivot,int right){
    if (pivot < right)//SORTING WITH QUICK SORT!!!!
    {
        int q = separation(dict, pivot, right);
        sortDictionaryLexicographic(dict, pivot, q-1);
        sortDictionaryLexicographic(dict, q+1, right);
    }
}
/* Separation DICTIONARY WORDS FUNCTION*/
int separation (char***dict,int pivot,int right){
    int i = pivot - 1;
    for (int j = pivot;j <= right - 1;j++)
    {
        if (strcmp (dict[j][WORD], dict[right][WORD]) <= 0)//comparing words
        {
            i++;
            SwapRows(dict,i,j);
        }
    }
    SwapRows(dict, i+1, right);
    return i+1;
}
/* SWAPS ROWS FUNCTION*/
void SwapRows (char***dict,int i,int j){
    char ** temp = dict[i];
    dict[i] = dict[j];
    dict[j] = temp;
}
/* REMOVE DUPLICATES WITH PUTTING NULL ON THEM FUNCTION*/
void removeDuplicates(char***dict,int size)
{
    int j,i;
    for (i = 0; i < size; ++i)
    {
        for(j = 0; j < size;++j)
        {
            if(i == j)
            {
                break;
            }
            if (strcmp(dict[i][WORD], dict[j][WORD]) == 0)
            {//putting null on equal words, so I can see what is the equal words to separate in the new dictionary
                *dict[i][WORD] ='\0';
                *dict[i][DEFINITION] ='\0';
            }
        }
    }
}
/* dictionary search FUNCTION*/
void dictSearch(char***dict,int sizeDict)
{
    int i;
    char searchWord[WORD_MAX_SIZE];
    char exitDictionary[EXIT] = {'E','x','i','t','\0'};
    std::cout << "please enter a word you want to search on the dictionary,if you want to exit the dictionary write 'e'x'i't'" << std::endl;
    std::cin >> searchWord;
    fflush(stdin);//buffer clean
    wordDefinitionCorrectSpelling(searchWord, strlen((searchWord)+1),START_POINT);//fix word, so you can find the word even if you enter a word in the first letter lowercase
    for(i = 0;i < sizeDict;++i)
    {
        if (strcmp(searchWord, dict[i][WORD]) == 0)//if search word is equal to a word in the dictionary
        {
            std::cout << dict[i][WORD] << " - " << dict[i][DEFINITION] << std::endl;//finding a word that really equal
            strcpy(searchWord,exitDictionary);//copying the search word to exit so if you enter exit it will always return to exit
            dictSearch(dict,sizeDict);
        }
    }
    if (strcmp(searchWord, exitDictionary) == 0)//statement if search word equal to exit
    {
        return;
    }
    std::cout << "unknown word" << std::endl;//if the word you entered is unknown in the dictionary
    dictSearch(dict,sizeDict);
}
/* FREE DICTIONARY FUNCTION */
void freeDict(char***dict,int sizeDict)
{//freeing memory allocated.
    for (int i = sizeDict-1; i >=0; i--)
    {
        for ( int j = 1; j >= 0; j--)
        {
            delete [] dict[i][j];
        }
        delete [] dict[i];
    }
    delete [] dict;
}
/* NEW DICTIONARY WITHOUT THE DUPLICATES FUNCTION */
char ***creatNewDictionary(char***dict,int size,char***newDict,int&sizeNewDict)
{
    int i,j,k;
    for(i = 0;i < size;++i)
    {
        if(*dict[i][WORD] >= '!' && *dict[i][WORD] <= '~')//after changing the equal words to null ,statement showing the size of the not removed words
            ++sizeNewDict;
    }
    newDict = new char **[sizeNewDict];//allocate memory char** of the new dictionary, size of words
    i = 0;
    while (i < sizeNewDict)//ends if you run all over the new chars allocate memory
    {
        for (k = 0; k < size; ++k)
        {
            if (*dict[k][WORD] >= '!' && *dict[k][WORD] <= '~')//statement enters only if the word is not on null
            {
                newDict[i] = new char *[DEFINITION_WORD_ARRAY];//array for word and definition
                for (j = 0; j < DEFINITION_WORD_ARRAY; ++j)
                {
                    if (j == WORD)
                    {
                        newDict[i][j] = allocString(dict[k][WORD]);
                    }
                    if (j == DEFINITION)
                    {
                        newDict[i][j] = allocString(dict[k][DEFINITION]);
                    }
                }
                *dict[k][WORD] ='\0';
                break;
            }
        }
        ++i;
    }
    return  newDict;
}
void Rules()
{
    std::cout << "Welcome to dictionary creat\n";
    std::cout << "RULES:\n";
    std::cout <<"1. First you declare how many words you want to enter to the dictionary.\n";
    std::cout <<"2. Second you enter a word you want to define.\n";
    std::cout <<"3. Now you define the word you entered\n";
    std::cout <<"4. When precess of declaration finished you enter to search \n";
    std::cout <<"   Enter a word,see what its definition\n";
    std::cout <<"5. Type exit to exit the dictionary \n\n";
}