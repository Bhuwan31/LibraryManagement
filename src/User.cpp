#include "User.hpp"             // Include the header file for the User class definitions
#include <sstream>              // For stringstream (used to parse comma-separated strings)
#include <stdexcept>            // Enables throwing runtime_error exceptions

// Default constructor (creates an empty User object)
User::User() {}

// Parameterized constructor: initializes user with username, password, and role
User::User(string u, string p, string r) {
    username = u;               // Set the username field
    password = p;               // Set the password field
    role = r;                   // Set the role field (e.g., "admin" or "student")
}

// Converts User object data into a single comma-separated string format
string User::toLine() const {
    return username + "," + password + "," + role;   // Format: username,password,role
}

// Static function to create a User object from a comma-separated line
User User::fromLine(const string &line) {
    if (line.empty()) {                                  // Check if input is empty
        throw runtime_error("Cannot parse an empty line.");   // Throw error if nothing to parse
    }

    stringstream ss(line);                                // Create parser using stringstream
    string u, p, r;                                       // Temporary variables to hold parts

    getline(ss, u, ',');                                  // Extract username until comma
    getline(ss, p, ',');                                  // Extract password
    getline(ss, r, ',');                                  // Extract role

    // Check if any important field is missing
    if (u.empty() || p.empty() || r.empty()) {
        throw runtime_error("Invalid user data format."); // Throw error if parsing failed
    }

    return User(u, p, r);                                 // Return a new User object
}

