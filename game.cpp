#include "game.h"           // "player.h", <string>, <vector>
using namespace std;

Game :: Game(){
    isFirstInnings = false;
    teamA.name = "Team-A";
    teamB.name = "Team-B";

    playersPerTeam = 4;
    maxBalls = 6;
    totalPlayers = 11;

    players[0] = "Virat";
    players[1] = "Rohit";
    players[2] = "Dhawan";
    players[3] = "Pant";
    players[4] = "Karthik";
    players[5] = "Rahul";
    players[6] = "Jadeja";
    players[7] = "Hardik";
    players[8] = "Bumrah";
    players[9] = "B.Kumar";
    players[10] = "Ishant";

}

void Game :: welcome(){
    cout << " ____________________________________________________________________________________________ " << endl;
    cout << "|                                                                                            |" << endl;
    cout << "|                       !!!   Welcome to Virtual Cricket Game   !!!                          |" << endl;
    cout << "|____________________________________________________________________________________________|" << endl << endl;
    sleep(1);
    cout << " ____________________________________________________________________________________________ " << endl;
    cout << "|                                                                                            |" << endl;
    cout << "|                                    < Instructions >                                        |" << endl;
    cout << "|--------------------------------------------------------------------------------------------|" << endl;
    cout << "|                                                                                            |" << endl;
    cout << "|  1. Create 2 teams (Team-A & Team-B with 4 players each) from a given pool of 11 players.  |" << endl;
    cout << "|  2. Lead the toss and decide the choice of play.                                           |" << endl;
    cout << "|  3. Each innings will be of 6 balls.                                                       |" << endl;
    cout << "|____________________________________________________________________________________________|" << endl;
}

void Game :: displayAllPlayers() {
    cout << " ____________________________________________________________________________________________ " << endl;
    cout << "|                                                                                            |" << endl;
    cout << "|                                  < Players Name List >                                     |" << endl;
    cout << "|--------------------------------------------------------------------------------------------|" << endl;
    for (int i=0; i<totalPlayers; i++) {
        cout << "|\t\t[" << i << "]. " << players[i] << "\t\t\t\t\t\t\t\t     |" << endl;
    }
    cout << "|____________________________________________________________________________________________|" << endl;
}

int Game::takeIntegerInput() {                      // Validation for taking integer value only
    int n;
    while(!(cin >> n)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please try again with valid input: "; 
    }
    return n;
}

bool Game::validateSelectedPlayer(int index) {      // Validation for already selected player
    int n;
    vector<Player> players;

    players = teamA.players;
    n = players.size();
    for(int i=0; i<n; i++) { 
        if (players[i].id == index) {
            return false;
        }
    }

    players = teamB.players;
    n = players.size();
    for(int i=0; i<n; i++) {
        if (players[i].id == index) {
            return false;
        }
    }
    return true;
}

void Game::selectPlayers() {                        // Player Selection
    cout << " ____________________________________________________________________________________________ " << endl;
    cout << "|                                                                                            |" << endl;
    cout << "|                          !!!   Create Team-A and Team-B   !!!                              |" << endl;
    cout << "|____________________________________________________________________________________________|" << endl << endl;

    cout << endl << "Select players for Team-A " << endl;
    for (int i=0; i < playersPerTeam; i++) {
        teamA_selection:                            // Goto Label for Team A
            cout << "Player " << i+1 << " id : ";
            int playerId_TeamA = takeIntegerInput();

            if (playerId_TeamA < 0 || playerId_TeamA > 10) {
                cout << "Invalid Id! Please enter a valid id." << endl;
                goto teamA_selection;
            }
            else if (!validateSelectedPlayer(playerId_TeamA)){
                cout << "Player has been already selected. Please select other player" << endl;
                goto teamA_selection;
            }
            else{
                Player player_TeamA;                // create object of type player
                player_TeamA.id = playerId_TeamA;
                player_TeamA.name = players[playerId_TeamA];
                teamA.players.push_back(player_TeamA);
            }
            
    }

    cout << endl << "Select players for Team-B " << endl; 
    for (int i=0; i < playersPerTeam; i++) {
        teamB_selection :                           // Goto Label for Team-A
            cout << "Player " << i+1 << " id : ";
            int playerId_TeamB = takeIntegerInput();

            if(playerId_TeamB < 0 || playerId_TeamB > 10)
            {
                cout << "Invalid Id! Please enter a valid id." << endl;
                goto teamB_selection;
            }
            else if (!validateSelectedPlayer(playerId_TeamB)){
                cout << "Player has been already selected. Please select other player" << endl;
                goto teamB_selection;
            }
            else
            {
                Player player_TeamB;            // create object of type player for team-B
                player_TeamB.id = playerId_TeamB;
                player_TeamB.name = players[playerId_TeamB];
                teamB.players.push_back(player_TeamB);
            }
    }
}

