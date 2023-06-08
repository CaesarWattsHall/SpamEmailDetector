/*
By: Caesar R. Watts-Hall
Date: June 08, 2023
*/

#include <iostream>
#include <regex>
#include <string>
using namespace std;

bool isSpamEmail(string email) {
    // Function to check if the email is a spam email using regular expressions
    regex pattern("spam"); // Example: all emails containing the word "spam" are considered spam
    return regex_search(email, pattern);
}

int main() {
    string email;
    cout << "Enter email: ";
    cin >> email;

    if (isSpamEmail(email)) {
        cout << "The email is a spam email." << endl;
    } else {
        cout << "The email is not a spam email." << endl;
    }

    return 0;
}
