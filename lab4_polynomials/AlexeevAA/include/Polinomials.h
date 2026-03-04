#include "TList.h"


class Polinomial {
private:
    TList<int> terms;

public:
    Polinomial() {}

    void add_terms(int k, std::string s){
        if(k == 0) 
            return;
        int step = 0;
        for(TList<int>::iterator iter = terms.begin(); iter != terms.end();iter++){
            if(s == iter.i->exp){
                iter.i->data += k;
                    
                if(iter.i->data == 0){
                    terms.erase_after(step-1);
                }
                return;
            }
            step++;
        }
        terms.push_back(k, s);
    }
    Polinomial operator+(Polinomial& p) {
        Polinomial result;
        for(TList<int>::iterator iter = terms.begin();iter != terms.end();iter++){
            result.add_terms(iter.i->data, iter.i->exp);    
        }
        for(TList<int>::iterator iter = p.terms.begin();iter != p.terms.end();iter++){
            result.add_terms(iter.i->data, iter.i->exp);    
        }
        return result;
    }
    Polinomial operator-(Polinomial& p) {
        Polinomial result;
        for(TList<int>::iterator iter = terms.begin();iter != terms.end();iter++){
            result.add_terms(iter.i->data, iter.i->exp);    
        }
        for(TList<int>::iterator iter = p.terms.begin();iter != p.terms.end();iter++){
            result.add_terms(iter.i->data * (-1), iter.i->exp);    
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& out, Polinomial& p) {
        out << p.terms;
        return out;
    }
};