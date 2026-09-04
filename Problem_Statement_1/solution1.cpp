#include<iostream>
using namespace std;

int main(){
    int R=0, C=0, G=0;
    cin>>R>>C;
    cin>>G;
    char matrix1[R][C];
    char matrix2[R][C];
    for (int i=0; i<R; i++){
        for (int j=0; j<C; j++){
            cin>>matrix1[i][j];
        }
    }
    
    int alive=0;
    for(int i=0; i<R; i++){
       
        for(int j=0; j<C; j++){
           
            if (matrix1[i][j]=='#') alive++;
        }
        
    }
    cout<<"Initial Population: " <<alive<<endl;
    int peak=alive;


    for (int k=0; k<G; k++){
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){

                int live=0;
            
                for(int x=-1; x<=1; x++){
                    for (int y=-1; y<=1; y++){
                        if((x==0)&&(y==0)) continue;
                        int newi=i+x;
                        int newj=j+y;

                        if((newi>=0)&&(newi<R)&&(newj>=0)&&(newj<C)){
                            if(matrix1[newi][newj]=='#') live++;
                        }
                    }
                }
                if(matrix1[i][j]=='#'){
                    if((live==2)||(live==3)) matrix2[i][j]='#';
                    else matrix2[i][j]='.';
                }
                else{
                    if (live==3) matrix2[i][j]='#';
                    else matrix2[i][j]='.';
                }
            } 

        }
        for(int i=0; i<R;i++){
            for (int j=0; j<C; j++){
                matrix1[i][j]=matrix2[i][j];
            }
        }

        alive=0;
        for(int i=0; i<R; i++){
            for (int j=0; j<C; j++){
                if (matrix1[i][j]=='#') alive++;
            }
        }

        if(alive>peak) peak=alive;
    }
    
    cout<<"Final Population: "<<alive<<endl;
    cout<<"Peak Population: "<<peak<<endl;

    cout<<"Final Grid:"<<endl;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout<<matrix1[i][j];
        } cout<<endl;
    }

    return 0;    
    }
