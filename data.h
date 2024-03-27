#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NAME 50
#define MAX_DATA 20
#define MAX_EMAIL 30
#define MAX_NUM 50
#define MAX_ADDRESS 100
//���ŵĻ������
typedef struct {
    int department_id;//�������Ϊý��
    char department_name[MAX_NAME];
    char department_supervisor[MAX_NUM];
    char establishment_date[MAX_DATA];
    int department_size;
} DepartmentBasic;
//����������������departmentlist.txt��
struct NodeD {
    DepartmentBasic data;
    NodeD* next;
};
//ְλ�Ļ������
typedef struct {
    int position_id;
    char position_name[MAX_NAME];
    float min_salary;
    float max_salary;
} Position;
//����ְλ��Ϣ����������positionlist.txt��
struct NodeP {
    Position data;
    NodeP* next;
};
//ְ���Ļ������
typedef struct {
    int employee_id;
    char name[MAX_NAME];
    char id_number[MAX_NUM];
    char join_date[MAX_DATA];
    int department_id;
    int position_id;
    char email[MAX_EMAIL];
    char phone_number[MAX_NUM];
    char address[MAX_ADDRESS];
    char alma_mater[MAX_NUM];
    char education[MAX_NUM];
} EmployeeBasic;
//����ְ�������������������employlist.txt��
struct NodeEB {
    EmployeeBasic data;
    NodeEB* next;
};
//ְ���ı仯���
typedef struct {
    int change_id;//����Ǹôα䶯�ĵ���
    int employee_id;//��Ա��id��ý��
    int old_department_id;
    int old_position_id;
    int new_department_id;
    int new_position_id;
    char change_date[MAX_DATA];
} EmployeeChange;
//����һ��ְ���仯����������employchange.txt��
struct NodeEC {
    EmployeeChange data;
    NodeEC* next;
};
//ְ����нˮ
typedef struct {
    int salary_id;
    int employee_id;
    char salary_date[MAX_DATA];
    float base_salary;
    float position_salary;
    float performance_salary;
    float bonus_penalty;
    float gross_salary;
    float provident_fund;
    float tax_deduction;
    float net_salary;
} EmployeeSalary;
//����ְ��нˮ����������employesalary.txt��
struct NodeES {
    EmployeeSalary data;
    NodeES* next;
};