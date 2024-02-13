/* Assignment: 1
Author: Daniel boguslavsky, ID: 207915729
*/
/*
#include <iostream> // using std::cin std::cout
#define JUMP_LETTER 32 //conversion between caps lock letter to not caps lock letter
#define BIG_LETTER 'Z' //biggest caps lock letter
#define LOW_LETTER 'A' //lowest caps lock letter
#define BIG_LITTLE_LETTER 'z' //biggest letter
#define LOW_LITTLE_LETTER 'a' //lowest letter
#define LOW_4DIGIT 1000 //lowest 4 digit numbers
#define BIG_4DIGIT 9999 //biggest 4 digit numbers
#define BIG_1DIGIT 9 //biggest 1 digit number
#define LOW_1DIGIT 0 //lowest 1 digit number
#define FAILED_TEST 56 //the failed test under 56
enum {CASE_CHANGE_CODE = 1 ,DIGIT_SEARCH_CODE,FAILED_CHECK_CODE};
int main() {

    int choice = 0;

    std::cout << "Please chose a number between 1-3: " << std::endl;//choosing between 3 cases:
    // the first is case change code conversion of caps lock letter to not caps lock letter or other char the same char
//  the second choice is a Digit search code that showing you the number of times that a digit shown in a 4digit number
    // the third choice is Failed check code that showing you the average of 3 tests and if 3 of the test are under 56 than it will show failed
    std::cin >> choice;

    //chose a number between 1 to 3 for entering the switch

    switch (choice)
    {
        case (CASE_CHANGE_CODE)://the first case
        {
            std::cout << "you entered a case change code" << std::endl; //enter a char
            char ch = 0;

            std::cout << "Please enter a char: " << std::endl;
            std::cin >> ch;

            if (ch >= LOW_LITTLE_LETTER && ch <= BIG_LITTLE_LETTER) //conversion from Caps lock letter to non caps lock letter
            {
                ch = (char) (ch - JUMP_LETTER); //the result
            }
            else if (ch >= LOW_LETTER && ch <= BIG_LETTER) //conversion from non caps lock letter to caps lock letter
            {
                ch = (char) (ch + JUMP_LETTER); //the result
            }
            else
                ch = (char) (ch); // leaving the char without change
            std::cout << ch << std::endl;//the result
            break;
        }
        case (DIGIT_SEARCH_CODE): //the second code
        {
            std::cout << "You entered a Digit search code" << std::endl;

            int num = 0;
            int digit = 0;
            int counter = 0;

            std::cout << "Please enter a 4 digit number: " << std::endl;
            std::cin >> num;

            std::cout << "Please enter a 1 digit number: " << std::endl;
            std::cin >> digit;

            if ((num >= LOW_4DIGIT && num <= BIG_4DIGIT) && (digit >= LOW_1DIGIT && digit <= BIG_1DIGIT)) //range of number you can chose
            {

                if (digit == (num / 1000) % 10) //the 4 digit
                {
                ++counter; // counting the times the digit a appeared
                }
                if (digit == (num / 100) % 10) //the 3 digit
                {
                ++counter; // counting the times the digit a appeared
                }
                if (digit == (num / 10) % 10) // the 2 digit
                {
                ++counter; // counting the times the digit a appeared
                }
                if (digit == (num / 1) % 10) // the 1 digit
                {
                ++counter; // counting the times the digit a appeared
                }
                std::cout << digit << " " << "appears" << " " << counter << " " << "time in" << " " << num << std::endl;
            }
            if (digit > BIG_1DIGIT || digit < LOW_1DIGIT) // not in range
            {
                std::cout << "Error:" << digit << " " << "is not a digit" << std::endl;
            }
            if (num > BIG_4DIGIT || num < LOW_4DIGIT) // not in range
            {
                std::cout << "Error:" << num << " " << "is not a number in the right range" << std::endl;
            }
            break;
        }
        case (FAILED_CHECK_CODE): // the third choice
        {
            std::cout << "You entered a Failed check code: " << std::endl;

            int test1 = 0; //entering the first test
            int test2 = 0;  //second test
            int test3 = 0; //third test
            double sum = 0.0; //sum of the test
            int counter = 0; //counting number of test that pass 56

            std::cout << "Please enter the grade of the first test: " << std::endl;
            std::cin >> test1;

            std::cout << "Please enter the grade of the second test: " << std::endl;
            std::cin >> test2;

            std::cout << "Please enter the grade of the third test: " << std::endl;
            std::cin >> test3;

            if (test1 < FAILED_TEST && test3 < FAILED_TEST && test2 < FAILED_TEST) //if all the test did not pass
            {
                std::cout << "failed" <<std::endl;
            }
            if (test1 >= FAILED_TEST ) //if the 1 test pass
            {
                sum += test1;
                ++counter;
            }
            if (test2 >= FAILED_TEST) //if the 2 test pass
            {
                sum += test2;
                ++counter;
            }
            if (test3 >= FAILED_TEST) //if the 3 test pass
            {
                sum += test3;
                ++counter;
            }
            std::cout << "The average is: " << (double)(sum / counter); //doing an average calculation
        }
            break;
        default:(std::cout << "unsupported operation" << std::endl);//not choosing a number in between 1 to 3
    }
    return 0;
}

*/
/* Assignment: 2
Author: Daniel Boguslavsky, ID: 207915729
*/

