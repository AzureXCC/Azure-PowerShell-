#pragma once
#include <stdio.h>

typedef struct Student
{
	char name[16], major[32];
	int sex, age;
	long int ID;

	float Chinese, Math, English;

	struct Student* next;
}Stu;

void Load();
void CursorJump(int x, int y);
int DisplayMenu();
int DisplayMenu_noHub();
void InstructionHub();
void LoadData();
//Stu * CreateHeadNode();
Stu * CreateNode(Stu* head, char nameT[16], char majorT[32], int sexT, int ageT, long int ID_t,float chi,float mat,float eng);
int Input();
int AddPerson();
void View(Stu* head);
void Edit(Stu* head);
void Delete(Stu* head);
void About();
void Setting();
void Save(Stu* head);
void SetSize_window(int w, int h);