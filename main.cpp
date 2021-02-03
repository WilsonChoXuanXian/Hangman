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

void checkPositions(const string& secret,
                    char guess,
                    vector<int>& positions
                    )
{
    positions.clear();
    int len = secret.length();
    for(int i=0; i<len; i++)
    {
        if (guess == secret[i])
            positions.push_back(i);
    }
}

void test2()
{
    cout << "test function 2" << endl;
    string secret= "programming";
    char guess = 'g';

    vector<int> positions; //declared positions to be a container of integers
    checkPositions(secret, guess, positions);

    cout << "character \'" << guess << "\' appears in string \""
         << secret << "\" at position : ";

    //After calling function checkPositions(...) above,
    //  function displayNumbersInVector below should display: 3 10
    //  because char 'g' appears in position 3 and 10 of string secret
    
    displayNumbersInVector( positions );
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
    // test1();
    test2();
}
