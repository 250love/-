#include"data.h"
#include"employlist_operate.h"
#include"Basic_Manage.h"
extern struct NodeEB* headEB;
void menu01() {
    printf("----------------------------------------------------------------------\n");
    printf("                           1.基本信息管理                              \n");
    printf("                           2.员工工作调整                               \n");
    printf("                           3.员工工资管理                                \n");
    printf("                           4.基本信息查询                                 \n");
    printf("                           5.基本信息统计                                  \n");
    printf("                           6.员工工资分析                                   \n");
    printf("                          按任意键退出系统                                   \n");
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
}//管理员操作界面