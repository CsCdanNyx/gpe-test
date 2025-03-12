#include <bits/stdc++.h>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    stringstream ss("");

    while (getline(cin, line)) {

        if (line[0] == '.')
            break;

        ss << line;
        string aword;
        vector<string> exp_list;

        while (ss >> aword)
            exp_list.push_back(aword);
        
        ss.clear();
        ss.str("");


        reverse(exp_list.begin(), exp_list.end());

        stack<int> num_stack;

        bool err_check = false;

        for (auto exp: exp_list)
        {
            if (isdigit(exp[0]))
                num_stack.push(stoi(exp));
            else
            {
                int a, b;
                if (num_stack.empty()) {  err_check = true;  break; }
                else { a = num_stack.top(); num_stack.pop(); }
                if (num_stack.empty()) {  err_check = true;  break; }
                else { b = num_stack.top(); num_stack.pop(); }

                if (exp == "+")
                    num_stack.push(a+b);

                else if (exp == "-")
                    num_stack.push(a-b);

                else if (exp == "*")
                    num_stack.push(a*b);

                else if (exp == "/")
                    num_stack.push(a/b);

                else if (exp == "%")
                    num_stack.push(a%b);
                
            }
        }
        
        if (err_check)
            cout << "illegal" << endl;
        else
            cout << num_stack.top() << endl;


    }


    return 0;
}