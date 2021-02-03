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

void stage7(){
    cout << " +----+     " << endl;
    cout << " |    |     " << endl;
    cout << " |    O     " << endl;
    cout << " |   /|\\   " << endl;
    cout << " |    |     " << endl;
    cout << " |   / \\   " << endl;
    cout << " |   R.I.P. " << endl;
    cout << " ========== " << endl;
}

void stage6(){
    cout << " +----+     " << endl;
    cout << " |    |     " << endl;
    cout << " |    O     " << endl;
    cout << " |   /|\\   " << endl;
    cout << " |    |     " << endl;
    cout << " |   /      " << endl;
    cout << " |          " << endl;
    cout << " ========== " << endl;
}

void stage5(){
    cout << " +----+     " << endl;
    cout << " |    |     " << endl;
    cout << " |    O     " << endl;
    cout << " |   /|\\   " << endl;
    cout << " |    |     " << endl;
    cout << " |          " << endl;
    cout << " |          " << endl;
    cout << " ========== " << endl;
}

void stage4(){
    cout << " +----+     " << endl;
    cout << " |    |     " << endl;
    cout << " |    O     " << endl;
    cout << " |   /|\\   " << endl;
    cout << " |          " << endl;
    cout << " |          " << endl;
    cout << " |          " << endl;
    cout << " ========== " << endl;
}

void stage3(){
    cout << " +----+     " << endl;
    cout << " |    |     " << endl;
    cout << " |    O     " << endl;
    cout << " |   /|     " << endl;
    cout << " |          " << endl;
    cout << " |          " << endl;
    cout << " |          " << endl;
    cout << " ========== " << endl;
}

void stage2(){
    cout << " +----+     " << endl;
    cout << " |    |     " << endl;
    cout << " |    O     " << endl;
    cout << " |   /      " << endl;
    cout << " |          " << endl;
    cout << " |          " << endl;
    cout << " |          " << endl;
    cout << " ========== " << endl;
}

void stage1(){
    cout << " +----+     " << endl;
    cout << " |    |     " << endl;
    cout << " |    O     " << endl;
    cout << " |          " << endl;
    cout << " |          " << endl;
    cout << " |          " << endl;
    cout << " |          " << endl;
    cout << " ========== " << endl;
}

void stage0(){
    cout << " +----+     " << endl;
    cout << " |    |     " << endl;
    cout << " |          " << endl;
    cout << " |          " << endl;
    cout << " |          " << endl;
    cout << " |          " << endl;
    cout << " |          " << endl;
    cout << " ========== " << endl;
}

void displayHangman(int stage)
{
 switch(stage)
 {
    case 7: stage7(); break;
    case 6: stage6(); break;
    case 5: stage5(); break;
    case 4: stage4(); break; 
    case 3: stage3(); break; 
    case 2: stage2(); break; 
    case 1: stage1(); break; 
    case 0: stage0(); break; 
    }
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
}

int main()
{
    //test1();
    //test2();
    //test3();
    for(int i=0; i<7; i++)
    {
        displayHangman(i);
    }
} 