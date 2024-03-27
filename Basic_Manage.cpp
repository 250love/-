
#include"data.h"
#include"employlist_operate.h"
#include"menu00.h"
#include "Basic_Manage.h"
extern struct NodeEB* headEB;
void Employee_Informationmenu() {
    printf("----------------------------------------------------------------------\n");
    printf("                           1.增加员工信息                               \n");
    printf("                           2.删除员工信息                                \n");
    printf("                           3.修改员工信息                                \n");
    printf("                           4.返回上一菜单                                 \n");
    printf("                           5.显示员工信息                                \n");
    printf("                          按任意键退出系统                                   \n");
    printf("----------------------------------------------------------------------    \n");
    int cnt = 0;
    scanf("%d", &cnt);
    struct NodeEB* root = NULL;
    readDataFromFile(&root);
    switch (cnt) {
    case 1:
        AddEmployeeinformation(&root);
        break;
    case2:
        DeleteEmployeeinformation();
        break;
    case 3:
        break;
    case 4:
        Basic_Managemenu();
        break;
    case 5:
        readList(root);
        break;
    default:
        exit(0);
    }
}
void Basic_Managemenu() {
    printf("----------------------------------------------------------------------\n");
    printf("                           1.部门信息管理                               \n");
    printf("                           2.职位信息管理                                \n");
    printf("                           3.员工信息管理                                \n");
    printf("                           4.返回上一菜单                                 \n");
    printf("                          按任意键退出系统                                   \n");
    printf("----------------------------------------------------------------------    \n");
   
    printf("----------------------------请输入你的操作-----------------------------\n");
    int i= 0;
    scanf("%d", &i);
    switch (i) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        system("cls");
        Employee_Informationmenu();
        break;
    case 4:
        system("cls");
        menu01();
        break;
    default:
        exit(0);
    }
}
void AddEmployeeinformation(struct NodeEB** root) {
    addEmployee(root);
    freeList(*root);
    printf("您接下来的操作是：");
        printf("----------------------------------------------------------------------\n");
    printf("                           1.返回主菜单                                \n");
    printf("                           2.返回上一菜单                                 \n");
    printf("                          按任意键退出系统                                   \n");
    printf("----------------------------------------------------------------------    \n");

    printf("----------------------------请输入你的操作-----------------------------\n");
    int cnt = 0;
    scanf("%d", &cnt);
    switch (cnt) {
    case 2:
        Basic_Managemenu();
        break;
    case 1:
        menu01();
    default:
        exit(0);
    }
}
void DeleteEmployeeinformation() {

};
 