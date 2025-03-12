#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    string input;

    // string test = "SAME AS 23";
    // cout << test.find("AS") << endl;
    // cout << test.substr(test.find("AS")+3) << endl;
    // cout << stoi(test.substr(test.find("AS")+3)) << endl;


    int cases_number = 0;
    cin >> cases_number;

    if (cases_number == 0)
        return 0;

    int instructions_number = 0;
    while(cin >> instructions_number) {
        int x_axis = 0;
        cin.ignore();
        string instruction = "";
        vector<int> operation;
        for(int i = 0; i < instructions_number; i++) {
            getline(cin, instruction);
            if (instruction == "LEFT") {
                operation.push_back(-1);
                x_axis--;
            }
            else if (instruction == "RIGHT") {
                operation.push_back(1);
                x_axis++;
            }
            else {
                // int op_index = stoi(instruction.substr(instruction.find("AS")+3));
                int op_index = 0;
                for (size_t i = 8; i < instruction.size(); i++) {
                    op_index = op_index*10 + instruction[i] - '0';
                }
                
                int tmp_op = operation[op_index-1];
                operation.push_back(tmp_op);
                x_axis += tmp_op;
            }
        }
        cout << x_axis << endl;
    }


    return 0;
}
