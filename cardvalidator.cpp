#include "cardvalidator.h"


// Function to clear the screen
void clearScreen() {
	system("CLS");
}


// Entry point of the program
void run() {

	// Get a valid credit card number from the user
	const string cardNumber = getCard();

	// Check the validity of the card using the Luhn algorithm
	const bool isValid = luhnAlgorithm(cardNumber);

	// Identify the card type
	const string cardType = identifyCardType(cardNumber);

	// Display the result
	displayResult(cardType, isValid);

}


// Function to get a valid credit card number from the user
string getCard() {

	string cardNumber;

	clearScreen();

	while (true) {
		//show the menu screen and input prompt
		cout << "***********************************************************************************************\n";
		cout << "\n\t\t\tCredit Card Verification and Identifier\n";
		cout << "\n***********************************************************************************************\n";
		cout << "\nEnter a credit card number ('exit' or 'quit' or 0 to quit): ";
		string userInput;
		getline(cin, userInput);	//4250 5478 9789 4506 or 4250-5478-9789-4506 or 4250547897894506 etc
 
		// Allow the user to exit the program gracefully
		if (userInput == "exit" || userInput == "quit" || userInput == "0") {
			clearScreen();
			cout << "***********************************************************************************************\n";
			cout << "\n\t\t\t\t\tGoodbye, Come again.\n";
			cout << "\n***********************************************************************************************\n";
			cin.ignore(100, '\n');
			exit(0);
		}


		// Check the validity of the input and continue or prompt for a valid input
		if (isValidInput(userInput)) {
			return userInput;
		}

		cout << "Invalid Input. Please enter a valid credit card number.\n";
		cin.ignore(100, '\n');
		clearScreen();
	}
}


// Function to display the result
void displayResult(const string& cardType, bool isValid) {
	clearScreen();
	cout << "*******************************************************************************************\n";
	cout << "\n\t\t\t\tCredit card number is " << (isValid ? "valid!" : "invalid.") << endl;

	if (isValid) {
		// If the card type is "Unknown," provide a message indicating it may not be supported
		cout << "\t\t\t\tCard Type: ";
		if (cardType != "Unknown")
			cout << cardType;
		else
			cout << "Unknown \n\t\t\t\t(Card type may not be supported).";
		cout << endl;
	}

	cout << "\n*******************************************************************************************\n";
}

// Function to validate a credit card number using the Luhn algorithm
bool luhnAlgorithm(const string& cardNumber) {
		
	// Luhn's algorithm
	int sum = 0;
	bool isAlternateDigit = false;

	// Start from right to left
	for (int i = cardNumber.length() - 1; i >= 0; i--) {
		int digit = cardNumber[i] - '0';

		// Multiply every second digit from the end by 2,
		// and subtract 9 from it if it's greater than 9
		if (isAlternateDigit) {
			digit *= 2;
			if (digit > 9) {
				digit -= 9;
			}
		}

		sum += digit; // Add digit to sum

		isAlternateDigit = !isAlternateDigit;//for alternate digits, it will be true
	}
	// Luhn's algorithm requires the sum of all digits to be divisible by 10
	return (sum % 10 == 0);
}


// Function to check if the input consists of digits only and has a valid length
bool isValidInput( string& input) {

	string formattedCC="";

	for (char c : input) {
		// Ensure the input contains digits, spaces, or dashes only
		if (!isdigit(c) && c != ' ' && c != '-') 
			return false;
		else if (c != ' ' && c != '-')
			formattedCC += c;	//remove the dashes and spaces
	}


	if (formattedCC.length() < 12 || formattedCC.length() > 19) {
		return false;
	}

	input = formattedCC;
	return true;
}

// Function to identify the card type based on the prefix
string identifyCardType(const string& cardNumber) {

	int prefix = stoi(cardNumber.substr(0, 2)), prefourix = stoi(cardNumber.substr(0,4));

	if ((prefix >= 40 && prefix <= 49) && (cardNumber.length() == 13 || cardNumber.length() == 16 || cardNumber.length() == 19)) {
		return "Visa";
	}
	else if (((prefix >= 51 && prefix <= 55) || (prefourix >= 2221 && prefourix <= 2759)) && (cardNumber.length() == 16)) {
		return "MasterCard";
	}
	else if (prefix == 35 && cardNumber.length() == 16) {
		return "JCB";
	}
	else if (((prefix == 34 || prefix == 37) || (prefix == 30)) && cardNumber.length() == 15) {
		return "American Express";
	}
	else if ((prefix == 62 || prefix == 81) && (cardNumber.length() >= 16  && cardNumber.length() <= 19)) {
		return "UnionPay";
	}
	else if ((prefix >= 60 && prefix <= 65 )&& cardNumber.length() == 16) {
		return "Discover";
	}
	else if ((prefix == 30 || (prefix == 20 || prefix == 21) || prefix == 36 || prefix == 38) && (cardNumber.length() >= 14 && cardNumber.length() <= 16)) {
		return "Diners";
	}



	// If the card type is not recognized, return "Unknown"
	return "Unknown";
}
