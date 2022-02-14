#include<stdio.h>
#define n 3
#define m 4
float find_det(float arr[n][m]);
void replacing_column(float arr[n][m],float arr_c[n][m],int column);
void replacing_back(float arr[n][m],float arr_c[n][m],int column);
int main(){
    int i,j;
    float num[n][m],num_c[n][m],det[m],x[3];
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            scanf("%f" ,&num[i][j]);
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            num_c[i][j]=num[i][j];
        }
    }
    det[0]=find_det(num);
    if(det[0]==0){
        printf("No solution!\n");
        return 0;
    }
    replacing_column(num,num_c,0);
    det[1]=find_det(num_c);
    replacing_back(num,num_c,0);

    replacing_column(num,num_c,1);
    det[2]=find_det(num_c);
    replacing_back(num,num_c,1);

    replacing_column(num,num_c,2);
    det[3]=find_det(num_c);

    for(i=1;i<=3;i++){
        x[i-1]=det[i]/det[0];
        if(x[i-1]==0*(-1)){
            x[i-1]=0;
        }
    }
    printf("x = %.2f \n" ,x[0]);
    printf("y = %.2f \n" ,x[1]);
    printf("z = %.2f \n" ,x[2]);
    return 0;
}
float find_det(float arr[n][m]){
    int i,j;
    float det=0,mul_d[3]={1,1,1},mul_u[3]={-1,-1,-1};
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            mul_d[i]*=  arr[j][(i+j)%3];
        }
        det+=mul_d[i];
    }
    for(i=0;i<n;i++){
        for(j=n-1;j>=0;j--){
            mul_u[i]*= arr[j][(i-j+2)%3];
        }
        det+=mul_u[i];
    }
    return det;
}
void replacing_column(float arr[n][m],float arr_c[n][m],int column){
    int i;
    for(i=0;i<n;i++){
        arr_c[i][column]=arr[i][m-1];
    }
}
void replacing_back(float arr[n][m],float arr_c[n][m],int column){
    int i;
    for(i=0;i<n;i++){
        arr_c[i][column]=arr[i][column];
    }
}
