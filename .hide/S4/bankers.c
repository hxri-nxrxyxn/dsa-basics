#include<stdio.h>
#include<stdlib.h>
struct process{
    int pid;
};
int main(){
    int alloc[20][20],max[20][20],need[20][20],available[20];
    int m,n,sequence[20],status[20],completed=0;
    int c = 0;
    printf("Enter the no of processes and resources:");
    scanf("%d %d",&m,&n);
    printf("Enter the allocation matrix:");
    for(int i =0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter the max matrix:");
    for(int i =0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&max[i][j]);
        }
    }
    for(int i =0;i<m;i++){
        for(int j=0;j<n;j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    printf("Enter the availabiltiy of resources:");
    for(int i =0;i<n;i++){
        scanf("%d",&available[i]);
    }
    for(int i =0;i<m;i++){
        sequence[i] = 0;
        status[i] = 0;
    }
    for(int k = 0;k<m;k++){
        for(int i =0;i<m;i++){
            if(status[i] == 0){
                int count = 0;
                for(int j=0;j<n;j++){
                    if(need[i][j] <= available[j]){
                        count++;
                    }
                }
                if(count == n){
                    completed++;
                    sequence[c] = i;
                    c++;
                    status[i] = 1;
                    for(int j = 0;j<n;j++){
                        available[j]+=alloc[i][j];
                    }
                }
            }
        }
    }
    if(completed == m){
        printf("It is safe");
        for(int i = 0;i<m;i++){
            printf("P%d->",sequence[i]);
        }
    }else{
        printf("It is unsafe and is in deadlock");
    }
}
