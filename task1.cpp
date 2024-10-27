//Create a program that can encrypt and decrypt text using caesar cipher algorithm. Allow users to input a message and shift value to perform encryption and decryption.
#include <iostream>
#include <string>
using namespace std;
string caesarEncrypt(const std::string& text, int shift) {
    string encryptedText;
    for (char ch : text) {
        if (isalpha(ch)) {  // Check if the character is a letter
            char base = islower(ch) ? 'a' : 'A';
            // Encrypt the character
            encryptedText += (ch - base + shift) % 26 + base;
        } else {
            encryptedText += ch;  // Non-letter characters remain unchanged
        }
    }
    return encryptedText;
}

string caesarDecrypt(const string& text, int shift) {
    return caesarEncrypt(text, -shift);  // Decrypting is the same as encrypting with the negative shift
}

int main() {
    while (true) {
        string action;
        cout << "Do you want to (e)ncrypt or (d)ecrypt or (q)uit? ";
        cin >> action;

        if (action == "q") {
            cout << "Goodbye!" << endl;
            break;
        }
        if (action != "e" && action != "d") {
            cout << "Invalid option. Please choose 'e', 'd', or 'q'." << endl;
            continue;
        }

        cin.ignore();  // Clear the newline character from the input buffer
        string message;
        cout << "Enter your message: ";
        getline(std::cin, message);
        
        int shift;
        cout << "Enter the shift value (0-25): ";
        cin >> shift;

        if (action == "e") {
            string encryptedMessage = caesarEncrypt(message, shift);
            cout << "Encrypted message: " << encryptedMessage <<endl;
        } else if (action == "d") {
            string decryptedMessage = caesarDecrypt(message, shift);
            cout << "Decrypted message: " << decryptedMessage <<endl;
        }
    }

    return 0;
}
