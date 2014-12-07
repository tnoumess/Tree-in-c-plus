#include <iostream>
#include <stdexcept>
#include<assert.h>
using namespace std;

template<class T>
class Node{
public:
    template<class> friend class tree;
    Node(){data=NULL; left=NULL; right=NULL;} //backup constructor
    Node(const T& x){data=x; left=NULL; right=NULL;}
   ~Node(){delete this->left; delete this->right;};
private:
    T data;
    Node<T>* left;
    Node<T>* right;

};
template<class T>
class tree{
    public:
    Node<T>* root;
    Node<T>* &sroot=root;

    tree();
   //virtual ~tree();
   void insertdata(const T& x,Node<T>*  &p);// done
   void inserttree(const T& x);//done
   bool finddata(const T& x);//done
   void pre_printtree();//done
   void inorder( Node<T>* const &p);//done
   void postorder( Node<T>* const &p);//done
   void in_printtree();//done
   void post_printtree();//done
   bool isempty();//done
   long int numberOfelmt();//done
   void preorder(Node<T>* const &p);//done
   void inorder(const Node<T>*& p);//done
   void postorder(const Node<T>*& p);//done
   bool finddataz(const T& x, Node<T>* &p);//done
   long int getheight(Node<T>* n);//done
   int remove_node(const T& x);
   void deleteposttree( Node<T>* n);
   void deletetree();
   Node<T>* getnode();
   long int depthnode(const T& x);//done
   long int finddataz2(const T& x, Node<T>* &p,int c);// depthnode's component
   Node<T>* &find_pos_node(const T& x,Node<T>* n);
   private:
   long counter=0;
};
template<class T>
Node<T>*& tree<T>:: find_pos_node(const T& x,Node<T>* n){
//cout<<n->right->data; //if (n->right->data==x) return n;
  // if((n->left->data==x)||(n->right->data==x)) return n;

   if((n->right==NULL||n->right!=NULL) && n->left->data==x)  return n;
   if((n->left==NULL||n->left!=NULL) &&  n->right->data==x) return n;

    if (n->data>x) return find_pos_node(x,n->left);
    if (n->data<x) return find_pos_node(x,n->right);

}
template<class T>
int tree<T>::remove_node(const T& x){
    if (!finddata(x)) return -1;
    //if root
    if((root->data==x)&&((root->right==NULL)&&(root->left==NULL))) { Node<T>* &n2=root;

        delete n2; root=NULL; return 1;}

    // very root with kids

  /*  if((root->data==x)&&((root->right!=NULL)&&(root->left!=NULL))){  Node<T>* &n2=root;

    Node<T>* &n3=root->right;// doesn't change
    Node<T>* &n4=n->right->right;
   if(n4->left==NULL){}else{
    while(n4->left->left!=NULL)
    {
        n4=n->left;
    }}
    if(n2->left==NULL){}else{
    while(n2->left!=NULL){
        n2=n2->left;
    }}

    n2->left=n->right->left;
    n2->right=n->right->right;
    n->right=n2;
    n4->right=NULL;
    delete &n3;
       return 9;

    }*/

    Node<T>* &n=find_pos_node(x,root);//shouldn't move

    //if  child(left of root)  who has to disappear has no kids   "finished"
 if((n->left!=NULL)&&(n->left->data==x)&&(n->left->left==NULL)&&(n->left->right==NULL)){    Node<T>* &n2=n->left;
        n->left=NULL;
        delete n2; // without '&' 'cause pointing to null(left and right) at deletion
        return 2;
 }

    //if  child(right of root) who has to disappear has no kids   "finished"
  if ((n->right!=NULL)&&(n->right->data==x)&&(n->right->left==NULL)&&(n->right->right==NULL)){   Node<T>* &n2=n->right;
        n->right=NULL;
        delete n2; // without '&' 'cause pointing to null(left and right) at deletion
        return 3;
    }
    // if  child(left of root) who has to disappear has only one kid(left) "finished"
    if((n->left->data==x)&&((n->left->left!=NULL)&&(n->left->right==NULL))){ Node<T>* &n2=n->left;
         n->left=n->left->left;
        delete &n2; // with '&' 'cause pointing to something !null(left) at deletion
        return 4;
    }
     // if  child(left of root) who has to disappear has only one kid(right) "finished"
    if((n->left->data==x)&&((n->left->right!=NULL)&&(n->left->left==NULL))){ Node<T>* &n2=n->left;
        n->left=n->left->right;
        delete &n2; // with '&' 'cause pointing to something !null(right) at deletion
        return 5;
    }

    // if  child(right of root) who has to disappear has only one kid(left)   "finished"
    if((n->right->data==x)&&((n->right->left!=NULL)&&(n->right->right==NULL))){ Node<T>* &n2=n->right;
         n->right=n->right->left;
         delete &n2; // with '&' 'cause pointing to something !null(left) at deletion
        return 6;
    }
     // if  child(right of root) who has to disappear has only one kid(right)    "finished"
    if((n->right->data==x)&&((n->right->right!=NULL)&&(n->right->left==NULL))){ Node<T>* &n2=n->right;
        n->right=n->right->right;
        delete &n2; // with '&' 'cause pointing to something !null(right) at deletion
        return 7;
    }


     //to the left of n with more than one kid
    if((n->left->data==x)&&((n->left->left!=NULL)&&(n->left->right!=NULL))){ Node<T>* n2=n->left->right;
    Node<T>* &n3=n->left;// doesn't change
    Node<T>* &n4=n->left->right;

    if(n4->left==NULL){}else{
    while(n4->left->left!=NULL)
    {
        n4=n->left;
    }}

    if(n2->left==NULL){}else{
    while(n2->left!=NULL){
        n2=n2->left;
    }}


    n2->left=n->left->left;

    if(n2->right==NULL){
    n2->right=n->left->right;
    n4->left=NULL;
    }else{  Node<T>* r=n2->right;
    n2->right=n->left->right;
    n4->left=r;

    }
    n->left=n2;


    delete &n3;
       return 8;
    }

    //to the right of n with more than one kid
     if((n->right->data==x)&&((n->right->left!=NULL)&&(n->right->right!=NULL))){ Node<T>* n2=n->right->right;
    Node<T>* &n3=n->right;// doesn't change
    Node<T>* &n4=n->right->right;
   if(n4->left==NULL){}else{
    while(n4->left->left!=NULL)
    {
        n4=n->left;
    }}
    if(n2->left==NULL){}else{
    while(n2->left!=NULL){
        n2=n2->left;
    }}

    n2->left=n->right->left;
    if(n2->right==NULL){
    n2->right=n->right->right;
    n4->left=NULL;
    }else{Node<T>* r=n2->right;
    n2->right=n->right->right;
    n4->left=r;

    }
    n->right=n2;

    delete &n3;
       return 9;
    }

}
template<class T>
long int tree<T>::getheight(Node<T>* n){
if (!n) return -1;
  int left_height = getheight(n->left);
  int right_height = getheight(n->right);
  return (left_height > right_height) ? left_height + 1 : right_height + 1;

}

