#pragma once
/**
 * @link https://blog.csdn.net/kong_xz/article/details/79484843
 * @brief 不是教材上的定义，但是比教材上的定义好
 */
typedef enum ElemTag {
    ATOM,
    LIST
}ElemTag;
typedef int atom;
typedef struct general_list {
    ElemTag tag;
    typedef union {
        atom data;
        struct general_list *list;
    }value;
    struct general_list *link;
}general_list,genList;