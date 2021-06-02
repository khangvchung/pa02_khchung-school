#ifndef MOVIES_H
#define MOVIES_H
#include <string>
#include <iostream>
using namespace std;

class MoviesTree {

private:
    struct Node {
        double movieRating;
        string movieTitle;
        Node *left, *right, *parent;
        Node(string t ="", double r=0) : movieTitle(t), movieRating(r), left(0), right(0), parent(0){}
    };

    Node *root;


    void initTree() {root = nullptr;}
    void deleteTree(Node* &t);
    void addNode(string title, double rating, Node *n);
    void printPreOrder(Node* t, int depth);
    void maxPrefix(Node *r, string &title, double &rating, string pref);

public:
    MoviesTree();
    ~MoviesTree();

    bool isEmpty() {return (root == nullptr);}
    void addNode(string title, double rating);
    void printPreOrder();

    void maxPrefix(string pref);

};
#endif