template <class T>
Node<T>* tree<T>::getnode(){
return root;
}



template<class T>
bool tree<T>::isempty(){
if (root!=NULL) {cout<< std::boolalpha; return false;}
else {cout<<std::boolalpha; return true;}
}
template<class T>
long int tree<T>::numberOfelmt(){
return counter;
}

template<class T>
tree<T>::tree(){root=NULL; }
template<class T>
void tree<T>::inserttree(const T& x){
insertdata(x,root);
}

template<class T>
void tree<T>::insertdata(const T& x,Node<T>*  &p){

if (p==NULL){ p=new Node<T>(x); counter++;}
if (p->data>x){  insertdata(x,p->left);}
if (p->data<x){  insertdata(x,p->right);}
}

template<class T>
void tree<T>::pre_printtree(){
    if (root==NULL)
        cout<<" the tree is empty"<<endl;
    else{
       // Node<T>* sroot=root;
        preorder(root);

        }
    }
template<class T>
void tree<T>::preorder( Node<T>* const &p){
    if(p==NULL) cout<<"";
    else{
        cout<<p->data; cout<<"--";
        preorder(p->left);
        preorder(p->right);
    }

}
template<class T>
void tree<T>::post_printtree(){
    if (root==NULL)
        cout<<" the tree is empty"<<endl;
    else{
       // Node<T>* sroot=root;
        postorder(root);

        }
    }
