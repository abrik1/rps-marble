#include <iostream>
#include <string.h>

using namespace std; 
int choice;

class PublicGame{
  public:
    string p1name;
    string p2name;
    int p1score = 0;
    int p2score = 0;
    int p1choice = 0;
    int p2choice = 0;
    int total_score = 0;

    void determine_winner(int p1c, int p2c){
      if(p1c==p2c){
        std::cout << "\x1b[33mnote: " << p1name << " and " << p2name << " got the same choice so it is a draw.\x1b[0m" << std::endl;
      } 
      else if((p1c==1 && p2c==3) || (p1c==2 && p2c==1) || (p1c==3 && p2c == 2)){
        p1score = p1score+1;
        if(p2score==0){
          p2score = p2score;
        }
        else{
          p2score = p2score-1;
        }
        std::cout << "\x1b[33mnote: " << p1name << " won and " << p2name << " lost\x1b[0m" << std::endl;
      }
      else if((p2c==1 && p1c==3) || (p2c==2 && p1c==1) || (p2c==3 && p1c==2)){
        p2score = p2score+1;
        if(p1score==0){
          p1score = p1score;
        }
        else{
          p1score = p1score-1;
        }
      }
    std::cout << p1name << "\'s total marbles:\x1b[31m " << p1score << "\x1b[0m\n";
    std::cout << p2name << "\'s total marbles:\x1b[34m " << p2score << "\x1b[0m\n";
    }

   void get_input(){
     std::cout << "[1] rock" << std::endl;
     std::cout << "[2] paper" << std::endl;
     std::cout << "[3] scissor" << std::endl;
     std::cout << p1name << " enter your input:\x1b[30m ";
     std::cin >> p1choice;
     std::cout << "\x1b[0m" << p2name << " enter your input:\x1b[30m ";
     std::cin >> p2choice;
     std::cout << "\x1b[0m";
     determine_winner(p1choice, p2choice);
   }

   int play_game(){
     while(p1score < total_score || p2score < total_score){
      get_input();
      if(p1score == total_score){
        std::cout << "\x1b[31m" << p1name << "\x1b[0m won the game" << std::endl;
        return 0;
      }
      else if(p2score == total_score){
        std::cout << "\x1b[34m" << p2name << "\x1b[0m won the game" << std::endl;
        return 0;    
      }
    } 
   } 
};

void setup_game(){
  std::cout << "\x1b[36mnote: we are setting up your game:\x1b[0m  " << std::endl;
  PublicGame Currentgame;
  std::cout << "player1, enter your name:\x1b[34m ";
  std::cin >> Currentgame.p1name;
  std::cout << "\x1b[0mplayer2, enter your name:\x1b[34m ";
  std::cin >> Currentgame.p2name;
  std::cout << "\x1b[0mtotal score: ";
  std::cin >> Currentgame.total_score;
  std::cout << "\x1b[32msucess: game prepared.. loading game\x1b[0m" << std::endl;
  Currentgame.play_game();
}

int main(){
  cout << "welcome to rps-marble" << endl;
  cout << "[1] play" << endl;
  cout << "[2] exit" << endl;
  cout << "choice: ";
  cin >> choice;
  switch(choice){
    case 1:
      setup_game();
      return 0;
    case 2:
      cout << "\x1b[33mnote: user chose to exit so exiting\x1b[0m" << endl;
      return 0;     
    default:
      cout << "\x1b[31merror: invalid choice\x1b[0m" << endl;
      return 0;
  }
}
