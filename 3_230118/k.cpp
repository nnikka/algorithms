#include<iostream> 
#include <list> 
#include <stdlib.h>
#include <algorithm>
#include <vector>


using namespace std; 

struct Emp {
    string name;
    int salary;
};

bool compareEmp(const Emp  &a, const Emp  &b)
{
    return b.salary < a.salary;
}

int main() 
{  
    ios::sync_with_stdio(false);
    int n, m, max;
    cin >> n;
    cin >> m;
    cin >> max;

    vector<Emp> emps;

    for (int i = 0; i < n; i++) {
        Emp emp;
        cin >> emp.name;
        cin >> emp.salary;
        emps.push_back(emp);
    }

    sort(emps.begin(), emps.end(), compareEmp);

    // for (int i = 0; i < n; i++) {
    //     cout << emps[i].salary << endl;
    // }

    int current = 0;
    int sum = 0;
    for (int i = 0; i < max; i++) {
        if (current < m) {
            sum++;
        }
        current += emps[i].salary;
    }
    
    if (current < m) {
        cout << "impossible" << endl;
        return 0;
    } else {
        cout << sum << endl;
        int curhere = 0;
        int counter = 0;
        while (curhere < m) {
            curhere += emps[counter].salary;
            cout << emps[counter].name << ", YOU ARE FIRED!" << endl;
            counter++;
        }
    }


    return 0;
} 
