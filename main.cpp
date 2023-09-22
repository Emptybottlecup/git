#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iomanip>

using namespace std;

class Reader {
    public:
    
    Reader() {
        people.resize(100001,-1);
        pages.resize(1000,0);
    }
    
    void Read(int user, int page) {
        for (int i = people[user] + 1; i <= page; ++i) {
            ++pages[i];
        }
        people[user] = page;
    }
    
    double Cheer(int user) {
       if(people[user] == -1) {
           return 0;
       }
       if (pages[0] == 1) {
          return 1;
       }
       return (pages[0] - pages[people[user]]) * 1.0 / (pages[0] - 1) * 1.0;
    }
    private:
    vector<int> people;
    vector<int> pages;
};

int main() {
    Reader manager;
    int number_query;
    cin >> number_query;
    for(int i = 0; i <= number_query; ++i) {
        string query;
        int user;
        cin >> query >> user;
        if (query == "READ") {
            int page;
            cin >> page;
            manager.Read(user, page);
        }
        if (query == "CHEER") {
            cout << setprecision(6) << manager.Cheer(user) << "\n";
        }
    }
}