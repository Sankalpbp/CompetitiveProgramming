#include<bits/stdc++.h>
#define N 10
using namespace std;


bool isValidVertically(char cross[0][N], string word, int row,int col){

	int count = 0;
	for(int i = 0; i < word.length(); i++){
		if((cross[row + i][col] == '-' ) || (cross[row + i][col] == word[i])){
			count++;
		}
		if(cross[row + i][col] == '+'){
			return false;
		}
	}

	if(count != word.size()){
		return false;
	}

	return true;

}
bool isValidHorizontally(char cross[0][N], string word, int row,int col){

	int count = 0;
	for(int i = 0; i < word.length(); i++){
		if((cross[row][col+i] == '-' ) || (cross[row][col+i] == word[i])){
			count++;
		}
		if(cross[row][col+i] == '+'){
			return false;
		}
	}

	if(count != word.size()){
		return false;
	}

	return true;

}


void setVertically(char crossword[][10],string word, vector<string>&helper, int i, int j){
    string help="";
    for(int k=0;k<word.length();k++){
        if(crossword[i][j]=='-'){
            crossword[i][j]=word[k];
            help+='T';
        }else{
            help+='F';
        }
        i++;
    }
    help+='\0';
    helper.push_back(help);
}
void setHorizontally(char crossword[][10],string word, vector<string>&helper, int i,int j){
    string help="";
    for(int k=0;k<word.length();k++){
        if(crossword[i][j]=='-'){
            crossword[i][j]=word[k];
            help+='T';
        }else{
            help+='F';
        }
        j++;
    }
    help+='\0';
    helper.push_back(help);
}
void resetVertically(char crossword[][10],string word, vector<string>&helper,int i, int j){
    int len=helper.size();
    string help=helper[len-1];
    helper.pop_back();
    
    for(int k=0;k<help.length();k++){
        if(help[k]=='T'){
            crossword[i][j]='-';
        }
        i++;
    }
}
void resetHorizontally(char crossword[][10],string word, vector<string>&helper, int i,int j){
    int len=helper.size();
    string help=helper[len-1];
    helper.pop_back();
    
    for(int k=0;k<help.length();k++){
        if(help[k]=='T'){
            crossword[i][j]='-';
        }
        j++;
    }
}

bool solveCrossword(char crossword[][10],vector<string>&words,vector<string>&helper,int index){
    
    if(index==words.size()){
        //print crossword
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                cout<<crossword[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
        if((words[index][0]==crossword[i][j]) || crossword[i][j]=='-'){
           
           if(isValidVertically(crossword,words[index],i,j)){
                setVertically(crossword,words[index],helper,i,j);
                if(solveCrossword(crossword,words,helper,index+1))
                    return true;
                resetVertically(crossword,words[index],helper,i,j);
               }
            else if(isValidHorizontally(crossword,words[index],i,j)){
                setHorizontally(crossword,words[index],helper,i,j);
                if(solveCrossword(crossword,words,helper,index+1))
                    return true;
                resetHorizontally(crossword,words[index],helper,i,j);
               }
           }
       }
    }
    return false;
}


int main() {
    
    char crossword[10][10];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>crossword[i][j];
        }
    }
    
    string s;
    cin>>s;
    vector<string>words;
    string word="";
    int i=0;
    while(s[i]){
        if(s[i]==';'){
            words.push_back(word);
            word="";
        }
        else{
            word+=s[i];
        }
        i++;
    }
    words.push_back(word);
    int size= words.size();
    
    vector<string>helper(size);
    
    solveCrossword(crossword,words,helper,0);
    
}