void Game::displaySelectedTeamPlayers() {       // Display Selected Team Players
    vector<Player> teamAPlayers = teamA.players;
    vector<Player> teamBPlayers = teamB.players;

    cout << endl << endl;
    cout << " ____________________________________________________________________________________________ " << endl;
    cout << "|                                                                                            |" << endl;
    cout << "|                                !!!   Selected Players   !!!                                |" << endl;
    cout << "|____________________________________________________________________________________________|" << endl;
    cout << "|                                             |                                              |" << endl;
    cout << "|               Team - A                      |                 Team - B                     |" << endl;
    cout << "|_____________________________________________|______________________________________________|" << endl;
    cout << "|                                             |                                              |" << endl;

    for (int i=0; i<playersPerTeam; i++){
        cout << "|\t\t" << "[" << i << "] " << teamAPlayers[i].name << "\t\t      "
                << "|\t\t\t" << "[" << i << "] " << teamBPlayers[i].name << "\t\t     |" << endl;
    }
    cout << "|_____________________________________________|______________________________________________|" << endl;
}

void Game::toss(){                              //  Toss for batting and bowling
    cout << endl << "Tossing the coin..." << endl << endl;
    sleep(3);
    srand(time(NULL));
    int randomValue = rand() % 2;
    switch(randomValue){
        case 0: 
            cout << "Team-A won the toss" << endl << endl; 
            tossChoice(teamA);
            break;

        case 1: 
            cout << "Team-B won the toss" << endl << endl; 
            tossChoice(teamB);
            break;
    }
}

void Game::tossChoice(Team tossWinnerTeam){     // After toss win choose batting or bowling
    cout << "Choose either batting with press 1 or bowling with press 2." << endl;
    int tossInput = takeIntegerInput();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch(tossInput){
        case 1:
        {
            cout << endl << tossWinnerTeam.name << " has decided to bat first." << endl << endl;
            if(tossWinnerTeam.name.compare("Team-A") == 0){
                battingTeam = &teamA;
                bowlingTeam = &teamB;
            } else{
                battingTeam = &teamB;
                bowlingTeam = &teamA;
            }
            break;
        }

        case 2:
        {
            cout << endl << tossWinnerTeam.name << " has decided to bowl first." << endl << endl;
            if(tossWinnerTeam.name.compare("Team-A") == 0){
                battingTeam = &teamB;
                bowlingTeam = &teamA;
            } else{
                battingTeam = &teamA;
                bowlingTeam = &teamB;
            }
            break;
        }

        default:
        {
            cout << endl << "Invalid input. Please try again:" << endl << endl;
            tossChoice(tossWinnerTeam);
            break;
        }
    }
}

//-------------------------------------- First Inning Starts ----------------------------------------
void Game::startFirstInnings(){ 
    cout << "################################!!!   FIRST INNING STARTS   !!!###############################" << endl << endl;
    isFirstInnings = true;
    initializePlayers();
    playInnings();
}

