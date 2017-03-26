//
//  main.cpp
//  ComplexListNodeClone
//
//  Created by 修海锟 on 2017/3/12.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
#include <ext/hash_map>
using namespace std;

struct ComplexListNode {
    int m_nValue;
    ComplexListNode* m_pNext;
    ComplexListNode* m_pSibling;
};

struct hash_A {
    size_t operator() (const struct ComplexListNode & A) const {
        return A.m_nValue;
    }
};

struct equal_A {
    bool operator() (const struct ComplexListNode & a1, const struct ComplexListNode & a2) const {
        return a1.m_nValue == a2.m_nValue && a1.m_pNext == a2.m_pNext && a1.m_pSibling == a2.m_pSibling;
    }
};

int main(int argc, const char * argv[]) {
    __gnu_cxx::hash_map<ComplexListNode, ComplexListNode, hash_A, equal_A> hash;
    
    
    return 0;
}
