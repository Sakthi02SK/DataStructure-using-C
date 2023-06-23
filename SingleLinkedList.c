//SingleLinkedList
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *l;
};
struct node *st=NULL,*end=NULL,*new=NULL;
void crtlist(int m){
    new = (struct node*)malloc(sizeof(struct node));
    new->data = m;
    new->l = NULL;
    if(st==NULL){
        st = new;
        end = new;
    }
    else{
        end->l = new;
        end = new;
    }
}
void inst(int v){
    new = (struct node*)malloc(sizeof(struct node));
    new->data = v;
    new->l = st;
    st = new;
}
void inend(int v){
    new = (struct node*)malloc(sizeof(struct node));
    new->data = v;
    new->l = NULL;
    end->l = new;
    end = new;
}
void inpos(int p,int v,struct node *pt){
    for(int i=1;i<p-1;i++){
        pt = pt->l;
    }
    new = (struct node*)malloc(sizeof(struct node));
    new->data = v;
    new->l = pt->l;
    pt->l = new;
}
void delst(){
    struct node *del = st->l;
    free(st);
    st = del;
}
void delend(struct node *p){
    while(p->l!=end){
        p = p->l;
    }
    p->l = NULL;
    free(end);
    end = p;
}
void delpos(int p,struct node *pt){
    for(int i=1;i<p-1;i++){
        pt = pt->l;
    }
    struct node *t = pt;
    pt = pt->l;
    t->l = pt->l;
    free(pt);
}
void sort(struct node *pt){
    for(struct node *i = pt;i!=NULL;i = i->l){
        for(struct node *j = i->l;j!=NULL;j = j->l){
            if(i->data > j->data){
                int t = i->data;
                i->data = j->data;
                j->data = t;
            }
        }
    }
}
int srv(int v,struct node *p){
    int i = 1,c = 0;
    while(p->l!=NULL){
        if(p->data==v){
            printf("Value %d is at %d position\n",v,i);
            c++;
            break;
        }
        i++;
        p = p->l;
    }
    if(c==0){
        printf("Value not found in the list\n");
    }
}
void prt(struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->l;
    }
    printf("\n");
}
int main(){
    int n,m,a;
    printf("Enter N value:");
    scanf("%d",&n);
    printf("Enter a Array:");
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        crtlist(m);
    }
    while(1){
        printf("1) Insert\n2) Delete\n3) SortList\n4) Search\n5) PrintList\n6) Exit\nEnter ur option:");
        scanf("%d",&a);
        if(a==1){
            int p,v,o;
            printf("1) Insert at st\n2) Insert at end\n3) Insert at position\nEnter ur option:");
            scanf("%d",&o);
            if(o==1){
                printf("Enter ur value:");
                scanf("%d",&v);
                inst(v);
            }
            else if(o==2){
                printf("Enter ur value:");
                scanf("%d",&v);
                inend(v);
            }
            else if(o==3){
                printf("Enter a position:");
                scanf("%d",&p);
                printf("Enter ur value:");
                scanf("%d",&v);
                inpos(p,v,st);
            }
        }
        else if(a==2){
            int p,v,o;
            printf("1) Delete at st\n2) Delete at end\n3) Delete at position\nEnter ur option:");
            scanf("%d",&o);
            if(o==1){
                delst();
            }
            else if(o==2){
                delend(st);
            }
            else if(o==3){
                printf("Enter a position:");
                scanf("%d",&p);
                delpos(p,st);
            }
        }
        else if(a==3){
            sort(st);
        }
        else if(a==4){
            int v,i;
            printf("Enter a value:");
            scanf("%d",&v);
            srv(v,st);
        }
        else if(a==5){
            prt(st);
        }
        else if(a==6){
            exit(0);
        }
        else{
            printf("Enter a num btw 1-6");
        }
    }
}