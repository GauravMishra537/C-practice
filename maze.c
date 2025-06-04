#include<stdio.h>
int maze(int cr,int cc,int er,int ec){//cr=current row,cc=current column,er=end row,ec=end column
    int rightways=0;
    int downways=0;
    if(cr==er && cc==ec) return 1;//last block means last row and last column
    else if (cr==er){
        rightways+=maze(cr,cc+1,er,ec);//last row so can only go in right direction
    }
    else if(cc==ec){
        downways+=maze(cr+1,cc,er,ec);//last column so can only go downward
    }
    else if(cr<er && cc<ec){//can go both right and down
         rightways+=maze(cr,cc+1,er,ec);
          downways+=maze(cr+1,cc,er,ec);
    }
    int noofways=downways+rightways;//counting total no of ways
    return noofways;
}

int main() {
    int a,b;
    printf("Enter no of rows:");
    scanf("%d",&a);
    printf("Enter no of columns:");
    scanf("%d",&b);
    int totalways=maze(1,1,a,b);//cr==1,cc==1,er==a,ec==b;at starting position
    printf(" The total no of ways in a maze to go from starting to end only by going right and down 1 step at a moment is %d",totalways);
    return 0;
}