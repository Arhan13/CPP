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
ll days_counter(ll x, ll value)
{
    ll counter = 0;
    if (x >= value)
    {
        return 0;
    }
    while (x < value)
    {
        x = x * 2;
        counter++;
    }
    // cout<<counter<<endl;
    return counter;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        int master_flag = 0;
        ll master_answer1 = 0;
        ll master_answer2 = 0;
        ll n, x;
        cin >> n >> x;
        vector<ll> pop = {};
        vector<ll>::iterator it;
        int giveup_flag = 0;
        // it = pop.begin();
        for (ll i = 0; i < n; i++)
        {
            ll data;
            cin >> data;
            pop.push_back(data);
        }
        ll days = 0;
        ll infliction_pt;
        ll cure_quant = x;
        sort(pop.begin(), pop.end());
        ll days_to_be_removed = 0;
        if (cure_quant >= pop[n - 1])
        {
            cout << n << endl;
            master_flag = 1;
        }

        if (master_flag == 0)
        {
            for (ll i = 0; i < n; i++)
            {
                if (x <= pop[i])
                {
                    infliction_pt = i;
                    break;
                }
            }
            while (2 * pop[infliction_pt - 1] >= pop[infliction_pt] && infliction_pt-1>=0)
            {
                infliction_pt--;
            }
            days = 0;
            for (ll i = infliction_pt; i < n; i++)
            {
                ll newdays = days_counter(cure_quant, pop[i]);
                days += newdays;
                if (pop[i] <= (pow(2, newdays) * cure_quant))
                {
                    cure_quant = 2 * pop[i];
                }
                else
                {
                    cure_quant = 2 * pow(2, newdays) * cure_quant;
                }
                days++;
            }
            for (ll i = infliction_pt - 1; i >= 0; i--)
            {
                ll newdays = days_counter(cure_quant, pop[i]);
                days += newdays;
                if (pop[i] <= (pow(2, newdays) * cure_quant))
                {
                    cure_quant = 2 * pop[i];
                }
                else
                {
                    cure_quant = 2 * pow(2, newdays) * cure_quant;
                }
                days++;
            }
            // cout<<days<<endl;
            master_answer1 = days;

            days = 0;
            cure_quant=x;
            //Method 2
            ll pointer1 = n - 1;
            ll pointer2 = 0;
            while (pointer2 <= n - 2)
            {
                if (cure_quant >= pop[pointer2])
                {
                    days++;
                    cure_quant = 2 * pop[pointer2];
                    pointer2++;
                }
                else if (cure_quant < pop[pointer2])
                {
                    if (2 * cure_quant < pop[pointer1])
                    {
                        days++;
                        cure_quant = 2 * cure_quant;
                    }
                    else if (2 * cure_quant >= pop[pointer1])
                    {
                        // cout << "Im here" << endl;
                        // days++;
                        days += pointer1 - pointer2 + 1;
                        giveup_flag = 1;
                        break;
                    }
                }
            }
            if (giveup_flag == 0)
            {
                while (cure_quant < pop[pointer1])
                {
                    cure_quant *= 2;
                    days++;
                }
                if (cure_quant >= pop[pointer1])
                {
                    days++;
                }
            }
            master_answer2 = days;
            cout<<master_answer1<<" "<<master_answer2<<endl;
            if(pop[0]==pop[n-1]) {
                cout<<master_answer1<<endl;
            }
            else {
                cout << min(master_answer1, master_answer2) << endl;
            }
            
        }
    }
    return 0;
}

