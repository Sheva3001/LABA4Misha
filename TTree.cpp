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
	ifstream file("file.txt"); // Открываем файл
	if (!file)
		return 0;
	string tmp;
	file >> tmp; 
	createNewNode(root, tmp); // Заносим первое значение из файла в корень
	Node* pNode = root; // Указатель на корень
	for (string current; file >> current;) { // Пока значения из файла считываются в переменную current
		if (current <= pNode->data) { // Просто раскидываем по веткам значения
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
		if (symb[0] == str[i]) // Если один из символов строки str равен symb, то функция возвращает true
			return 1;
	}
	
}
void TTree::twoString(string& red, string str) { // red - строка из кот будут удаляться символы 
	string symb;
	for (int i = 0; i < red.length(); ) { // Проходимся по red
		symb = red[i];
		if (!stringCheck(symb, str)) { // Если символа из строки red нет в str, то удаляем его
			red.erase(i, 1); // Удаление
		}
		else // Иначе переходим к след. символу
			i++;
	}
}

void TTree::searchTree() { 
	string red = root->data; // В red передаём строку из корня
	strTree(red, root); // Вызываем strTree
	cout << endl << red; // Выводим резульатат
}

void TTree::strTree(string& red, Node* T) {
	twoString(red, T->data); 
	if ((T->left != 0) && (red.length() != 0)) // Если строка red не пустая и левая ветка не пустая, то вызываем эту функию для левого узла
		strTree(red,T->left);
	if ((T->right != 0) && (red.length() != 0)) // То же самое и для правого
		strTree(red, T->right);
	else
		return;
}