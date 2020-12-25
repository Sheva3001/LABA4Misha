#pragma once

#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

class TTree {
	struct Node {
		string data;
		Node* left;
		Node* right;
	};
	Node* root;
public:
	TTree();
	TTree(int elem);
	TTree(int elem, TTree& leftTree, TTree& rightTree);
	bool isEmpty();
	~TTree();
	void destroyTree(Node* root);
	void copyTree(Node* root, Node*& newRoot);
	void attachLeftSubTree(TTree& subTree);
	void attachRightSubTree(TTree& subTree);
	void createNewNode(Node*& T, string str); // Создаёт новый узел
	bool fromFileToThree(); // Считывает из файла и заполняет дерево
	bool stringCheck(string symb, string str); // Проверяет есть ли символ в строке
	void twoString(string& red, string str); // Удаляет из первой строки символы, которых нет во второй
	void searchTree(); // Вызывает функциию преобразования строки и выводит результат
	void strTree(string& red, Node* T); // Рекурсивная фунция, проходится по дереву и вызывает twoString()
};
