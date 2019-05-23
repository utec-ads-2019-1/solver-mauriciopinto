//
// Created by Malena on 5/14/2019.
//

#ifndef SOLVER_SOLVER_H
#define SOLVER_SOLVER_H
#include<iostream>
#include"nodes/node.h"
#include<stdlib.h>
class solver{
public:
    node* root;
    string equation;

    solver(string equation) : root(nullptr), equation(equation){
        if(!isFixed(equation)) {
            equation = fixOperators(equation);
        }
        cout << equation << endl;
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
        return found;
    }

    void create(char data, string equation) {
        bool found = false;
        int i = equation.size()-1;
        while (i >= 0) {
            if (equation[i] == data) {
                found = true;
                break;
            } else {
                i--;
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
        }
        else{
            return;
        }
    }
    string fixOperators(string equation) {
        string newEquation;
        int i = 0;
        while(equation[i] != '+' && equation[i] != '-'){
            newEquation.push_back(equation[i]);
            i++;
        }
        newEquation.push_back(equation[i]);
        int j = i + 1;
        while(equation[j] == '+' || equation[j] == '-'){
            if(newEquation[i] == '+'){
                if(equation[j] == '+'){
                    newEquation[i] = '+';
                }
                else{
                    newEquation[i] = '-';
                }
            }
            else{
                if(equation[j] == '+'){
                    newEquation[i] = '-';
                }
                else{
                    newEquation[i] = '+';
                }
            }
            j++;
        }
        string newEquation2;
        for(j; j < equation.size(); j++) {
            newEquation2.push_back(equation[j]);
        }
        if(!isFixed(newEquation2)){
            newEquation2 = fixOperators(newEquation2);
        }
        newEquation += newEquation2;
        return newEquation;
    }

    bool isFixed(string equation){
        for(int i = 0; i < equation.size() -1; i++){
            if(equation[i] == '+' || equation[i] == '-'){
                if(equation[i+1] == '+' || equation[i+1] == '-') {
                    return false;
                }
                else{
                }
            }
        }
    }
    double solve(){
            return root->operate();
        }
};
#endif //SOLVER_SOLVER_H
