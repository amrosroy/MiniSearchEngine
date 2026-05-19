#include "../include/SearchEngine.h"

int main()
{
    SearchEngine engine;

    vector<string> files = {
        "../data/dbms.txt",
        "../data/os.txt",
        "../data/cn.txt"
    };

    engine.buildIndex(files);

    while(true)
    {
        string query;

        cout << "\nEnter word to search (or exit): ";

        cin >> query;

        if(query == "exit")
        {
            break;
        }

        engine.searchWord(query);
    }

    return 0;
}