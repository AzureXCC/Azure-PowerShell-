#pragma warning(disable:4996)
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include "FunFun.h"

#define SOP(str) printf("********* %s ********* 键入任意键以继续......",str);getch();

int nodeCount = 0,color = 1;
Stu* headNode;

void CursorJump(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
}
void LoadData() {
	headNode = (Stu*)malloc(sizeof(Stu));
	headNode->next = NULL;

	char sex[4], age[4];
	char ID[20];

	//读取数据
	FILE* fp = fopen("DATA\\NodeCount.txt", "r");
	fscanf(fp, "%d", &nodeCount);
	int n = nodeCount;
	nodeCount = 0;

	for (int i = 0; i < n; i++)
	{
		CreateNode(headNode, " ", " ", -1, -1, -1,-1,-1,-1);
	}
	if (n > 0) {
		fp = fopen("DATA\\Inf.txt", "r");
		Stu* p = headNode->next;
		while (p!=NULL)
		{
			fscanf(fp, "%s %s %d %d %ld %f %f %f ", p->name, p->major, &p->sex, &p->age, &p->ID,&p->Chinese,&p->Math,&p->English);
			p = p->next;
		}
	}
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	SOP("读取数据成功!");

	DisplayMenu();
}

void Load() {
	SetSize_window(150, 60);
	system("title Azure PowerShell");
	Beep(523, 500);
	LoadData();
}
int DisplayMenu() {
	system("cls");
	if(color == 1)
		system("color 0F");
	else {
		system("color F0");
	}
	printf(
"    _                          ____                        ____  _          _ _\n"
"   / \\    _____   _ _ __ ___  |  _ \\ _____      _____ _ __/ ___|| |__   ___| | |\n"
"  / _ \\  |_  / | | | '__/ _ \\ | |_) / _ \\ \\ /\\ / / _ \\ '__\\___ \\| '_ \\ / _ \\ | |\n"
" / ___ \\  / /| |_| | | |  __/ |  __/ (_) \\ V  V /  __/ |   ___) | | | |  __/ | |\n"
"/_/   \\_\\/___|\\__,_|_|  \\___| |_|   \\___/ \\_/\\_/ \\___|_|  |____/|_| |_|\\___|_|_|\n"
"                                                                                \n"
	);
	printf("___________________________________________________________________________________________\n");

	printf("%*s", 14, "|\n");
	printf("%*s", 14, "查看[1]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "录入[2]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "编辑[3]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "删除[4]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "保存[5]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "设置[6]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "关于[7]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "退出[0]  |\n");
	printf("%*s", 14, "|\n");
	printf("%*s", 14, "|\n");
	printf("%*s", 14, "|\n");
	printf("%*s", 14, "|\n");
	printf("%*s", 14, "|\n");
	printf("%*s", 14, "|\n");

	InstructionHub();

}
int DisplayMenu_noHub() {
	system("cls");
	if (color == 1)
		system("color 0F");
	else {
		system("color F0");
	}
	printf(
		"    _                          ____                        ____  _          _ _\n"
		"   / \\    _____   _ _ __ ___  |  _ \\ _____      _____ _ __/ ___|| |__   ___| | |\n"
		"  / _ \\  |_  / | | | '__/ _ \\ | |_) / _ \\ \\ /\\ / / _ \\ '__\\___ \\| '_ \\ / _ \\ | |\n"
		" / ___ \\  / /| |_| | | |  __/ |  __/ (_) \\ V  V /  __/ |   ___) | | | |  __/ | |\n"
		"/_/   \\_\\/___|\\__,_|_|  \\___| |_|   \\___/ \\_/\\_/ \\___|_|  |____/|_| |_|\\___|_|_|\n"
		"                                                                                \n"
	);
	printf("___________________________________________________________________________________________\n");

	printf("%*s", 14, "|\n");
	printf("%*s", 14, "查看[1]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "录入[2]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "编辑[3]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "删除[4]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "保存[5]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "设置[6]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "关于[7]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "退出[0]  |\n");
	printf("%*s", 14, "|\n");
	printf("%*s", 14, "|\n");
	printf("%*s", 14, "|\n");
	printf("%*s", 14, "|\n");
	printf("%*s", 14, "|\n");
	printf("%*s", 14, "|\n");

	//InstructionHub();

}

//int test() {
//	CursorJump(14,8);
//	printf("123\n");
//	printf("123\n");
//	getchar();
//}

void SetSize_window(int w, int h)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//获取标准输出的句柄
	COORD size = { w, h };//设置窗口的大小。
	SetConsoleScreenBufferSize(hOut, size);//重新设置缓冲区大小。
	SMALL_RECT rc = { 1,1, w, h };//重置窗口位置和大小。
	SetConsoleWindowInfo(hOut, TRUE, &rc);//重置窗口大小
	system("cls");//清理屏幕
}
Stu* CreateNode(Stu* head, char nameT[16], char majorT[32], int sexT, int ageT, long int ID_t, float chi, float mat, float eng) {
	Stu* p = head;
	while (p->next!=NULL)
	{
		p = p->next;
	}
	Stu* newNode = (Stu*)malloc(sizeof(Stu)); nodeCount++;
	p->next = newNode;
	strcpy(newNode->name, nameT);
	strcpy(newNode->major, majorT);
	newNode->sex = sexT;
	newNode->age = ageT;
	newNode->ID = ID_t;
	newNode->Chinese = chi;
	newNode->Math = mat;
	newNode->English = eng;
	newNode->next = NULL;

	/*printf(" 1 1 1 1 1 %s %s %d %d %ld", newNode->name,newNode->major,newNode->sex, newNode->age,newNode->ID);
	getch();*/

}
int Input() {
	char nameT[16]; char majorT[32]; int sexT = 0; int ageT = 0; long int ID_t = 0;
	float chi = 0, mat = 0, eng = 0;

	printf("输入样例:XiaoXi CS 0(0:MAN 1:FEMAIL OTHER:OTHER) 17 2234110507 89 101 90\\n 输入:");
	scanf("%s%s%d%d%ld%f%f%f", nameT,majorT,&sexT,&ageT,&ID_t,&chi,&mat,&eng);
	CreateNode(headNode, nameT, majorT, sexT, ageT, ID_t,chi,mat,eng);

	return 0;
}
int AddPerson() {
	int n = 0;

	CursorJump(14, 8);
	printf("数量:");
	scanf("%d", &n);

	if (n > 0) {
		DisplayMenu_noHub();
		for (int i = 0; i < n; i++)
		{
			CursorJump(14, 8+i);
			Input();
		}
		DisplayMenu_noHub();
		CursorJump(14, 8);
		SOP("录入完毕!");
		
		DisplayMenu();
	}
	else
	{
		CursorJump(14, 8);
		SOP("数值错误!");
		DisplayMenu();
	}
}

void View(Stu* head) {
	int n = 0;
	CursorJump(14, 8);
	printf("1:根据学号进行查询并显示  0:显示所有  10:正排序  11:逆排序  输入:");
	scanf("%d", &n);

	if (n==1) {
		CursorJump(14, 9);
		printf("目标学号:");
		long int target = 0;
		scanf("%ld", &target);

		DisplayMenu_noHub();
		Stu* p = head->next;
		while (p!=NULL)
		{
			if (p->ID == target) {
				CursorJump(14, 10);
				printf("Name\tMajor\tsex\tage\tID\tChinese\tMath\tEnglish\tSum\tAver\t");
				CursorJump(14, 11);
				printf("%s\t%s\t", p->name, p->major);
				switch (p->sex)
				{
				case 0:printf("男\t"); break;
				case 1:printf("女\t"); break;
				default:printf("Other\t"); break;
				}
				float sum = p->Chinese + p->Math + p->English, aver = sum / 3.0;
				printf("%d\t%ld\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\t", p->age, p->ID, p->Chinese, p->Math, p->English, sum, aver);

				CursorJump(14, 12);
				SOP("查询结束!");
				DisplayMenu();
			}
			else {
				p = p->next;
			}
		}
		CursorJump(14, 12);
		SOP("查询结束!没有寻找到目标人员!");
		DisplayMenu();
	}
	else if (n == 10) {
		//选择排序
		Stu* p1 = head->next;
		Stu* p2 = p1->next;

		while (p1!=NULL)
		{
			while (p2 != NULL) {
				float p1_sum = p1->Chinese + p1->Math + p1->English;
				float p2_sum = p2->Chinese + p2->Math + p2->English;
				if (p1_sum > p2_sum) {
					//临时变量
					char name[16], major[32];
					int sex = 0, age = 0;
					long int ID = 0;
					float Chinese = 0, Math = 0, English = 0;

					strcpy(name, p1->name);
					strcpy(major, p1->major);
					sex = p1->sex;
					age = p1->age;
					ID = p1->ID;
					Chinese = p1->Chinese;
					Math = p1->Math;
					English = p1->English;

					strcpy(p1->name, p2->name);
					strcpy(p1->major, p2->major);
					p1->sex = p2->sex;
					p1->age = p2->age;
					p1->ID = p2->ID;
					p1->Chinese = p2->Chinese;
					p1->Math = p2->Math;
					p1->English = p2->English;

					strcpy(p2->name, name);
					strcpy(p2->major, major);
					p2->sex = sex;
					p2->age = age;
					p2->ID = ID;
					p2->Chinese = Chinese;
					p2->Math = Math;
					p2->English = English;
				}

				p2 = p2->next;
			}
			p1 = p1->next;
			if (p1 != NULL)
				p2 = p1->next;
		}
		CursorJump(14, 12);
		SOP("排序结束!");
		DisplayMenu();
	}
	else if (n == 11) {
		//选择排序
		Stu* p1 = head->next;
		Stu* p2 = p1->next;

		while (p1 != NULL)
		{
			while (p2 != NULL) {
				float p1_sum = p1->Chinese + p1->Math + p1->English;
				float p2_sum = p2->Chinese + p2->Math + p2->English;
				if (p1_sum < p2_sum) {
					//临时变量
					char name[16], major[32];
					int sex = 0, age = 0;
					long int ID = 0;
					float Chinese = 0, Math = 0, English = 0;

					strcpy(name, p1->name);
					strcpy(major, p1->major);
					sex = p1->sex;
					age = p1->age;
					ID = p1->ID;
					Chinese = p1->Chinese;
					Math = p1->Math;
					English = p1->English;

					strcpy(p1->name, p2->name);
					strcpy(p1->major, p2->major);
					p1->sex = p2->sex;
					p1->age = p2->age;
					p1->ID = p2->ID;
					p1->Chinese = p2->Chinese;
					p1->Math = p2->Math;
					p1->English = p2->English;

					strcpy(p2->name, name);
					strcpy(p2->major, major);
					p2->sex = sex;
					p2->age = age;
					p2->ID = ID;
					p2->Chinese = Chinese;
					p2->Math = Math;
					p2->English = English;
				}

				p2 = p2->next;
			}
			p1 = p1->next;
			if (p1 != NULL)
				p2 = p1->next;
		}
		CursorJump(14, 12);
		SOP("排序结束!");
		DisplayMenu();
	}else
	{
		DisplayMenu_noHub();

		int i = 0;
		if (head->next != NULL) {
			Stu* p = head->next;

			CursorJump(14, 8);
			printf("Name\tMajor\tsex\tage\tID\tChinese\tMath\tEnglish\tSum\tAver\t");
			while (p != NULL)
			{
				CursorJump(14, 9 + i);
				i++;
				printf("%s\t%s\t", p->name, p->major);
				switch (p->sex)
				{
				case 0:printf("男\t"); break;
				case 1:printf("女\t"); break;
				default:printf("Other\t"); break;
				}
				float sum = p->Chinese + p->Math + p->English, aver = sum / 3.0;

				printf("%d\t%ld\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\t", p->age, p->ID, p->Chinese, p->Math, p->English, sum, aver);
				p = p->next;
			}
		}
		else {
			CursorJump(14, 8);
			SOP("无数据!");
			DisplayMenu();
		}
		CursorJump(14, 9 + i);
		SOP("输出完毕!");
		DisplayMenu();
	}
}

void Edit(Stu* head) {
	int n = 0;
	Stu* p = head;
	CursorJump(14, 8);
	printf("目前共有%d名人员，请输入编号以进行编辑:", nodeCount);
	scanf("%d", &n);
	if (n > 0 && n <= nodeCount) {
		for (int i = 0; i < n; i++)
		{
			p = p->next;
		}
		CursorJump(14, 9);
		printf("原始数据:%s %s %d %d %ld %f %f %f 新数据:", p->name, p->major, p->sex, p->age, p->ID,p->Chinese,p->Math,p->English);
		scanf("%s%s%d%d%ld%f%f%f", p->name, p->major, &p->sex, &p->age, &p->ID, &p->Chinese, &p->Math, &p->English);
		CursorJump(14, 10);
		SOP("数据编辑成功!");
		DisplayMenu();
	}
	else
	{
		CursorJump(14, 10);
		SOP("数据编辑失败!非法编号!");
		DisplayMenu();
	}

}

void Delete(Stu* head) {
	int n = 0;
	Stu* p = head;
	CursorJump(14, 8);
	printf("目前共有%d名人员，请输入编号以删除:", nodeCount);
	scanf("%d", &n);
	for (int i = 0; i < n-1; i++)
	{
		p = p->next;
	}
	Stu* del = p->next;
	p->next = del->next;
	free(del);
	nodeCount--;
	CursorJump(14, 9);
	SOP("数据删除成功!");
	DisplayMenu();

}
void About() {
	CursorJump(14, 8);
	printf("程序名\t\t作者\t版本号\t备注\t");
	CursorJump(14, 9);
	printf("Azure PowerShell\t许...\t1.0.0\t大一上学期 大作业\t");
	CursorJump(14, 11);
	printf("仓库链接:%s   键入\"V\"以访问","https://github.com/AzureXCC/Azure-PowerShell-/tree/main");
	CursorJump(14, 12);
	printf("键入其它键以返回至上级菜单");
	char ch = getch();
	if (ch == 'V'||ch =='v') {
		system("start https://github.com/AzureXCC/Azure-PowerShell-/tree/main");
		DisplayMenu();
	}
	else {
		DisplayMenu();
	}

}
void Setting() {
	CursorJump(14, 8);
	printf("程序主题\t\t选项\t\t");
	CursorJump(14, 9);
	printf("暗黑\t\t1\t\t");
	CursorJump(14, 10);
	printf("明亮\t\t0\t\t");
	CursorJump(14, 11);
	scanf("%d", &color);

	CursorJump(14, 12);
	SOP("颜色主题变更成功!");
	DisplayMenu();
}
void Save(Stu* head) {
	Stu* p = head->next;
	FILE* fp = fopen("DATA\\Inf.txt","w");
	char nodeCountArr[20];

	while (p!=NULL)
	{
		fprintf(fp, "%s %s %d %d %ld %f %f %f ", p->name, p->major, p->sex, p->age, p->ID,p->Chinese,p->Math,p->English);
		
		p = p->next;
	}
	
	//写入人数
	remove("DATA\\NodeCount.txt");
	fp = fopen("DATA\\NodeCount.txt", "w");
	fprintf(fp,"%d",nodeCount);

	CursorJump(14, 8);
	SOP("写入数据成功!");
	DisplayMenu();
}
void InstructionHub() {
	char ch = getch();
	switch (ch)
	{
	case '1':View(headNode); break;
	case '2':AddPerson(); break;
	case '3':Edit(headNode); break;
	case '4':Delete(headNode); break;
	case '5':Save(headNode); break;
	case '6':Setting(); break;
	case '7':About(); break;
	case '0':exit(0); break;
	default:DisplayMenu(); break;
	}
}