#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

void displayNumbersInVector( const vector<int>& v )
{
    for (int i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

void test1()
{
    cout << "test function 1" << endl;
    vector<int> num;
    num.push_back(1);
    num.push_back(4);
    num.push_back(3);
    cout << "size = " << num.size() << endl;
    cout << "number in container are : ";
    displayNumbersInVector(num);
}
int main()
{
    test1();
}
