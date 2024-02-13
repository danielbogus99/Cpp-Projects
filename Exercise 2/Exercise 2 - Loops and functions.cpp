/* Assignment: 2
Author: Daniel Bogsulavsky ID: 207915729
 */
#include <cstdlib> //using rand function
#include <iostream> //using std::cout /cin
#include <windows.h> //using SetConsoleTextAttribute function
#define MAX_NUMBER_CHAR '9'//highest digit
#define MIN_NUMBER_CHAR '0' //lowest digit
#define YOUNG_AGE 18 //youngest valid age check
#define OLD_AGE 120 //oldest valid age check
#define BIG_UPPERCASE 'Z' //biggest caps lock letter
#define LOW_UPPERCASE 'A' //lowest caps lock letter
#define BIG_LOWERCASE_LETTER 'z' //biggest letter
#define LOW_LOWERCASE_LETTER 'a' //lowest letter
#define RED_TEXT 4 //windows h changing text color to red
#define ID_MAX_DIGITS 9 // max numbers that you can enter in your id
#define DOT '.'
#define UNDERSCORE '_'
#define STRUDEL '@'
#define SPACE ' '
#define WHITE_OUTPUT 15
//while(getChar() != '\n')means cleaning the buffer
bool nameCheck (char nameCheck); //name check function
bool IdCheck (char IdCheck); //Id check function
bool ageCheck (int ageCheck); //age check function
bool emailCheck (char emailCheck); //email check function
bool creditCheck (char creditCheck); //credit card check function
int payMouth (int payMouth);//pay in mouth check function
char logoSize (int Size);//logo SCE size function
char secondSwitch(char choice);//second switch case function
int waitTime (int waitTime); //waiting time function
char firstSwitch(); //first switch case function
bool upperCase (char upper); //valid uppercase function
bool noupperCase (char noupper);//invalid uppercase function
bool lowerCase (char lower); //valid lowercase function
bool nolowerCase (char nolower);//invalid lowercase function
bool notDigit (char nDigit); //invalid Digit check function
bool DigitCheck (char digit);//valid Digit check function
bool validAge (int age); //valid age check function
bool notvalidAge(int notAge); //invalid age check function
bool notMostlikenumber (int num); //invalid size most like number function
bool validEmailchar (char validEmailchar); //valid email chars that you can enter in your email
bool notvalidEmailchar (char notvalidEmailchar); //invalid email chars that you can enter in your email

int main(){

    char nameValid = 0;
    char ID = 0;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED_TEXT);//text color change function
        std::cout<< "Hey welcome to sce internet company please enter your name (the first letter must be uppercase the other ones need to be lowercase and in the end dot (.))\n";
        //checking valid ID
    nameCheck(nameValid);
    //checking valid ID
    IdCheck(ID);
    std::cout << "Thank you for choosing SCE Internet Company! How can we help you?" << std::endl;
    //entering the first switch case
    firstSwitch();
    return 0;
}

