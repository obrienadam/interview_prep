#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

char firstRepeatedChar(const string &str) {
    unordered_set<char> charMap;

    for(size_t i = 0; i < str.size(); ++i) {
        if(charMap.find(str[i]) != charMap.end())
            return str[i];

        charMap.insert(str[i]);
    }


}

char firstNonRepeatedChar(const string &str) {
    unordered_map<char, int> charFreqMap;

    for(size_t i = 0; i < str.size(); ++i) {
        auto insert = charFreqMap.insert(make_pair(str[i], 1));

        if(!insert.second) {
            insert.first->second++;
        }
    }

    for(size_t i = 0; i < str.size(); ++i) {
        if(charFreqMap.find(str[i])->second == 1)
            return str[i];
    }

    return 'N';
}

string reverseSentence(string str) {
    reverse(str.begin(), str.end());

    auto begin = str.begin();
    int idx = str.find_first_of(" ", 0);

    while(idx < str.size() > 0) {
        cout << idx << endl;
        reverse(begin, str.begin() + idx);
        begin = str.begin() + idx + 1;
        idx = str.find_first_of(" ", idx + 1);
    }

    return str;
}

int main() {
    auto str = "akdlafjlblzmdsfj;algohjaouhernlkcd753657636914314153541";

    cout << firstRepeatedChar(str) << "\n"
         << firstNonRepeatedChar(str) << "\n";

    str = "The quick brown fox jumped over the lazy dog";

    cout << reverseSentence(str) << endl;

    return 0;
}
