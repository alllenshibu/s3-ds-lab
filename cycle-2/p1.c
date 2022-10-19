#include<stdio.h>

typedef struct
{
	int row;
	int col;
	int val;

}sparse;
 #define MAX 100

void sumsparse(sparse s_matrix_1[],sparse  s_matrix_2[],sparse s_matrix_sum[]){
  if (s_matrix_1[0].row != s_matrix_2[0].row && s_matrix_1[0].col != s_matrix_2[0].col)
    {
        printf("Matrix dimesions are incompatiable\n");
        
    }

    

    s_matrix_sum[0].row = s_matrix_1[0].row;
    s_matrix_sum[0].col = s_matrix_1[0].col;

    int z = 1, x = 1, y = 1;

    for (int i = 0; i < s_matrix_1[0].row; i++)
        for (int j = 0; j < s_matrix_1[0].col; j++)
        {
            if (s_matrix_1[x].row == i && s_matrix_1[x].col == j && s_matrix_2[y].row == i && s_matrix_2[y].col == j)
            {
                s_matrix_sum[z].row = i;
                s_matrix_sum[z].col = j;
                s_matrix_sum[z].val = s_matrix_1[x].val+ s_matrix_2[y].val;
                x++;
                y++;
                z++;
            }
            else if (s_matrix_1[x].row == i && s_matrix_1[x].col == j)
            {
                s_matrix_sum[z].row = i;
                s_matrix_sum[z].col = j;
                s_matrix_sum[z].val= s_matrix_1[x].val;
                x++;
                z++;
            }
            else if (s_matrix_2[y].row == i && s_matrix_2[y].col == j)
            {
                s_matrix_sum[z].row = i;
                s_matrix_sum[z].col = j;
                s_matrix_sum[z].val = s_matrix_2[y].val;
                y++;
                z++;
            }
        }
    s_matrix_sum[0].val = --z;

    printf("Sum\n");
    for (int i = 0; i <= s_matrix_sum[0].val; i++)
        printf("%d %d %d\n", s_matrix_sum[i].row, s_matrix_sum[i].col, s_matrix_sum[i].val);

    
	

}

 void readsparse(sparse a[], int m, int n)
{
            int i, j, k, item, p;
            a[0].row = m;
            a[0].col = n;
            k = 1;

            printf("\nEnter the elements:\n");
            for(i=0; i<m; i++)
            {
                        for(j=0; j<n; j++)
                        {
                                    scanf("%d",&item);
                                    if(item == 0)
                                                continue;
                                    a[k].row = i;
                                    a[k].col = j;
                                    a[k].val = item;
                                    k++;
                        }
            }
            a[0].val = k-1;

            printf("\nThe entered sparse matrix is:\n");
            printf("\nRow\tColumn\tValue\n");
            for(p=0;  p<=a[0].val;  p++)
            {
                        printf("%d\t", a[p].row);
                        printf("%d\t", a[p].col);
                        printf("%d\n", a[p].val);
            }
}

int main(){
   int m, n, key;
            sparse a[MAX], b[MAX],c[MAX];
            printf("\nEnter  the no of rows and columns:\t");
            scanf("%d%d",&m, &n);

            readsparse(a, m, n);
            readsparse(b, m, n);
            sumsparse(a,b,c);
          
}
