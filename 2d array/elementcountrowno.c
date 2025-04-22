/*A matrix contain only 0 and 1 .Find the row which contains maximum no of 1 and also row no*/
#include <stdio.h>
int main(){
    int arr[3][4]={{1,0,1,1},{1,0,1,0},{1,1,1,1}};
    int Maxcount=0;
    int Maxidx=0;
    for(int i=0;i<3;i++){
        int count=0;
        for(int j=0;j<4;j++){
            if(arr[i][j]==1) count++;
        }
        if(Maxcount<count){
            Maxcount=count;
            Maxidx=i;
        }
        printf("\n");
    }
    printf("the %d row contains maximum no of 1 that is equal to %d",Maxidx,Maxcount);
}