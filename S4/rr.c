#include<stdio.h>
struct process{
    int id,at,bt,ct,tat,wt;
    int status,qstatus,r_time;
};
//Queue
int q[100],front=-1,rear=-1;
void enqueue(int item){
    if(rear == -1){
        rear++;
        front++;
        q[rear]=item;
    }
    else{
        rear++;
        q[rear]=item;
    }
}
int dequeue(){
    int item;
    item=q[front];
    front++;
    return item;
}

int main(){
    struct process p[30];
    int i,j,n,completed = 0,tq,current_time;
    printf("Enter the no of process:");
    scanf("%d",&n);
    printf("Enter the time quantum: ");
    scanf("%d",&tq);

    for(i=0;i<n;i++){
        printf("enter id, at, bt\n");
        scanf("%d %d %d",&p[i].id,&p[i].at,&p[i].bt);
        p[i].status=0;
        p[i].qstatus=0;
        p[i].r_time=p[i].bt;
    }
    enqueue(0);
    p[0].qstatus=1;
    current_time = p[0].at;
    while(completed != n){
        int i = dequeue();
        if(p[i].r_time > tq){
            current_time += tq;
            p[i].r_time -= tq;
        }
        else{
            current_time += p[i].r_time;
            p[i].ct = current_time;
            p[i].status = 1;
            completed ++;
            p[i].tat = p[i].ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt-(p[i].bt-p[i].r_time);
            p[i].r_time=0;
        }
        for(int j=i+1;j<n;j++){
            if(p[j].at <= current_time && p[j].status==0 && p[j].qstatus==0){
                enqueue(j);
                p[j].qstatus=1;
            }
        }
        if(p[i].r_time != 0){
            enqueue(i);
        }

    }
    float tot_tat,tot_wt;
    float avg_tat = 0.0;
    float avg_wt = 0.0;
    for(i=0;i<n;i++){
        tot_tat += p[i].tat;
        tot_wt += p[i].wt;
    }
    avg_tat = tot_tat/n;
    avg_wt = tot_wt/n;

    // process details
    printf("Process details\n");
    printf("id\tat\tbt\tct\ttat\twt\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    printf("Average tat = %0.2f\n",avg_tat);
    printf("Average wt = %0.2f\n",avg_wt);
}
