/*=========================================================
	6.7節 二元搜尋樹：建立,節點插入,節點搜尋,節點刪除

          *BstCreate()         建立二元搜尋樹
          *BstInsert()         插入節點
          *BstSearch()         搜尋節點
          *BstDelete()         刪除節點

  =========================================================
*/

#include <stdio.h>
#include <malloc.h>

typedef struct tagNode
        {
                char left_thread;
                struct tagNode *left_c;
                int data;
                char right_thread;
                struct tagNode *right_c;
        }TNode;
TNode *listA;

void visit(TNode  *);
void InOrder(TNode  *);  //中序走訪
TNode  *BstInsert(TNode  *,TNode  *);
TNode  *BstSearch(TNode  *,int );
TNode  *BstDelete(TNode  *,int );

void visit(TNode  *p)
{
    printf("%d ",p->data);
}

void InOrder(TNode  *p)
{
    if(p != NULL)
    {
        InOrder(p->left_c);
        visit(p);
        InOrder(p->right_c);
    }
}

//插入節點 主要就是用這個來建立二元樹
TNode  *BstInsert(TNode  *t,TNode  *p)  //t是root 將設定好的節點p插入
{
    TNode  *r,*q;
    char direction;
    p->left_c=p->right_c=NULL;

    if(t == NULL)
        t=p;

    else
    {
        q=t; 	 //為什麼不直接用t?  因為之後還要return t 不能失去該地址
        while(q != NULL)
        {
            if(p->data < q->data)
            {
                direction=1;
                r=q;		//為什麼要設一個r? 因為最後q會==NULL 要用r才能設下一個節點p  那為何while條件不設q->next!=NULL; ? 因為這個不是linked list 這個有分left跟right而不是next
                q=q->left_c;
            }
            else if(p->data > q->data)
            {
                direction=0;
                r=q;
                q=q->right_c;
            }
            else		//如果p的值已經存在於二元樹中 直接return一開始的t回去
                return(t);
        }
        //direction的意義在此 有這個最後r才知道要指向左邊還右邊
        if (direction==1)
            r->left_c=p;
        else
            r->right_c=p;
    }
    return(t);
}

TNode  *BstSearch(TNode  *t,int key)
{
    while(t != NULL)
    {
        if(key == t->data)
            return(t);
        else if(key < t->data)
            t=t->left_c;
        else
            t=t->right_c;
    }
    return(NULL);
}

TNode  *BstDelete(TNode  *t,int key) //t指向樹根  key是要刪除節點的鍵值 (用來搜尋比對的值)
{
    int found=0,direction=0;
    TNode  *r,*q,*s,*p;

    r=q=s=NULL;
    p=t;

    while(p!=NULL && !found)  //只要p=NULL or found=1  就脫離迴圈
    {
        if(key == p->data)
            found=1;
        else if(key < p->data)
        {
            direction=1;
            r=p;
            p=p->left_c;
        }
        else
        {
            direction=0;
            r=p;
            p=p->right_c;
        }
    }
    /////p找到目標 迴圈結束/////

    /////以下開始判斷p處在什麼狀況 個別處置/////
    if(p == NULL)  //找到底了都沒找到刪除目標
    {
        printf("=錯誤:找不到資料=\n");
        return t;
    }

    if( p==t )   //刪除目標就是樹根
    {
        if(p->right_c == NULL)
                return p->left_c;

        else if(p->left_c == NULL)
                return p->right_c;
    }

    if(p->right_c == NULL)        //刪除目標沒有右子樹
    {
        if(direction == 1)
            r->left_c=p->left_c;
        else
            r->right_c=p->left_c;
    }
    else if(p->left_c == NULL)    //刪除目標沒有左子樹
    {
        if(direction == 1)
            r->left_c=p->right_c;
        else
            r->right_c=p->right_c;
    }

    else    //刪除目標有兩個子節點
    {
        //首先要先找到中序立即前行者(inorder immediate successor)
        //方法就是目標節點p 先往左走一步(左子節點)
        //再往右走到不能再右 那個點就是p的inorder immediate successor
        s=p;
        q=p->left_c;              //先往左走一步
        while(q->right_c != NULL) //再往右走到底
        {
            s=q;                  //q的父節點就是s
            q=q->right_c;         //往右走
        }
        p->data=q->data;          //找到中序立即前行者q  用它來取代p的資料


        if(p == s)   //這個情況是q才往左走一步 就不能往右了 此時直接跳過這個節點直接指向其左節點
            s->left_c=q->left_c;
        else         //其餘的情況 左走一步再右走到底
            s->right_c=q->left_c;
    }

    printf("刪除成功!\n");
    return(t);
}

int main(int argc, char *argv[])
{
    TNode  *p;
    int choose,data,LoopFlag=1;

    //listA=BstCreate();  //開啟檔案讀裡面的資料 再利用BstInsert來建立二元樹

    while(LoopFlag)
    {
        printf("BST中序: ");
        InOrder(listA);
        printf("\n(1)插入資料\n(2)搜尋資料\n(3)刪除資料\n(0)結束=>");
        scanf("%d",&choose);

        switch(choose)
        {
            case 0:
				LoopFlag=0;
                break;                        /*結束程式*/
            case 1:
                printf("請輸入欲建立之資料=>");
                scanf("%d",&data);
                p=(TNode *)malloc(sizeof(TNode));
                p->data=data;
                listA=BstInsert(listA,p);
                break;
            case 2:
                printf("請輸入欲搜尋之資料=>");
                scanf("%d",&data);
                if(BstSearch(listA,data) == NULL)
                    printf("找不到資料\n");
                else
                    printf("找到!!!\n");
                break;
            case 3:

                printf("請輸入欲刪除之資料=>");
                scanf("%d",&data);
                listA=BstDelete(listA,data);

                break;
            default:
                printf("選項錯誤\n");
        }
        puts("");
     }
     //system("PAUSE");
	return 0;
}

