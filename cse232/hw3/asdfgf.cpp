#include<iostream>
#include<string>
using std::cin; using std::cout; using std::endl;
using std::string;
int main(){
  double body = 98.2;
  double temp1,temp2,temp3;
  string f;


  cin >> temp1 >>f>>temp2 >>f>> temp3>>f>>f;

  if ( temp1-body < .5 && temp1-body >-0.5){
    cout << temp1 << "F" << endl;
  }
  if ( temp2-body < .5 && temp2-body >-0.5){
    cout << temp2 << "F" << endl;
  }
  if ( temp3-body < .5 && temp3-body >-0.5){
    cout << temp3 << "F" << endl;
  }  
}