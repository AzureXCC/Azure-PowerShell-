#pragma warning(disable:4996)
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include "FunFun.h"

#define SOP(str) printf("********* %s ********* ����������Լ���......",str);getch();

int nodeCount = 0,color = 1;
short edited = 0;
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

	//��ȡ����
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
	FakeLoading();
	SOP("��ȡ���ݳɹ�!");

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
	printf("_______________________________________________________________________________________________________________\n");

	printf("%*s", 14, "|\n");
	printf("%*s", 14, "�鿴[1]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "¼��[2]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "�༭[3]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "ɾ��[4]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "����[5]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "����[6]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "����[7]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "�˳�[0]  |\n");
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
	printf("_______________________________________________________________________________________________________________\n");

	printf("%*s", 14, "|\n");
	printf("%*s", 14, "�鿴[1]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "¼��[2]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "�༭[3]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "ɾ��[4]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "����[5]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "����[6]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "����[7]  |\n");
	printf("%*s", 14, "|\n");

	printf("%*s", 14, "�˳�[0]  |\n");
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
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ��׼����ľ��
	COORD size = { w, h };//���ô��ڵĴ�С��
	SetConsoleScreenBufferSize(hOut, size);//�������û�������С��
	SMALL_RECT rc = { 1,1, w, h };//���ô���λ�úʹ�С��
	SetConsoleWindowInfo(hOut, TRUE, &rc);//���ô��ڴ�С
	system("cls");//������Ļ
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

	printf("��������:XiaoXi CS 0(0:MAN 1:FEMAIL OTHER:OTHER) 17 2234110507 89 101 90\\n ����:");
	scanf("%s%s%d%d%ld%f%f%f", nameT,majorT,&sexT,&ageT,&ID_t,&chi,&mat,&eng);
	CreateNode(headNode, nameT, majorT, sexT, ageT, ID_t,chi,mat,eng);

	return 0;
}
int AddPerson() {
	int n = 0;

	CursorJump(14, 8);
	printf("����:");
	scanf("%d", &n);

	if (n > 0) {
		edited = 1;
		DisplayMenu_noHub();
		for (int i = 0; i < n; i++)
		{
			CursorJump(14, 8+i);
			Input();
		}
		DisplayMenu_noHub();
		CursorJump(14, 8);
		SOP("¼�����!");
		
		DisplayMenu();
	}
	else if (n == 0) {
		DisplayMenu();
	}
	else
	{
		CursorJump(14, 8);
		SOP("��ֵ����!");
		DisplayMenu();
	}
}

