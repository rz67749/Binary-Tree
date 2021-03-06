#include <iostream>
#include <fstream>
#include "ItemType.h"
#include "BinaryTree.h"

using namespace std;

int main(int argc, char** argv)
{
    //read input file
    BinaryTree list;
    ItemType item;
    int input;
    fstream fs;
    fs.open(argv[1], fstream::in);

    if(fs.is_open())
    {
        fs >> input;
        while(!fs.eof())
        {
            item.initialize(input);
            list.insert(item);
            fs >> input;
        }//while
    }//if
    else {
        cout << "Failed to open the input file" << endl;
        return 0;
    }//else

    //user options
    cout << "insert (i), delete (d), retrieve (r), length (l), in-order (n), pre-order (p), post-order (o), getSameLevelNonsiblings (c), quit (q)" << "\n\t" << endl;

    char userInput = ' ';
    while(userInput != 'q')
    {
        cout << "Enter a command: "; //user choice
        cin >> userInput;
        switch(userInput)
        {
        case 'i': // insert
            cout << "Item to insert: ";
            cin >> input;
            item.initialize(input);
            list.insert(item);
            break;

        case 'd': //delete
           
            break;
            
        case 'r': // retrieve
            
            break;
            
        case 'l': //print length of list
            cout << "List Length: " << list.getLength() << endl;
            break;

        case 'n': //in-order print
            cout << "In-Order: ";
            list.inOrder();
            break;

        case 'p': //pre-order print
            cout << "Pre-order: ";
            list.preOrder();
            break;

        case 'o': //post-order print
            cout << "Post-Order: ";
            list.postOrder();
            break;

        case 'c': // same level nonsiblings
            cout << "Item to find same level nonsiblings: ";
            cin >> input;
            item.initialize(input);
            list.getSameLevelNonsiblings(item);
            break;
            
        case 'q': //exit program
            cout << "Quitting program..." << endl;
            cout << endl;
            exit(EXIT_SUCCESS);
            break;
      
        default: //incorrect option
            cout << "Command not recognized. Try again." << endl;
        }//switch
        cout << endl;
    }//while
  
    return 0;

}//main