void Game::initializePlayers(){
    // choose batsman and bowler: Initialize *batsman and *bowleer
    batsman = &battingTeam -> players[0];
    bowler = &bowlingTeam -> players[0];
    sleep(2);
    cout << battingTeam->name << " --> " << batsman->name << " is batting" << endl;
    cout << bowlingTeam->name << " --> " << bowler->name << " is bowling" << endl << endl;
}

void Game::playInnings(){
    for(int i=0; i<maxBalls; i++){
        cout << "Press Enter to bowl...";
        getchar();
        cout << "Bowling..." << endl;

        bat();

        if(!validateInningsScore()){
            break;
        }
    }
}

void Game::bat(){
    srand(time(NULL));
    int runsScored = rand() % 7;

    // update batting team and batsman score
    batsman->runsScored = batsman->runsScored + runsScored;
    battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;
    batsman->ballsPlayed = batsman->ballsPlayed + 1;

    // update bowling team and bowler score
    bowler->ballsBowled = bowler->ballsBowled + 1;
    bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;
    bowler->runsGiven = bowler->runsGiven + runsScored;
    sleep(2);

    if(runsScored !=0){
        cout << endl << bowler->name << " to " << batsman->name << " " << runsScored << " runs!" << endl << endl;
        // displayGameScorecard();

    } else{
        cout << endl << bowler->name << " to " << batsman->name << " OUT!" << endl << endl;

        battingTeam->wicketsLost = battingTeam->wicketsLost + 1;
        bowler->wicketsTaken = bowler->wicketsTaken + 1;


        int nextPlayerId = battingTeam->wicketsLost;
        batsman = &battingTeam->players[nextPlayerId];
    }
    sleep(1);
    displayGameScorecard();
}


bool Game::validateInningsScore(){
    if(isFirstInnings){                         // First Innings
        if(battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls){            
            cout << " ===============================!!!   FIRST INNING ENDS   !!!================================ " << endl;
            sleep(2);
            cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - " << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ")" << endl;
            cout << bowlingTeam->name << " needs " << battingTeam->totalRunsScored + 1 << " runs to win the match" << endl << endl;
            return false;
        }
    } else{                                     // 2nd Innings
        if(battingTeam->totalRunsScored > bowlingTeam->totalRunsScored){
            sleep(2);
            cout << " ____________________________________________________________________________________________ " << endl;
            cout << "|                                                                                            |" << endl;
            cout << "|\t\t\t\t   !!! " << battingTeam->name << " is Winner !!!\t\t\t\t     |" << endl;
            cout << "|____________________________________________________________________________________________|" << endl << endl;
            
            return false;

        } else{
            if(battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls){
                cout << " ==============================!!!   SECOND INNING ENDS   !!!================================ " << endl;
                cout << battingTeam->name << " has scored " << battingTeam->totalRunsScored << " runs" << endl;
                cout << bowlingTeam->name << " has scored " << bowlingTeam->totalRunsScored << " runs" << endl;
                sleep(2);
                
                if(battingTeam->totalRunsScored == bowlingTeam->totalRunsScored){
                    cout << " ____________________________________________________________________________________________ " << endl;
                    cout << "|                                                                                            |" << endl;
                    cout << "|              !!! Team-A and Team-B has same score. So the match is TIE !!!                 |" << endl;
                    cout << "|____________________________________________________________________________________________|" << endl << endl;
                }
                else if(battingTeam->totalRunsScored > bowlingTeam->totalRunsScored){
                    cout << " ____________________________________________________________________________________________ " << endl;
                    cout << "|                                                                                            |" << endl;
                    cout << "|\t\t\t\t   !!! " << battingTeam->name << " is Winner !!!\t\t\t\t     |" << endl;
                    cout << "|____________________________________________________________________________________________|" << endl << endl;
                } else{
                    cout << " ____________________________________________________________________________________________ " << endl;
                    cout << "|                                                                                            |" << endl;
                    cout << "|\t\t\t\t   !!! " << bowlingTeam->name << " is Winner !!!\t\t\t\t     |" << endl;
                    cout << "|____________________________________________________________________________________________|" << endl << endl;
                }
                return false;
            }
        }
    }
    return true;
}

