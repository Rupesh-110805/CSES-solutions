#include<bits/stdc++.h>
using namespace std;

int main() {
    map<char,int> hashmap;
    string s;
    cin >> s;

    // Counting occurrences of each character
    for(auto i : s) {
        if(hashmap.find(i) == hashmap.end()) {
            hashmap.insert(make_pair(i, 1));
        } else {
            map<char,int>::iterator it = hashmap.find(i);
            (it->second)++;
        }
    }

    int count_odd = 0;
    char oddChar;
    string newstr;
    
    // Counting odd occurrences and storing odd character if any
    for(auto x : hashmap) {
        if((x.second) % 2 == 1) {
            count_odd++;
            oddChar = x.first;
        }
        newstr += string(x.second / 2, x.first); 
    }

    if(s.size() % 2 == 0) {
        if(count_odd == 0) {
            cout << newstr;
            reverse(newstr.begin(), newstr.end());
            cout << newstr;
        } else {
            cout << "NO SOLUTION";
        }
    } else {
        if(count_odd == 1) {
            // Print a solution
            cout << newstr << oddChar;
            reverse(newstr.begin(), newstr.end());
            cout << newstr;
        } else {
            cout << "NO SOLUTION";
        }
    }

    return 0;
}

