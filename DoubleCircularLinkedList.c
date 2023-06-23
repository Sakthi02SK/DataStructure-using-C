//DoubleCircularLinkedList
#include<stdio.h>
#include<stdlib.h>
struct list{
    struct list *p;
    int d;
    struct list *l;
};
typedef struct list sl;
sl *st = NULL,*end = NULL,*new = NULL;
void crtlt(int v){
    new = (sl*)malloc(sizeof(sl));
    new->p = NULL;
    new->d = v;
    new->l = NULL;
    if(st==NULL){
        st = new;
        end = new;
    }
    else{
        end->l = new;
        new->p = end;
        end = new;
        end->l = st;
        st->p = end;
    }
}
void inst(int v){
    new = (sl*)malloc(sizeof(sl));
    new->d = v;
    end->l = new;
    st->p = new;
    new->l = st;
    new->p = end;
    st = new;
}
void inend(int v){
    new = (sl*)malloc(sizeof(sl));
    new->d = v;
    end->l = new;
    new->p = end;
    new->l = st;
    st->p = new;
    end = new;
}
void inpos(int p,int v,sl *pt){
    for(int i=1;i<p-1;i++){
        pt = pt->l;
    }
    new = (sl*)malloc(sizeof(sl));
    new->l = pt->l;
    new->d = v;
    new->p = (pt->l)->p;
    pt->l = new;
}
void delst(){
    sl *t = st;
    (st->l)->p = st->p;
    st = st->l;
    end->l = st;
    free(t); 
}
void delend(){
    sl *t = end;
    (end->p)->l = st;
    st->p = end->l;
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
void sort(sl *p){
    do{
        for(sl *i=p->l;i!=st;i = i->l){
            if(p->d > i->d){
                int t = p->d;
                p->d = i->d;
                i->d = t;
            }
        }
        p = p->l;
    }
    while(p!=st);
}
void srch(int v,sl *pt){
    int i = 1,c = 0;
    do{
        if(pt->d==v){
            printf("Value %d at %d Position\n",v,i);
            c++;
            break;
        }
        i++;
        pt = pt->l;
    }
    while(pt!=st);
    if(c==0){
        printf("Value %d Not Found in the List\n",v);
    }
}
void prtlt(sl *pt){
    do{
        printf("%d ",pt->d);
        pt = pt->l;
    }
    while(pt!=st);
    printf("\n");
}
int main(){
    int n,v,p,o;
    printf("Enter ur N value:");
    scanf("%d",&n);
    printf("Enter ur Array:");
    for(int i=0;i<n;i++){
        scanf("%d",&v);
        crtlt(v);
    }
    while(1){
        printf("1) Insert\n2) Delete\n3) Sort\n4) Search\n5) PrintList\n6) Exit\nEnter ur Option:");
        scanf("%d",&o);
        if(o==1){
            printf("1) Insert at Start\n2) Insert at End\n3) Insert at Position\nEnter ur Option:");
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
            printf("1) Delete at Start\n2) Delete at End\n3) Delete at Position\nEnter ur Option:");
            scanf("%d",&o);
            if(o==1){
                delst();
            }
            if(o==2){
                delend();
            }
            if(o==3){
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
            prtlt(st);
        }
        else if(o==6){
            exit(0);
        }
        else{
            printf("Enter ur option btw 1-6");
        }
    }
}