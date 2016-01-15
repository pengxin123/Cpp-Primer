//
// @author Xin Peng
//
// Exercise 10.24:
// Use bind and check_size to find the first element in a vector of ints that has a value greater
// than the length of a specified string value.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::find_if;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz)
{
    return s.size() < sz;
}
vector<int>::iterator find_first_greater( vector<int> & v, const string &str)
{
     return find_if(v.begin(),v.end(),bind(check_size, str, _1));
}

int main()
{
    vector<int> vec{ 0, 1, 2, 3, 4, 5, 6, 7 };
    string str("abcdef");
    auto result = find_first_greater(vec, str);
    if (result != vec.cend())
        cout << *result << endl;
    else
        cout << "Not found" << endl;
    return 0;
}  
