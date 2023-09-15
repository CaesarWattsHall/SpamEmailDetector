/*
By: Caesar R. Watts-Hall
Date: September 15, 2023
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <ctime>
#include <sqlite3.h>
using namespace std;

map<string, bool> spamCriteria;

// Function to load the spam criteria from a file
void loadSpamCriteria() {
    ifstream file("spamCriteria.txt");
    string line;
    while (getline(file, line)) {
        if (line[0] == '#') continue;  // Ignore comment lines
        string criterion = line.substr(0, line.find("="));
        bool value = line.substr(line.find("=") + 1) == "true" ? true : false;
        spamCriteria[criterion] = value;
    }
    file.close();
}

// Function to check if an email is spam based on the loaded criteria
bool isSpamEmail(string email) {
    if (spamCriteria["containsSpam"] && email.find("spam") != string::npos) {
        return true;
    }
    // Add more criteria here...
    return false;
}

// Function to log each email to a SQLite database
void logEmail(string email, bool isSpam) {
    sqlite3* DB;
    sqlite3_open("emailLogs.db", &DB);

    string sql = "INSERT INTO EMAIL_LOGS (EMAIL, TIME_STAMP, IS_SPAM) VALUES ('" 
                 + email + "', datetime('now'), " + (isSpam ? "1" : "0") + ");";

    sqlite3_exec(DB, sql.c_str(), NULL, 0, NULL);

    sqlite3_close(DB);
}

int main() {
    loadSpamCriteria();

    string email;
    cout << "Enter email: ";
    cin >> email;

    bool isSpam = isSpamEmail(email);
    
    if (isSpam) {
        cout << "The email is a spam email." << endl;
    } else {
        cout << "The email is not a spam email." << endl;
    }

    logEmail(email, isSpam);

    return 0;
}
