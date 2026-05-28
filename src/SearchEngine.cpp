#include "../include/SearchEngine.h"

#include <algorithm>

string SearchEngine::toLowerCase(string word)
{
    for(char &c : word)
    {
        c = tolower(c);
    }

    return word;
}

void SearchEngine::buildIndex(vector<string> files)
{
    for(string filename : files)
    {
        ifstream file(filename);

        if(!file)
        {
            cout << "Could not open "
                 << filename << endl;

            continue;
        }

        string word;

        while(file >> word)
        {
            word = toLowerCase(word);

            index[word][filename]++;
            trie.insert(word);
        }

        file.close();
    }
}

void SearchEngine::searchWord(string query)
{
    query = toLowerCase(query);

    if(index.find(query) != index.end())
    {
        cout << "\nFound in:\n";

        vector<pair<string,int>> results;

        for(auto entry : index[query])
        {
            results.push_back(
                {entry.first, entry.second}
            );
        }

        sort(results.begin(),
             results.end(),
             [](pair<string,int> a,
                pair<string,int> b)
             {
                 return a.second > b.second;
             });

        for(auto result : results)
        {
            cout << result.first
                 << " ("
                 << result.second
                 << " matches)\n";
        }
    }
    else
    {
        cout << "Word not found.\n";
    }
}

void SearchEngine::printIndex()
{
    for(auto entry : index)
    {
        cout << entry.first << " -> ";

        for(auto file : entry.second)
        {
            cout << file.first
                 << "("
                 << file.second
                 << ") ";
        }

        cout << endl;
    }
}

void SearchEngine::suggest(string prefix)
{
    trie.autocomplete(prefix);
}