void View(Stu* head) {
	int n = 0;
	CursorJump(14, 8);
	printf("1:����ѧ�Ž��в�ѯ����ʾ  0:��ʾ����  10:������  11:������  ����:");
	scanf("%d", &n);

	if (n==1) {
		CursorJump(14, 9);
		printf("Ŀ��ѧ��:");
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
				case 0:printf("��\t"); break;
				case 1:printf("Ů\t"); break;
				default:printf("Other\t"); break;
				}
				float sum = p->Chinese + p->Math + p->English, aver = sum / 3.0;
				printf("%d\t%ld\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\t", p->age, p->ID, p->Chinese, p->Math, p->English, sum, aver);

				CursorJump(14, 12);
				SOP("��ѯ����!");
				DisplayMenu();
			}
			else {
				p = p->next;
			}
		}
		CursorJump(14, 12);
		SOP("��ѯ����!û��Ѱ�ҵ�Ŀ����Ա!");
		DisplayMenu();
	}
	else if (n == 10) {
		//ѡ������
		Stu* p1 = head->next;
		Stu* p2 = p1->next;

		while (p1!=NULL)
		{
			while (p2 != NULL) {
				float p1_sum = p1->Chinese + p1->Math + p1->English;
				float p2_sum = p2->Chinese + p2->Math + p2->English;
				if (p1_sum > p2_sum) {
					//��ʱ����
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
		SOP("�������!");
		DisplayMenu();
	}
	else if (n == 11) {
		//ѡ������
		Stu* p1 = head->next;
		Stu* p2 = p1->next;

		while (p1 != NULL)
		{
			while (p2 != NULL) {
				float p1_sum = p1->Chinese + p1->Math + p1->English;
				float p2_sum = p2->Chinese + p2->Math + p2->English;
				if (p1_sum < p2_sum) {
					//��ʱ����
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
		SOP("�������!");
		DisplayMenu();
	}else
	{
		DisplayMenu_noHub();

		int i = 0;
		if (head->next != NULL) {
			Stu* p = head->next;

			CursorJump(14, 8);
			printf("Name\tMajor\tSex\tAge\tID\tChinese\tMath\tEnglish\tSum\tAver\t");
			while (p != NULL)
			{
				CursorJump(14, 9 + i);
				i++;
				printf("%s\t%s\t", p->name, p->major);
				switch (p->sex)
				{
				case 0:printf("��\t"); break;
				case 1:printf("Ů\t"); break;
				default:printf("Other\t"); break;
				}
				float sum = p->Chinese + p->Math + p->English, aver = sum / 3.0;

				printf("%d\t%ld\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\t", p->age, p->ID, p->Chinese, p->Math, p->English, sum, aver);
				p = p->next;
			}
		}
		else {
			CursorJump(14, 8);
			SOP("������!");
			DisplayMenu();
		}
		CursorJump(14, 9 + i);
		SOP("������!");
		DisplayMenu();
	}
}

void Edit(Stu* head) {
	int n = 0;
	Stu* p = head;
	CursorJump(14, 8);
	printf("Ŀǰ����%d����Ա�����������Խ��б༭:", nodeCount);
	scanf("%d", &n);
	if (n > 0 && n <= nodeCount) {
		edited = 1;
		for (int i = 0; i < n; i++)
		{
			p = p->next;
		}
		CursorJump(14, 9);
		printf("ԭʼ����:%s %s %d %d %ld %f %f %f ������:", p->name, p->major, p->sex, p->age, p->ID,p->Chinese,p->Math,p->English);
		scanf("%s%s%d%d%ld%f%f%f", p->name, p->major, &p->sex, &p->age, &p->ID, &p->Chinese, &p->Math, &p->English);
		CursorJump(14, 10);
		SOP("���ݱ༭�ɹ�!");
		DisplayMenu();
	}
	else
	{
		CursorJump(14, 10);
		SOP("���ݱ༭ʧ��!�Ƿ����!");
		DisplayMenu();
	}

}

void Delete(Stu* head) {
	int n = 0;
	Stu* p = head;
	CursorJump(14, 8);
	printf("Ŀǰ����%d����Ա������������ɾ��:", nodeCount);
	scanf("%d", &n);
	if (n>0&&n<=nodeCount) {
		edited = 1;
		for (int i = 0; i < n - 1; i++)
		{
			p = p->next;
		}
		Stu* del = p->next;
		p->next = del->next;
		free(del);
		nodeCount--;
		CursorJump(14, 9);
		SOP("����ɾ���ɹ�!");
		DisplayMenu();
	}
	else
	{
		CursorJump(14, 9);
		SOP("����ɾ��ʧ��!ԭ��:�Ƿ����!");
		DisplayMenu();
	}

}
void About() {
	CursorJump(14, 8);
	printf("������\t\t����\t�汾��\t��ע\t");
	CursorJump(14, 9);
	printf("Azure PowerShell\t��...\t1.0.1\t��һ��ѧ�� ����ҵ\t");
	CursorJump(14, 11);
	printf("�ֿ�����:%s   ����\"V\"�Է���","https://github.com/AzureXCC/Azure-PowerShell-/tree/main");
	CursorJump(14, 12);
	printf("�����������Է������ϼ��˵�");
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
	printf("��������\t\tѡ��\t\t");
	CursorJump(14, 9);
	printf("����\t\t1\t\t");
	CursorJump(14, 10);
	printf("����\t\t0\t\t");
	CursorJump(14, 11);
	scanf("%d", &color);

	CursorJump(14, 12);
	SOP("��ɫ�������ɹ�!");
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
	
	//д������
	remove("DATA\\NodeCount.txt");
	fp = fopen("DATA\\NodeCount.txt", "w");
	fprintf(fp,"%d",nodeCount);

	CursorJump(14, 8);
	SOP("д�����ݳɹ�!"); edited = 0;
	DisplayMenu();
}
void Exit() {
	if (edited) {
		CursorJump(14, 8);
		getchar();//�������ڶ����ַ�
		printf("���������ƺ������˱䶯,Ҫ������?  [Y/N]:");
		char ch = ' ';
		scanf("%c", &ch);
		if (ch == 'Y' || ch == 'y') {
			edited = 0;
			Save(headNode);
			CursorJump(14, 9);
			printf("����ɹ�!�����Ѱ�ȫ�˳�!");
			exit(0);
		}
		else if (ch == 'N' || ch == 'n') {
			CursorJump(14, 9);
			printf("δ����!�����Ѱ�ȫ�˳�!");
			exit(0);
		}
		else
		{
			CursorJump(14, 9);
			SOP("���ƺ������˷�Ԥ�ڼ�,�����¼���!");
			DisplayMenu_noHub();
			Exit();
		}
	}
	else
	{
		CursorJump(14, 8);
		printf("����δ�����䶯,�����Ѱ�ȫ�˳�!");
		exit(0);
	}
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
	case '0':Exit(); break;
	default:DisplayMenu(); break;
	}
}

void FakeLoading() {
	for (int i = 0; i < 100; i++)
	{
		system("cls");
		printf("[%d%%] ", i + 1);
		for (int j = 0; j < i; j++)
		{
			putchar('>');
		}
		srand((unsigned int)time(NULL));
		Sleep((int)rand()%10);
	}
	putchar('\n');
}