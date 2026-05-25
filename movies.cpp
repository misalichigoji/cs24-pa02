#include "movies.h"

void print_alphabetical(const map<string, double>& mbin)
{
    for(auto movie : mbin) //since std::map is automatically sorted in ascending order this should be alphabetical order
    {
        cout << movie.first << ", " << movie.second << endl;
    }
}

void print_prefixes(const vector<string>& prefixes, const map<string, double>& mbin)
{
    vector<string> largest_prefix;

    for (const string& prefix : prefixes) {
        string largest = print_prefix(prefix, mbin);
        largest_prefix.push_back(largest);

        if (largest.empty()) 
            cout << "No movies found with prefix " << prefix << endl;
        if (!largest.empty()) 
            cout << endl;
    }

    for (int i = 0; i < prefixes.size(); i++) {
        if (!largest_prefix[i].empty()) 
            cout << "Best movie with prefix " << prefixes[i] << " is: " << largest_prefix[i] << endl;
    }
}

string print_prefix(const string& prefix, const map<string, double>& mbin)
{
    struct Compare {
        bool operator()(const pair<double,string>& a, const pair<double,string>& b)
        {
            if(a.first == b.first)
                return a.second > b.second;

            return a.first < b.first;
        }
    };

    priority_queue<
        pair<double,string>,
        vector<pair<double,string>>,
        Compare
    > premovie;

    string greatest;
    int plength = prefix.length();

    for(const auto& movie : mbin)
    {
        if(movie.first.compare(0, plength, prefix) == 0)
            premovie.push({movie.second, movie.first});
    }

    if(!premovie.empty())
        greatest = premovie.top().second + " with rating " + castStr(premovie.top().first);

    while(!premovie.empty())
    {
        cout << premovie.top().second << ", " << castStr(premovie.top().first) << endl;
        premovie.pop();
    }

    return greatest;
}

string castStr(double val)
{
    ostringstream oss;
    oss << val;
    return oss.str();
}