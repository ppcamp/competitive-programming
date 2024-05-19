// URI: 1120
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int main(){
	string d,n;
	bool aux=true;
	while(cin>>d>>n && d!="0" && n!="0"){
		if(n.find_first_of(d) != -1){
			n.erase(remove(n.begin(), n.end(), d[0]),  n.end());
			n.erase(0, n.find_first_not_of("0") );
			if(n.empty())
				cout << "0" << endl;
			else
				cout << n << endl;
		}
		else
			cout << n << endl;
		d.clear();	n.clear();
		
	};
	return 0;
}