/*
#include <iostream> // using std::cin std::cout
#define BIGGEST_5DIGIT_NUM 99999 //biggest 5digit number
#define LOWEST_5DIGIT_NUM 10000 //lowest 5digit number
enum {ARITHMETIC_PROGRESSION = 1 ,PALINDROME_CODE};
int main() {

    int choice = 0; //a variable for the switch

    std::cout << "Please chose a number between 1-2: " << std::endl;  //choice between option 1 and option 2
 // in the first option you will entered a arithmetic progression code in this code you will put 5 number that will so you if it a arithmetic progression between them
 // in the second option you will entered a palindrome code in this code you will put 5 digit number and that will be verifying that the number you entered will be palindrome
    std::cin >> choice; //the variable vocabulary

        switch (choice) //start of the switch
        {
            case (ARITHMETIC_PROGRESSION)://the first case
            {
                int num1 , num2 , num3 , num4 , num5 = 0;


                std::cout << "You entered a Arithmetic progression code" << std::endl; //welcoming you to the code

                std::cout << "Please enter 5 numbers: " << std::endl; //putting the first number and then the second until the fifth
                std::cin >> num1 >> num2 >> num3 >> num4 >> num5;


                if (num1 - num2 == num2 - num3 && num2 - num3 == num3 - num4 && num3 - num4 == num4 - num5) //doing a sub between 2 numbers and if they similer to the sub of the other numbers
                {
                    std::cout << "This is an arithmetic series." << std::endl; //verifying the aritmetic series
                }
                break;
            }
            case (PALINDROME_CODE): // the second case
            {
                std::cout << "You entered a palindrome code" << std::endl; // welcoming you to the palindrome code

                int digit5_num = 0; //variable of the digit 5 number

                std::cout << "Please enter a 5 digit number: " << std::endl; //entering 5 digit number
                std::cin >> digit5_num;

                if (digit5_num < LOWEST_5DIGIT_NUM || digit5_num > BIGGEST_5DIGIT_NUM) //if the digit 5 number is not 5 digit number
                {
                    std::cout << "Error: number does not have 5 digits" << std::endl; //verifying the not 5 digit number
                }
                else if ((digit5_num / 10000) % 10 == (digit5_num % 10) && ((digit5_num / 1000) % 10 == (digit5_num / 10) % 10)) //checking if the number is palindrome
                {
                    std::cout << "This is a palindrome." << std::endl; //verifying the palindrome number
                }
                else
                    std::cout << "not a palindrome" << std::endl; //a 5 digit number and not a palindrome
                    break;
            }
            default:(std::cout << "An illegal option " << std::endl); // not 1 or 2 option of the choice)
    }
    return 0;
}
*/

/* Assignment: 3
Author: Daniel Boguslavsky, ID: 207915729
*/

/*
#include <iostream> // std::cin std::cout
#define SPACES 20
#include <iomanip> // setprecision,setfill,setw


int main() { // this code program  accepts  integer, a character and an broken integer from the user.
 // The program will use the iomanip library and print to the screen the incomplete number with precision of digits after the point to the received broken integer.
 //  The printout will occupy exactly 20 spaces, where the spaces must be filled with the received character.

    char ch = 0; //a character variable
    int num = 0; //a number variable
    double dNum = 0.0; //a broken variable

    std::cout << "Please enter a char: " << std::endl; //entering a char
    std::cin >> ch;

    std::cout << "Please enter a int number: " << std::endl; //entering a number
    std::cin >> num;

    std::cout << "Please enter a double number: " << std::endl; //entering a broken number
    std::cin >> dNum;

    if (num <= SPACES && num >= 0) //you must chose a num in between 20 to 0 because you must fill 20 spaces
    {
        std::cout << fixed <<  std::endl;//fixing the number after the .
        std::cout << setfill(ch) << setw(SPACES) << setprecision(num) << dNum << std::endl; //first filling the answer with 20 chars and then filling the dNum in the spaces
    }
    return 0;
}

*/

/* Assignment: bonus
Author: Daniel Boguslavsky, ID: 207915729
*/

