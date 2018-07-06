#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

#define all(v) (v).begin(), (v).end()
typedef long long LL;

using namespace std;

const int MAX_N = 1e6;
LL sum_tree[MAX_N];

LL sum(int index)
{
     LL answer = 0;
     for(; index > 0; index -= index&-index)
        answer += sum_tree[index];

     return answer;
}

void update(int index, int value)
{
      for(; index < MAX_N; index += index&-index)
        sum_tree[index] += value;
}

void solve()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <LL> A(no_of_elements + 1);
    vector <LL> alternate_A;

    for(int i = 1; i <= no_of_elements; i++)
    {
        scanf("%lld", &A[i]);

        alternate_A.push_back(A[i]);
        alternate_A.push_back(2*A[i]);
    }

    sort(all(alternate_A));
    map <LL, int> rank;
    rank[alternate_A[0]] = 1;
    for(int i = 1; i < alternate_A.size(); i++)
        if(rank[alternate_A[i]] == 0)
            rank[alternate_A[i]] = 1 + rank[alternate_A[i - 1]];

    memset(sum_tree, 0, sizeof(sum_tree));
    int array_size = alternate_A.size() + 1;
    LL answer = 0;
    for(int i = no_of_elements; i >= 1; i--)
    {
        answer += sum(array_size) - sum(rank[2*A[i]] - 1);

        update(rank[A[i]], 1);
    }

    printf("%lld\n", answer);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

