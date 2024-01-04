#include <bits/stdc++.h>
using namespace std;

int main(){

    int N;
    cin>>N;
    string infected;
    cin>>infected;
    vector<string> infection;
    string temp="";
    for(int i=0; i<N; i++){
        if(infected[i]=='1'){
            temp+='1';
        }else{
            if(i==0){
                continue;
            }
            if(infected[i-1]=='0'){
                continue;
            }
            infection.push_back(temp);
            temp="";
        }
    }
    
    if(temp!=""){
        infection.push_back(temp);
    }
    int days[infection.size()];
    for(int i=0; i<infection.size(); i++){
        if(i==0 and infected[i]=='1'){
            days[i]=infection[i].size()-1;
            continue;
        }
        if(i==infection.size()-1 and infected[N-1]=='1'){
            days[i]=infection[i].size()-1;
            continue;
        }
        if(infection[i].size()%2==0){
            days[i]=infection[i].size()/2-1;
        }else{
            days[i]=infection[i].size()/2;
        }
        // infection[i]=infection[i]/2;
    }
    int min=N;
    for(int i=0; i<infection.size(); i++){
        if(days[i]<min){
            min=days[i];
        }
    }
    int sum=0;
    // cout<<min<<endl;
    // for(int i=0; i<infection.size(); i++){
    //     cout<<infection[i]<<endl;
    // }
    for(int i=0; i<infection.size(); i++){
        if(i==0 and infected[0]=='1'){
            if(int(infection[i].size()-(min*2))<=1){
                sum+=1;
                
            }else{
                sum+=(infection[i].size()-min*2);
            }
        }else if(i==infection.size()-1 and infected[N-1]=='1'){
            if(int(infection[i].size()-2*min)<0){
                sum+=1;
            }else{
                sum+=(infection[i].size()-min*2);
            }
        }else{
            sum+=(infection[i].size()-2*min);
        }
        
    }
    cout<<sum<<endl;
    return 0;
}