#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string sub_cipher(string st,int n){ //n=0~25;
    string new_string=st;
    string::iterator it;
    for(it=new_string.begin(); it!=new_string.end(); ++it){
        if(*it >= ('A'+26-n) ) {
            *it = (*it-26) + n;
        }
        else *it=*it+n;
    }
    return new_string;
}

bool isSameMessage(string st1, string st2){
    sort(st1.begin(),st1.end()); //no need to change st1
    bool flag=0; //if there exisit a right shift method, set flag to 1
    for(int i=1;i<26;++i){ //this loop keep try different digit to shift st2
    // then compare with st1
        string temp=sub_cipher(st2,i);
        sort(temp.begin(),temp.end());
        if(temp == st1) {
            flag=1;
            break;
        }
    }
    return flag;
}

int main(){
    string line0,line1;
    cin >> line0;
    cin >> line1;
    if(isSameMessage(line0,line1)) cout << "YES";
    else cout << "NO";
    return 0;
}