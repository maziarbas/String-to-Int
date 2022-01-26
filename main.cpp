#include<iostream>
#include<string>
#include<limits.h>

using std::intmax_t;
using std::cout;
using std::isdigit;
using std::isdigit;
using std::string;

int myAtoi(string s){

    int sign =1; 
    int index=0;
    int result =0;
    int n=s.size();
    // removing the white spaces 
    while(index<n && s[index]==' '){
        index++;
    }

    // checking for sign + or -1 
    if(index<n && s[index]=='+'){
        index++;
    }
    else if(index<n && s[index]=='-'){
        sign = -1;
        index++;
    }

    // checking for digits 
    while(index<n && isdigit(s[index])){
        int digit = s[index]-'0';

        if((result>INT_MAX/10)|| (result ==INT_MAX/10 &&digit>INT_MAX%10)){
            return sign == 1 ? INT_MAX:INT_MIN;
        }
        result = result * 10 +digit;
    }
    return result;
}

int main(){

    cout<<myAtoi("   -123")<<"\n";
}