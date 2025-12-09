#ifndef USER_HPP                // Prevents the file from being included more than once (header guard)
#define USER_HPP

#include <string>               // Allows use of the string data type
using namespace std;            // Lets us use standard library names without std::

class User {                    // Start of the User class definition
public:                         // Access specifier: members below can be accessed anywhere
    string username;            // Stores the username of the user
    string password;            // Stores the user's password
    string role;                // Stores role type, e.g., "admin" or "user"

    User();                     // Default constructor (creates an empty User object)
    User(string u, string p, string r); // Constructor that initializes username, password & role

    string toLine() const;      // Converts User object to a string format for saving to file
    static User fromLine(const string &line); // Creates a User object from a file line
};

#endif                          // End of header guard

