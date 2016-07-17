1.求二叉树的宽度
typedef struct node{
     char data;
     struct node *lchild,*rchild;
}TNODE;
int getTreeDepth(TNODE * proot)
{
     if(proot==NULL)return 0;
     int lwidth = getTreeDepth(proot->lchild)+1;
     int rwidth = getTreeDepth(proot->rchild)+1;
     return lwidth>rwidth?lwidth:rwidth;
}
int getTreeWidth(TNODE * proot)
{
     static int a[100]={0};
    static int i = 0;
    if(proot!=NULL){
         if(i==0)a[i]=1;
         i++;
         if(proot->rchild!=NULL)a[i]++;
         if(proot->lchild!=NULL)a[i]++;
         if(proot->rchild!=NULL){
              getTreeWidth(proot->rchild);
              i--;
         }
         if(proot->lchild!=NULL){
              getTreeWidth(proot->lchild);
              i--;
         }
    }
    int max=0;
    for(int k=0;k<100){
         if(a[k]==0)break;
         if(a[k]>max)max=a[k];
    }
    return a[k];
}
int getTreeWidth(TNODE * proot)
{
     static vector<int> a(3);
    static int i = 0;
    if(proot!=NULL){
         if(i==0)a[i]=1;
         i++;
         if(i>=a.size())a.emplace_back();
         if(proot->rchild!=NULL)a[i]++;
         if(proot->lchild!=NULL)a[i]++;
         if(proot->rchild!=NULL){
              getTreeWidth(proot->rchild);
              i--;
         }
         if(proot->lchild!=NULL){
              getTreeWidth(proot->lchild);
              i--;
         }
    }
    int max=0;
    for(int k=0;k<a.size();++k)
         if(a[k]>max)max=a[k];
    return a[k];
}


