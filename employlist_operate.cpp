#include"data.h"
struct NodeEB*headEB= NULL;//是查看employlist的钥匙
/*
 * 创建一个包含客户数据的新节点
 */
struct NodeEB* createNode(EmployeeBasic* pdata) {
    struct NodeEB* pNew = (struct NodeEB*)malloc(sizeof(struct NodeEB));
    if (pNew == NULL) {
        return NULL;
    }
    pNew->next = NULL;
    pNew->data = *pdata;
    return pNew;
}
/*
 * 将新节点添加到链表中
 */
void addNode(struct NodeEB** root, EmployeeBasic* pdata) {
    if (root == NULL) return;
    if (*root == NULL) {
        *root = createNode(pdata);
        return;
    }
    struct NodeEB* pTemp = *root;
    while (pTemp->next!= NULL) {
        pTemp = pTemp->next;
    }
    pTemp->next = createNode(pdata);
}
/*
 * 从文件中读取客户数据并填充链表
 */
void readDataFromFile(struct NodeEB** root) {
    FILE* fp = fopen("./employlist.txt", "r");
    if (fp == NULL) {
        printf("数据检索失败！正在退出系统...\n");
        exit(0);
    }
    EmployeeBasic temp;
    while (fscanf(fp, "%d %s %s %s %d %d %s %s %s %s %s\n",&temp.employee_id, temp.name, temp.id_number, temp.join_date, &temp.department_id, &temp.position_id, temp.email, temp.phone_number, temp.address, temp.alma_mater, temp.education)==11) {
        addNode(root, &temp);
    }
    fclose(fp);
}

void writeDataToFile(struct NodeEB* root) {
    FILE* fp = fopen("./employlist.txt", "w");
    if (fp == NULL) {
        printf("文件打开失败！\n");
        return;
    }
    while (root) {
        fprintf(fp, "%d %s %s %s %d %d %s %s %s %s %s\n", root->data.employee_id, root->data.name, root->data.id_number, root->data.join_date, root->data.department_id, root->data.position_id, root->data.email, root->data.phone_number, root->data.address, root->data.alma_mater, root->data.education);
        root = root->next;
    }
    fclose(fp);
}
/*
 * 释放链表内存
 */
void freeList(struct NodeEB* root) {
    struct NodeEB* current = root;
    while (current) {
        struct NodeEB* next = current->next;
        free(current);
        current = next;
    }
}
/*
 * 删除客户信息
 */
void deleteEmployee(struct NodeEB** root) {
    char name[MAX_NAME];
    printf("输入要删除的客户姓名：");
    scanf("%s", name);

    struct NodeEB* current = *root;
    struct NodeEB* prev = NULL;

    while (current) {
        if (strcmp(current->data.name, name) == 0) {
            if (prev == NULL) {
                *root = current->next;
            }
            else {
                prev->next = current->next;
            }
            free(current);
            writeDataToFile(*root);
            printf("客户删除成功！\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("未找到客户！\n");
}

/*
 * 遍历链表读取数据并显示数据
 */
void readList(struct NodeEB* root) {
    struct NodeEB* current = root;
    while (current) {
        printf("员工编号：%d\n", current->data.employee_id);
        printf("员工姓名：%s\n", current->data.name);
        printf("员工身份证：%s\n", current->data.id_number);
        printf("入职日期：%s\n", current->data.join_date);
        printf("部门编号：%d\n", current->data.department_id);
        printf("职位编号：%d\n", current->data.position_id);
        printf("电子邮箱：%s\n", current->data.email);
        printf("电话号码：%s\n", current->data.phone_number);
        printf("地址：%s\n", current->data.address);
        printf("毕业院校：%s\n", current->data.alma_mater);
        printf("最高学历：%s\n", current->data.education);
        printf("\n");
        current = current->next;
    }
}

/*
 * 添加客户信息
 */
void addEmployee(struct NodeEB** root) {
    EmployeeBasic temp;
    printf("员工编号:");
    scanf("%d", &temp.employee_id);
    printf("员工姓名: ");
    scanf("%s", temp.name);
    printf("员工身份证：");
    scanf("%s", temp.id_number);
    printf("入职日期: ");
    scanf("%s", temp.join_date);
    printf("部门编号：");
    scanf("%d", &temp.department_id);
    printf("职位编号: ");
    scanf("%d", &temp.position_id);
    printf("电子邮箱:");
    scanf("%s", temp.email);
    printf("工作电话号码（请务必保持畅通）：");
    scanf("%s", temp.phone_number);
    printf("地址:");
    scanf("%s", temp.address);
    printf("毕业院校：");
    scanf("%s", temp.alma_mater);
    printf("最高学历：");
    scanf("%s", temp.education);
    addNode(root, &temp);
    writeDataToFile(*root);
    printf("客户信息添加成功！\n");
}


