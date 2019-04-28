#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct TreeNode
{
	int key;
	struct TreeNode* LChild;
	struct TreeNode* RChild;
}node;

int count;
node* treeSearch(node* root, int key);
node* treeInsert(node* root, int key);
node* minNode(node* root);
node* treeDelete(node* root, int key);
void print_preorder(node* root);
void print_inorder(node* root);
void print_postorder(node* root);


node* root = NULL;  // root of the tree

node* treeSearch(node* root, int key)
{
	if(root==NULL || root->key==key)
		return root;
		
	if(root->key > key)
	 	return treeSearch(root->LChild, key);
    else
        return treeSearch(root->RChild, key);
}

node* treeInsert(node* root, int key)
{
	if(root==NULL)
	{
		root = (node*)malloc(sizeof(node));
		root->key = key;
		root->LChild = NULL;
		root->RChild = NULL;  // root : new node
		count++;
		return root;
	}
	if(root->key > key)
	{
		root->LChild = treeInsert(root->LChild, key);
		count++;
	} else
		{
			root->RChild = treeInsert(root->RChild, key);
			count++;	
		}
	return root;
}

node* minNode(node* root)
{
    node* temp = root;
    while(temp->LChild != NULL)
        temp = temp->LChild;
    return temp;
}

node* treeDelete(node* root, int key)
{
	node* tNode = NULL;
    if(root == tNode)  //child = 0
        return NULL;
	
	// child = 1
    if(root->key > key)
       root->LChild = treeDelete(root->LChild, key);
    else if(root->key < key)
        root->RChild = treeDelete(root->RChild, key);
    else  // child = 2
    {	
        if(root->RChild != NULL && root->LChild != NULL)
        {
            tNode = minNode(root->RChild);
            root->key = tNode->key;
            root->RChild = treeDelete(root->RChild, tNode->key);
        }
        else
        {
            tNode = (root->LChild == NULL) ? root->RChild : root->LChild;
            free(root);
            return tNode;
        }
    }
    return root;
}

void print_preorder(node* root) 
{
	if(root== NULL)
		return;
		
	cout<<root->key<<" ";
	print_preorder(root->LChild);
	print_preorder(root->RChild);

}

void print_inorder(node* root) 
{
	if(root==NULL)
		return;

	print_inorder(root->LChild);
	cout<<root->key<<" ";
	print_inorder(root->RChild);

} 

void print_postorder(node* root)
{
	if(root==NULL)
		return;

	print_postorder(root->LChild);
	print_postorder(root->RChild);
	cout<<root->key<<" ";
}

int main()
{
	int size, k, p, x;
   	cin>>size;
    for(int i=0; i<size; i++)
   	{
      	int n;
      	cin>>n;
      	root = treeInsert(root, n);
    }
    cin>>k; // number of elemnents to delete
    cin>>p>>x;
    cin>>p>>x;
    cin>>p>>x;
    for(int i=0; i<k; i++)
    {
    	root = treeDelete(root, x);
    	if(p==0) print_preorder(root);
    	else if(p==1) print_inorder(root);
    	else if(p==2) print_postorder(root);
	}
/*
    cin>>p;  //types of operations to be traversed
    cin>>x; //element to delete
    root = treeDelete(root, x);
    if(p==0) print_preorder(root);
    else if(p==1) print_inorder(root);
    else if(p==2) print_postorder(root);
*/
	return 0;    
}