1.求二叉树的宽度
typedef struct node{
     char data;
     struct node *lchild,*rchild;
}TNODE;
//获取二叉树的深度
int getTreeDepth(TNODE * proot)
{
     if(proot==nullptr)return 0;
     return max(getTreeDepth(proot->lchild),getTreeDepth(proot->rchild))+1;
}
//获取二叉树的宽度
int getTreeWidth(TNODE * proot)
{
     static vector<int> a(10);
    static int i = 0;
    if(proot!=NULL){
         if(i==0)a[i]=1;
         i++;
         if(i>=a.size())a.emplace_back();
         if(proot->rchild!=NULL)a[i]++;
         if(proot->lchild!=NULL)a[i]++;
         if(proot->rchild!=NULL){
              getTreeWidth(proot->rchild);
              i--;
         }
         if(proot->lchild!=NULL){
              getTreeWidth(proot->lchild);
              i--;
         }
    }
    int max=0;
    for(int k=0;k<a.size();++k)
         if(a[k]>max)max=a[k];
    return a[k];
}
//获取二叉树的的最小深度
static int minDepth(const TNODE * root,bool hashbrother)
{
     if(!root)return hashbrother？INT_MAX:0;
     return 1+min(minDepth(root->left,root->right!=nullptr),minDepth(root->right,root->left!=nullptr));
}
//怎样从顶部开始逐层打印二叉树结点数据 
void printLevel(TNODE * tnode)
{
     queve<TNODE *> vtnode;
     vtnode.push_back(tnode);
     while(!vtnode.empty()){
          TNODE * tmp = vtnode.front();
          if(tmp->lchild!=NULL)vtnode.push_back(tmp->lchild);
          if(tmp->rchild!=NULL)vtnode.push_back(tmp->rchild);
          cout<<tmp->data<<endl;
          vtnode.pop_back();
     }
}
//如何判断一棵二叉树是否是平衡二叉树 
int isBalencedTree(TNODE *root)
{    
     if(root==nullptr)return 0;
     int depth1 = getTreeDepth(root->lchild);
     int depth2 = getTreeDepth(root->rchild);
     if(abs(depth1-depth2)<=1) return 1;
     else return 0;
     int flag1 = isBalencedTree(root->lchild);
     int flag2 = isBalencedTree(root->rchild);
     if(flag1&&flag2) return 1;
     else return 0;
}
//问题7：怎样编写一个程序，把一个有序整数数组放到二叉树中？
void createTreeFromArray(int a[],int begin,int end,TNODE **root)
{
     if(begin>end) return;
     else {
          *root = new TNODE;
          int mid = (begin+end)/2;
          (*root)->data = a[mid];
          (*root)->rchild = nullptr;
          (*root)->lchild = nullptr;
          createTreeFromArray(a,begin,mid-1,&((*root)->lchild);
          createTreeFromArray(a,mid+1,end,&((*root)->rchild));
     }
}
//问题9：求二叉树的镜像 
void changeMirror(TNODE * root)
{
     if(root == nullptr) return;
     else{
          TNODE * tmp = root->lchild;
          root->lchild = root->rchild;
          root->rchild = tmp;
          changeMirror(&(root->lchild));
          changeMirror(&(root->rchild));
     }
}
//问题12：打印二叉树中的所有路径（与题目5很相似） 
void printPathRecur(TNODE * node,char path[],int pathlen)
{
     if(node==nullptr) return ;
     path[pathlen++] = node->data;
     if(node->lchild==NULL&&node->rchild==NULL)
     {
          printArray(path,pathlen);
     }
     else {
          if(node->lchild!=nullptr)printPathRecur(node->lchild);
          if(node->rchild!=nullptr)printPathRecur(node->rchild);
     }
}
//问题10：10.一棵排序二叉树（即二叉搜索树BST），令 f=(最大值+最小值)/2，设计一个算 
int findNearMid(TNODE ** root)
{
     TNODE * ptr = *root;
     if(ptr!=nullptr){
          while(ptr->lchild) ptr= ptr->lchild;
          double mintree = ptr->data;
     }
     ptr = *root;
     if(ptr!=nullptr){
          while(ptr->rchild) ptr = ptr->rchild;
          double maxtree = ptr->data;
     }
     ptr = *root;
     double mid = (mintree+maxtree)/2.0;
     while(1){
          if(ptr->data<mid)ptr = ptr->rchild;
          else{
               if(ptr->data>mid)return ptr->data;
               else (ptr->rchild)->data;
          }
     }
}

////问题8：判断整数序列是不是二叉搜索树的后//序遍历结果 
int isPostTraverse(int a[],int begin,int end)
{
     if(begin>=end)return;
     else{
          int root = a[end];
          int lroot;
          int i,location = beigin;
          for(i = beign;i<end;++i){
               if(a[i]>root){
                    location = i;
                    lroot = a[i];
                    break;
               }
          }
          if(location != begin)
               for(i = location+1;i<end;++i)
                    if(a[i]<lroot)return 0;
          int flag1 = isPostTraverse(a,begin,location-1);
          int flag2 = isPostTraverse(a,location,end-1);
          if(flag1&&flag2) return 1;
          else return 0;
     }
}
//设计堆排序的代码
void buildMaxHeap(ElemType A[],int len)
{
     for(int i=len/2;i>0;--i)
          adjustDown(A,i,len);

}
void adjustDown(ElemType A[],int k, int len)
{
     A[0] = A[K];
     for(int i = 2*k;i<len;i*=2)
     {
          if(i<len&&A[i]<A[i+1])
               i++;
          if(A[0]>=A[i])break;
          else{
               A[k] = A[i];
               k = i;
          }
     }
     A[K] = A[0];
}
void adjustUp(ElemType A[],int k)
{
     A[0]=A[k];
     int i = K/2;
     while(i>0&&A[i]<A[0]){
               A[k] = A[i];
               k = i;
               i = i/2;
     }
}
void HeapSort(ElemType A[],int len)
{
     buildMaxHeap(A,len);
     for(i=len;i>1;--i){
          swap(A[i],A[1]);
          adjustDown(A,1,i-1);
     }
}

//求解两个已经排序数组的交集
vec<int> intersection(int A[],int B[])
{
     if(sizeof(A)==0||sizeof(B)==0)return null;
     vector<int> insect;
     int A_pos=0,B_pos=0;
     while(A_pos<sizeof(A)/4&&B_pos<sizeof(B)/4){
          if(A[A_pos]<B[B_pos])A_pos++;
          else if(A[A_pos]>B[B_pos])B_pos++;
          else{
               insect.push_back(A[A_pos]);
               A_pos++;
               B_pos++;
          }    
     }
}
//快速排序
void QuickSort(ElemType A[],int low,int high)
{
     if(low<high){
          int pivotpos = Partition(A,low,high);
          QuickSort(A,low,pivotpos-1);
          QuickSort(A,pivotpos+1,high);
     }
}
typedef ElemType int;
int Partition(ElemType A[],int low,int high)
{
     ElemType pivot = A[low];
     while(low<high){
          while(low<high&&A[high]>=pivot)high--;
          A[low] = A[high];
          while(low<high&&A[low]<=pivot)low++;
          A[high] = A[low];
     }
     A[low] = pivot;
     return low;
}
int BinarySearch(int A[],int begin,int end,int key)
{
     int mid = (begin+end)/2;
     if(begin<=end)
     {
          if(A[mid]==key)return mid;
          if(A[mid]>key)BinarySearch(A,beign,mid-1);
          if(A[mid]<key)BinarySearch(A,mid+1,end);
     }
     else return -1;
}
int BinarySearch(vector<int> &A,int key)
{
     int begin = 0,end = A.size();
     while(begin<=end)
     {
          mid = (begin+end)/2;
          if(A[mid]==key)return mid;
          else if(A[mid]>key)begin = mid+1;
          else end = mid -1;
     }
     return -1;
}

struct  list_node
{
     int data;
     list_node * next;
};
bool isloop(list_node *head)
{
     list_node * n1 = head;
     list_node * n2 = head;
     while(n2->next!=NULL){
          n1 = n1->next;
          n2 = n2->next->next;
          if(n1==n2) return true;
          if(n2==NULL)return false;
     }
     return false;
}
list_node * FindLoopBeg(list_node * head)
{
     list_node * n1 = head;
     list_node * n2 = head;
     while(n2->next!=NULL)
     {
          n1 = n1->next;
          n2 = n2->next->next;
          if(n1==n2) break;
          if(n2==NULL) return NULL;
     }
     if(n2->next==NULL)return NULL;
     n1 = head;
     while(n1!=n2)
     {
          n1 = n1->next;
          n2 = n2->next;
     }
}

//利用两个栈实现队列的功能
template <class T> class  MyQueue
{
     stack<T> s1,s2;
public:
     MyQueue(){};
     int size(){
          return s1.size()+s2.size();
     }
     bool empty(){
          if(size()==0) return True;
          else return false;
     }
     void push(T value){
          s1.push(value);
     }
     void pop(){
          if(s2.empty())
          {
               while(!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
          }
          s2.pop();
     }
     T front(){
               if(!s2.empty()) return s2.top();
               while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
               }
          }
          return s2.top();
     }
     ~ MyQueue();
};
struct node  
{
     node *pleft;
     node *pright;
    int nMaxLeft;
    int nMaxRight;
    char chValue;
};
int nmaxlen =0;
void FindMaxLen(node* proot)
{
     if(proot==NULL) return;
     if(proot->pleft==NULL) proot->nMaxLeft = 0;
     if(proot->pright==NULL) proot->nMaxRight = 0;
     if(proot->pleft!=NULL) FindMaxLen(proot->pleft);
     if(proot->pright!=NULL) FindMaxLen(proot->pright);
     if(proot->pleft!=NULL){
          int ntmpmax = 0;
          if(proot->pleft->nMaxLeft>proot->pright->nMaxRight)
               ntmpmax = proot->pleft->nMaxLeft;
          else ntmpmax = proot->pleft->nMaxRight;
          proot->nMaxLeft = ntmpmax+1;
     }
     if(proot->pright!=NULL){
          int ntmpmax = 0;
          if(proot->pright->nMaxLeft>proot->pright->nMaxRight)
               ntmpmax = proot->pright->nMaxLeft;
          else ntmpmax = proot->pright->nMaxRight;
          proot->nMaxRight = ntmpmax+1;
     }
     if(proot->nMaxLeft+proot->nMaxRight>nmaxlen)
               nmaxlen = proot->nMaxLeft+proot->nMaxRight;
}

