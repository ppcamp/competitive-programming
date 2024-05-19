#include <algorithm>
#include <cstdio>
#include <cmath>
#include <stack>
#include <vector>
#include<iostream>
using namespace std;

#ifndef EPS
#define EPS 1e-9
#endif

#ifndef PI
#define PI acos(-1.0)
#endif


struct point { 
  /**
   * @brief Base class to keep the points coordenades (x,y)
  */
  double x, y;   // only used if more precision is needed
  point() { x = y = 0.0; }                      // default constructor
  point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
  bool operator == (point other) const {
  return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } };

struct vec { 
  double x, y;  // name: `vec' is different from STL vector
  vec(double _x, double _y) : x(_x), y(_y) {} };

//Headers_Functions                                                   //Descriptions

double DEG_to_RAD(double d);                                          //Convert Degrees to radian
double RAD_to_DEG(double r);                                          //Convert radian to degree
vec toVec(point a, point b);                                          //Convert 2 points to vector a->b
double dist(point p1, point p2);                                      //Euclidean distance
double perimeter(const vector<point> &P);                             //Calc the perimeter distance
double area(const vector<point> &P);                                  //Calculate the area's poligon
double dot(vec a, vec b);                                             //dot product between two vectors (V.U)
double norm_sq(vec v);                                                //Equal to pow(value,2)
double cross(vec a, vec b);                                           //Cross product between two vectors (VxU)
double angle(point a, point o, point b);                              //Calculate vector OA and OB, and give the angle between both
bool ccw(point p, point q, point r);                                  //Function used in algorithm to get where it needs to go.
bool collinear(point p, point q, point r);                            //Calculate if 3 points are collinear
bool isConvex(const vector<point> &P);                                //Examine the points and discover if they form a convex polygon
bool inPolygon(point pt, const vector<point> &P);                     //Calculate if the points are in polygon
point lineIntersectSeg(point p, point q, point A, point B);           //line segment p-q intersect with line A-B.
vector<point> cutPolygon(point a, point b, const vector<point> &Q);   //cuts polygon Q along the line formed by point a -> point b
bool angleCmp(point a, point b);                                      //Angle-sorting function used in CH
vector<point> CH(vector<point> P);                                    //Convex Hull

vector<point> input;
point pivot;

void TO_DO(point res){
	for(auto& i: input)
		if(i==res)
			input.erase(i);
}
void PRINT(vector<point> i){
	for(auto j : i){
		cout << "(" << j.x << "," << j.y << ")\n";
	}
}
int main() {
	int n, cont;
	bool check;
	point in;
	while(cin>>n && n){
		cont = check = 0;
		input.clear();
		
		while(n--){
			cin>>in.x >> in.y;
			input.push_back(in);
		}
		while(!check){
			vector<point> res = CH(input);
			PRINT(res);
			cout << "_--------------------___\n";
			PRINT(input);
			for_each(input.begin(), input.end(), TO_DO);
			cout << "______________________\n";
			PRINT()
		}
	}
	return 0;
}



















/**
 * @file Geometry.hpp
 * @brief Lib com funções para trabalhar com polígonos
 * 
 * @warning Lib somente com funções para polígonos
 * @todo
 * @bug Ainda nenhum bug conhecido
 * @copyright Código retirado do livro do halim -- 3ªEd
*/
double DEG_to_RAD(double d) { 
  /**
   * @brief Convert Degrees to radian
   * @param double d - angle to be converted
   * @return The converted angle
  */
  return d * PI / 180.0; }
double RAD_to_DEG(double r) { 
  /**
   * @brief Convert radian to degree
   * @param double r - angle to be converted
   * @return The converted angle
  */
  return r * 180.0 / PI; }


vec toVec(point a, point b) {
  /**
   * @brief Convert 2 points to vector a->b
   * @param point a - Ponto A
   * @param point b - Ponto B
   * @return struct vec com os valores do vetor desses pontos
  */
  return vec(b.x - a.x, b.y - a.y); }

double dist(point p1, point p2) { 
  /**
   * @brief Euclidean distance
   * @param point p1 - Point A
   * @param point p2 - Point B
   * @return distance between A->B
  */
  return hypot(p1.x - p2.x, p1.y - p2.y); }           // return double


double perimeter(const vector<point> &P) {
  /**
   * @brief Calc the perimeter distance
   * @param vector<point> P - "borders" points
   * @return The perimeter, which is the sum of Euclidian distances of consecutive line segments (polygon edges)
  */

  double result = 0.0;
  for (int i = 0; i < (int)P.size()-1; i++)  // remember that P[0] = P[n-1]
    result += dist(P[i], P[i+1]);
  return result; }

double area(const vector<point> &P) {
  /** 
   * @brief Calculate the area's poligon
   * @param vector<point> - borders point
   * @return The area, which is half the determinant
  */
  double result = 0.0, x1, y1, x2, y2;
  for (int i = 0; i < (int)P.size()-1; i++) {
    x1 = P[i].x; x2 = P[i+1].x;
    y1 = P[i].y; y2 = P[i+1].y;
    result += (x1 * y2 - x2 * y1);
  }
  return fabs(result) / 2.0; }

double dot(vec a, vec b) { 
  /**
   * @brief dot product between two vectors (V.U)
   * @param vec - Vector a
   * @param vec - Vector b
   * @return dot Product
  */
  return (a.x * b.x + a.y * b.y); }

double cross(vec a, vec b) { 
   /**
   * @brief Cross product between two vectors (VxU)
   * @param vec - Vector a
   * @param vec - Vector b
   * @return cross Product
  */
  return a.x * b.y - a.y * b.x; }

