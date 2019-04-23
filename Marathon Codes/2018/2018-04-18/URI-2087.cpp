#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;


class Trie {
private:
  struct Node {
    char ch;
    map<char, Node*> children;};
protected:
    Node head;
    // Keep all newly created node in an array, for the ease of
    // memory release.
    vector<Node*> children;

public:
    Trie() { head.ch = -1; };
    ~Trie(){
		for (int i=0; i<children.size(); ++i) {
			delete children[i];
		}};

    void build_trie(vector<string> words) {
		for(auto i: words) insert(i);}
    void insert(string word) {
		map<char, Node*> *current_tree = &head.children;
		map<char, Node*>::iterator it;

		for (int i=0; i<word.length(); ++i) {
			char ch = word[i];

			if ((it = current_tree->find(ch)) != current_tree->end()) {
			current_tree = &it->second->children;
			continue;
			}

			if (it == current_tree->end()) {
			// Display inserting position in the tree, for debug use
			//
			// cout << "Inserting " << ch << endl;
			// cout << "on layer " << endl;
			// map<char, Node*>::iterator temp = current_tree->begin();
			// for (; temp != current_tree->end(); ++temp)
			//   cout << temp->first << endl;

			Node* new_node = new Node();
			new_node->ch = ch;
			(*current_tree)[ch] = new_node;

			// For continuous inserting a word.
			current_tree = &new_node->children;
			
			// For the ease of memory clean up.
			children.push_back(new_node);
			}}};
    bool search(string word, bool& prefix) {
		map<char, Node*> current_tree = head.children;
  		map<char, Node*>::iterator it;
		for (int i=0; i<word.length(); ++i) {
    		if ((it = current_tree.find(word[i])) == current_tree.end()) {
      			return false;}
    		current_tree = it->second->children;}
			prefix = !(current_tree.empty());
			print_tree(current_tree);
  		return true;}

	bool search(string word) {
		map<char, Node*> current_tree = head.children;
  		map<char, Node*>::iterator it;
		for (int i=0; i<word.length(); ++i) {
    		if ((it = current_tree.find(word[i])) == current_tree.end()) {
      			return false;}
    		current_tree = it->second->children;}
			cout << "EXIBINDO\n";
			print_tree(current_tree);
			cout << "FIM\n";
  		return true;}


    void print_tree(map<char, Node*> tree) {
		if (tree.empty()) {
			return;}
		for (map<char, Node*>::iterator it=tree.begin(); it!=tree.end(); ++it) {
			cout << it->first << endl;
			print_tree(it->second->children);}};
    void print(){
		map<char, Node*> current_tree = head.children;
  		print_tree(current_tree);}; 
	
	bool isPrefix(string word){
		bool prefix;
		search(word,prefix);
		return prefix;}
};



int main(){
	int n;
	while(cin>>n && n){
		string input;
		Trie tree;
		while(n--){
			cout << "Entrada #" << n << endl;
			cin >> input;
			tree.insert(input);
		}
		cin >> input;
		if(tree.search(input)) cout << "TES";
		else cout << "afs";
	}
	return 0;
}

