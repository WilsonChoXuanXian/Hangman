#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <ctime>
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

string getSecret(){
    string words[] = {"programming","multimedia","university","computer","worldwide",
                      "putrajaya","sarawak"};
    srand(time(NULL));
    int r=rand()%8;
    return words[r];

}

void hangman(){
    
        vector<int> positions;
        vector<char> letterChosen;
        string secret = getSecret();
        string word(secret.length(),'_');
        char guess;
        int lastStage = 7;
        int stage = 0;

        system("clear");

        displayHangman(stage);
        cout << word << endl
             << endl;
        do
        {
            bool correct = 0;

            cout << "Letters that you've chosen but not the secret word => ";

            for (int i=0; i<letterChosen.size();i++)
            {
                cout << letterChosen[i];

                if (i != letterChosen.size()-1)
                    cout << ", ";
            }

            cout << endl << "Guess the string => ";
            cin >> guess;

            for(int i=0; i<secret.length(); i++)
                if (guess == secret[i])
                    correct = 1;
                    
            for(int i=0; i<letterChosen.size(); i++)
                if (guess == letterChosen[i])
                    correct = 1;

            if (!correct)
                letterChosen.push_back(guess);

            checkPositions(secret, guess, positions);

            fillWordInPositions(positions, guess, word);

            if (positions.size() == 0)
                stage += 1;
            
            system("clear");
            displayHangman(stage);
            cout << word << endl
                 << endl;
        }
        while( secret != word && stage != lastStage );

        if (stage == lastStage)
            cout << "You are DEAD! " << endl;
        else
            cout << "Congratulation, you are safe! " << endl;
}

bool playAgn(){

    bool TorF = false;
    char YESorNO;

    cout << endl << endl
         << "Do you want to PLAY AGAIN ?  (y/n)" << endl;
    cin >> YESorNO;

    if (YESorNO == 'y')
        TorF = true;
    else TorF = false;

return TorF;
}

int main()
{
    bool playAgain = false;

    do{
    hangman();
    playAgain = playAgn();
    }while(playAgain);

return 0;
}