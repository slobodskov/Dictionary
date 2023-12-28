#ifndef Tree_h
#define Tree_h

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

#include <string>
#include <vector>

using namespace std;

const int ALPHABET_SIZE = 26;
const int MAX_OPTIONS = 15;

struct TrieNode
{
	struct TrieNode* table[ALPHABET_SIZE];
	bool endOfWord;
};

TrieNode* getNewNode(void);
void paste(TrieNode*, string);
bool isLastNode(const TrieNode* root);
void recordPosition(const TrieNode* root, string current, string* result, int& result_length);
int getPosition(TrieNode* root, const string& query, string* result);
void fillDictionary(TrieNode*);
#endif


