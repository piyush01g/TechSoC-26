#include<iostream>
using namespace std;

int main(){
    int C, N;
    cout<<"Enter maximum storage capacity: ";
    cin>>C;
    cout<<"\nEnter number of containers: ";
    cin>>N;
    double weight[N];
    double total=0;
    for(int i=0; i<N; i++){
        cout<<"\nEnter value of weight "<<(i+1)<<" : ";
        cin>>weight[i];
        total+=weight[i];
      }
    cout<<"\nTotal Shipment Weight: "<<total;

    double avg = total/N;
    cout<<"\nAverage Container Weight: "<<avg;

    int max= weight[0];
    for (int j=0; j<N; j++){
        if (weight[j]>max){
            max=weight[j];
        } else {
            max=max;
        }
    }
    cout<<"\nHeaviest Container: "<<max;


    int min= weight[0];
    for (int k=0; k<N; k++){
        if (weight[k]<min){
            min=weight[k];
        } else {
            min=min;
        }
    }
     cout<<"\nLightest Container: "<<min;

     
    if(total>=200){
        cout<<"\nClassification: Heavy";
    } else{
        cout<<"\nClassification: Light";
    } 

    cout<<"\nPort Capacity: "<<C;

    if (total>C){
        cout<<"\nStatus: Shipment exceeds port capacity";
    } else {
        cout<<"\nStatus: Shipment can be unloaded";
    }
return 0;
}