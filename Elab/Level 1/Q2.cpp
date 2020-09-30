#include <iostream>
using namespace std;
int main() {
    int number;
    cin>>number;
    int copy = number;
    int sum=0;int num;
    while(number) {
        num = number%10;sum += num*num*num;
        number = number/10;
    }
    if(sum==copy) {
        cout<<"Give to Scientist Armstrong"<<endl;
    }
    else {
        cout<<"Dont Give to Scientist Armstrong"<<endl;
    }
    return 0;
}