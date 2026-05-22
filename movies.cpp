#include "movies.h"


void print_alphabetical(map<string, double> mbin)
{
    for(auto movie : mbin) //since std::map is automatically sorted in ascending order this should be alphabetical order
    {
        cout << movie.first << ", " << movie.second << endl;
    }
}