#include <iostream>
#include <iomanip> //set::setprecision
#include <string>
#include <cmath> //exp(), floor()
using namespace std;

/*
humidex = temperature + h
h = (0.5555)× (e - 10.0)
e = 6.11 × exp [5417.7530 × ((1/273.16) - (1/(dewpoint+273.16)))]
*/

class solution{
    public:
    void ans(string cmd1, float num1, string cmd2,float num2);
    private:
    float temp,dew,hum; // hum == humindex
    void getT(); // T == temperature
    void getD(); // D == dewpoint
    void getH(); // H == humindex
};

void solution::getT(){
    float e = 6.11 * exp( 5417.7530 * ((1/273.16) - (1/(dew+273.16))) );
    float h = (0.5555) * (e - 10.0);
    temp=hum-h;
}

void solution::getD(){
    float h = hum - temp;
    float e = (h/0.5555) + 10.0;
    dew = 1/273.16 - log(e/6.11)/5417.7530;
    dew = 1/dew - 273.16;
}

void solution::getH(){
    float e = 6.11 * exp( 5417.7530 * ((1/273.16) - (1/(dew+273.16))) );
    float h = (0.5555) * (e - 10.0);
    hum = temp+h;
}

void solution::ans(string cmd1, float num1, string cmd2,float num2){
    if(cmd1=="T" && cmd2=="D"){
        temp=num1; dew=num2;
        getH();
    }
    else if(cmd1=="D" && cmd2=="T"){
        dew=num1; temp=num2;
        getH();
    }
    else if(cmd1=="T" && cmd2=="H"){
        temp=num1; hum=num2;
        getD();
    }
    else if(cmd1=="H" && cmd2=="T"){
        hum=num1; temp=num2;
        getD();
    }
    else if(cmd1=="D" && cmd2=="H"){
        dew=num1; hum=num2;
        getT();
    }
    else{
        hum=num1; dew=num2;
        getT();
    }
    cout << setprecision(1) << fixed << "T " << temp << ' ';
    cout << setprecision(1) << fixed << "D " << dew << ' ';
    cout << setprecision(1) << fixed << "H " << hum;
}

int main(){
    string cmd1,cmd2;
    float num1,num2;
    int i=0;
    while(cin >> cmd1){
        solution sol;
        if (cmd1=="E") break;
        else{
            if(i >0) cout << endl;
            cin >> num1 >> cmd2 >> num2;
            sol.ans(cmd1,num1,cmd2,num2);
            i++;
        }
    }
    return 0;
}