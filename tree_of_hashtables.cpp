#include<iostream>
#include<string>
using namespace std;

struct tree{
	char data;
	tree *hash[26];
	bool end;
};

tree* dict = new tree;
tree* root = dict;

tree* newNode(char c){
	tree* newbox = new tree;
	newbox->data = c;
	for(int i=0;i<26;i++)
		newbox->hash[i] = NULL;
	newbox->end = false;
	return newbox;	
}

int hash_pos(char c){
	return c-'a';
}

void insert(char word[]){
	tree* curr = root;
	int hash_key;
	for(int i=0;word[i]!='\0';i++){
		hash_key = hash_pos(word[i]);
		if(curr->hash[hash_key]==NULL)
			curr->hash[hash_key] = newNode(word[i]);
		curr = curr->hash[hash_key];	
	}
	curr->end = true;
}

bool isLastNode(tree* root) 
{ 
    for (int i = 0; i < 26; i++) 
        if (root->hash[i]) 
            return 0; 
    return 1; 
} 

void suggestions(tree* root, string prefix){
    if (root->end) 
        cout << prefix<<'\n'; 
 
    if (isLastNode(root)) 
        return; 
  
    for (int i = 0; i < 26; i++) 
    { 
        if (root->hash[i]) 
        { 
            prefix.push_back(97 + i); 
            suggestions(root->hash[i], prefix); 
            prefix.resize(prefix.size()-1);
        } 
    }
}

void search(char word[]){
	cout<<"Sugesstions for '"<<word<<"' are: \n";
	tree* curr = root;
	for(int i=0;word[i]!='\0';i++){
		int hash_key = hash_pos(word[i]);
		if(curr->hash[hash_key] == NULL){
			cout<<"Nothing!!";
			return;
		}
		curr = curr->hash[hash_key];	
	}
	//cout<<curr->data;
	suggestions(curr, word);
	cout<<"\n";
}


main(){
	for(int i =0;i<26;i++)
		dict->hash[i] = NULL;
	insert("and");
	insert("auto");
	insert("bit");
	insert("bool");
	insert("break");
	insert("case");
	insert("catch");
	insert("char");
	insert("class");
	insert("const");
	insert("consteval");
	insert("constexpr");
	insert("constinit");
	insert("constcast");
	insert("false");
	insert("float");
	insert("for");
	insert("friend");
	insert("static");
	insert("struct");
	insert("while");
	insert("xor");
	
	search("ca");
	search("const");
	search("int");
}

