// URI: 1873
#include <bits/stdc++.h>

inline int condition(std::string s){
	return (s == "tesoura")? 0 :(s == "papel")? 1 :(s == "pedra")? 2 :(s == "lagarto")? 3 : 4/*spock*/;
}

int matrix[5][5]={
	{0,1,0,1,0}, 
	{0,0,1,0,1}, 
	{1,0,0,1,0}, 
	{0,1,0,0,1}, 
	{1,0,1,0,0}};

int main(){
	int c, s1,s2;
	std::string str1, str2;
	scanf("%i", &c);
	while(c--){
		std::cin >> str1 >> str2;
		s1 = condition(str1);		
		s2 = condition(str2);				
		(s1==s2)? printf("empate\n") :(matrix[s1][s2])? printf("rajesh\n") : printf("sheldon\n"); 					
	}
	return 0;
}
