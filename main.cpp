#include <iostream>
#include <stdlib.h>
#include "Tree.h"

int main(int argc, const char* argv[])
{
    struct TrieNode* root = getNewNode();
    fillDictionary(root);

    string input;
    string new_word;

    cout << "If you need to add a new word, press '1', if you want to stop, press '0'." << endl;

    while (true)
    {
        cout << "Type the word and press enter: ";
        cin >> input;
        if (input == "0")
        {
            cout << "Goodbye!";
            break;
        }
        else if(input == "1")
        {
            cout << "Type the word: ";
            cin >> new_word;
            cout << endl;
            paste(root, new_word);
            cout << "The new word was sucsessfully added to the dictionary!" << endl;
            continue;
        }

        string pos[MAX_OPTIONS];
        const int num_variants = getPosition(root, input, pos);

        if (num_variants != 0)
        {
            for (size_t i = 0; i < num_variants; ++i)
                cout << pos[i] << endl;
        }
    }
    return 0;
}