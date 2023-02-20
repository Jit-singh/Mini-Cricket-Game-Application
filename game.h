#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <unistd.h>
#include "team.cpp"           // "player.h", <string>, <vector>

class Game{
    public:
        bool isFirstInnings;
        Team teamA, teamB;
        Team *battingTeam;
        Team *bowlingTeam;
        Player *batsman;
        Player *bowler;

        Game();

        int playersPerTeam;
        int maxBalls;
        int totalPlayers;
        std:: string players[11];

        void welcome();
        void displayAllPlayers();
        int takeIntegerInput();
        void selectPlayers();
        bool validateSelectedPlayer(int);
        void displaySelectedTeamPlayers();
        void toss();
        void tossChoice(Team);

        void startFirstInnings();       // First Innings
        void initializePlayers();
        void playInnings();
        void bat();
        bool validateInningsScore();
        void displayGameScorecard();

        void startSecondInnings();      // Second Innings
        
        void displayMatchScoreboard();
};