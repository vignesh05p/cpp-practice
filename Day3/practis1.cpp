//write program to  generate random 3 number in between 0 to10

#include<iostream>

using namespace std;

int main(){
    int num1 , num2, num3;

    srand(time(NULL));
    num1= rand() %11;
    num2=rand()%11;
    num3=rand()%11;

    cout<<"Random numbers are: "<<num1<<" "<<num2<<" "<<num3<<endl;
    return 0;

}