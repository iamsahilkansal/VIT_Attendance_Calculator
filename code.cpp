#include <bits/stdc++.h>

using namespace std;
float percent(float pr,float total);

void skip(float pr, float total){
    int counter=0;
    while(percent(pr,total)>=74.01){
        counter++;
        total++;
    }
    if(!(percent(pr,total)>=74.01)){
        counter--;
    }
    if(counter==0){
        cout<<"You are on the verge, just go all the classes!";
    }
    else{
        cout<<"Class can be skipped: "<<counter;
        cout<<"Attendance percentage will be: "<<ceil(percent(pr, total))<<"%"<<endl;
    }
}

void attend(float pr, float total){
    int temp=pr;
    while(percent(temp, total)<=74.01){
        temp++;
        total++;
    }
    cout<<"Class needed to be attended: "<<temp-pr<<endl;
    cout<<"Attendance percentage will be: "<<ceil(percent(temp, total))<<"%"<<endl;
}
bool can_skip(float pr,float total){
    float per=(pr*100)/total;
    if(per>=74.01){
        return true;
    }
    return false;
}

float percent(float pr,float total){
    return (pr*100)/total;
    
}
int main(){
    float total;
    float pr;
    cout<<"Enter the total no of classes happened: ";
    cin>>total;
    cout<<"Enter the total no of present days: ";
    cin>>pr;
    cout<<"Current Attendance percentage is: "<<ceil(percent(pr, total))<<"%"<<endl;
    if(can_skip(pr, total)){
        skip(pr, total);
    }
    else{
        attend(pr, total);
    }
}
