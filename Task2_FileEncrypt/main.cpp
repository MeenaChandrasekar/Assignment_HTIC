/*
 * main.cpp
 *
 *  Created on: 24-Jun-2025
 *      Author: meena
 */

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

// XOR encryption and decryption function
string encryptDecrypt(string text) {
    char key = 'K'; // simple fixed key
    for (int i = 0; i < text.length(); i++) {
        text[i] = text[i] ^ key;
    }
    return text;
}

// Function to store encrypted file
void storeFile() {
    string country, state, district, description;

    cin.ignore(); // clear input buffer

    cout << "Enter Country: ";
    getline(cin, country);

    cout << "Enter State: ";
    getline(cin, state);

    cout << "Enter District: ";
    getline(cin, district);

    cout << "Enter Description: ";
    getline(cin, description);

    // Create folder path
    string path = "./data/" + country + "/" + state + "/" + district;

    // Create nested directories
    try {
        fs::create_directories(path);
    } catch (exception& e) {
        cout << "Error creating folders: " << e.what() << endl;
        return;
    }

    // Prepare content to save
    string content = "Country: " + country + "\nState: " + state +
                     "\nDistrict: " + district + "\nDescription: " + description;

    // Encrypt the content
    string encrypted = encryptDecrypt(content);

    // Save encrypted content to file
    ofstream file(path + "/info.txt");
    if (!file) {
        cout << "Error writing to file!" << endl;
        return;
    }

    file << encrypted;
    file.close();
    cout << "Encrypted file saved successfully in: " << path << endl;
}

// Function to retrieve and decrypt file
void retrieveFile() {
    string country, state, district;

    cin.ignore(); // clear input buffer

    cout << "Enter Country: ";
    getline(cin, country);

    cout << "Enter State: ";
    getline(cin, state);

    cout << "Enter District: ";
    getline(cin, district);

    // File path to read
    string path = "./data/" + country + "/" + state + "/" + district + "/info.txt";

    // Open file
    ifstream file(path);
    if (!file) {
        cout << "File not found at: " << path << endl;
        return;
    }

    // Read encrypted content
    string encrypted((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    // Decrypt content
    string decrypted = encryptDecrypt(encrypted);

    // Show output
    cout << "\n--- Decrypted Content ---\n";
    cout << decrypted << endl;
}

// Main function to choose option
int main() {
    int choice;

    cout << "Choose option:\n";
    cout << "1. Store new file\n";
    cout << "2. Retrieve and view file\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        storeFile();
    } else if (choice == 2) {
        retrieveFile();
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
