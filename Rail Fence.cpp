#include <iostream>
#include <string>
using namespace std;
int main() {
    while(true) {
        // display welcome message and menu
        cout << " " << endl; //this line is only to make the message appear correctly when the loop works
        cout << "----+----+----+----+----+----" << endl;
        cout << "Welcome To Rail Fence Cipher!" << endl;
        cout << "----+----+----+----+----+----" << endl;
        cout << "Menu Options:" << endl;
        cout << "1)Cipher a message" << endl;
        cout << "2)Decipher a message" << endl;
        cout << "3)Exit" << endl;
        //let the user know that the key value is 3 (the message appears in 3 rows)
        cout << "(( please note that the key value is 3! ))" << endl;
        cout << "Please enter an option from 1,2,3 : ";
        int option;
        cin >> option;

        //user chose to cipher a message
        if (option == 1) {
            string msg;
            cout << "please enter a message to cipher: ";
            getline(cin, msg); //this line is only to avoid the effect of /n in the stream or any similar effect
            // get message from user
            getline(cin, msg);
            //take only the alphabet(remove spaces, numbers, special characters) from message and make a new variable
            string edited_msg = "";
            for (char i: msg) {
                if (isalpha(i)) {
                    edited_msg += i;
                }
            }
            cout << "ciphered message is: ";
            // the key is 3 which means we have 3 rows
            //in the first row starting from the first letter in the message skip three letters and take the rest
            for (int element = 0; element < edited_msg.length(); element += 4) {
                cout << edited_msg[element];
            }
            //in the second row starting from the second letter in the message skip one letter and take the rest
            for (int element = 1; element < edited_msg.length(); element += 2) {
                cout << edited_msg[element];
            }
            //in the third row starting from the third letter in the message skip three letters and take the rest
            for (int element = 2; element < edited_msg.length(); element += 4) {
                cout << edited_msg[element];
            }
        }


        //user chose to decipher a message
        else if (option == 2) {
            string msg;
            cout << "please enter a message to decipher: ";
            getline(cin, msg);
            getline(cin, msg);
            string edited_msg = "";
            //take only the alphabet(remove spaces, numbers, special characters) from message and make a new variable
            for (char i: msg) {
                if (isalpha(i)) {
                    edited_msg += i;
                }
            }
            // the size of the array is the key(3) as the number of rows and thne length of the message as the number of columns
            char zigzag[3][edited_msg.length()];
            string deciphered_msg = "";
            //make an empty 2d array
            for(int row = 0 ; row < 3 ; ++row){
                for (int column = 0 ; column < edited_msg.length() ; ++column){
                    zigzag[row][column] = 0;
                }
            }
            //put a special character to track the zigzag
            for(int row = 0 , column = 0 , d = 1 ; column < edited_msg.length() ; row += d , ++column ){
                zigzag[row][column] = '-';
                if(row == 3 - 1 ){d = -1 ;}
                else if(row == 0){d = 1 ;}
            }
            //row by row place the letters instead of the special characters
            int count = 0;
            for(int row = 0 ; row < 3 ; ++row){
                for(int column = 0 ; column < edited_msg.length() ; ++column ){
                    if(zigzag[row][column] == '-'){
                        zigzag[row][column] = edited_msg[count++];
                    }
                }
            }
            //read the zigzag of letters row by row to get the deciphered message
            for(int row = 0 , column = 0 , d = 1 ; column < edited_msg.length() ; row += d , ++column){
                deciphered_msg += zigzag[row][column];
                if(row == 3 - 1 ){d = -1 ;}
                else if(row == 0){d = 1 ;}
            }
            cout<< deciphered_msg ;

        }


        //user chose to exit program
        else if (option == 3) {
            cout << "thanks for using our program"<<endl;
            break;
        }
        else if (isdigit(option) == false) {
            cout << "invalid input please enter 1 or 2 or 3 only"<<endl;
            break;
        }
        //user entered an invalid choice (anything other than 1 or 2 or 3)
        else {
            cout << "invalid input please enter 1 or 2 or 3 only";
        }
    }
    return 0;
}
