#include<stdio.h>
#include<stdlib.h>
int *a,t,n;
void push(){
    if(t == n-1)
        printf("Queue OverFlow\n");
    else{
        t += 1;
        printf("Enter ur insert Value:");
        scanf("%d",&a[t]);
    }
}
void pop(){
    if(t==-1)
        printf("Queue UnderFlow\n");
    else
        t -= 1;
}
void isEmpty(){
    if(t == -1)
        printf("Queue is Empty\n");
    else
        printf("Queue has some value\n");
}
void isFull(){
    if(t == n-1)
        printf("Queue is Full\n");
    else
        printf("Queue is some empty Blocks\n");
}
void peek(){
    if(t == -1)
        printf("Queue is Empty");
    else
        printf("%d\n",a[t]);
}
void display(){
    for(int i=0;i<=t;i++)
        printf("%d ",a[i]);
    printf("\n");
}
int main(){
    int o,v;
    printf("Enter N value:");
    scanf("%d",&n);
    t = n-1;
    printf("Enter ur Array value:");
    a = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    while(1){
        printf("1) Push\n2) Pop\n3) isEmpty\n4) isFull\n5) Peek\n6) Display\n7) Exit\nEnter ur Option:");
        int o;
        scanf("%d",&o);
        switch(o){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                isEmpty();
                break;
            case 4:
                isFull();
                break;
            case 5:
                peek();
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
            default:
                printf("Enter ur Option btw 1-7\n");
        }
    }
}