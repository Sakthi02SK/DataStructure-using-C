//DoubleLinkedList
#include<stdio.h>
#include<stdlib.h>
struct list{
    struct list *p;
    int data;
    struct list *l;
};
typedef struct list sl;
sl *st = NULL,*end = NULL,*new = NULL;
void crtlt(int m){
    new = (sl*)malloc(sizeof(sl));
    new->p = NULL;
    new->data = m;
    new->l = NULL;
    if(st==NULL){
        st = new;
        end = new;
    }
    else{
        end->l = new;
        new->p = end;
        end = new;
    }
}
void inst(int v){
    new = (sl*)malloc(sizeof(sl));
    new->p = NULL;
    new->data = v;
    new->l = st;
    st->p = new;
    st = new;
}
void inend(int v){
    new = (sl*)malloc(sizeof(sl));
    new->p = end;
    new->data = v;
    new->l = NULL;
    end->l = new;
    end = new;
}
void inpos(int p,int v,sl *pt){
    for(int i=1;i<p-1;i++){
        pt = pt->l;
    }
    new = (sl*)malloc(sizeof(sl));
    new->l = pt->l;
    new->data = v;
    new->p = (pt->l)->p;
    pt->l = new;
}
void delst(){
    sl *t = st;
    (st->l)->p = NULL;
    st = st->l;
    free(t);
}
void delend(){
    sl *t = end;
    (end->p)->l = NULL;
    end = end->p;
    free(t);
}
void delpos(int p,sl *pt){
    for(int i=1;i<p-1;i++){
        pt = pt->l;
    }
    ((pt->l)->l)->p = (pt->l)->p;
    sl *t = pt->l;
    pt->l = (pt->l)->l;
    free(t);
}
void sort(sl *pt){
    for(sl *i = pt;i!=NULL;i = i->l){
        for(sl *j = i->l;j!=NULL;j = j->l){
            if(i->data > j->data){
                int t = i->data;
                i->data = j->data;
                j->data = t;
            }
        }
    }
}
void srch(int v,sl *pt){
    int i = 1,c = 0;
    while(pt!=NULL){
        if(pt->data==v){
            printf("Value %d at %d Position\n",v,i);
            c++;
            break;
        }
        i++;
        pt = pt->l;
    } 
    if(c==0){
        printf("%d Value Not Found in the List\n");
    }
}
void prlt(sl *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->l;
    }
    printf("\n");
}
int main(){
    int n,m,v,p,o;
    printf("Enter N Value:");
    scanf("%d",&n);
    printf("Enter a Array:");
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        crtlt(m);
    }
    while(1){
        printf("1) Insert\n2) Delete\n3) SortList\n4) Search\n5) PrintList\n6) Exit\nEnter ur Option:");
        scanf("%d",&o);
        if(o==1){
            printf("1) Insert at Start\n2) Insert at End\n3) Insert at Position\nEnter ur Oprion:");
            scanf("%d",&o);
            if(o==1){
                printf("Enter ur Value:");
                scanf("%d",&v);
                inst(v);
            }
            else if(o==2){
                printf("Enter ur Value:");
                scanf("%d",&v);
                inend(v);
            }
            else if(o==3){
                printf("Enter ur Insert Position:");
                scanf("%d",&p);
                printf("Enter ur Value:");
                scanf("%d",&v);
                inpos(p,v,st);
            }
        }
        else if(o==2){
            printf("1) Delete at Start\n2) Delete at End\n3) Delect at Position\nEnter ur Option:");
            scanf("%d",&o);
            if(o==1){
                delst();
            }
            else if(o==2){
                delend();
            }
            else if(o==3){
                printf("Enter ur Position to Delete:");
                scanf("%d",&p);
                delpos(p,st);
            }
        }
        else if(o==3){
            sort(st);
        }
        else if(o==4){
            printf("Enter ur Searching Value:");
            scanf("%d",&v);
            srch(v,st);
        }
        else if(o==5){
            prlt(st);
        }
        else if(o==6){
            exit(0);
        }
        else{
            printf("Enter ur option btw 1-6");
        }
    }
}