bool nameCheck (char nameCheck)
{
    //entering the nameCheck function
    int counter = 0;
    while (counter != 3)// checking if counter is not 3
    {
            std::cin >> nameCheck;
            if (upperCase(nameCheck))//entering a right uppercase function
            {
                ++counter; //if you did as asked in the name counting 1
            }
            else if (noupperCase(nameCheck))//entering a wrong uppercase function
            {
                counter = 0; //if you didnt enter a uppercase counter goes to 0
            }
        do
        {
            if (counter == 0)
            {
                break;//if you didnt entered a uppercase in the first do while breaking to the last do while
            }
            std::cin >> nameCheck;
            if (lowerCase(nameCheck))//checking if you entered a right lowercase and enter the function
            {
                ++counter;//count goes to 1
            }
            else if (nolowerCase(nameCheck))//entering a invalid lowercase function
            {
                counter = 0;//count goes to 0 and break down to the last do while
                break;
            }
        }while (counter != 2);
        do
        {
            if (counter == 0)// if you didnt enter a uppercase and lowercase entering the statement  say to try again and returning to the first do while
            {
                std::cout << "try again" << std::endl;
                std::cout << "please enter your name" << std::endl;
                break;
            }
            std::cin >> nameCheck;
            if (nameCheck == DOT)//entering if you entered a dot
            {
                ++counter;//count go up  to 3 exiting the first while returning true
            }
            else if (nameCheck != DOT && nolowerCase(nameCheck))//entering a invalid lowercase function and not dot
            {
                counter = 0;//count goes to 0 and break and goes back to the first do while
                while(getchar() != '\n')
                break;
            }
        } while (counter != 3);
        while (getchar() != '\n');
    }
    return true;

}
bool IdCheck (char IdCheck)
{
    int counter = 0;
        std::cout << "Please enter your id: " << std::endl;
        std::cin >> IdCheck;
        //checking if we entered 9 valid digits numbers
        while (counter < ID_MAX_DIGITS)
        {//entering the function if digit is invalid number
        if (notDigit(IdCheck))
            {
                std::cout << "please try again" << std::endl;
                //if you entered wrong digit number restart the counter
                counter = 0;
                //clearing the buffer
                while (getchar() != '\n');
                std::cin >> IdCheck;
            }//entering the function if digit is valid
        if (DigitCheck(IdCheck))
            {//adding a number for the count until 9
            ++counter;
            //checking until the 9 digit so you wouldnt enter a wrong char in the 9 place
            if(counter < ID_MAX_DIGITS)
            {
                std::cin >> IdCheck;
            }
        }

}
return true;
}
bool ageCheck (int ageCheck)
{
    std::cout << "Please enter your age in the range of 18 to 120" << std::endl;
    std::cin >> ageCheck;
    //checking if age is valid
        if (validAge(ageCheck))
        {
            return true;
        }
        //checking if age is invalid
        while (notvalidAge(ageCheck))
        {
            std::cout << "Please enter your age again" << std::endl;
            //buffer restore
            while (getchar() != '\n');
            std::cin >> ageCheck;
        }
}
bool emailCheck (char emailCheck)
{
    int counter = 0;
    std::cout << "Please enter your email\n";
    std::cout << "1.please enter a uppercase or lowercase or dot or underscore\n";
    std::cout << "2.after '1' enter a strudel\n";
    std::cout << "then again as asked in '1'\n";
    std::cout << "and in the end press space and enter\n";

    while (counter != 4)
    {//entering a right email until we enter all the things that been asked after every right thing we will add for the count 1
    do {
        std::cin >> emailCheck;
        if (validEmailchar(emailCheck))//entering a valid email char function
            {
                ++counter;//if you enter a valid email char counter goes up to 1
            }
        else if (notvalidEmailchar(emailCheck))//entering not valid email char function
            {
                std::cout << "try again" << std::endl;
                while (getchar() != '\n')
                counter = 0;//if you entered wrong char counter goes to 0
             }
          } while (counter != 1);
        do
        {
            if (counter == 0)//if you entered wrong email char it will enter to here and break up to the last do while
            {
                break;
            }
            std::cin >> emailCheck;
            if (emailCheck == STRUDEL)//entering strudel check function
            {
                ++counter;//if you entered strudel count go up to 2
            }
            else if (notvalidEmailchar(emailCheck) &&  emailCheck != STRUDEL)//entering not valid email char and not strudel functions
            {
                std::cout << "try again" << std::endl;
                while(getchar() != '\n')
                    counter = 0;//if you entered a wrong char as asked the counter goes to 0
                break;
            }

        }while (counter != 2);
        do
        {
            if (counter == 0)//if you entered wrong email char or not strudel it will enter to here and break up to the last do while
            {
                break;
            }
            emailCheck = getchar();
            if (validEmailchar(emailCheck))//entering a valid email functions
            {
                ++counter;//if you enter a valid email char counter goes up to 3
            }
            else if (notvalidEmailchar(emailCheck))//entering a not valid email char function
            {
                std::cout << "try again" << std::endl;
                while(getchar() != '\n')
                    counter = 0;//if you entered a wrong char as asked the counter goes to 0
                break;
            }
        } while (counter != 3);
        do
        {
            if (counter == 0)//if you entered wrong email char  it will enter to here and break  to the first do while
            {
                break;
            }
            emailCheck = getchar();
            if (emailCheck == SPACE)//entering to space Check function
            {
                ++counter;//if you entered space count go up to 4 exiting the first while and returning true
            }
            else if (notvalidEmailchar(emailCheck) && emailCheck != SPACE)//entering a not valid email char and not space functions
            {
                std::cout << "try again" << std::endl;
                while(getchar() != '\n')
                    counter = 0;//if you entered a wrong email char or wrong space as asked the counter goes to 0
            }
        }while (counter != 4);
    }

}
bool creditCheck (char creditCheck)
{

    int counter = 0;
    std::cout << "Please enter your last 4 numbers in your credit card" << std::endl;
    std::cin >> creditCheck;
//counting the 4 digit number that you must put
    while (counter < 4)
    {//checking if the digit is invalid
        if(notDigit(creditCheck))
        {
            std::cout << "please try again" << std::endl;
            //buffer clean
            while (getchar() != '\n');
            //restoreing the counter if number is invalid
            counter = 0;
            std::cin >> creditCheck;
        }//checking if the digit is valid
        if (DigitCheck(creditCheck))
        {
            ++counter;
            //counting until 4 to give a right credit card check
            if(counter < 4)
            {
                std::cin >> creditCheck;
            }
        }
    }
    return true;
}
int payMouth (int payMouth)
{//rand function taking a random number between 20 to 100
#define MAX_VALUE  100 //local define
#define MIN_VALUE  20//local define
    srand((unsigned) time(NULL));
    payMouth = MIN_VALUE + (rand() % (MAX_VALUE - MIN_VALUE));
    return payMouth;
}
char logoSize (int Size)
{
    std::cout << "Please enter your most like number between 3 to 9" << std::endl;
    std::cin >> Size;
    //checking if the number is invalid size as asked
    while (notMostlikenumber(Size))
    {
        std::cout << "You entered a wrong number" << std::endl;
        //buffer clean
        while (getchar() != '\n');
        std::cin >> Size;
    }
    //printing the size of the s
    for (int i = 0; i < 5 ; ++i)
    {//checking if the for is in the 3 interaction
        if (i == 3)
        {
            for (int j = 1; j < Size; ++j)
            {//printing spaces to put the * in the last place depending on the size number
                std::cout << " ";
                if (j == Size - 1)
                {
                    std::cout << "*";
                }
            }
            std::cout << std::endl;

        }
        if(i == 1)
        {//printing * if the for is in the 1 interaction
                std::cout << "*";
            std::cout << std::endl;
        }
        if(i % 2 == 0)
        {//checking if the interaction is an even number and then printing * depending on the size number
            for (int j = 0; j < Size; ++j)
            {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
    }
}
char secondSwitch(char choice)
{
    enum {PAY_MONTH = 'a' ,MORE_ABOUT,SPEAK_HUMAN ,MAIN_MENU};//local enum
    char creditCard = 0;
    int value = 0;
    int logo = 0;
    char email = 0;
    bool flag = false;
    std::cout << "What information are you after?" << std::endl;
    //if you chose the d option to exit the switch case
    while (!flag)
    {
        std::cout << "a) I would like to know how much I need to pay this month." << std::endl;
        std::cout << "b) I would like to know more about you." << std::endl;
        std::cout << "c) I would like to speak with a real human." << std::endl;
        std::cout << "d) I want to return to the main menu." << std::endl;
        std::cin >> choice;
        switch (choice)
        {//if you chose the pay month option
            case (PAY_MONTH):
            {//checking if you entered a correct last 4 digit number digit
                creditCheck(creditCard);
                //giving you a random pay in a mouth value
                std::cout << payMouth(value) << std::endl;
                //exit the a option case
                break;
            }
            case (MORE_ABOUT)://b option switch case
            {//entering a logo size function
                std::cout << logoSize (logo) << std::endl;
                std::cout << "SCE Internet Company is a growing internet service company located in Israel.\n"
                             "More details can be found in our website." << std::endl;
                break;
            }
            case (SPEAK_HUMAN):
            {//c option on the swtich case
                std::cout << "representative is currently unavailable please leave an email address so that a service representative will contact you as soon as possible.\n";
                //entering a valid email function
                emailCheck(email);
                std::cout << "We will contact you in the next 48 hours.\n";
                break;
            }
            case (MAIN_MENU):
            {//exit the switch case
                flag = true;
            }
        }

    }
}
int waitTime (int waitTime)
{//rand function random value
#define MAX_VALUE  168 //local define
#define MIN_VALUE  72 //local define
    srand((unsigned) time(NULL));
    waitTime = MIN_VALUE + (rand() % (MAX_VALUE - MIN_VALUE));
    return waitTime;
}
char firstSwitch()
{
    enum {JOIN_COMPANY = '1' ,DETAILS_ACCOUNT,LEAVE_COMPANY ,EXIT_CHAT}; // local enum
    int counter = 1;
    char choice = 0;
    char name = 0;
    char ID = 0;
    int age = 0;
    char email = 0;
    char creditCard = 0;
    char logo = 0;
    char secondSwitchB = 0;
    int waitTimes = 0;
    while (name != true && ID != true && counter != 4)//checking if you entered a right id and right name and checking if counter is not 4
    {
        std::cout << "1) I want to join your company as a new client." << std::endl;
        std::cout << "2) I want to find out some details about my already existing account." << std::endl;
        std::cout << "3) I want to leave your company." << std::endl;
        std::cout << "4) I want to exit the chat." << std::endl;
        std::cin >> choice;
        if (choice != JOIN_COMPANY && choice != DETAILS_ACCOUNT && choice != LEAVE_COMPANY && choice != EXIT_CHAT)//if you chose a wrong number to enter the switch case
        {//counting the times you entered a wrong number
            std::cout << "An illegal option! This is the " << counter << " time you chose an illegal option."<< std::endl;
            while (getchar() != '\n');
            ++counter;
            if (counter == 4)
            {//if you entered 3 times a wrong number as asked
                std::cout << "Please come back only when you need something. Have a good day!" << std::endl;
                //exiting the case and exiting the code
                break;
            }
            std::cout << "please retry" << std::endl;
        }
        switch (choice)
        {
            case (JOIN_COMPANY)://1 option in the switch case
            {
                std::cout<< "please enter your surname (the first letter must be uppercase the other ones need to be lowercase and in the end dot (.))\n";
                //entering right surname function
                nameCheck(name);
                //entering right age function
                ageCheck(age);
                //entering right email function
                emailCheck(email);
                //entering right last 4 digit of your credit card
                creditCheck(creditCard);
                std::cout << "Thank you for choosing our company and welcome! Our people will contact you shortly!\n";
                break;
            }
            case (DETAILS_ACCOUNT)://if you chose the 2 option in the switch case
            {//entering the second switch case
                secondSwitch(secondSwitchB);
                break;
            }
            case (LEAVE_COMPANY):
            {
                std::cout<< "You Must speak to a service representative, and there is not one available at the moment \n"
                            "Enter an email address so that we can return to it.\n";
                //entering right email function
                emailCheck(email);
                std::cout << "We are sorry to hear you are unhappy. We will contact you in the next" << " "<< waitTime(waitTimes) << " " << "hours.\n";
                break;
            }
            case (EXIT_CHAT)://exit the code
            {//entering a size logo function
                std::cout << logoSize(logo);
                std::cout << "Have a great day & see you soon!\n";
                counter = 4;
            }

        }
    }
}
bool upperCase (char upper)
{//checking if you entered a right uppercase
    if (upper >= LOW_UPPERCASE && upper <= BIG_UPPERCASE)
    {
        return true;
    }
    return false;
}
bool noupperCase (char noupper)
{//checking if you entered a wrong uppercase
    if(noupper < LOW_UPPERCASE || noupper > BIG_UPPERCASE)
    {
        return true;
    }
    return false;
}
bool lowerCase (char lower)
{//checking if you entered a right lowercase
    if (lower >= LOW_LOWERCASE_LETTER && lower <= BIG_LOWERCASE_LETTER)
    {
        return true;
    }
    return false;
}
bool nolowerCase (char nolower)
{//checking if you entered a wrong uppercase
    if (nolower < LOW_LOWERCASE_LETTER || nolower > BIG_LOWERCASE_LETTER)
    {
        return true;
    }
    return false;
}
bool notDigit (char nDigit)
{//checking if you entered a wrong digit
    if (nDigit < MIN_NUMBER_CHAR || nDigit > MAX_NUMBER_CHAR)
    {
        return true;
    }
    return false;
}
bool DigitCheck (char digit)
{//checking if you entered a right digit number
    if (digit >= MIN_NUMBER_CHAR && digit <= MAX_NUMBER_CHAR)
    {
        return true;
    }
    return false;
}
bool validAge (int age)
{//checking if you entered a right age that stand in the range
    if(age >= YOUNG_AGE && age <= OLD_AGE)
    {
        return true;
    }
    return false;
}
bool notvalidAge(int notAge)
{//checking if you entered a wrong age between the asked range
  if(notAge < YOUNG_AGE || notAge > OLD_AGE)
  {
     return true;
  }
     return false;
}
bool notMostlikenumber (int num)
{//checking if you entered a wrong number that is not in the range that asked
    if(num < 3 || num > 9)
    {
        return true;
    }
    return false;
}
bool validEmailchar (char validEmailchar)
{//entering valid email char
    if(upperCase(validEmailchar) || lowerCase(validEmailchar) || validEmailchar == DOT || DigitCheck(validEmailchar) || validEmailchar == UNDERSCORE || DigitCheck(validEmailchar))
    {
        return true;
    }
    return false;
}
bool notvalidEmailchar (char notvalidEmailchar)
{//not valid email char
    if(noupperCase(notvalidEmailchar) && nolowerCase(notvalidEmailchar) &&  notDigit(notvalidEmailchar) && notvalidEmailchar != UNDERSCORE && notvalidEmailchar != '.')
    {
        return true;
    }
    return false;
}