double norm_sq(vec v) { 
  /**
   * @brief Equal to pow(value,2)
   * @param vec - vector
   * @return vec(x²,y²)
  */
  return v.x * v.x + v.y * v.y; }

double angle(point a, point o, point b) {
  /**
   * @brief Calculate vector OA and OB, and give the angle between both
   * @param point a - Point A
   * @param point o - Commom Point (Origin)
   * @param point b - Point B
   * @return Angle aob in rad
  */
  vec oa = toVec(o, a), ob = toVec(o, b);
  return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); }

bool ccw(point p, point q, point r) {
  /**
   * @brief Function used in algorithm to get where it needs to go.
   * @note To accept collinear points, we have to change the `> 0' to '>=0'
   * @param point p - Point A
   * @param point q - Point O origin to OA_OB
   * @param point r - Point B
   * @return True if point r is on the left side of line pq
  */
  return cross(toVec(p, q), toVec(p, r)) >= 0; }

bool collinear(point p, point q, point r) {
  /**
   * @brief Calculate if 3 points are collinear
   * @param point p - Point A
   * @param point q - Point O - Origin OA_OB
   * @param point r - Point B
   * @return True if point r is on the same line as the line pq
  */
  return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; }

bool isConvex(const vector<point> &P) {
  /**
   * @brief Examine the points and discover if they form a convex polygon
   * @param vector<point> - vector with extreme points
   * @return True if we always make the same turn while examining all the edges of the polygon one by one
  */

  int sz = (int)P.size();
  if (sz <= 3) return false;   // a point/sz=2 or a line/sz=3 is not convex
  bool isLeft = ccw(P[0], P[1], P[2]);               // remember one result
  for (int i = 1; i < sz-1; i++)            // then compare with the others
    if (ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLeft)
      return false;            // different sign -> this polygon is concave
  return true; }                                  // this polygon is convex

bool inPolygon(point pt, const vector<point> &P) {
  /**
   * @brief Calculate if the points are in polygon
   * @param point - point to verifies
   * @param vector<point> - polygon  
   * @returns True if point p is in either convex/concave polygon P
  */
  if ((int)P.size() == 0) return false;
  double sum = 0;    // assume the first vertex is equal to the last vertex
  for (int i = 0; i < (int)P.size()-1; i++) {
    if (ccw(pt, P[i], P[i+1]))
         sum += angle(P[i], pt, P[i+1]);                   // left turn/ccw
    else sum -= angle(P[i], pt, P[i+1]); }                 // right turn/cw
  return fabs(fabs(sum) - 2*PI) < EPS; }

point lineIntersectSeg(point p, point q, point A, point B) {
  /**
   * @brief line segment p-q intersect with line A-B.
   * @return point that 
  */
  double a = B.y - A.y;
  double b = A.x - B.x;
  double c = B.x * A.y - A.x * B.y;
  double u = fabs(a * p.x + b * p.y + c);
  double v = fabs(a * q.x + b * q.y + c);
  return point((p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v)); }

vector<point> cutPolygon(point a, point b, const vector<point> &Q) {
  /**
   * @brief cuts polygon Q along the line formed by point a -> point b
   * @param point a - Point A
   * @param point b - Point B
   * @param vector<point> - Polygon
   * @note The last point must be the same as the first point)
   * @return cut the polygon
  */

  vector<point> P;
  for (int i = 0; i < (int)Q.size(); i++) {
    double left1 = cross(toVec(a, b), toVec(a, Q[i])), left2 = 0;
    if (i != (int)Q.size()-1) left2 = cross(toVec(a, b), toVec(a, Q[i+1]));
    if (left1 > -EPS) P.push_back(Q[i]);       // Q[i] is on the left of ab
    if (left1 * left2 < -EPS)        // edge (Q[i], Q[i+1]) crosses line ab
      P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
  }
  if (!P.empty() && !(P.back() == P.front()))
    P.push_back(P.front());        // make P's first point = P's last point
  return P; }

bool angleCmp(point a, point b) {
  /**
   * @brief Angle-sorting function used in CH
   * @param point a - Point a
   * @param point b - Point b
   * @return True 
  */
  if (collinear(pivot, a, b))                               // special case
    return dist(pivot, a) < dist(pivot, b);    // check which one is closer
  double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
  double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
  return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; }   // compare two angles

vector<point> CH(vector<point> P) {
  /**
   * @brief Convex Hull
   * @param vector<point> - Points to find convex hull
   * @return vector<point> with convex hull points
  */
  
  int i, j, n = (int)P.size(); // the content of P may be reshuffled
  if (n <= 3) {
    if (!(P[0] == P[n-1])) P.push_back(P[0]); // safeguard from corner case
    return P;                           // special case, the CH is P itself
  }

  
  int P0 = 0;// first, find P0 = point with lowest Y and if tie: rightmost X
  for (i = 1; i < n; i++)
    if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
      P0 = i;

  point temp = P[0]; P[0] = P[P0]; P[P0] = temp;    // swap P[P0] with P[0]

  // second, sort points by angle w.r.t. pivot P0
  pivot = P[0];                    // use this global variable as reference
  sort(++P.begin(), P.end(), angleCmp);              // we do not sort P[0]

  // third, the ccw tests
  vector<point> S;
  S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);   // initial S
  i = 2;                                         // then, we check the rest
  while (i < n) {           // note: N must be >= 3 for this method to work
    j = (int)S.size()-1;
    if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);  // left turn, accept
    else S.pop_back(); }   // or pop the top of S until we have a left turn
  return S; }                                          // return the result