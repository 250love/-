#include"data.h"
#include"employlist_operate.h"
#include"Basic_Manage.h"
extern struct NodeEB* headEB;
void menu01() {
    printf("----------------------------------------------------------------------\n");
    printf("                           1.������Ϣ����                              \n");
    printf("                           2.Ա����������                               \n");
    printf("                           3.Ա�����ʹ���                                \n");
    printf("                           4.������Ϣ��ѯ                                 \n");
    printf("                           5.������Ϣͳ��                                  \n");
    printf("                           6.Ա�����ʷ���                                   \n");
    printf("                          ��������˳�ϵͳ                                   \n");
    printf("-------------------------------------------------------------------------     \n");
    int cnt = 0;
    scanf("%d", &cnt);
    switch (cnt) {
    case 1:
        system("cls");
        Basic_Managemenu();
        break;
    case 2:
        //Work_change();
        break;
    case 3:
        //Salary_Manage();
        break;
    case 4:
        //Basic_information_check();
        break;
    case 5:
        //Basic_information_statistics();
        break;
    case 6:
        //Salary_analysis();
        break;
    default:
        exit(1);
    }
}//����Ա��������