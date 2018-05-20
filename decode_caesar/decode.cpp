//
//  main.cpp
//  decode_caesar
//
//  Created by Emily Denise Chatterjee on 7/26/17.
//  Copyright © 2017 Emily Denise Chatterjee. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int NUM_LETTERS = 26;
void start();
void ask_message(char plain_alpha[], char cipher_alpha[]);
string decode_text(string user_input, char plain_alpha[], char cipher_alpha[]);

int main() {
    
    start();
    
    return 0;
}

void start () {
    
    int shift;
    char direction;
    
    cout << "What is the shift of the message? ";
    cin >> shift;
    cout << "Which direction is the shift? (L for left and R for right) ";
    cin >> direction;
    
    char plain_alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                          'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                          'w', 'x', 'y', 'z'};
    char cipher_alpha[NUM_LETTERS];
    
    if (toupper(direction) == 'L') {
        // initializing all values in ciphertext
        for (int i = 0; i < NUM_LETTERS; i++) {
            if (i >= shift) {
                cipher_alpha[i] = plain_alpha[i - shift];
            }
            else if (i < shift) {
                cipher_alpha[i] = plain_alpha[(NUM_LETTERS + i) - shift];
            }
        }
    }
    if (toupper(direction) == 'R') {
        // initializing all values in ciphertext
        for (int i = 0; i < NUM_LETTERS; i++) {
            if (i < NUM_LETTERS - shift) {
                cipher_alpha[i] = plain_alpha[i + shift];
            }
            else if (i < NUM_LETTERS) {
                cipher_alpha[i] = plain_alpha[i - (NUM_LETTERS - shift)];
            }
        }
        
    }
    
    
    ask_message(plain_alpha, cipher_alpha);
    return;
}

void ask_message(char plain_alpha[], char cipher_alpha[]) {
    
    string user_input = "";
    string plaintext = "";
    string ciphertext = "";
    
    // asks user for plaintext
    cout << "Enter the messsage you want decoded (all lower case letters please): ";
    getline(cin, user_input);
    ciphertext += user_input;
    plaintext += decode_text(user_input, plain_alpha, cipher_alpha);
    
    // keeps encoding lines of user entered text
    while (getline(cin, user_input) && user_input != "") {
        ciphertext += user_input;
        plaintext += decode_text(user_input, plain_alpha, cipher_alpha);
    }
    cout << endl;

    //prints out decoded message
    cout << "DECODED MESSAGE: " << plaintext << endl;
    return;
    
}

string decode_text(string user_input, char plain_alpha[], char cipher_alpha[]) {
    
    string decoded_text = user_input;
    
    for (int i = 0; i < user_input.length(); i++) {
        for (int j = 0; j < NUM_LETTERS; j++) {
            if (cipher_alpha[j] == user_input[i]) {
                decoded_text[i] = plain_alpha[j];
            }
        }
    }
    
    return decoded_text;
}
