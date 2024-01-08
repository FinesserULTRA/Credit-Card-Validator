#pragma once

#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

void run();	//calls the functions, basically the predefined main() function

/*the following functions can be used alone in any order as well.
 *any of these functions can be called in another program,
 * to check for luhn algorithm, validity of card input or even identification, etc.
 */

string getCard();	//Get card from user, also gives UI
bool isValidInput(string& input);	//Validated input

bool luhnAlgorithm(const string& cardNumber);	//apply luhn algorithm on the validated and formatted CC number

string identifyCardType(const string& cardNumber); //Identify the cards

void displayResult(const string& card_type, const bool is_valid);	//Final result and output
void clearScreen();	//system("CLS");

