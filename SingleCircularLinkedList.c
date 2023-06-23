//SingleCircularList
#include<stdio.h>
#include<stdlib.h>
struct list{
    int data;
    struct list *l;
};
typedef struct list sl;
sl *st = NULL,*end = NULL,*new = NULL;
void crtlt(int m){
    new = (sl*)malloc(sizeof(sl));
    new->data = m;
    new->l = NULL;
    if(st==NULL){
        st = new;
        end = new;
    }
    else{
        end->l = new;
        end = new;
        end->l = st;
    }
}
void inst(int v){
    new = (sl*)malloc(sizeof(sl));
    new->data = v;
    new->l = st;
    end->l = new;
    st = new;
}
void inend(int v){
    new = (sl*)malloc(sizeof(sl));
    new->data = v;
    new->l = st;
    end->l = new;
    end = new;
}
void inpos(int p,int v,sl *pt){
    for(int i=1;i<p-1;i++){
        pt = pt->l;
    }
    new = (sl*)malloc(sizeof(sl));
    new->data = v;
    new->l = pt->l;
    pt->l = new;
}
void delst(){
    end->l = st->l;
    free(st);
    st = end->l;
}
void delend(sl *pt){
    while(pt->l!=end){
        pt = pt->l;
    }
    pt->l = st;
    free(end);
    end = pt;
}
void delpos(int p,sl *pt){
    for(int i=1;i<p-1;i++){
        pt = pt->l;
    }
    sl *t = pt->l;
    pt->l = (pt->l)->l;
    free(t);
}
void sort(sl *p){
    do{
        for(sl *i=p->l;i!=st;i = i->l){
            if(p->data > i->data){
                int t = p->data;
                p->data = i->data;
                i->data = t;
            }
        }
        p = p->l;
    }
    while(p!=st);
}
void srch(int v,sl *pt){
    int i = 1,c = 0;
    do{
        if(pt->data==v){
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
void prtlt(sl *p){
    do{
        printf("%d ",p->data);
        p = p->l;
    }
    while(p!=st);
    printf("\n");
}
int main(){
    int n,m,v,p;
    printf("Enter N value:");
    scanf("%d",&n);
    printf("Enter a Array:");
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        crtlt(m);
    }
    while(1){
        int o;
        printf("1) Insert\n2) Delete\n3) SortList\n4) Search\n5) PrintList\n6) Exit\nEnter ur Opition:");
        scanf("%d",&o);
        if(o==1){
            printf("1) Insert at Start\n2) Insert at End\n3) Insert at Position\nEnter ut Option:");
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
                printf("Enter a Position to Insert:");
                scanf("%d",&p);
                printf("Enter ur Value:");
                scanf("%d",&v);
                inpos(p,v,st);
            }
        }
        else if(o==2){
            printf("1) Delete at Start\n2) Delete at End\n3) Delete at Position\nEnter ut Option:");
            scanf("%d",&o);
            if(o==1){
                delst();
            }
            else if(o==2){
                delend(st);
            }
            else if(o==3){
                printf("Enter a Position to Delete:");
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
            printf("%d %d",st,end->l);
            exit(0);
        }
        else{
            printf("Enter ur option btw 1-6\n");
        }
    }
}