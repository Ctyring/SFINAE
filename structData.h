//
// Created by cty on 2023/1/22.
//

#ifndef SFINAE_STRUCTDATA_H
#define SFINAE_STRUCTDATA_H

#include <string>
// 类型A只有to_string 方法
struct A {
};

std::string to_string(const A &) {
    return "I am A";
}

// 类型B有serialize方法
struct B {
    std::string serialize() const {
        return "I am B";
    }
};

// 类型C有个serialize数据成员与to_string方法
struct C {
    std::string serialize;
};

std::string to_string(const C &) {
    return "I am C";
}
#endif //SFINAE_STRUCTDATA_H
