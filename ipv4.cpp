#include <iostream>  
#include <string>

using namespace std;  

// Custom function for converting a string to an integer
int custom_stoi(string text){
    char c_num [] = {'0','1','2','3','4','5','6','7','8','9'};
    int i_num [] = {0,1,2,3,4,5,6,7,8,9};
    //bool find = true;
    int index = -1;

    int res = 0;
    for(int i = 0; i < text.length(); i++) {
        for(int j = 0; j < 10; j ++) {
            if (text[i] == c_num[j]) {
                index = j;
                break;
            }
        }
        if (index == -1) {
            return index;
        } else {
            res += i_num[index];
            res *= 10;
            index = -1;
        }
    }
    res /= 10;
    return res;
}

// Checking the entered ipv4 address
bool parce_ipv4(string ip) {
    string block = "";
    int count = 0;
    for(int i = 0; i < ip.length(); i++) {
        if (i == ip.length() -1) {
            if (custom_stoi(block) < 0 || custom_stoi(block) > 255) {
                return false;
            }
        }
        if (ip[i] != '.') {
            block += ip[i];
        } else {
            count +=1;
            if (custom_stoi(block) < 0 || custom_stoi(block) > 255) {
                return false;
            }
            block.clear();
        }
    }
    if (count != 3) {
        return false;
    }
    return true;
}

int main() {
    string command = "ping ";
    string argument; // ipv4 address
    char exit = 'n';
    while(true) {
        cout << "Enter ip (format ipv4) or enter \"exit\": ";
        cin >> argument;
        if (argument == "exit") {
            break;
        }
        else if (parce_ipv4(argument)) {
            command += argument;
            system(command.c_str());
            command = "ping ";
            argument.clear();
        } else {
            cout << "incorrect ipv4. Please try again or enter \"exit\"\n";
        }
    }
    cout << "Goodbye!\n";
    system("pause");
    return 0;
}  