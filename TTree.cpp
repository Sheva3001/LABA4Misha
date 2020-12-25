#include "TTree.h"

using namespace std;

TTree::TTree() {
	root = NULL;
}
TTree::TTree(int elem) {
	root = new Node;
	root->data = elem;
	root->left = NULL;
	root->right = NULL;
}
TTree::TTree(int elem, TTree& leftTree, TTree& rightTree) {
	root = new Node;
	root->data = elem;
	attachLeftSubTree(leftTree);
	attachRightSubTree(rightTree);
}
TTree::~TTree() {
	destroyTree(root);
}
bool TTree::isEmpty() {
	return root == NULL;
}
void TTree::destroyTree(Node* root) {
	if (root != 0) {
		destroyTree(root->left);
		destroyTree(root->right);
		delete root;
	}
}
void TTree::copyTree(Node* root, Node*& newRoot) {
	if (root != 0) {
		newRoot = new Node;
		newRoot->data = root->data;
		newRoot->left = 0;
		newRoot->right = 0;
		copyTree(root->left, newRoot->left);
		copyTree(root->right, newRoot->right);
	}
}
void TTree::attachLeftSubTree(TTree& subTree) {
	if (!isEmpty() && root->left == NULL) {
		Node* tmp = NULL;
		copyTree(subTree.root, tmp);
		root->left = tmp;
	}
}
void TTree::attachRightSubTree(TTree& subTree) {
	if (!isEmpty() && root->right == NULL) {
		Node* tmp = NULL;
		copyTree(subTree.root, tmp);
		root->right = tmp;
	}
}
bool TTree::fromFileToThree() {
	ifstream file("file.txt"); // ��������� ����
	if (!file)
		return 0;
	string tmp;
	file >> tmp; 
	createNewNode(root, tmp); // ������� ������ �������� �� ����� � ������
	Node* pNode = root; // ��������� �� ������
	for (string current; file >> current;) { // ���� �������� �� ����� ����������� � ���������� current
		if (current <= pNode->data) { // ������ ����������� �� ������ ��������
			createNewNode(pNode->left, current);
			pNode = pNode->left;
		}
		else {
			createNewNode(pNode->right, current);
			pNode = pNode->right;
		}
	}
}
void TTree::createNewNode(Node*& T, string str) {
	Node* temp = new Node;
	temp->data = str;
	temp->left = 0;
	temp->right = 0;
	T = temp;
}
bool TTree::stringCheck(string symb, string str) {
	for (int i = 0; i < str.length(); i++) { 
		if (symb[0] == str[i]) // ���� ���� �� �������� ������ str ����� symb, �� ������� ���������� true
			return 1;
	}
	
}
void TTree::twoString(string& red, string str) { // red - ������ �� ��� ����� ��������� ������� 
	string symb;
	for (int i = 0; i < red.length(); ) { // ���������� �� red
		symb = red[i];
		if (!stringCheck(symb, str)) { // ���� ������� �� ������ red ��� � str, �� ������� ���
			red.erase(i, 1); // ��������
		}
		else // ����� ��������� � ����. �������
			i++;
	}
}

void TTree::searchTree() { 
	string red = root->data; // � red ������� ������ �� �����
	strTree(red, root); // �������� strTree
	cout << endl << red; // ������� ����������
}

void TTree::strTree(string& red, Node* T) {
	twoString(red, T->data); 
	if ((T->left != 0) && (red.length() != 0)) // ���� ������ red �� ������ � ����� ����� �� ������, �� �������� ��� ������ ��� ������ ����
		strTree(red,T->left);
	if ((T->right != 0) && (red.length() != 0)) // �� �� ����� � ��� �������
		strTree(red, T->right);
	else
		return;
}