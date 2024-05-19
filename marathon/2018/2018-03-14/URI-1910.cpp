// URI: 2688
#include <bits/stdc++.h>
// 88 walls
// 11 out
// 99 table
// 00 chair

#define E 88 //exit

#define pair<int,int> pii;
#define mp make_pair
#define fst first
#define snd second

int matrix[13][13]={
	{99, 99, 99, 99, 99, 99, 99,  E, 11, 11, 11, 11, 11},
	{99, 00, 00, 99, 00, 00, 99, 88, 11, 11, 11, 11, 11},
	{99, 00, 00, 99, 00, 00, 99, 88, 11, 11, 11, 11, 11},
	{99, 00, 00, 99, 00, 00, 99, 88, 11, 11, 11, 11, 11},
	{99, 00, 00, 99, 00, 00, 99, 88, 11, 11, 11, 11, 11},
	{99, 00, 00, 99, 00, 00, 99, 88, 88, 88, 88, 88, 88},
	{99, 00, 00, 99, 00, 00, 99, 99, 99, 99, 99, 99, 99},
	{99, 00, 00, 99, 00, 00, 99, 00, 00, 00, 00, 00, 99},
	{99, 00, 00, 99, 00, 00, 99, 00, 00, 00, 00, 00, 99},
	{99, 00, 00, 99, 00, 00, 99, 99, 99, 99, 99, 99, 99},
	{99, 00, 00, 99, 00, 00, 99, 00, 00, 00, 00, 00, 99},
	{99, 00, 00, 99, 00, 00, 99, 00, 00, 00, 00, 00, 99},
	{99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}};
//int compare[13][13];

/*
141
150
190
202
*/


int main(){
	int line, l, column, c, input, average = 0;
	vector <pii> possible;
	
	scanf("%i", &input);
	for(int i=0; i<13; i++){
		for(int j=0; j<13; j++){
			scanf("%i ", matrix[i][j]);
			if(matrix[i][j]==0)
				possible.push_back(mp(i,j));
		}
	}
	for(int i=0; i<possible.size(); i++)
		l = possible[i].fst;
		c = possible[i].snd;
		if(  (c+1)<13 && matrix[l][c+1]!=99   &&   (c-1)>=0 && matrix[l][c-1]!=99   &&  c<8){
			if(  (l+1)<13 && matrix[l+1][c]!=99   &&   (c-1)>=0 && matrix[l][c-1]!=99){
		
		}
	}
			
	for(int i=0; i<13; i++){
		for(int j=12; j>=0; j++)
			if(matrix[i][j]==compare[i][j])
		
	printf("linha > %i coluna > %i", line+1, column+1);
/*	for(int i=0;i<13;i++){
		for(int j=0;j<13;j++)
			printf("%2i ",matrix[i][j]);
		printf("\n");
	}
*/
	return 0;
}
