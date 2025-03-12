#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    string letter_line;

    int n = 0;
    vector<string> distinct_words;

    while(getline(cin, letter_line)) {

        if (letter_line == "0") {
            break;
        }
        
        for (size_t i = 0; i < letter_line.size(); i++) {

            char c = letter_line[i];
            if ((c >= 'a' && c <= 'z' ) || (c >= 'A' && c <= 'Z')) {
                string tmp = "";
                while ((letter_line[i] >= 'a' && letter_line[i] <= 'z' ) || (letter_line[i] >= 'A' && letter_line[i] <= 'Z'))
                {
                    tmp += letter_line[i];
                    i++;
                }
                i--;
                distinct_words.push_back(tmp);
                cout << tmp;
            }
    
            else if (c >= '1' && c <= '9') {
                int nth = 0;
                while (letter_line[i] >= '0' && letter_line[i] <= '9') {
                    nth = nth * 10 + letter_line[i] - '0';
                    i++;
                }
                i--;
                nth = distinct_words.size() - nth;

                string nth_word = distinct_words[nth];
                cout << nth_word;
                distinct_words.erase(distinct_words.begin() + nth);
                distinct_words.push_back(nth_word);
            }
    
            else {
                cout << c;
            }

        }

        // cout << "line " << n << " : " << letter_line << endl;
        cout << endl;
        n++;
    }


    return 0;
}