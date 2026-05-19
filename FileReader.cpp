#include<fstream>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std;

string toLowerCase(string word){
    for(char &c : word){
        c=tolower(c);
    }
    return word;
}

int main(){
    unordered_map<string, unordered_map<string, int>> index;    
    vector<string>filenames={
        "data/dbms.txt",
        "data/os.txt",
        "data/cn.txt"
    };

    for(string filename : filenames){
        ifstream file(filename);
        if(!file) continue;
        string word;
        while(file>>word){
            word=toLowerCase(word);
            index[word][filename]++;
        }
        file.close();
    }

    /*
    
    for(auto entry : index){
        cout << entry.first << " -> ";
        for(string file : entry.second){
            cout << file << " ";
        }
        cout << endl;
    }
    
    */
    
    cout<<"Welcome!\n";

    while(true){
        string query;
        cout<<"Enter word to search or type 'exit' to leave:\n";
        cin>>query;
        query=toLowerCase(query);
        if(query=="exit"){
            break;
        }
        if(index.find(query) != index.end()){
            cout << "\nFound in:\n";
            vector<pair<string, int>> results;

            for(auto entry : index[query]){
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

            for(auto result:results){
                cout << result.first
                     << " ("
                     << result.second
                     << " matches)"
                     << endl;
            }
        }
        else{
            cout<<"Word not found.\n";
        }
    }

    return 0;
}