#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <cctype>

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

string dashes(int NumberOfDashes)
{
    return string(NumberOfDashes, '-');
}

string Tabs(int NumberOfTabs)
{
    return string(NumberOfTabs, '\t');
}

enum enRock_Paper_Scissors {Rock = 1, Paper = 2, Scissors = 3};
enum enWinner {Draw = 0, Player = 1, Computer = 2};

struct stRoundResults
{
    enRock_Paper_Scissors PlayerChoose, ComputerChoose;
    enWinner Winner;
};

struct stGameResults
{
    int GameRounds = 0;
    int PlayerWonTimes = 0;
    int ComputerWonTimes = 0;
    int DrawTimes = 0;
    enWinner FinalWinner;
};

int RandomNumber(int From, int To)
{
    int randnum = rand() % (To - From + 1) + From;
    return randnum;
}

void ClearBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

short AskNumberOfRounds(string message)
{
    short Rounds;
    cout << message;
    
    while(true)
    {
        cin >> Rounds;
        
        if(cin.fail() || cin.peek() != '\n')
        {
            ClearBuffer();
            cout << "Entre Only a positive Number: ";
        }
        else if(Rounds < 1 || Rounds > 10)
        {
            cout << "Only choose between 1 To 10: ";
        }
        else 
            return Rounds;
    }
}

char PlayAgain()
{
    char Continue;
    cout << "Do you want to play again? Y/N? ";
    
    while(true)
    {
        cin >> Continue;
        Continue = toupper(Continue);
        
        if((Continue != 'Y' && Continue != 'N') || cin.peek() != '\n')
        {
            ClearBuffer();
            cout << "Entre Only Y/N ";
        }
        else{
            cout << '\n';
            return Continue;
        }
    }
}

enRock_Paper_Scissors PlayerChooseFunc()
{
    short Choice;
    cout << "Choose one item: [1]: Rock, [2]: Paper, [3]: Scissors\n";
    
    while(true)
    {
        cin >> Choice;
        
        if(cin.fail() || cin.peek() != '\n')
        {
            ClearBuffer();
            cout << "Entre Only a positive Number: ";
        }
        else if(Choice < 1 || Choice > 3)
        {
            cout << "Please entre only 1 or 2 or 3: ";
        }
        else 
            return (enRock_Paper_Scissors)Choice;
    }
}

enRock_Paper_Scissors ComputerChooseFunc()
{
    return (enRock_Paper_Scissors)RandomNumber(1, 3);
}

string DetermineChoiceItem(enRock_Paper_Scissors &Item)
{
    string item[] {"Rock", "Paper", "Scissors"};
    
    return item[Item - 1];
}

string DetermineWinnerName(enWinner &WinnerName)
{
    string Name[] {"Draw", "Player", "Computer"};
    
    return Name[WinnerName];
}

enWinner DetermineRoundWinner(stRoundResults &RoundData)
{
    if(RoundData.PlayerChoose == RoundData.ComputerChoose)
    {
        return enWinner::Draw;
    }
    
    switch(RoundData.PlayerChoose)
    {
        case enRock_Paper_Scissors::Rock:
        {
            if(RoundData.ComputerChoose == enRock_Paper_Scissors::Scissors)
            {
                return enWinner::Player;
            }
        }
        case enRock_Paper_Scissors::Paper:
        {
            if(RoundData.ComputerChoose == enRock_Paper_Scissors::Rock)
            {
                return enWinner::Player;
            }
        }
        case enRock_Paper_Scissors::Scissors:
        {
            if(RoundData.ComputerChoose == enRock_Paper_Scissors::Paper)
            {
                return enWinner::Player;
            }
        }
    }
    
    return enWinner::Computer;
}

void UpdataGameData(stGameResults &GameData, enWinner Winner)
{
    switch(Winner)
    {
        case enWinner::Draw:
        {
            GameData.DrawTimes++;
            break;
        }
        case enWinner::Player:
        {
            GameData.PlayerWonTimes++;
            break;
        }
        case enWinner::Computer:
        {
            GameData.ComputerWonTimes++;
            break;
        }
    }
}

void PrintRoundResult(stRoundResults &RoundData, short Round)
{
    cout << '\n' << dashes(14) << "Round [" << Round << ']' << dashes(14) << "\n\n";
    
    cout << "Player Choose: " << DetermineChoiceItem(RoundData.PlayerChoose) << ".\n";
    cout << "Computer Choose: " << DetermineChoiceItem(RoundData.ComputerChoose) << ".\n";
    cout << "Round Winner : " << DetermineWinnerName(RoundData.Winner) << ".\n";
    
    cout << '\n' << dashes(37) << "\n\n";
}

void DetermineFinalWinner(stGameResults &GameData)
{
    if(GameData.PlayerWonTimes == GameData.ComputerWonTimes)
        GameData.FinalWinner = enWinner::Draw;
    
    if(GameData.PlayerWonTimes > GameData.ComputerWonTimes)
        GameData.FinalWinner = enWinner::Player;
    
    if(GameData.PlayerWonTimes < GameData.ComputerWonTimes)
        GameData.FinalWinner = enWinner::Computer;
}

void ShowGameOverScreen()
{
    cout << Tabs(4) << dashes(73) << "\n\n";
    cout << Tabs(7) << "*** G a m e  O v e r ***\n\n";
    cout << Tabs(4) << dashes(73) << "\n\n";
}

void ShowFinalGameResults(stGameResults &GameData)
{
    cout << Tabs(4) << dashes(28) << "[Game Results]" << dashes(31) << "\n\n";
    cout << Tabs(4) << "Game Rounds        : " << GameData.GameRounds << '\n';
    cout << Tabs(4) << "Player won times   : " << GameData.PlayerWonTimes << '\n';
    cout << Tabs(4) << "Computer won times : " << GameData.ComputerWonTimes << '\n';
    cout << Tabs(4) << "Draw times         : " << GameData.DrawTimes << '\n';
    cout << Tabs(4) << "Final winner       : " << DetermineWinnerName(GameData.FinalWinner) << '\n';
    
    cout << "\n\n" << Tabs(4) << dashes(73) << "\n\n";
}

void PrintGameResults(stGameResults &GameData)
{
    ShowGameOverScreen();
    ShowFinalGameResults(GameData);
}

stGameResults PlayGame(short RoundsNum)
{
    stRoundResults RoundData;
    stGameResults GameData;
    GameData.GameRounds = RoundsNum;
    
    for(short Round = 1; Round <= RoundsNum; Round++)
    {
        cout << "\nRound [" << Round << "] begins:\n";
        
        RoundData.PlayerChoose = PlayerChooseFunc();
        RoundData.ComputerChoose = ComputerChooseFunc();
        
        RoundData.Winner = DetermineRoundWinner(RoundData);
        UpdataGameData(GameData, RoundData.Winner);
        
        PrintRoundResult(RoundData, Round);
    }
    
    return GameData;
}

void Rock_Paper_Scissors()
{
    do
    {
        system("clear");
        ResetScreen();
        
        cout << "\n\n" << Tabs(6) << "*** Welcome to the Rock_Paper_Scissors game!! ***\n\n";
        
        stGameResults GameData = PlayGame(AskNumberOfRounds("How many rounds do you want?\nOnly choose between 1 To 10: "));
        
        DetermineFinalWinner(GameData);
        PrintGameResults(GameData);
        
    } while(PlayAgain() == 'Y');
    
    cout << '\n' << Tabs(6) << "*** Thank you for playing my game. ***";
}

int main(void)
{
    srand((unsigned)time(NULL));
    
    Rock_Paper_Scissors();
    
    return 0;
}
