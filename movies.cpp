#include "movies.h"
#include <string>
#include <iostream>
using std::cout;

MoviesTree::MoviesTree(){
    initTree();
}
MoviesTree::~MoviesTree(){
    deleteTree(root);
}

void MoviesTree::deleteTree(Node *&t) {
    if(t != nullptr){
        deleteTree(t->left);
        deleteTree(t->right);

        delete t;
        t = nullptr;
    }
}

void MoviesTree::addNode(string title, double rating) {
    if(!root) {
        root = new Node(title, rating);

    }
    addNode(title, rating, root);
}

void MoviesTree::addNode(string title, double rating, Node *n){
    if(title == n->movieTitle){
        return;
    }
    if(title < n->movieTitle) {
        if(n->left) {
            addNode(title, rating, n->left);
        }
        else{
            n->left = new Node(title, rating);
            n->left->parent = n;
        }
    }
    else {
        if(n->right) {
            addNode(title, rating, n->right);
        }
        else{
            n->right = new Node(title, rating);
            n->right->parent = n;
        }
    }
}


void MoviesTree::printPreOrder(Node *t, int depth) {
    if(t != NULL) {
        cout << t->movieTitle << ", " << t->movieRating << ", " <<depth <<endl;
        printPreOrder(t->left, depth+1);
        printPreOrder(t->right, depth+1);
    }
}

void MoviesTree::printPreOrder(){
    printPreOrder(root, 0);
}

void MoviesTree::maxPrefix(string pref){
    string title = "";
    double rating = -1;
    maxPrefix(root, title, rating, pref);
    if(title != ""){
        cout <<"Best movie is " << title << " with rating " << rating << endl;
    }
}

void MoviesTree::maxPrefix(Node* r, string &title, double &rating, string pref){
    if(r != NULL) {
        if(r->movieTitle.substr(0, pref.length()) == pref){
            if(title == "") {
                title = r->movieTitle;
                rating = r->movieRating;
            }
            else{
                if(rating < r->movieRating) {
                    rating = r->movieRating;
                    title = r->movieTitle;
                }
            }
        }
        maxPrefix(r->left, title, rating, pref);
        maxPrefix(r->right, title, rating, pref);
    }
}
