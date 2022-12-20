#include <stdio.h>
#include "FunFun.h"


int main(int argc, char const* argv[])
{
    Load();//创建头结点并读取存档
    DisplayMenu();//显示界面并调用指令枢纽

    return 0;
}
