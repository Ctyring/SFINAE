//
// Created by cty on 2023/1/22.
//
#include "hasSerialize.h"
#include <iostream>
int main() {
    // 检测结构体是否有serialize方法
    // Using the struct A, B, C defined in the previous hasSerialize example.
    std::cout << hasSerialize<A>::value << std::endl;
    std::cout << hasSerialize<B>::value << std::endl;
    std::cout << hasSerialize<C>::value << std::endl;
}
