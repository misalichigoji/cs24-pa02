#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <iomanip>
#include <set>
#include <queue>
#include <sstream>
#include <map>
#include <utility>

using namespace std;

void print_alphabetical(const map<string, double>& mbin);
void print_prefixes(const vector<string>& prefixes, const map<string, double>& mbin);
string print_prefix(const string& prefix, const map<string, double>& mbin);
string castStr(double val);