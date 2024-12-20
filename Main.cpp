#include <cstdlib>
#include <iostream>
using namespace std;
// Stone, Paper, Scissor Game Project :)
// 2024-03-12, 1445-09-01, Fist of ramadan 2024.

string Tabs(short NumberOfTabs) {
  string tabs;
  cout << "\n";
  for (int i = 0; i < NumberOfTabs; i++) {
    tabs += "\t";
  }
  return tabs;
}

void signature() {
  cout << Tabs(4) << " ┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸";
  cout << Tabs(4) << " ┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ ";
  cout << Tabs(4) << " ╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸" << endl;
}

void GameASCII() {
  cout << "\n▄▖▗           ▄▖            ▄▖  ▘        ";
  cout << "\n▚ ▜▘▛▌▛▌█▌    ▙▌▀▌▛▌█▌▛▘    ▚ ▛▘▌▛▘▛▘▛▌▛▘";
  cout << "\n▄▌▐▖▙▌▌▌▙▖▗   ▌ █▌▙▌▙▖▌ ▗   ▄▌▙▖▌▄▌▄▌▙▌▌";
  cout << "\n          ▘       ▌     ▘               ";
  cout << "\n▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n";
}

void EndASCII(short i) {
  cout << Tabs(i)
       << " ██████╗  █████╗ ███╗   ███╗███████╗     ██████╗ ██╗   "
          "██╗███████╗██████╗ ";
  cout << Tabs(i)
       << "██╔════╝ ██╔══██╗████╗ ████║██╔════╝    ██╔═══██╗██║   "
          "██║██╔════╝██╔══██╗";
  cout << Tabs(i)
       << "██║  ███╗███████║██╔████╔██║█████╗      ██║   ██║██║   ██║█████╗  "
          "██████╔╝";
  cout << Tabs(i)
       << "██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ██║   ██║╚██╗ ██╔╝██╔══╝  "
          "██╔══██╗";
  cout << Tabs(i)
       << "╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    ╚██████╔╝ ╚████╔╝ "
          "███████╗██║  ██║";
  cout << Tabs(i)
       << " ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝     ╚═════╝   ╚═══╝  "
          "╚══════╝╚═╝  ╚═╝";
}

struct stGameResults {
  short PlayerWin = 0;
  short ComputerWins = 0;
  short Draw = 0;
  short RoundsCount = 0;
  string TheFinalWinner = "";
  string RoundWinner = "";
  enum enChoices { Paper = 2, Rock = 1, Scissor = 3 };
};

int ReadPositiveNumber(string message, short from, short to) {
  int N;
  do {
    cout << message;
    cin >> N;
  } while (N < from || N > to);
  return N;
}

void ShowFinalGameResults(stGameResults Results, short i) {
  cout << Tabs(i) << "Game rounds        : " << Results.RoundsCount;
  cout << Tabs(i) << "Player won times   : " << Results.PlayerWin;
  cout << Tabs(i) << "Computer won times : " << Results.ComputerWins;
  cout << Tabs(i) << "Draw times         : " << Results.Draw;
  cout << Tabs(i) << "Final winner       : " << Results.TheFinalWinner;
}

void ShowGameOverScreen(stGameResults Resluts) {
  short i = 2;
  cout << "\033[37m" << Tabs(i);
  EndASCII(i);
  cout << Tabs(i)
       << "_____________________________ [Game Resluts] "
          "_____________________________";
  ShowFinalGameResults(Resluts, i);
  cout << Tabs(i)
       << "\033[37m____________________________________________________________"
          "________"
          "______";
  cout << Tabs(i) << "Do you want to Play again? (✅/❌): ";
}

short readhowmanyrounds() {
  short roundcount = ReadPositiveNumber(
      "Enter how many rounds to play (from 01 to 10): ", 1, 10);
  return roundcount;
}

int RandomNumber(int from, int to) {
  int randNum = rand() % (to - from + 1) + from;
  return randNum;
}

int CheckGame(int c, int p) {
  if ((p == 2 && c == 1) || (p == 1 && c == 3) || (p == 3 && c == 2))
    return 0;
  else if ((p == 3 && c == 3) || (p == 1 && c == 1) || (p == 2 && c == 2))
    return 1;
  else
    return 2;
  ;
}

void PrintRound(stGameResults Results, int i, short playerchoice,
                short computerchoice) {
  stGameResults::enChoices Cho;
  cout << "\n▁▁▁▁▁▁▁▁▁▁▁▁▂▃▅▆▓▒░ ROUND [" << i << "] ░▒▓▆▅▃▂▁▁▁▁▁▁▁▁▁▁▁▁\n";
  cout << "Player choice  : ";
  if (playerchoice == 1) {
    cout << "🪨 Stone";
  } else if (playerchoice == 2) {
    cout << "📄 Paper";
  } else {
    cout << "✂️ Scissor";
  }
  cout << "\nComputer choice: ";
  if (computerchoice == 1) {
    cout << "🪨 Stone";
  } else if (computerchoice == 2) {
    cout << "📄 Paper";
  } else {
    cout << "✂️ Scissor";
  }
  cout << "\nRound Winner   : [" << Results.RoundWinner << "]";
  cout << "\n_________________________________________________\n";
}

void CheckResults(stGameResults &Results) {
  if (Results.ComputerWins > Results.PlayerWin) {
    if (Results.ComputerWins > Results.Draw) {
      Results.TheFinalWinner = "\033[91mComputer";
    } else {
      Results.TheFinalWinner = "";
    }
  } else if (Results.PlayerWin > Results.ComputerWins) {
    if (Results.PlayerWin > Results.Draw) {
      Results.TheFinalWinner = "\033[32mPlayer";
    } else {
      Results.TheFinalWinner = "\033[33mDraw";
    }
  } else {
    Results.TheFinalWinner = "\033[33mDraw";
  }
}

void PrintGame(stGameResults &Results, short playerchoice,
               short computerchoice) {
  if (CheckGame(computerchoice, playerchoice) == 0) {
    printf("\033[32m");
    Results.PlayerWin++;
    Results.RoundWinner = "Player";
  } else if (CheckGame(computerchoice, playerchoice) == 1) {
    printf("\033[33m");
    Results.Draw++;
    Results.RoundWinner = "Draw";
  } else {
    printf("\a\033[91m");
    Results.ComputerWins++;
    Results.RoundWinner = "Computer";
  }
}

void StartGame() {
  GameASCII();

  stGameResults Results;
  Results.RoundsCount = readhowmanyrounds();
  short i = 0;
  short playerchoice = 0, computerchoice = 0;

  for (i = 1; i <= Results.RoundsCount; i++) {
    cout << "\n\033[37mRound [" << i << "] Begins:\n";
    playerchoice = ReadPositiveNumber(
        "Your Choice? [1] Stone, [2] Paper, [3] Scissor: ", 1, 3);

    int computerchoice = RandomNumber(1, 3);

    PrintGame(Results, playerchoice, computerchoice);
    PrintRound(Results, i, playerchoice, computerchoice);
  }

  CheckResults(Results);
  ShowGameOverScreen(Results);
}

void ResetScreen() {
  bool question = true;
  cout << "\f\033[37m";
  cin >> question;
  if (question)
    StartGame();
}

int main() {
  srand((unsigned)time(NULL));
  StartGame();
  // ResetScreen();
  signature();
  return 0;
}
