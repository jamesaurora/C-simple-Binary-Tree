#include <iostream>
using namespace std;

//KELOMPOK 1 STUKTUR DATA DAN ALGORITMA KELAS RPL 2C
//Muhammad Akbar Permanaatmaja			(2204074) 
//Kezia Helena Patricia Naibaho			(2209498) 
//Alfia April Riani						(2209367) 
//Dhowy Anja Alhusna					(2210013) 

struct Node {
	int nilai;
	Node *left, *right, *parent;
};

//variabel pointer global
Node *root, *newNode;

void masukTree(int nilai){
	if (root != NULL){
		cout << "Tree sudah dibuat" << endl;
		
	} else {
		root = new Node();
		root->nilai = nilai;
		root->left = NULL;
		root->right = NULL;
		root->parent = NULL;
		cout << "\n" << nilai <<" berhasil dibuat menjadi root" << endl;
	}
}

//insert left
Node *insertLeft(int nilai, Node *node){
		newNode = new Node();
		newNode->nilai = nilai;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->parent = node;
		node->left = newNode;
		cout << "\n" << nilai <<" berhasil menjadi anak kiri " <<
		newNode->parent->nilai << endl;
		return newNode;
}

//insert right
Node *insertRight(int nilai, Node *node){
		newNode = new Node();
		newNode->nilai = nilai;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->parent = node;
		node->right = newNode;
		cout << "\n" << nilai <<" berhasil menjadi anak kanan " <<
		newNode->parent->nilai << endl;
		return newNode;
}

////empty
//bool empty(){
//	if (root == NULL)
//		return true;
//	else
//		return false;
//}
//
//
//
////update
//void update(int nilai, Node *node){
//	if(root == NULL){
//		cout << "\nBuat Tree terlebih dahulu!" << endl;
//	} else {
//		if(!node){
//			cout << "\nNode yang ingin diganti tidak ada!!" << endl;
//		} else {
//			int temp = node->nilai;
//			node->nilai =nilai;
//			cout << "Label Node " << temp << " Berhasil diubah menjadi " << nilai << endl;	
//		}
//	}
//
//}

//find
void find (Node *node){
	if(root == NULL){
		cout << "\nBuat Tree terlebih dahulu!" << endl;
	} else {
		if (!node){
			cout << "\n Node yang ditunjuk tidak ada!!" <<endl;
		} else {
			cout << "nilai Node : " << node->nilai << endl;
			cout << "root Node : " << root->nilai << endl;
			
			if (!node->parent )
				cout << "Parent Node : tidak punya orangtua" << endl;
			else 
				cout << "Parent Node : " << node->parent->nilai << endl;
				
			if (!node->left )
				cout << "Anak kiri Node : tidak punya anak kiri" << endl;
			else 
				cout << "Anak kiri Node : " << node->left->nilai << endl;
				
			if (!node->right )
				cout << "Anak kanan Node : tidak punya anak kanan" << endl;
			else 
				cout << "Anak kanan Node : " << node->right->nilai << endl;
			
		}
				
	}
}
//preorder artinya dari root, kiri, kanan
void preorder(Node *node = root){
	if(node!=NULL){
		cout << node->nilai << ", ";
		preorder(node->left);
		preorder(node->right);

	}

}

//inorder artinya dari kiri, root, kanan
void inorder(Node *node = root){
	if(node!=NULL){
		inorder(node->left);		
		cout << node->nilai << ", ";
		inorder(node->right);

	}

}

//postorder artinya dari kiri, kanan, root
void postorder(Node *node = root){
	if(node!=NULL){
		inorder(node->left);		
		inorder(node->right);		
		cout << node->nilai << ", ";
	}

}


int main(){
	masukTree(42);
	Node *nodeB,*nodeC,*nodeD,*nodeE,*nodeF,*nodeG,*nodeH,*nodeI,*nodeJ;
	nodeB = insertLeft(68,root);
	nodeC = insertRight(35,root);
	nodeD = insertLeft(1,nodeB);
	nodeE = insertRight(70, nodeB);
	nodeF = insertRight(25, nodeC);
	nodeG = insertLeft(79,nodeE);
	nodeH = insertLeft(59,nodeE);
	nodeI = insertLeft(63, nodeG);
	nodeJ = insertRight(65,nodeG);
	
	cout << "Fitur Find : "; 
	find(nodeC) ;
	
	cout << "\nTraversal Preordernya : " ;
	preorder(); 
	cout << "\nTraversal Inordernya : " ;
	inorder() ;
	cout << "\nTraversal Postordernya : " ;
	postorder();
	
	
}