template<class T>
void tree<T>::postorder( Node<T>* const &p){
    if(p==NULL) cout<<"";
    else{

        postorder(p->left);
        postorder(p->right);
        cout<<p->data; cout<<"--";
    }

}
template<class T>
void tree<T>::in_printtree(){
    if (root==NULL)
        cout<<" the tree is empty"<<endl;
    else{
       // Node<T>* sroot=root;
        inorder(root);

        }
    }
template<class T>
void tree<T>::inorder( Node<T>* const &p){
    if(p==NULL) cout<<"";
    else{
        inorder(p->left);
        cout<<p->data; cout<<"--";
        inorder(p->right);
    }

}

template<class T>
bool tree<T>::finddata(const T& x){

  cout<< std::boolalpha; return finddataz(x,root);

}
 template<class T>
bool tree<T>::finddataz(const T& x, Node<T>* &p){

    if ((p==NULL)||((p->data!=x)&&((p->left==NULL)&&(p->right==NULL))))  return false;
    if (p->data==x) return true;
    if (p->data>x) return finddataz(x,p->left);
    if (p->data<x) return finddataz(x,p->right);
}
//find 2
template<class T>
long int tree<T>::depthnode(const T& x){
int c=-1;
if(x==root->data) return 0;
  cout<< std::boolalpha; return finddataz2(x,root,c);

}
 template<class T>
long int tree<T>::finddataz2(const T& x, Node<T>* &p,int c){

    if ((p==NULL)||((p->data!=x)&&((p->left==NULL)&&(p->right==NULL))))  return -1;
    if (p->data==x) return 1+c;
    if (p->data>x) {c++;return finddataz2(x,p->left,c);}
    if (p->data<x) { c++;return finddataz2(x,p->right,c);}
}
//end find 2
int main()
{ /*
    int s=1,pp=1;
    try { assert(s!=NULL);}
    catch(exception e){cout<<e.what();}*/
    tree<long int> t;
cout << "my tree" << endl;

//cout << std::boolalpha <<t.finddata(0)<< endl;

  /*  t.inserttree(4);
   t.inserttree(2);
   t.inserttree(8);
   t.inserttree(10);
    t.inserttree(7);
    t.inserttree(11);*/
/*
    t.inserttree(17);
    t.inserttree(4);
    t.inserttree(2);
    t.inserttree(6);
    t.inserttree(5);
    t.inserttree(8);
    t.inserttree(3);
    t.inserttree(1);
    t.inserttree(39);
    t.inserttree(20);
    t.inserttree(40);
    t.inserttree(21);
    t.inserttree(19); */

    t.inserttree(17);
    t.inserttree(39);
    t.inserttree(4);
    t.inserttree(2);
    t.inserttree(7);
    t.inserttree(10);
    t.inserttree(5);
    t.inserttree(6);
    t.inserttree(8);
    t.inserttree(13);
    t.inserttree(9);
  /*  t.inserttree(2);
    t.inserttree(6);
    t.inserttree(7);
    t.inserttree(5);
    t.inserttree(1);
    t.inserttree(9);*/

 t.in_printtree();
   // cout<<"\ndeleted?:";
tree<long int> pt=t;
t.remove_node(13);
cout<<"\n after removing the node 13\n";
t.in_printtree();
}
