#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

bool isNumber(char i){
	return i < 58 && i > 47;
}

void solution(int numOfOrder, string *orderArr) {
  // TODO: 이곳에 코드를 작
	
	stack<char> s;
	stack<char> s2;
	vector<char> v;
	
	for(int t_case = 0 ; t_case < numOfOrder ; t_case++){
		string now = orderArr[t_case];
		
		for(int i = 0 ; i < now.size(); i++){
			if(now[i] == ')'){
				char ch;
				
				while(true) {
					ch = s.top();
					s.pop();

          if(ch == '(') break;
					v.push_back(ch);
				}
				
				char prefix = s.top();
				s.pop();
				
				if(isNumber(prefix)){
					for(int j = 0 ; j < prefix - '0' ; j++){
						for(int k = v.size() - 1; k >= 0 ; k--){
							s.push(v[k]);
						}
					}
					
					v.clear();
				}
				
				else {
					while(!v.empty()){
						s.push(prefix);
						s.push(v[v.size()-1]);
						v.pop_back();
					}
				}
			}

      else if(isNumber(now[i])){
        if(now[i + 1] == '('){
          s.push(now[i]);
          continue;
        }

        for(int l = 0 ; l < now[i] - '0'; l++){
          s.push(now[i+1]);
        }

        i++;
      }
			
			else s.push(now[i]);
		}
		
		while(!s.empty()){
			s2.push(s.top());
			s.pop();
		}
		
		while(!s2.empty()){
			printf("%c", s2.top());
			s2.pop();
		}
		
		printf("\n");
		
		v.clear();
	}
}

struct input_data {
  int numOfOrder;
  string *orderArr;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.numOfOrder;

  inputData.orderArr = new string[inputData.numOfOrder];
  for (int i = 0; i < inputData.numOfOrder; i++) {
    getline(cin, line);
    iss.clear();
    iss.str(line);
    iss >> inputData.orderArr[i];
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.numOfOrder, inputData.orderArr);
  return 0;
}