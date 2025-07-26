#include<iostream>

using namespace std;

string addString(string s1, string s2);


int main(){
    string name="vignesh";
    string lastname ="prabhu";
    
     string sum=addString(name,lastname);
     std::cout << sum << std::endl;
    
    
    return 0;
}

string addString(string s1, string s2)
{
    return s1+" "+s2;
    
}