void Game::displayGameScorecard(){          
    cout << " ____________________________________________________________________________________________ " << endl;
    cout << "|                                                                                            |" << endl;
    
    cout << "|\t\t" << battingTeam->name << " " << battingTeam->totalRunsScored << " - " << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ")   |   " 
            << batsman->name << " " << batsman->runsScored << " (" << batsman->ballsPlayed << ")\t\t" 
            << bowler->name << " " << bowler->ballsBowled << " - " << bowler->runsGiven << " - " << bowler->wicketsTaken << "  \t     |"<< endl;

    cout << "|____________________________________________________________________________________________|" << endl << endl;
}


//-------------------------------------- Second Inning Starts ---------------------------------------
void Game::startSecondInnings(){
    cout << "###############################!!!   SECOND INNING STARTS   !!!###############################" << endl << endl;
    isFirstInnings = false;
    // swapTeams(battingTeam, bowlingTeam);
    Team *swapTeam = battingTeam;
    battingTeam = bowlingTeam;
    bowlingTeam = swapTeam;
    initializePlayers();
    playInnings();
}

void Game::displayMatchScoreboard(){
    cout << " ____________________________________________________________________________________________ " << endl;
    cout << "|                                                                                            |" << endl;
    cout << "|                                      MATCH SCOREBOARD                                      |" << endl;
    cout << "|____________________________________________________________________________________________|" << endl;
    cout << "|                                             |                                              |" << endl;
    cout << "|           Team - A\t  " << teamA.totalRunsScored << "-" << teamA.wicketsLost << " (" << teamA.totalBallsBowled <<")\t      |\t\t  Team - B\t " << teamB.totalRunsScored << "-" << teamB.wicketsLost << " (" << teamB.totalBallsBowled << ")\t     |" << endl;
    cout << "|_____________________________________________|______________________________________________|" << endl;
    cout << "|   PLAYER        BATTING        BOWLING      |   PLAYER         BATTING         BOWLING     |" << endl;
    cout << "|_____________________________________________|______________________________________________|" << endl;
    cout << "|                                             |                                              |" << endl;
    
    for (int i=0; i<playersPerTeam; i++){
        Player currentBatsman = battingTeam->players[i];
        Player currentBowler = bowlingTeam->players[i];

        if(battingTeam->name == "Team-A"){
            cout << "|  [" << i << "] " << currentBatsman.name << "\t    " << currentBatsman.runsScored << " (" << currentBatsman.ballsPlayed << ")\t" << currentBatsman.ballsBowled << "-" << currentBatsman.runsGiven << "-" << currentBatsman.wicketsTaken << "\t      |\t" 
                << "  [" << i << "] " << currentBowler.name << "\t " << currentBowler.runsScored << " (" << currentBowler.ballsPlayed << ")\t\t" << currentBowler.ballsBowled << "-" << currentBowler.runsGiven << "-" << currentBowler.wicketsTaken << "\t     |" << endl;
        } else{
            cout << "|  [" << i << "] " << currentBowler.name << "\t    " << currentBowler.runsScored << " (" << currentBowler.ballsPlayed << ")\t" << currentBowler.ballsBowled << "-" << currentBowler.runsGiven << "-" << currentBowler.wicketsTaken << "\t      |\t" 
                << "  [" << i << "] " << currentBatsman.name << "\t " << currentBatsman.runsScored << " (" << currentBatsman.ballsPlayed << ")\t\t" << currentBatsman.ballsBowled << "-" << currentBatsman.runsGiven << "-" << currentBatsman.wicketsTaken << "\t     |" << endl;
        }
    }
    cout << "|_____________________________________________|______________________________________________|" << endl << endl;
    cout << "###################################!!!   THANK YOU   !!!######################################" << endl << endl;;
}
