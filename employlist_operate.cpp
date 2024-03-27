#include"data.h"
struct NodeEB*headEB= NULL;//�ǲ鿴employlist��Կ��
/*
 * ����һ�������ͻ����ݵ��½ڵ�
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
 * ���½ڵ���ӵ�������
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
 * ���ļ��ж�ȡ�ͻ����ݲ��������
 */
void readDataFromFile(struct NodeEB** root) {
    FILE* fp = fopen("./employlist.txt", "r");
    if (fp == NULL) {
        printf("���ݼ���ʧ�ܣ������˳�ϵͳ...\n");
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
        printf("�ļ���ʧ�ܣ�\n");
        return;
    }
    while (root) {
        fprintf(fp, "%d %s %s %s %d %d %s %s %s %s %s\n", root->data.employee_id, root->data.name, root->data.id_number, root->data.join_date, root->data.department_id, root->data.position_id, root->data.email, root->data.phone_number, root->data.address, root->data.alma_mater, root->data.education);
        root = root->next;
    }
    fclose(fp);
}
/*
 * �ͷ������ڴ�
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
 * ɾ���ͻ���Ϣ
 */
void deleteEmployee(struct NodeEB** root) {
    char name[MAX_NAME];
    printf("����Ҫɾ���Ŀͻ�������");
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
            printf("�ͻ�ɾ���ɹ���\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("δ�ҵ��ͻ���\n");
}

/*
 * ���������ȡ���ݲ���ʾ����
 */
void readList(struct NodeEB* root) {
    struct NodeEB* current = root;
    while (current) {
        printf("Ա����ţ�%d\n", current->data.employee_id);
        printf("Ա��������%s\n", current->data.name);
        printf("Ա�����֤��%s\n", current->data.id_number);
        printf("��ְ���ڣ�%s\n", current->data.join_date);
        printf("���ű�ţ�%d\n", current->data.department_id);
        printf("ְλ��ţ�%d\n", current->data.position_id);
        printf("�������䣺%s\n", current->data.email);
        printf("�绰���룺%s\n", current->data.phone_number);
        printf("��ַ��%s\n", current->data.address);
        printf("��ҵԺУ��%s\n", current->data.alma_mater);
        printf("���ѧ����%s\n", current->data.education);
        printf("\n");
        current = current->next;
    }
}

/*
 * ��ӿͻ���Ϣ
 */
void addEmployee(struct NodeEB** root) {
    EmployeeBasic temp;
    printf("Ա�����:");
    scanf("%d", &temp.employee_id);
    printf("Ա������: ");
    scanf("%s", temp.name);
    printf("Ա�����֤��");
    scanf("%s", temp.id_number);
    printf("��ְ����: ");
    scanf("%s", temp.join_date);
    printf("���ű�ţ�");
    scanf("%d", &temp.department_id);
    printf("ְλ���: ");
    scanf("%d", &temp.position_id);
    printf("��������:");
    scanf("%s", temp.email);
    printf("�����绰���루����ر��ֳ�ͨ����");
    scanf("%s", temp.phone_number);
    printf("��ַ:");
    scanf("%s", temp.address);
    printf("��ҵԺУ��");
    scanf("%s", temp.alma_mater);
    printf("���ѧ����");
    scanf("%s", temp.education);
    addNode(root, &temp);
    writeDataToFile(*root);
    printf("�ͻ���Ϣ��ӳɹ���\n");
}


