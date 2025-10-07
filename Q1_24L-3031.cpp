//#include <iostream>
//#include <string>
//#include <conio.h>
//using namespace std;
//
////// ===================== FUNCTION DECLARATIONS =====================
//bool isPalindrome(string str);
//void inputString();
//
////// ===================== MAIN FUNCTION =====================
//int main() 
//{
//    inputString();
//
//    return 0;
//}
//
//
////// ===================== FUNCTION DEFINITIONS =====================
//
///// <summary>
///// This Function checks wheter a grven string str is Palindrome or NOT
///// A string is palindromeif we reverse a string and it reamin same
///// </summary>
///// <param name="str">String to be tested for being Palindrome</param>
///// <returns>True if string is palindrome and False if not</returns>
//bool isPalindrome(string str)
//{
//    int start = 0;
//    int end = str.length() - 1;
//
//    while (start < end)
//    {
//        if (str[start] != str[end])   // if start and end character not same,not a plaindrome
//        {
//            return false;
//        }
//        start++;
//        end--;
//    }
//    return true;
//}
//
///// <summary>
///// This Function Take Input from the User and calls Palindrome Function
///// and then display the result
///// </summary>
//void inputString()
//{
//    string input;
//    char ch;
//
//    cout << "======================-PALINDROME CHECKER====================\n";
//
//    while (true)
//    {
//        input = "";
//        cout << "Enter a string: ";
//
//        while (true)
//        {
//            ch = _getch();
//
//            //Check if Esc key is pressed (ASCII 27)
//            if (ch == 27)
//            {
//                cout << "\n================EXITING THE PROGRAM-===============\n";
//                return;
//            }
//
//            // Check if Enter key is pressed
//            if (ch == 13)
//            {
//                cout << endl;
//                break;
//            }
//
//            //Add character to input
//            input += ch;
//            cout << ch;
//        }
//
//        //Check palindrome and display result
//        if (isPalindrome(input))
//        {
//            cout << "Palindrome!" << endl;
//        }
//        else
//        {
//            cout << "Not Palindrome!" << endl;
//        }
//    }
//}
