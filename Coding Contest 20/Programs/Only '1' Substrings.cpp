#include <iostream>
#include <string>

using namespace std;

long long count_total(long long n)
{
    return (n*(n + 1))/2;
}

void solve()
{
    string S;
    cin >> S;

    long long no_of_substrings = 0, current_substring_length = 0;

    for(int i = 0; i <= S.size(); i++)
    {
        if(i == S.size() || S[i] == '0')
        {
            no_of_substrings += count_total(current_substring_length);
            current_substring_length = 0;
        }
        else if(S[i] == '1')
        {
            current_substring_length++;
        }
    }
    cout << no_of_substrings << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
