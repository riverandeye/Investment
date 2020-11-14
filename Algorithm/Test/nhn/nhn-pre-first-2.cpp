#include <iostream>
#include <sstream>

using namespace std;

int currentState[100];

void solution(int day, int width, int **blocks) {
  // TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.
	
	int count = 0;
	
	if(width == 1 || width == 2){ // width 가 1이나 2이면 시멘트를 뿌리지 않아도 된다. (뿌리면 옆으로 샘)
		printf("0");
		return;
	}
	
	for(int i = 0 ; i < day ; i++){
		for(int j = 0 ; j < width; j++){
			currentState[j] += blocks[i][j]; // 벽돌을 놓아준다.
		}
		
		int l_now = 0, l_max = currentState[0]; 
		int r_now = width - 1, r_max = currentState[width - 1]; 
		
		for(int j = 1 ; j < width; j++){ // scan from left (add equal case)
			if(currentState[j] < l_max) continue;
			
			for(int i = l_now; i < j ; i++){ // 시멘트를 부어준다. 
				count += currentState[l_now] - currentState[i];
				currentState[i] = currentState[l_now];
			}
			
			l_max = currentState[j];
			l_now = j;
		}
		
		for(int j = width - 2 ; j >= 0 ; j--){ // scan from right (don't add equal case)
			if(currentState[j] <= r_max) continue;
			
			for(int i = r_now; i > j ; i--){
				count += currentState[r_now] - currentState[i];
				currentState[i] = currentState[r_now];
			}
			
			r_max = currentState[j];
			r_now = j;
		}
	}
	
	printf("%d", count);
}

struct input_data {
  int day;
  int width;
  int **blocks;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.day;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.width;

  inputData.blocks = new int*[inputData.day];
  for (int i = 0; i < inputData.day; i++) {
    getline(cin, line);
    iss.clear();
    iss.str(line);
    inputData.blocks[i] = new int[inputData.width];
    for (int j = 0; j < inputData.width; j++) {
      iss >> inputData.blocks[i][j];
    }
  }
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.day, inputData.width, inputData.blocks);
	return 0;
}