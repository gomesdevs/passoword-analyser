#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <iomanip> // Added for better formatting

using namespace std;

string checkPasswordStrength(const string& password) {
    int length = password.length();
    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
    vector<string> commonPatterns = {"password", "1234", "qwerty", "admin"};

    for (char c : password) {
        if (islower(c)) hasLower = true;
        else if (isupper(c)) hasUpper = true;
        else if (isdigit(c)) hasDigit = true;
        else hasSpecial = true;
    }

    string lowerPassword = password;
    transform(lowerPassword.begin(), lowerPassword.end(), lowerPassword.begin(), ::tolower);
    bool hasCommonPattern = false;
    for (const string& pattern : commonPatterns) {
        if (lowerPassword.find(pattern) != string::npos) {
            hasCommonPattern = true;
            break;
        }
    }

    int score = 0;
    if (length >= 12) score += 2;
    else if (length >= 8) score += 1;
    if (hasLower) score +=1;
    if (hasUpper) score += 1;
    if (hasDigit) score += 1;
    if (hasSpecial) score += 1;
    if (!hasCommonPattern) score += 1;

    cout << "\nStrength Analysis:" << endl;
    cout << "- Length: " << length << " chars (" << (length >= 12 ? "+2" : (length >= 8 ? "+1" : "0")) << " points)" << endl;
    cout << "- Lowercase letters: " << (hasLower ? "Yes (+1)" : "No (0)") << endl;
    cout << "- Uppercase letters: " << (hasUpper ? "Yes (+1)" : "No (0)") << endl;
    cout << "- Digits: " << (hasDigit ? "Yes (+1)" : "No (0)") << endl;
    cout << "- Special characters: " << (hasSpecial ? "Yes (+1)" : "No (0)") << endl;
    cout << "- Common patterns: " << (hasCommonPattern ? "Found (0)" : "None (+1)") << endl;
    cout << "- Total Score: " << score << "/7" << endl;

    if (score >= 6) return "Strong";
    else if (score >= 4) return "Moderate";
    else return "Weak";
}

string encryptPassword(const string& password, char key) {
    string encrypted = password;
    for (char& c : encrypted) {
        c = c ^ key;
    }
    return encrypted;
}

void displayEncrypted(const string& encrypted) {
    cout << "Encrypted (hex): ";
    cout << hex << uppercase << setfill('0');
    for (unsigned char c : encrypted) {
        cout << setw(2) << static_cast<int>(c) << " ";
    }
    cout << dec << nouppercase << setfill(' ') << endl;
}

int main() {
    string password;
    char encryptionKey = 0x5A;
    cout << "Cybersecurity Demo: Password Strength Analyzer & Encryption" << endl;
    cout << "Enter a password: ";
    getline(cin, password);

    if (password.empty()) {
        cout << "Error: Password cannot be empty." << endl;
        return 1;
    }

    string strength = checkPasswordStrength(password);
    cout << "\nPassword Strength: " << strength << endl;

    string encrypted = encryptPassword(password, encryptionKey);
    cout << "\nOriginal Password: " << password << endl;
    displayEncrypted(encrypted);

    string decrypted = encryptPassword(encrypted, encryptionKey);
    cout << "Decrypted Password: " << decrypted << endl;

    cout << "\nCybersecurity Tips:" << endl;
    cout << "- Use passwords longer than 12 characters." << endl;
    cout << "- Include uppercase, lowercase, digits, and special characters." << endl;
    cout << "- Avoid common words or patterns (e.g., 'password', '1234')." << endl;
    cout << "- Never reuse passwords across systems." << endl;

    return 0;
}