先序遍历非递归算法
void PreOrderUnrec(Bitree *t)
{
    Stack s;
    StackInit(s);
    Bitree *p=t;
 
    while (p!=NULL || !StackEmpty(s))
    {
        while (p!=NULL)             //遍历左子树
        {
            visite(p->data);
            push(s,p);
            p=p->lchild;
        }
      
        if (!StackEmpty(s))         //通过下一次循环中的内嵌while实现右子树遍历
        {
            p=pop(s);
            p=p->rchild;      
        }//endif
             
    }//endwhile
}


2.中序遍历非递归算法
void InOrderUnrec(Bitree *t)
{
    Stack s;
    StackInit(s);
    Bitree *p=t;

    while (p!=NULL || !StackEmpty(s))
    {
        while (p!=NULL)             //遍历左子树
        {
            push(s,p);
            p=p->lchild;
        }
      
        if (!StackEmpty(s))
        {
            p=pop(s);
            visite(p->data);        //访问根结点
            p=p->rchild;            //通过下一次循环实现右子树遍历
        }//endif 
 
    }//endwhile
}

3.后序遍历非递归算法
typedef enum{L,R} tagtype;
typedef struct
{
    Bitree ptr;
    tagtype tag;
}stacknode;

typedef struct
{
    stacknode Elem[maxsize];
    int top;
}SqStack;

void PostOrderUnrec(Bitree t)
{
    SqStack s;
    stacknode x;
    StackInit(s);
    p=t;
 
    do
    {
        while (p!=null)        //遍历左子树
        {
            x.ptr = p;
            x.tag = L;         //标记为左子树
            push(s,x);
            p=p->lchild;
        }
 
        while (!StackEmpty(s) && s.Elem[s.top].tag==R)
        {
            x = pop(s);
            p = x.ptr;
            visite(p->data);   //tag为R，表示右子树访问完毕，故访问根结点    
        }
      
        if (!StackEmpty(s))
        {
            s.Elem[s.top].tag =R;     //遍历右子树
            p=s.Elem[s.top].ptr->rchild;      
        } 
    }while (!StackEmpty(s));
}//PostOrderUnrec
两个栈实现一个队列，写代码。
求二叉树的最大距离（即相距最远的两个叶子节点），写代码
打印二叉树两个叶子节点间的路径，写代码（汗，百度这么喜欢问二叉树）。
题目：一颗标准形式存储的二叉树，求他的宽度。
空的二叉树的宽度为0，非空二叉树的宽度为各层结点个数的最大值。