/*
#include <iostream> //using std::cout , std::cin
#define ASCII_0  48 //48 in char is 0
#define NUMBER_BIGGER_THEN 10 // if the digit is bigger than 10
int main() { //finding if the check digit is matching to you're last digit in you're id and finding if youre id is correct

    int sum = 0; //summing for the digits
    char firstIdDigit = 0;
    char secondIdDigit = 0;
    char thirdIdDigit = 0;
    char forthIdDigit = 0;
    char fifthIdDigit = 0;
    char sixthIdDigit = 0;
    char seventhIdDigit = 0;
    char eighthIdDigit = 0;
    char ninethIdDigit = 0;
    int checkDigit = 0;

    std::cout << "Please enter your id number: " << std::endl; //please enter you're id if you have an id with 8 digit please enter 0 after the last digit

    std::cin >> firstIdDigit >> secondIdDigit >> thirdIdDigit >> forthIdDigit >> fifthIdDigit >> sixthIdDigit >> seventhIdDigit >> eighthIdDigit >> ninethIdDigit;

    sum += (int)(firstIdDigit - ASCII_0) + (int)(thirdIdDigit - ASCII_0) + (int)(fifthIdDigit - ASCII_0) + (int)(seventhIdDigit - ASCII_0); //summing the odd digits

        if ((int)(secondIdDigit - ASCII_0) * 2 >= NUMBER_BIGGER_THEN) //multiplying the digit by 2 and if the digit is bigger then 9 for entering the if
        {
           sum += ((((int)(secondIdDigit - ASCII_0) * 2) % 10) + (((int)(secondIdDigit - ASCII_0) * 2) / 10)); //multiplying the digit by 2 and spearing the first digit and the second and summing them up
        }
        if ((int)(secondIdDigit - ASCII_0) * 2 < NUMBER_BIGGER_THEN) //multiplying the digit by 2 and if the digit is lower than 10 for entering the if
        {
            sum += ((int)(secondIdDigit - ASCII_0) * 2);//multiplying the digit by 2
        }
         if ((int)(forthIdDigit - ASCII_0) * 2 >= NUMBER_BIGGER_THEN)//multiplying the digit by 2 and if the digit is bigger then 9 for entering the if
        {
             sum += ((((int)(forthIdDigit - ASCII_0) * 2 )% 10) + (((int)(forthIdDigit - ASCII_0) * 2) / 10));//multiplying the digit by 2 and spearing the first digit and the second and summing them up
        }
        if ((int)(forthIdDigit - ASCII_0) * 2 < NUMBER_BIGGER_THEN)//multiplying the digit by 2 and if the digit is lower than 10 for entering the if
        {
            sum += ((int)(forthIdDigit - ASCII_0) * 2);//multiplying the digit by 2
        }
        if ((int)(sixthIdDigit - ASCII_0) * 2 >= NUMBER_BIGGER_THEN)//multiplying the digit by 2 and if the digit is bigger then 9 for entering the if
        {
            sum += ((((int)(sixthIdDigit - ASCII_0) * 2 )% 10) + (((int)(sixthIdDigit - ASCII_0) * 2) / 10));//multiplying the digit by 2 and spearing the first digit and the second and summing them up
        }
        if ((int)(sixthIdDigit - ASCII_0) * 2 < NUMBER_BIGGER_THEN)//multiplying the digit by 2 and if the digit is lower than 10 for entering the if
        {
            sum += ((int)(sixthIdDigit - ASCII_0) * 2);//multiplying the digit by 2
        }
        if ((int)(eighthIdDigit - ASCII_0) * 2 >= NUMBER_BIGGER_THEN)//multiplying the digit by 2 and if the digit is bigger then 9 for entering the if
        {
            sum += ((((int)(eighthIdDigit - ASCII_0)* 2) % 10) + (((int)(eighthIdDigit - ASCII_0) * 2) / 10));//multiplying the digit by 2 and spearing the first digit and the second and summing them up
        }
        if ((int)(eighthIdDigit - ASCII_0) * 2 < NUMBER_BIGGER_THEN)//multiplying the digit by 2 and if the digit is lower than 10 for entering the if
        {
            sum += ((int)(eighthIdDigit - ASCII_0) * 2);//multiplying the digit by 2
        }
        checkDigit = 10 - (sum % 10 );//finding the check digit

        if (checkDigit == 10) //if the digit is 10
        {
          checkDigit = checkDigit - 10; //if the digit is 10, we do 10 minus 10 to find that the check digit is 0
        }
        std::cout << "The check id: " << checkDigit << std::endl; //verifying the number of the check id

        if (checkDigit == (int)(ninethIdDigit - ASCII_0))//finding if the id is correct
        {
            std::cout << "This a correct id";//verifying the id if it is a correct
        }
        if (checkDigit != (int)(ninethIdDigit - ASCII_0))//finding if the id is incorrect
        {
            std::cout << "This is an incorrect id";
        }

    return 0;
}
*/