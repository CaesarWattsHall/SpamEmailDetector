/*
By: Caesar R. Watts-Hall
Date: June 08, 2023
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isSpamEmail(string email) {
    // Function to check if the email is a spam email
    // This function can be modified to implement the desired logic for checking spam emails
    return email.find("spam") != string::npos; // Example: all emails containing the word "spam" are considered spam
}

void storeSpamEmail(string email) {
    // Function to store the spam email in a text file
    ofstream file;
    file.open("spamEmails.txt", ios::app);
    file << email << endl;
    file.close();
}

void deleteSpamEmail(string email) {
    // Function to delete the spam email from the text file
    ifstream file;
    file.open("spamEmails.txt");
    ofstream temp;
    temp.open("temp.txt");
    string line;
    while (getline(file, line)) {
        if (line != email) {
            temp << line << endl;
        }
    }
    temp.close();
    file.close();
    remove("spamEmails.txt");
    rename("temp.txt", "spamEmails.txt");
}

void readSpamEmails() {
    // Function to read and display the spam emails stored in the text file
    ifstream file;
    file.open("spamEmails.txt");
    string line;
    cout << "Spam emails:" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main() {
    string email;
    cout << "Enter email: ";
    cin >> email;

    if (isSpamEmail(email)) {
        cout << "The email is a spam email." << endl;
        cout << "Do you want to store or delete the spam email in/from the text file? (store/delete): ";
        string choice;
        cin >> choice;
        if (choice == "store") {
            storeSpamEmail(email);
            cout << "The spam email has been stored in the text file." << endl;
        } else if (choice == "delete") {
            deleteSpamEmail(email);
            cout << "The spam email has been deleted from the text file." << endl;
        } else if (choice == "read") {
              readSpamEmails(email);
            cout << "The spam emails will now be read and displayed from the text file." << endl;
        } else {
            cout << "Invalid choice." << endl;
        }
    } else {
        cout << "The email is not a spam email." << endl;
    }

    return 0;
}
