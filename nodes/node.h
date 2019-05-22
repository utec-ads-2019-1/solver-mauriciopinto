//
// Created by Malena on 5/14/2019.
//

#ifndef SOLVER_NODE_H
#define SOLVER_NODE_H
#include<string>
#include<cmath>
using namespace std;

class node{
public:
    string data;
    node* right;
    node* left;
public:
    node(string data) : right(nullptr), left(nullptr), data(data){
    };
    double operate(){
        double result = 0;
        if(data == "+"){
            result = left->operate() + right->operate();
        }
        else if(data == "-"){
            result = left->operate() - right->operate();
        }
        else if(data == "*"){
            result = left->operate() * right->operate();
        }
        else if(data == "/"){
            result = left->operate() / right->operate();
        }
        else if(data == "^"){
            result = pow(left->operate(), right->operate());
        }
        else{
            result = stof(data);
        }
        return result;
    }
};
#endif //SOLVER_NODE_H
