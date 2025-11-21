
#ifndef TREE
#define TREE

#include "iostream"
#include "Node.h"
#include <fstream>


class Tree
{
	public:
	
		Tree();													// Default CTOR
		//..........................................
		//POST: new tree is created with a root
		
		
		Tree(string questionText, string leftObject, string rightObject);	// CTOR when root info is known
		//..........................................
		//POST: new tree is created with a root with text questionText, plus two children:
		//		right child has text of rightObject, and left child has text of leftObject


		
		~Tree();												// DTOR
		//..........................................
		//Calls DeleteAllTree
		//POST: entire tree is deleted/freed and all dynamic memory cleared



		void DeleteAllTree(Node *root);
		//..........................................
		// Post: Recursively goes through the tree deleting each node
		
		
		bool IsEmpty(void) const;
		//..........................................
		//POST: RETURN T/F whether or not the root node of the Tree has children


		Node* GetRoot(void) const;
		//..........................................
		//POST: RETURN == address of root node

	Tree& operator=(Tree& tree);
	//.............................................
	//POST: this->root = tree->root
	// this -> root.AppendLeft(tree->root->LChild)
	// this -> root.AppendRight(tree->root->RChild)


	void SaveTreeToFile(string outputFileName);
	void ReadTreeFromFile(string inputFileName);



	private:
		Node* root;    // pointer to root node of tree


		ofstream FOUT;
		ifstream FIN;


	void  RecursiveNodeSAVEtoFile(Node* root);
	Node* RecursiveNodeREADfromFile( );
};// class Tree

#endif

