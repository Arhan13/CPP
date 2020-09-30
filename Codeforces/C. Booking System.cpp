//Template
#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = int(a); i < int(n); i++)
#define endl "\n"
#define vi vector<int>
#define se set<char>
#define pb push_back
#define um unordered_map
typedef long long ll;
using namespace std;

class group
{
public:
    int id;
    int income;
    int size;
};

class table
{
public:
    int size;
    int id;
};

bool incomeDecreasing(const group&g1, const group&g2) {
    return g1.income > g2.income;
}

bool bySizeIncerasing(const table&t1, const table&t2) {
    return t1.size < t2.size;
}

bool canFit(const table&t, const group& g) {
    return g.size > t.size;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;cin>>n;
    vector<group> groups(n);
    // vector<table> tables()
    for(int i=0;i<n;i++) {
        groups[i].id = i+1;
        cin>> groups[i].size;
        cin>> groups[i].income;
    }

    sort(groups.begin(), groups.end(), incomeDecreasing);

    ll m;cin>>m;
    vector<table> tables(m);
    for(int i=0;i<m;i++) {
        tables[i].id = i+1;
        cin>>tables[i].size;
    }

    sort(tables.begin(), tables.end(), bySizeIncerasing);

    int sum=0;
    vector<pair<int, int>> ans;
    for(int i=0;i<n;i++) {
        auto group = groups[i];
        auto TableToGive = lower_bound(tables.begin(), tables.end(), group, canFit);
        //Here group show become larger than table to break and get lower_bound;
        if(TableToGive==tables.end()) continue;

        sum+= group.income;
        ans.push_back(make_pair(group.id, TableToGive->id ));
        tables.erase(TableToGive );
    }
    cout<<ans.size()<<" "<<sum<<endl;
    for( auto q: ans) {
        cout<<q.first<<" "<<q.second<<endl;
    }
    return 0;
}