#include "User.hpp"             // Include the header file for the User class definitions
#include <sstream>              // For stringstream (used to parse comma-separated strings)
#include <stdexcept>            // Enables throwing runtime_error exceptions


User::User() {}

User::User(string u, string p, string r) {
    username = u;
    password = p;
    role = r;
}

string User::toLine() const {
    return username + "," + password + "," + role;
}

User User::fromLine(const string &line) {
    if (line.empty()) {
        throw runtime_error("Cannot parse an empty line.");
    }

    stringstream ss(line);
    string u, p, r;
    getline(ss, u, ',');
    getline(ss, p, ',');
    getline(ss, r, ',');

    // Validate extracted fields
    if (u.empty() || p.empty() || r.empty()) {
        throw runtime_error("Invalid user data format.");
    }

    return User(u, p, r);
}
