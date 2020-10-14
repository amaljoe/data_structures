#include <stdio.h>
#define SIZE 50

void input_sparse(int[][3]);
int add_sparse(int[][3], int[][3], int[][3]);
int compare_index(int, int, int, int);
void output_sparse(int[][3]);

int main(){
    int smat1[SIZE][3], smat2[SIZE][3], smat3[SIZE * 2][3];
    printf("MATRIX 1\n");
    input_sparse(smat1);
    printf("MATRIX 2\n");
    input_sparse(smat2);
    //add_sparse will return 1 if matirx addition is not possible
    if(add_sparse(smat1, smat2, smat3) == 1){
        printf("Matrix addition not possible.\n");
        return 1;
    }
    printf("\nMATRIX 1 + MATRIX 2 (SPARSE MATRIX)\n");
    output_sparse(smat3);
    return 0;
}

void input_sparse(int smat[][3]){
    int i, j, r, c, num, index = 0;
    printf("Enter the no. of rows:\n");
    scanf("%d", &r);
    printf("Enter the no. of columns:\n");
    scanf("%d", &c);
    //fill the first first row of sparse matrix with no. of rows and columns
    smat[0][0] = r;
    smat[0][1] = c;
    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            scanf("%d", &num);
            //check if its a non-zero number
            if (num != 0){
                index++;
                smat[index][0] = i;
                smat[index][1] = j;
                smat[index][2] = num;
            }
        }
    }
    //at this point, index denotes the number of non-zero elements in the matrix
    smat[0][2] = index;
}

int add_sparse(int smat1[][3], int smat2[][3], int smat3[][3]){
    //check if no. of rows and columns of both matrix are equal otherwise return 1 denoting error
    if(smat1[0][0] != smat2[0][0] || smat1[0][1] != smat2[0][1]){
        return 1;
    }
    int i, j, index1 = 1, index2 = 1, index3 = 1;
    //fill the first row with no. of rows and columns of resultant matrix
    smat3[0][0] = smat1[0][0];
    smat3[0][1] = smat1[0][1];
    while(index1 <= smat1[0][2] && index2 <= smat2[0][2]){
        int compare = compare_index(smat1[index1][0], smat1[index1][1], smat2[index2][0], smat2[index2][1]);
        //compare will return 1 if first matrix index is less than second matrix index
        if(compare == 1){
            smat3[index3][0] = smat1[index1][0];
            smat3[index3][1] = smat1[index1][1];
            smat3[index3][2] = smat1[index1][2];
            index1++;
            index3++;
        }
        //compare will return 2 if second matrix index is less than first matrix index
        else if(compare == 2){
            smat3[index3][0] = smat2[index2][0];
            smat3[index3][1] = smat2[index2][1];
            smat3[index3][2] = smat2[index2][2];
            index2++;
            index3++;
        }
        //compare will return 0 if both indexes are same
        else{
            smat3[index3][0] = smat1[index1][0];
            smat3[index3][1] = smat1[index1][1];
            //if both indexes are same, add the value
            smat3[index3][2] = smat1[index1][2] + smat2[index2][2];
            index1++;
            index2++;
            index3++;
        }
    }
    //the above while loop will be terminated when any ONE OF THE TWO matrices reaches its end
    //the following two while loops will check for the remaining elements and add them to the resultant matrix 
    while(index1 <= smat1[0][2]){
        smat3[index3][0] = smat1[index1][0];
        smat3[index3][1] = smat1[index1][1];
        smat3[index3][2] = smat1[index1][2];
        index1++;
        index3++;
    }
    while(index2 <= smat2[0][2]){
        smat3[index3][0] = smat2[index2][0];
        smat3[index3][1] = smat2[index2][1];
        smat3[index3][2] = smat2[index2][2];
        index2++;
        index3++;
    }
    //store the no. of elements in the resultant matrix
    smat3[0][2] = index3 - 1;
    return 0;
}

int compare_index(int r1, int c1, int r2, int c2){
    //the index with lower row number is always the lower index
    if(r1 < r2){
        return 1;
    }
    else if(r2 < r1){
        return 2;
    }
    //if row numbers are same, check for column numbers
    else{
        if(c1 < c2){
            return 1;
        }
        else if(c2 < c1){
            return 2;
        }
        //if both row and column numbers are same, both indexes are same
        else{
            return 0;
        }
    }
}

void output_sparse(int smat[][3]){
    int i, j;
    //print the elements of the matrix
    for(i = 0; i <= smat[0][2]; i++){
        for(j = 0; j < 3; j++){
            printf("%d  ", smat[i][j]);
        }
        printf("\n");
    }
}

