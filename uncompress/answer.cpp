#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <map>
#include <sstream>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int,int> pii;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    
    vector<string> dic;
    string inputline;

    while( getline(cin, inputline) ){

        if( inputline == "0" )
            break;

        for( size_t i=0; i < inputline.size(); i++ ){

            if(( inputline[i] >='a' && inputline[i] <= 'z' ) || ( inputline[i] >= 'A' && inputline[i] <= 'Z' )) {

                string tmp = "";

                while(( inputline[i] >= 'a' && inputline[i] <= 'z' )||( inputline[i] >= 'A' && inputline[i] <= 'Z' ))
                    tmp+=inputline[i++];
                i--;
                dic.push_back(tmp);
                cout << tmp;
            }
            
            else if( inputline[i] >= '0' && inputline[i] <= '9' ){
                int val = 0;
                
                while( inputline[i] >= '0' && inputline[i] <= '9' )
                    val = val*10 + inputline[i++] - '0';
                i--;
                
                string tmp = dic[dic.size()-val];

                dic.erase(dic.end()-val);
                dic.push_back(tmp);

                cout << tmp;
            }

            else
                cout << inputline[i];
        }

        cout << '\n';
    }

    return 0;
}
