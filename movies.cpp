#include "movies.h"

void print_alphabetical(map<string, double> mbin)
{
    for(auto movie : mbin) //since std::map is automatically sorted in ascending order this should be alphabetical order
    {
        cout << movie.first << ", " << movie.second << endl;
    }
}

void print_prefixes(vector<string> prefixes, map<string, double> mbin)
{
    for(int i = 0; i < prefixes.size(); i++)
    {
        string best = print_prefix(prefixes[i], mbin);

        if(best.empty())
            cout << "No movies found with prefix " << prefixes[i] << endl;
        else
            cout << "\nBest movie with prefix " << prefixes[i] << " is: " << best << endl;
        if(i != prefixes.size() - 1)
            cout << endl;
    }
}

string print_prefix(string prefix, map<string, double> mbin)
{
    vector<pair<double,string>> prefixed;

    for(auto movie : mbin)
    {
        if(movie.first.compare(0, prefix.length(), prefix) == 0)
            prefixed.push_back({movie.second, movie.first});
    }

    if(prefixed.empty())
        return "";

    sort(prefixed.begin(), prefixed.end(),
        [](const pair<double,string>& a,
           const pair<double,string>& b)
        {
            if(a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        });

    for(auto &m : prefixed)
        cout << m.second << ", " << m.first << endl;

    return prefixed[0].second + " with rating " + castStr(prefixed[0].first);
}

string castStr(double val)
{
    ostringstream oss;
    oss << val;
    return oss.str();
}