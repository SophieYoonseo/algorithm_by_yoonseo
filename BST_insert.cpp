#include <iostream>
#include <cstdlib>

using namespace std;

int count;

typedef struct TreeNode
{
	int key;
	struct TreeNode* LChild;
	struct TreeNode* RChild;
}node;

node* root = NULL;

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


int main()
{
	int size;
   	cin>>size;
    for(int i=0; i<size; i++)
   	{
      	int n;
      	cin>>n;
      	root=treeInsert(root, n);
    }
      	cout<<count<<endl;
}
