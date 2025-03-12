#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <map>
#include <sstream>
#include <set>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    int frosh = 0;

    while (cin >> frosh && frosh)
    {
        vector<set<int>> courses(frosh);
        int pop = 0;
        for (int i = 0; i < frosh; i++)
        {
            for (int n = 0; n < 5; n++)
            {
                int class_num;
                cin >> class_num;
                courses[i].insert(class_num);
            }
            
            // for (auto i : courses[i])
            // {
            //     cout << i << " ";
            // }
            // cout << endl;
        }

        map<set<int>, int> class_pop;
        for (int i = 0; i < frosh; i++)
        {
            // cout << "frosh " << i << ": ";
            // for (auto i : courses[i])
            //     cout << i << " ";
            // cout << endl;
            // cout << "count: " << count(courses.begin(), courses.end(), courses[i]) << endl;
            
        //     int course_count = count(courses.begin(), courses.end(), courses[i]);
        //     class_pop[courses[i]] = course_count;
        //     pop = max(pop, course_count);
        // }

        // int pop_class_tot = 0;
        // for (auto i : class_pop)
        //     if (i.second == pop)
        //         pop_class_tot++;
        

        // cout << pop_class_tot << endl;
        
    }
    

    

    return 0;
}