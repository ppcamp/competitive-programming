// URI: 1024
#include <bits/stdc++.h>

int main(){
	int n,found;
	std::string input;
	std::cin >> n >> std::ws;
	while(n--){		
		std::getline(std::cin, input);
		for(int i=0; i<input.size(); i++) if((input[i]>=65 && input[i]<=90) || (input[i]>=97 && input[i]<=122)) input[i]+=3;
		reverse(input.begin(), input.end());
		for(int i=input.size()/2; i<input.size(); i++) input[i]-=1;
		std::cout << input << std::endl;
	}
	return 0;
}
