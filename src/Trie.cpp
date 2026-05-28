#include "../include/Trie.h"

Trie::Trie()
{
    root = new TrieNode();
}

void Trie::insert(string word)
{
    TrieNode* current = root;

    for(char c : word)
    {
        // If character path doesn't exist
        if(current->children.find(c)
           == current->children.end())
        {
            current->children[c]
                = new TrieNode();
        }

        // Move to next node
        current = current->children[c];
    }

    // Mark end of word
    current->isEndOfWord = true;
}

bool Trie::search(string word)
{
    TrieNode* current = root;

    for(char c : word)
    {
        // Character path missing
        if(current->children.find(c)
           == current->children.end())
        {
            return false;
        }

        current = current->children[c];
    }

    return current->isEndOfWord;
}

void Trie::dfs(TrieNode* node,
               string currentWord)
{
    // If complete word found
    if(node->isEndOfWord)
    {
        cout << currentWord <<"\n";
    }

    // Explore all children
    for(auto child : node->children)
    {
        char nextChar = child.first;

        TrieNode* nextNode = child.second;

        dfs(nextNode,
            currentWord + nextChar);
    }
}

void Trie::autocomplete(string prefix)
{
    TrieNode* current = root;

    // Move to prefix node
    for(char c : prefix)
    {
        if(current->children.find(c)
           == current->children.end())
        {
            cout << "No suggestions found.\n";

            return;
        }

        current = current->children[c];
    }

    cout << "\nSuggestions:\n";

    dfs(current, prefix);
}