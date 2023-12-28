#include "Tree.h"
#include <stdio.h>

TrieNode* getNewNode(void)
{
    struct TrieNode* _node = new TrieNode;
    _node->endOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        _node->table[i] = nullptr;
    }
    return _node;
}

bool isLastNode(const TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->table[i])
        {
            return 0;
        }
    }
    return 1;
}

void paste(struct TrieNode* root, string key)
{
    struct TrieNode* node = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!node->table[index])
        {
            node->table[index] = getNewNode();
        }
        node = node->table[index];
    }
    node->endOfWord = true;
}

void recordPosition(const TrieNode* root, string currentPrefix, string* result, int& result_length)
{
    if (root->endOfWord)
    {
        result[result_length++] = currentPrefix;
    }

    if (isLastNode(root))
        return;

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->table[i])
        {
            currentPrefix.push_back(97 + i);
            recordPosition(root->table[i], currentPrefix, result, result_length);
            currentPrefix.pop_back();
        }
    }
}

int getPosition(TrieNode* root, const string& query, string* result)
{
    struct TrieNode* node = root;

    size_t i;
    size_t size = query.length();
    for (i = 0; i < size; i++)
    {
        int index = CHAR_TO_INDEX(query[i]);
        if (!node->table[index])
        {
            return 0;
        }
        node = node->table[index];
    }

    bool isWord = (node->endOfWord == true);

    bool isLast = isLastNode(node);

    if (isWord && isLast)
    {
        return 0;
    }
    int result_length = 0;
    if (!isLast)
    {
        recordPosition(node, query, result, result_length);
    }
    return result_length;
}

void fillDictionary(struct TrieNode* root)
{
    paste(root, "angel");
    paste(root, "back");
    paste(root, "car");
    paste(root, "day");
    paste(root, "education");
    paste(root, "face");
    paste(root, "game");
    paste(root, "hand");
    paste(root, "health");
    paste(root, "image");
    paste(root, "joke");
    paste(root, "knowledge");
    paste(root, "lord");
    paste(root, "mine");
    paste(root, "nasty");
    paste(root, "oracle");
    paste(root, "pickle");
    paste(root, "queue");
    paste(root, "rust");
    paste(root, "sample");
    paste(root, "tank");
    paste(root, "umbrella");
    paste(root, "vending");
    paste(root, "whiskey");
    paste(root, "xenon");
    paste(root, "year");
    paste(root, "zeal");
};
