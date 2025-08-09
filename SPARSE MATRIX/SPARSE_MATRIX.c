//DSA
#include<stdio.h>
#define MAX 10
//GLOBAL STRUCTURE DECLERACTION
struct compsit
{
    int row;
    int col;
    int val;
};
//function for print 2D matrix 
void print_Matrix2d(int r,int c,int m[r][c])
{
    printf("\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
}
//function for taking input of 2D matrix
void matrix_input_2D(int r,int c,int m[r][c])
{
    printf("Enter the values of the matrix:\n");
    for(int i=0;i<r;i++)
        {
            for(int k=0;k<c;k++)
            {
                scanf("%d",&m[i][k]);
            }
        }
}
//function for creating composit matrix
void composit_matrix(struct compsit co[MAX],int r,int c,int m[r][c])
{
    int k=1;
    co[0].row=r;
    co[0].col=c;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(m[i][j]!=0)
            {
                co[k].row=i;
                co[k].col=j;
                co[k].val=m[i][j];
                k=k+1;
            }
        }
    }
    co[0].val=k-1;
    //printing of the matrix
    for(int i=0;i<=co[0].val;i++)
    {
        printf("%d %d %d",co[i].row,co[i].col,co[i].val);
        printf("\n");
    }
}
//creating transpose 
void transpose_matrix(int r,int c,int mt[c][r],int m[r][c])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            mt[j][i]=m[i][j];
        }
    }
}
void transpose_using_copo(struct compsit co[MAX],struct compsit T[MAX],int r,int c ,int m[r][c])
{
    T[0].row=co[0].col;
    T[0].col=co[0].row;
    T[0].val=co[0].val;
    for(int i=1;i<=co[0].val;i++)
    {
        T[i].row=co[i].col;
        T[i].col=co[i].row;
        T[i].val=co[i].val;
    }
}
void print_com(struct compsit co[MAX])
{
    for(int i=0;i<=co[0].val;i++)
    {
        printf("%d %d %d",co[i].row,co[i].col,co[i].val);
        printf("\n");
    }

}
int main()
{
    int r,c;
    printf("Enter the  Row and collome of the matrix:");
    scanf("%d %d",&r,&c);
    if (r>0&&c>0)
    {
        int m[r][c];
        //Function calling for enter element
        matrix_input_2D(r,c,m);
        printf("1)Create composit matrix\n2)Transpose the spars Matrix\n3)Transpose of the composit Matrix\nEnter:");
        int in;
        scanf("%d",&in);
        switch(in)
        {
            case 1:
            {
                struct compsit co[MAX];
                composit_matrix(co,r,c,m);
                break;
            }
            case 2:
            {
                int tm[c][r];
                transpose_matrix(r,c,tm,m);
                print_Matrix2d(c,r,tm);
                break;
            }
            case 3:
            {
                int tm[c][r];
                struct compsit co[MAX];
                struct compsit sec[MAX];
                struct compsit T[MAX];
                transpose_matrix(r,c,tm,m);
                printf("Transpose in arranged format:\n");
                composit_matrix(co,c,r,tm);
                printf("\n");
                composit_matrix(sec,r,c,m);
                printf("\n");
                transpose_using_copo(co,T,r,c,m);
                printf("Transpose directly by composit matrix(have to arrange it)");
                print_com(T);
                break;
            }
            
        }
    }
    else printf("NULL");
}