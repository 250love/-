
#include"data.h"
#include"employlist_operate.h"
#include"menu00.h"
#include "Basic_Manage.h"
extern struct NodeEB* headEB;
void Employee_Informationmenu() {
    printf("----------------------------------------------------------------------\n");
    printf("                           1.����Ա����Ϣ                               \n");
    printf("                           2.ɾ��Ա����Ϣ                                \n");
    printf("                           3.�޸�Ա����Ϣ                                \n");
    printf("                           4.������һ�˵�                                 \n");
    printf("                           5.��ʾԱ����Ϣ                                \n");
    printf("                          ��������˳�ϵͳ                                   \n");
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
    printf("                           1.������Ϣ����                               \n");
    printf("                           2.ְλ��Ϣ����                                \n");
    printf("                           3.Ա����Ϣ����                                \n");
    printf("                           4.������һ�˵�                                 \n");
    printf("                          ��������˳�ϵͳ                                   \n");
    printf("----------------------------------------------------------------------    \n");
   
    printf("----------------------------��������Ĳ���-----------------------------\n");
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
    printf("���������Ĳ����ǣ�");
        printf("----------------------------------------------------------------------\n");
    printf("                           1.�������˵�                                \n");
    printf("                           2.������һ�˵�                                 \n");
    printf("                          ��������˳�ϵͳ                                   \n");
    printf("----------------------------------------------------------------------    \n");

    printf("----------------------------��������Ĳ���-----------------------------\n");
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
 