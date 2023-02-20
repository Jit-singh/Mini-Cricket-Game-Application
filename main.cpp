#include "game.cpp"
using namespace std;

int main(){

    Game game;
    game.welcome();

    cout << "\nPress Enter to continue...";
    getchar();
    game.displayAllPlayers();
    
    cout << "\nPress Enter to continue...";
    getchar();
    game.selectPlayers();

    sleep(2);
    game.displaySelectedTeamPlayers();
    
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    
    cout << "\nPress Enter to toss...";
    getchar();
    game.toss();
    
    sleep(3);
    game.startFirstInnings();
    sleep(3);
    game.startSecondInnings();
    sleep(4);
    game.displayMatchScoreboard();

   return 0;
}
