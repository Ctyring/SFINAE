#include "structData.h"
template<class T>
struct hasSerialize {
    // 编译时比较
    typedef char yes[1];
    typedef char no[2];
    // 允许我们检查序列化确实是一种方法
    // 第二个参数必须是第一个参数的类型
    // 例如：reallyHas<int,10> 替换为 reallyHas<int,int 10> 并起作用
    // 注意：它仅适用于整数常量和指针(因此函数指针可以使用)
    // 例如：reallyHas<std::string (C::*)(), &C::serialize> 替换为
    // reallyHas<std::string (C::*)(), std::string (C::*)() &C::serialize> 并起作用
    template<typename U, U u>
    struct reallyHas;

    // std::string (C::*)() 是函数指针声明
    template<typename C>
    static yes &test(reallyHas<std::string (C::*)(), &C::serialize> * /*unused*/) {}

    //  std::string (C::*)()const 函数指针 -> std::string serialize() const
    template<typename C>
    static yes &test(reallyHas<std::string (C::*)() const, &C::serialize> * /*unused*/) {}

    // The famous C++ sink-hole.
    // Note that sink-hole must be templated too as we are testing test<T>(0).
    // If the method serialize isn't available, we will end up in this method.
    template<typename>
    static no &test(...) { /* dark matter */ }

    //用作测试的返回值的常数。
    //由于编译时评估的大小，因此实际上在这里完成了测试。
    static const bool value = sizeof(test<T>(0)) == sizeof(yes);
    // 或者
//     enum { value = sizeof(test<T>(0)) == sizeof(yes) };
};