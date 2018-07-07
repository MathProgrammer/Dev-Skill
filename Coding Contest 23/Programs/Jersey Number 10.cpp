#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

void solve()
{
    int no_of_players;
    cin >> no_of_players;

    string chosen;
    int max_skill = 0;

    while(no_of_players--)
    {
        string name;
        int skill;

        cin >> name >> skill;

        if(skill >= max_skill)
            max_skill = skill, chosen = name;
    }

    cout << chosen << "\n";
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
