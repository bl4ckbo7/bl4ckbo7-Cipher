//bl4ckbo7 CRYPTOSYSTEM (With (Encryption + Decryption) functions)
//Coded by Andy Kawa - bl4ckbo7
//February 1, 2017

#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

//encrypting function(Encrypts the plaintext)
 string encode(string plaintext, int shift){

	string ciphertext;
    string encode_engine(string plaintext, int shift);

	//prompts the user to enter the plaintext
	cout<<"Please enter the plaintext: \n\n";
	cin>>plaintext;

	//open output stream that prints the output in the file
    ofstream fout("EncodeFile.txt");

	//prompts the user to enter the key to encrypt the plaintext
	cout<< "\nWhat is your key? ";
	cin>>shift;
	cout<<"\n\n";

	//checks if the key is greater than one unless it repeats the loop
	while (shift < 1) {
		cout<< "You have entered an invalid number. \n";
		cout<< "Please try again. \n";
		cout<< "Enter a proper number for the amount of letter shifting: ";
		cin>>shift;
	}

	//display/alerts the user that the program is encrypting the plaintext
	cout<<"Encrypting....\n\n";

	//assigns ciphertext the value in encode function
	ciphertext = encode_engine(plaintext, shift);

	//outputs the ciphertext on the screen
	cout<<"\nEncoded message: \a\n\n" << ciphertext << "\n\n";

	//outputs the values in the output file
	fout<<"\tCAESAR CIPHER CRYPTO\n";
	fout<<"\tDEVELOPED BY ANDY KAWA - BL4CKBO7\n";
	fout<<"\t (c) 2017\n\n";
	fout<<"Your plaintext >>>\n";
	fout<<plaintext<<"\n\n";
	fout<<"Key used >>>\n";
	fout<<shift<<"\n\n";
	fout<<"Your Ciphertext >>>\n";
	fout<<ciphertext<<"\n\n";

	//closes the output stream
	fout.close();

	system("pause");

	return ciphertext;
}

//Plaintext encrypting engine
string encode_engine(string plaintext, int shift){
	string temp = plaintext;
    int length;
    length = temp.length();

    //increments the size of string until the exact one entered by the user
    for (int i = 0; i < length; i++)
    {
    	//validates that each characters in the string is a letter
        if (isalpha(temp[i]))
        {
            for (int j = 0; j < shift; j++)
            {
                if (temp[i] == 'z')
                {
                    temp[i] = 'a';
                }
                else if (temp[i] == 'Z')
                {
                    temp[i] = 'A';
                }
                else
                {
                    temp[i]++;
                }
            }
        }
    }

    return temp;
}

//Decrypting function (Decrypts the ciphertext)
string decode(string ciphertext, int shift){

	string plaintext;
    string decode_engine(string ciphertext, int shift);

	//prompts the user to enter the ciphertext
	cout<<"Please enter the ciphertext: \n\n";
	cin>>ciphertext;

	//prompts the user to enter the key to decrypt the plaintext
	cout<< "\nWhat is your key? ";
	cin>>shift;
	cout<<"\n\n";

	//checks if the key is greater than one unless it requests user to re-enter key
	while (shift < 1) {
		cout<< "You have entered an invalid number. \n";
		cout<< "Please try again. \n";
		cout<< "Enter a proper number for the amount of letter shifting: ";
		cin>>shift;
	}

	//display/alerts the user that the program is decrypting the ciphertext
	cout<<"Decrypting....\n\n";

	//assigns plaintext the value in decode engine
	plaintext = decode_engine(ciphertext, shift);

	//outputs the plaintext on the screen
	cout<<"\nPlaintext Found! >>>>> \a \x5B " << plaintext << " \x5D\n\n";

	system("pause");

	return plaintext;
}

//Ciphertext decrypting engine
string decode_engine(string ciphertext, int shift){
	string temp2 = ciphertext;
	int length;
	length = temp2.length();

	//increments the size of string until the exact one entered by the user
	for (int i = 0; i < length; i++)
	{
		//validates that each characters in the string is a letter
	    if (isalpha(temp2[i]))
	    {
	        for (int j = 26; j > shift; j--)
	        {
	            if (temp2[i] == 'z')
	            {
	                temp2[i] = 'a';
	            }
	            else if (temp2[i] == 'Z')
	            {
	                temp2[i] = 'A';
	            }
	            else
	            {
	                temp2[i]++;
	            }
	        }
	    }
	}

return temp2;
}

//about program function
void about(){
	cout<<"\n\n\tbl4ckbo7 CIPHER CRYPTO\n\n";
	cout<<"\tDEVELOPED BY ANDY KAWA - bl4ckbo7@protonmail.com\n\n";
	cout<<"\t           \x40 2017\n\n";
}

//function menu of user choices
void menu(){
	cout<<"\t***CRYPTO MENU***\n\n";
   	cout<<"\t1. Encryption\n\n";
   	cout<<"\t2. Decryption\n\n";
   	cout<<"\t3. About\n\n";

}

//function to quit the program
int quit(){
	char Quit;
	int main();
	cout<<"\nYou wanna quit (Y/n)?\n";
	cin>>Quit;

	if (Quit == 'Y'){
		system("cls");
		cout<<"Goodbye! \n\n";
		system ("exit");
	}
	else if(Quit == 'n'){
		system("cls");
		cout<<main();
	}
	else{
		system("cls");
		cout<<"Wrong choice! \n\n";
		system("pause");
		system("cls");
		cout<<quit();
	}

	return 0;
}

//declaration of the functions and their respective variables
	string encode_engine(string plaintext, int shift);
    string decode_engine(string ciphertext, int shift);
    string encode(string plaintext, int shift);
    string decode(string ciphertext, int shift);




//main function starts - the core of the cipher program
int main(){

    system("color 0a");
	string plaintext, ciphertext;
	int shift = 0;
	string encode_;
	string decode_;
	int choice;
	int abt;
	int quit();
	int about();
	int menu();

	cout << "\n******/*****************[ Welcome to bl4ckbo7 Cipher ]*****************/******\n\n";
    cout<<"----------------------DEVELOPED BY ANDY KAWA CYBER-LABS-------------------------\n\n\n";



    do {
    	//displays the menu of the program
    	choice = menu();
    	cout<<"\n\n";
    	cin>>choice;
    }
    while (choice < 1 || choice > 3);

    //if conditions options
    	if (choice == 1){
            cout<<"\n********[ ---ENCODE--- ]*******\n";
			encode_ = encode(plaintext, shift);
			cout<<quit();
    	}

		else if (choice == 2){
            cout<<"\n********[ ---DECODE--- ]*******\n";
			decode_ = decode(ciphertext, shift);
			cout<<quit();
		}

        else if (choice == 3) {
            cout<<"\n********[ ---ABOUT--- ]*******\n";
			abt = about();
			cout<<quit();
        }

		else{
            cout<<"Wrong choice! Please Repeat again!";
			cout<<main();
		}



	getch();
}
