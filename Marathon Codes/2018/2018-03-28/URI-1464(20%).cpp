/*
Pesquise Convex Hull, eu usei o algoritmo de Graham Scan. A ideia do problema é 
contar quantas vezes vc consegue achar um polígono que possa cercar os pontos, 
depois vc elimina os pontos que pertence ao perímetro do polígono, e continua 
fazendo isso até ter menos que 3 pontos.A resposta depende da paridade do 
número de camadas. Tome cuidado com pontos duplicados e retire não só os pontos 
do Convex Hull mas tbm os que estiverem no perímetro do polígono. Boa sorte!
*/

/* Uri-1464
 * Convex Hull, overflow, perimeter, algebra
 */
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

#define DEBUG(Z) cout << #Z << "\t" << Z.x << " " << Z.y << endl
class Point{
public:
    long long x, y;
    bool operator < (Point _aux) {
        return (this->y==_aux.y)? this->x<_aux.x : this->y < _aux.y;
    }
    bool operator == (Point _aux){
    	return this->y==_aux.y && this->x==_aux.x;
    }
};

Point pivot;
vector<Point> points;

long long posLeftMost();																//Position for Bottommost/leftmost point
long long crossProduct(Point a, Point b, Point c);									//Direction to follow
long long sqrDist(Point a, Point b);													//pow(Distance between 2 points,2)
bool POLAR_ORDER(Point a, Point b);												//Order function used in sort (i.angle, ii.ray)
bool grahamScan();											//graham's Scan

int main(){
	long long n, count; 
    Point aux;
	while(cin >> n && n){
		points.clear();
		count=0;

		for(long long i=0;i<n;i++){
			cin >> aux.x >> aux.y;
			points.push_back(aux);
		}
		while(grahamScan()) count++;
		
		if(count%2)	cout << "Take this onion to the lab!" << endl;			
		else 		cout << "Do not take this onion to the lab!" << endl;
	}		
    return 0;
}


bool grahamScan(){
	if(points.size() < 3) return false;
	stack<Point> hull;

	long long leastY = posLeftMost();													//get number pos for leftmost/bottommost point
	swap(points[leastY], points[0]);											//Put leftmost/bottommost point in first pos
    pivot = points[0];															//Take the pivot element

    sort(points.begin()+1, points.end(), POLAR_ORDER);							//Put in polar order

	for(long long i=0; i<points.size()-1; i++)
		if(points[i]==points[i+1])
			points.erase(points.begin() + i); 

    hull.push(points[0]);		
    hull.push(points[1]);		
    hull.push(points[2]);		

    for (long long i = 3; i < points.size(); i++){
        Point top = hull.top();
        hull.pop();
        while(crossProduct(hull.top(), top, points[i]) > -1){
            top = hull.top();
            hull.pop();
        }
        hull.push(top);
        hull.push(points[i]);	
    }

	stack<Point> iHull;
	while(!hull.empty()){
		Point top=hull.top(); hull.pop();
		iHull.push(top);
	}
	vector<Point> aux;
	while(!iHull.empty()){
		Point top=iHull.top(); iHull.pop();
		aux.push_back(top);
	}    
	for(long long i=0; i<points.size(); i++){
		for(long long j=0; j<aux.size(); j++)
			if(points[i] == aux[j])
				points.erase(points.begin()+i);
	}
    return true;
}

long long posLeftMost(){
	long long leastY=0;
	for(long long i=1; i<points.size(); i++)	
		if (points[i] < points[leastY]) leastY = i;								
	return leastY;
}
long long crossProduct(Point a, Point b, Point c){									
    long long prodVetorial = (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
    return (prodVetorial==0)? 0 :(prodVetorial>0)? -1 : 1;						//Collinear, left(counterclock), right(clockwise)
}
long long sqrDist(Point a, Point b){													//pow(distance,2)
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
bool POLAR_ORDER(Point a, Point b){
   	return (crossProduct(pivot,a,b)==0)? (sqrDist(pivot, a) < sqrDist(pivot, b)) 
    							       : ((crossProduct(pivot, a, b) == -1));				    
}
