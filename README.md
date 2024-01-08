# Credit Card Validator Program

The Credit Card Validator Program is a C++ application that validates and identifies credit card numbers based on the Luhn algorithm and card number prefixes. It provides a simple user interface to input credit card numbers, checks their validity, and identifies the card type.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Installation](#installation)
- [Files](#files)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Credit Card Validator Program validates credit card numbers using the Luhn algorithm, which verifies the legitimacy of a card number by assessing its mathematical properties. Additionally, the program identifies the card type based on common card number prefixes.

## Features

- Validates credit card numbers using the Luhn algorithm.
- Identifies the card type based on known card number prefixes.
- User-friendly interface with input validation.
- Supports various card types such as Visa, MasterCard, American Express, JCB, UnionPay, Discover, and Diners.

## Usage

1. **Compile and Run:**

    ```bash
    g++ main.cpp -o credit_card_validator
    ./credit_card_validator
    ```

2. **Follow the on-screen instructions:**

    - Enter a credit card number when prompted.
    - Type 'exit', 'quit', or '0' to gracefully exit the program.

## Installation

1. **Clone the repository:**

    ```bash
    git clone https://github.com/FinesserULTRA/credit-card-validator.git
    ```

2. **Navigate to the project directory:**

    ```bash
    cd credit-card-validator
    ```

3. **Compile the program:**

    ```bash
    g++ main.cpp -o credit_card_validator
    ```

## Files

- **main.cpp:** This is the main entry point of the program. It includes the user interface, the run function, and the entry point for the program.
- **cardvalidator.h:** Header file containing function prototypes, including `isValidInput`, `luhnAlgorithm`, `identifyCardType`, `displayResult`, `getCard`, and `run`. This file also declares the `clearScreen` function.
- **cardvalidator.cpp:** Implementation of the functions declared in `cardvalidator.h`.

## Contributing

Contributions are welcome! If you have any ideas, improvements, or bug fixes, feel free to open an issue or create a pull request.

## License

This project is licensed under the [MIT License](LICENSE).

---

*Note: Further enhancements and improvements may be required, and contributions are encouraged.*
