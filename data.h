#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NAME 50
#define MAX_DATA 20
#define MAX_EMAIL 30
#define MAX_NUM 50
#define MAX_ADDRESS 100
//部门的基本情况
typedef struct {
    int department_id;//用这个作为媒介
    char department_name[MAX_NAME];
    char department_supervisor[MAX_NUM];
    char establishment_date[MAX_DATA];
    int department_size;
} DepartmentBasic;
//创建部门链表（处理departmentlist.txt）
struct NodeD {
    DepartmentBasic data;
    NodeD* next;
};
//职位的基本情况
typedef struct {
    int position_id;
    char position_name[MAX_NAME];
    float min_salary;
    float max_salary;
} Position;
//创建职位信息的链表（处理positionlist.txt）
struct NodeP {
    Position data;
    NodeP* next;
};
//职工的基本情况
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
//创建职工基本情况的链表（处理employlist.txt）
struct NodeEB {
    EmployeeBasic data;
    NodeEB* next;
};
//职工的变化情况
typedef struct {
    int change_id;//存的是该次变动的单号
    int employee_id;//用员工id做媒介
    int old_department_id;
    int old_position_id;
    int new_department_id;
    int new_position_id;
    char change_date[MAX_DATA];
} EmployeeChange;
//创建一个职工变化的链表（处理employchange.txt）
struct NodeEC {
    EmployeeChange data;
    NodeEC* next;
};
//职工的薪水
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
//创建职工薪水的链表（处理employesalary.txt）
struct NodeES {
    EmployeeSalary data;
    NodeES* next;
};