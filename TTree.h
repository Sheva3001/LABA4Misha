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
	void createNewNode(Node*& T, string str); // ������ ����� ����
	bool fromFileToThree(); // ��������� �� ����� � ��������� ������
	bool stringCheck(string symb, string str); // ��������� ���� �� ������ � ������
	void twoString(string& red, string str); // ������� �� ������ ������ �������, ������� ��� �� ������
	void searchTree(); // �������� �������� �������������� ������ � ������� ���������
	void strTree(string& red, Node* T); // ����������� ������, ���������� �� ������ � �������� twoString()
};
