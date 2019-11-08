#include <iostream>
#include <string>
using namespace std;

string numtostr(int num){
    if(num==1||num==0){
        return "";
    }
    else if(num==2){
        return "abc";
    }
    else if(num==3){
        return "def";
    }
    else if(num==4){
        return "ghi";
    }
    else if(num==5){
        return "jkl";
    }
    else if(num==6){
        return "mno";
    }
    else if(num==7){
        return "pqrs";
    }
    else if(num==8){
        return "tuv";
    }
    else if(num==9){
        return "wxyz";
    }
}

void printKey(int num,string output){
    if(num==0){
        cout<<output<<"\n";
        return;
    }
    
    int k= num%10;
    string small= numtostr(k);
    for(int i=0;i<small.length();i++){
        printKey(num/10,small[i]+output);
    }
}



void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
        printKey(num,"");
    
}
