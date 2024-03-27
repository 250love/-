#pragma once

NodeEB* createNode(EmployeeBasic* pdata);

void addNode(NodeEB** root, EmployeeBasic* pdata);

void readDataFromFile(NodeEB** root);

void writeDataToFile(NodeEB* root);

void freeList(NodeEB* root);

void deleteEmployee(struct NodeEB**);

void readList(struct NodeEB*);
void addEmployee(struct NodeEB**);