// Date: 17 September 2024
// Author: Dev Khullar

#include <iostream>
#include <string>
using namespace std;

//  myAdd    : Adds new word to the dictionary,
//             doesn't add if word already exists
// Arguments : string[], int, string
// Returns   : array
string* myAdd(string *dictionary, int &wordCount, string aWord){
    for (int i = 0; i < wordCount; i++){
        if (dictionary[i] == aWord){
            cout << aWord << " already exists" << endl; 
            return dictionary;
        }

    string *newDictionary = new string[wordCount + 1];
    for (int i = 0; i < wordCount; i++){
        for (int i = 0; i < wordCount; i++) {
        newDictionary[i] = dictionary[i];
        }
        newDictionary[wordCount] = aWord;
        wordCount++;
        cout << aWord << " is added." << endl;
        
        delete[] dictionary; // Deallocate old dictionary memory
        return newDictionary;
    }
    }
}

// myDelete : deletes an existing word
// Arguments: string[], int, string
// Returns  : array
string *myDelete(string *dictionary, int &wordCount, string aWord){
    int index = 0;

    for (int i = 0; i < wordCount; i++){
        if (dictionary[i] == aWord){
            string *newDictionary = new string[wordCount - 1];   
            for (int j = 0; j < wordCount; j++){
ord){
            cout << aWord << " 
                if(dictionary[i] != aWord){
                    newDictionary[index++] = dictionary[j];
                }
            }
            cout << aWord << "is deleted." << endl;
            delete[] dictionary;
            return newDictionary;
        }

        else{
            cout << aWord << "is not found." << endl;
            return dictionary;
        }
    }
}

// mySearch : searches the word in the dictionary
// Arguments: string[], int, string
// Returns  : None
void mySearch(string dictionary[], int wordCount, string aWord){

    for (int i = 0; i < wordCount; i++){
        int comparisons = 0;
        if (dictionary[i] == aWord){
            comparisons++;
            cout << "aword is found.";
            cout << comparisons << " comparisons" << endl;
        }

        else{
            cout << "aword is not found" << endl;
        }
    }
}

// myList   : prints out all the words, line by line
// Arguments: string[], int, string
// Returns  : None
void myList(string dictionary[], int wordCount){

    for (int i = 0; i < wordCount; i++){
        cout << dictionary[i] << endl;
    }

}

// myExit   : implements the command exit
// Arguments: None
// Returns  : None
void myExit(){
    cout << "bye bye" << endl;

}

// linearSearch : implements the linear search algorithm
// Arguments    : string[], int, string, count
// Returns      : True if a word is found, false otherwise.
bool linearSearch(const string dictionary[], int wordCount, string aWord, int &count){
    for (int i = 0; i < wordCount; i++){
        if (dictionary[i] == aWord){
            return true;
            count++;
        }
        
        else 
            return false;
    }
}

int main(){
    string *dictionary = nullptr; // Start with an empty dictionary
    int wordCount = 0;
    string command;
    string aWord;

    while (true) {
        cout << ">>> ";
        cin >> command;

        if (command == "ADD") {
            cin >> aWord;
            dictionary = myAdd(dictionary, wordCount, aWord);
        } else if (command == "DELETE") {
            cin >> aWord;
            dictionary = myDelete(dictionary, wordCount, aWord);
        } else if (command == "SEARCH") {
            cin >> aWord;
            mySearch(dictionary, wordCount, aWord);
        } else if (command == "LIST") {
            myList(dictionary, wordCount);
        } else if (command == "EXIT") {
            for (int i =0; i < 10; i++)
                cout << dictionary[i] << endl;
            }
            myExit();
            break;
        }
        else {
            cout << "Please try something else" << endl;
        }
    }

    delete[] dictionary; 
    return 0;
}string *newDictionary = new string[wordCount + 1];
    for (int i = 0; i < wordCount; i++){
        for (int i = 0; i < wordCount; i++) {
        newDictionary[i] = dictionary[i];
        }
        newDictionary[wordCount] = aWord;
        wordCount++;
        cout << aWord << " is added." << endl;
        
        delete[] dictionary; // Deallocate old dictionary memory
        return newDictionary;
    }