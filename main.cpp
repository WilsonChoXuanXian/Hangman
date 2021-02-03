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

void fillWordInPositions( const vector<int>& positions,
                          char charToFill,
                          string& word )
{
    // for (int i=0; i<positions.size(); i++)
    //     word[positions[i]] = charToFill;
    
    for (auto e : positions)
        word[e] = charToFill;
}

void test3()
{
    cout << "test function 3" << endl;
    vector<int> positions;
    positions.push_back(3);
    positions.push_back(10);

    string word= "pro_ra___n_";
    char charToFill = 'g';

    cout << "Original word is : \"" << word << "\"," << endl;
    cout << "after filling char \'" << charToFill << "\' at position ";
    displayNumbersInVector( positions );

    fillWordInPositions( positions, charToFill, word );
    cout << "word becomes \"" << word << "\"." << endl;
    //After calling function fillWordInPositions(...) above,
    // the word will be filled at position 3 and 10 with char 'g'
    // and thus the word should become : progra___ng
}

int main()
{
    //test1();
    //test2();
    test3();
} 