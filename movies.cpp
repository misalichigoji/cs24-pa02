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
    vector<string> largest_prefix;
    int size = prefixes.size();
    for(int i = 0; i < size; i++)
    {
        largest_prefix.push_back(print_prefix(prefixes[i], mbin));
        cout << endl;
    }
    for(int i = 0; i < size; i++)
    {
        if(largest_prefix[i].empty())
            cout << "No movies found with prefix " << prefixes[i] << endl;
        else
            cout << "Best movie with prefix " << prefixes[i] << " is: " << largest_prefix[i] << endl;
    }
}

string print_prefix(string prefix, map<string, double> mbin)
{
    string greatest;
    priority_queue<pair<double, string>> premovie;
    int plength = prefix.length();
    for(auto movie : mbin)
    {
        if((movie.first).substr(0,plength) == prefix)
            premovie.push({movie.second, movie.first});
    }
    if(!premovie.empty())
        greatest = premovie.top().second + " with rating " + format("{}", premovie.top().first);
    while(!premovie.empty())
    {
        cout << premovie.top().second << ", " << format("{}", premovie.top().first) << endl;
        premovie.pop();
    }
    return greatest;
}

string doubleCast(const)