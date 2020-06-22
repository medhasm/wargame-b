
#include <stdio.h>
#include "Soldier.hpp"
#include "FootSoldier.hpp"
#include <vector>
#include "FootCommander.hpp"






using namespace std;






int FootCommander::getInit() {
return initial;
}


void FootCommander::Ability(std::pair<int,int> source , std::vector<std::vector<Soldier*>> &board,int x, int y) {



for(int i=0; i< board.size() ; i++){
  for(int j=0;j< board[i].size(); j++) {
if(board[i][j]!=nullptr){ 
Soldier* soldier = board[i][j];
if(soldier->getPN() == board[source.first][source.second]->getPN() ){
if (dynamic_cast<FootSoldier*>(board[i][j])) {
std::pair<int,int> sour(i,j);
    soldier->Ability(sour,board, x , y);
      }
   }
}
}

    }
 





std::pair<int,int> target;
double Cav=10000;
for(int i=0;i< x ; i++) {
 for( int j=0 ; j < board[i].size(); j++){
if(board[i][j]!= nullptr){
if(board[i][j]->getPN()!= board[source.first][source.second]->getPN() && board[i][j]->getIH() >0 ){
std::pair<int,int> tar(i,j);
double av= (this)->pitagoras(source,tar); 
if(av<=Cav){
Cav=av;
target=tar;
    }
        }
            }
                }
                     }
if(board[target.first][target.second]!=nullptr){
int enemyHP= board[target.first][target.second]->getIH();
board[target.first][target.second]->setIH(enemyHP - DPA);
if(board[target.first][target.second]->getIH() <= 0){
 board[target.first][target.second] = nullptr;
}
}


}
