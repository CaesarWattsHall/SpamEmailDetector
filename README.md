# SpamEmailDetector
The Spam Email Detector program, written in C++, serves as a counterpart to the Spam Caller Detector program. Its primary function is to identify and manage spam emails based on user-defined criteria.

The core components of the program include:

1. **Spam Criteria**: The program allows users to define their own criteria for what constitutes a spam email. These criteria are stored in a text file and loaded into the program at runtime. The `loadSpamCriteria()` function is responsible for loading these criteria.

2. **Spam Detection**: The `isSpamEmail()` function checks if an email is spam based on the loaded criteria. This function can be customized to implement any desired logic for checking spam emails.

3. **Email Logging**: Each time an email is checked, the program logs the email, whether it was identified as spam, and the current timestamp to a SQLite database. The `logEmail()` function handles this logging.

4. **User Interaction**: The program prompts the user to enter an email and then checks if it's spam based on the loaded criteria. It displays a message indicating whether the email is spam and logs the email to the database.

Just like its counterpart, the Spam Caller Detector, this program provides a practical tool for managing and controlling spam effectively. Its modular design and use of standard C++ libraries make it highly adaptable for future enhancements and integrations.
