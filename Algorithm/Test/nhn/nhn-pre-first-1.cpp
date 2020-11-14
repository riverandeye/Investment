#include <iostream>
#include <sstream>

using namespace std;

int result[26];
char currentStatus[26];

bool contain(char *players, int numberOfPlayer, char player){
	for(int i = 0 ; i < numberOfPlayer; i++){
		if(players[i] == player) return true;
	}
	
	return false;
}

void solution(int numOfAllPlayers, int numOfQuickPlayers, char *namesOfQuickPlayers, int numOfGames, int *numOfMovesPerGame) {
  // TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.
	for(int i = 0 ; i < numOfAllPlayers - 1; i++){
		currentStatus[i] = 'B' + i;
	}
	
	char sulae = 'A';
	
	int position = 0;
	for(int round = 0; round < numOfGames; round++){
		result[sulae - 'A'] += 1;
		
		position = (position + numOfMovesPerGame[round] + (numOfAllPlayers - 1)) % (numOfAllPlayers-1);
		
		if(contain(namesOfQuickPlayers, numOfQuickPlayers, currentStatus[position])){
			continue;
		}
		
		char b = currentStatus[position];
		currentStatus[position] = sulae;
		sulae = b;
	}
	
	result[sulae - 'A'] += 1;
	
	for(int i = 0 ; i < numOfAllPlayers - 1; i++){
		printf("%c %d\n", currentStatus[i], result[currentStatus[i] - 'A']);
	}
	
	printf("%c %d\n", sulae, result[sulae - 'A']);
}

struct input_data {
  int numOfAllPlayers;
  int numOfQuickPlayers;
  char *namesOfQuickPlayers;
  int numOfGames;
  int *numOfMovesPerGame;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.numOfAllPlayers;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.numOfQuickPlayers;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  inputData.namesOfQuickPlayers = new char[inputData.numOfQuickPlayers];
  for (int i = 0; i < inputData.numOfQuickPlayers; i++) {
    iss >> inputData.namesOfQuickPlayers[i];
  }

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.numOfGames;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  inputData.numOfMovesPerGame = new int[inputData.numOfGames];
  for (int i = 0; i < inputData.numOfGames; i++) {
    iss >> inputData.numOfMovesPerGame[i];
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.numOfAllPlayers, inputData.numOfQuickPlayers, inputData.namesOfQuickPlayers, inputData.numOfGames, inputData.numOfMovesPerGame);
  return 0;
}