//
// Created by Malena on 5/14/2019.
//

#ifndef SOLVER_SOLVER_H
#define SOLVER_SOLVER_H
#include<iostream>
#include"nodes/node.h"
class solver{
public:
    node* root;
    string equation;

    solver(string equation) : root(nullptr), equation(equation){
        if(find('+', equation)){
            create('+', equation);
            return;
        }
        else if(find('-', equation)){
           create('-', equation);
           return;
        }
        else if(find('*', equation)){
           create('*', equation);
           return;
        }
        else if(find('/', equation)){
           create('/', equation);
           return;
        }
        else if(find('^', equation)){
           create('^', equation);
           return;
        }
        else{
           node* number1 = new node(equation);
           root = number1;
        }
    };
    bool find(char data, string equation){
        bool found = false;
        int i = 0;
        while (i < equation.size()) {
            if (equation[i] == data) {
                found = true;
                break;
            } else {
                i++;
            }
        }
        cout << " " << data << " found in " <<  equation << " " << found << endl;
        return found;
    }
    void create(char data, string equation) {
        cout << "creating solver for" << data << endl;
        bool found = false;
        bool created = false;
        int i = 0;
        while (i < equation.size()) {
            if (equation[i] == data) {
                found = true;
                break;
            } else {
                i++;
            }
        }
        if(found) {
            string section1, section2, s;
            int j = i - 1;
            int k = i + 1;

            s.push_back(equation[i]);
            node* op1 = new node(s);
            root = op1;
            for (int m = 0; m <= j; m++) {
                section1.push_back(equation[m]);
            }
            for (int n = k; n < equation.size(); n++) {
                section2.push_back(equation[n]);
            }
            op1->left = solver(section1).root;
            op1->right = solver(section2).root;
            created = true;
        }
        else{
            return;
        }
    }
    double solve(){
            return root->operate();
        }
};
#endif //SOLVER_SOLVER_H
