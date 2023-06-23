#include<stdio.h>
#include<stdlib.h>
int n,t;
int *a;
void push(){
    if(t == n-1)
        printf("StackOverflow\n");
    else{
        t+=1;
        printf("Enter ur Element to Insert:");
        scanf("%d",&a[t]);
    }
}
void pop(){
    if(t==-1)
        printf("StackUnderflow\n");
    else
        t-=1;
}
void isEmpty(){
    if(t==-1)
        printf("Stack is Empty\n");
    else
        printf("Stack has some Value\n");
}
void isFull(){
    if(t==n-1)
        printf("Stack is Full\n");
    else
        printf("Stack is not Full\n");
}
void peek(){
    if(t==-1)
        printf("Stack is Empty\n");
    else
        printf("Peek value is %d\n",a[t]);
}
void dis(){
    if(t==-1)
        printf("Stack is empty\n");
    else{
        for(int i=t;i>=0;i--){
            printf("%d ",a[i]);
            t-=1;
        }
        printf("\n");
    }
}
int main(){
    printf("Enter ur N value:");
    scanf("%d",&n);
    t = n-1;
    a = (int*)malloc(n*sizeof(int));
    printf("Enter ur Elements:");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
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
                dis();
                break;
            case 7:
                exit(0);
        }
    }
}