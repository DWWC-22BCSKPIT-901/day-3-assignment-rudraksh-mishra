#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string makeLargestSpecial(string s) {
    if (s.empty()) return s;

    vector<string> specials;

    int counter  = 0; 
    int startIdx = 0;

    for (int currentIdx = 0; currentIdx < s.size(); ++currentIdx) {
        counter += s[currentIdx] == '1' ? 1 : -1;

        if (counter == 0) {
            specials.push_back(
                "1" + makeLargestSpecial(
                    s.substr(
                        startIdx + 1, 
                        currentIdx - startIdx - 1
                    )
                ) + "0"
            );
            startIdx = currentIdx + 1;
        }
    }

    sort(specials.begin(), specials.end(), greater<string>());

    return accumulate(specials.begin(), specials.end(), string{});
}

int main() {
    string s = "11011000";
    cout << "String : " << s << endl;
    cout << "Result : " << makeLargestSpecial(s);
}