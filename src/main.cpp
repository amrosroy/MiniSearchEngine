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

    cout<<"\n\tWelcome!\n";

    while(true)
    {
        int choice=3;

        cout << "\nChoose one option from below :\n"<<
        "1. Exact Search\n"<<
        "2. Autocomplete\n"<<
        "3. Exit\n";

        cin>>choice;

        if(choice==3) break;

        if(choice==1){
            string query;
            cout<<"Enter the word : ";
            cin>>query;
            engine.searchWord(query);
        }
        else if(choice==2){
            string prefix;
            cout << "Enter prefix: ";
            cin >> prefix;
            engine.suggest(prefix);
        }
        else{
            cout<<"\nInvalid choice\n";
            break;
        }

    }

    return 0;
}