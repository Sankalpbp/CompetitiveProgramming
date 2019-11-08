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


int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num==0){
        output[0]="";
        return 1;
    }
    
    int dig=num%10;
    int subProbSize=keypad(num/10,output);
    
    string small= numtostr(dig);
    
    string arr[subProbSize];
    
    for(int i=0;i<subProbSize;i++){
        arr[i]=output[i];
    }
    int count=0;
    for(int i=0;i<small.length();i++){
        for(int j=0;j<subProbSize;j++){
            output[count++]=arr[j]+small[i];
        }
    }
   
    return subProbSize*(small.length());
    
}





