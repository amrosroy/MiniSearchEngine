#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class SearchEngine
{
private:

    // word -> (filename -> frequency)
    unordered_map<string,
        unordered_map<string, int>> index;

public:

    void buildIndex(vector<string> files);

    void searchWord(string query);

    string toLowerCase(string word);

    void printIndex();
};

#endif