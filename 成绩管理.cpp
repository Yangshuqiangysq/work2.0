#include<iostream>
#include<string>
using namespace std;
struct student//����һ��student�Ľṹ��
{
	int number;//���
	string name;//����
	int c_score;//c�������
	int math_score;//�ߵ���ѧ
	int english_score;//Ӣ��
	int rank;//����
	int sum;//�ܺ�
	student* next;//��һ��ѧ��
};
student* Head = new student;//student��Ľṹ��ָ�룬����ΪHead
student* End = new student;//new�ǿ���һ���µ��ڴ�ռ�
void init()//init��������ʼ������ĺ���
{
	Head->next = End;
	End->next = NULL;
}

int find_pos(int num)//ͨ��ѧ�Ų��ҽڵ��������е�λ��
{
	student* find = Head->next;
	int pos = -1, i = 0;
	while (find->next != NULL)
	{
		i++;
		if (find->number == num)pos = i;
		find = find->next;
	}
	return pos;
}
void change()//�޸�����ѧ����Ϣ
{
	cout << "������Ҫ�޸ĵ�ѧ�����" << endl;
	int num;
	cin >> num;
	if (find_pos(num) == -1)cout << "���޴��ˣ�" << endl;
	else
	{
		student* cur = Head;//curΪ���ҵ�Ҫ�޸�ѧ���ĵ�ַ�������õ���ʱ����
		for (int i = 1; i <= find_pos(num); i++)
		{
			cur = cur->next;
		}
		int Number, c, math, english;
		string Name;
		cout << "������ ���� c���Գɼ� ��ѧ�ɼ� Ӣ��ɼ�";
		cin >> Number >> Name >> c >> math >> english;
		cur->number = Number;
		cur->name = Name;
		cur->c_score = c;
		cur->math_score = math;
		cur->english_score = english;
		cur->sum = c + math + english;
	}
	cout << "�������" << endl;
	system("pause");
}
void find()//��������ѧ�����
{
	cout << "������Ҫ���ҵ�ѧ�����" << endl;
	int num;
	cin >> num;
	if (find_pos(num) == -1)cout << "���޴��ˣ�" << endl;
	else
	{
		student* cur = Head;
		for (int i = 1; i <= find_pos(num); i++)
		{
			cur = cur->next;
		}
		cout << cur->number << " ";
		cout << cur->name << ' ';
		cout << cur->c_score << ' ';
		cout << cur->english_score << ' ';
		cout << cur->math_score << ' ';
	}
	system("pause");
}
void add()//���ѧ���ɼ�
{
	student* Node = new student;
	Node->next = Head->next;
	Head->next = Node;
	int Number, c, math, english;
	string Name;
	while (1)
	{
		system("cls");
		cout << "������ ���� c���Գɼ� ��ѧ�ɼ� Ӣ��ɼ�";
		cin >> Number >> Name >> c >> math >> english;
		student* show = Head->next;
		int flag = 0;
		while (show->next != NULL)//�����û���ظ�����ѧ��
		{
			if (show->number == Number)
			{
				flag = 1;
				break;
			}
			show = show->next;//������һ��
		}
		if (flag == 1)
		{
			flag = 0;
			cout << "���������������ѧ��ѧ���Ѿ����ڣ����������룡" << endl;
			system("pause");
			continue;
		}
		else break;
	}
	Node->number = Number;//��Node���渳ֵ
	Node->name = Name;
	Node->c_score = c;
	Node->math_score = math;
	Node->english_score = english;
	Node->sum = c + math + english;
	cout << "�����ϣ�" << endl;
	system("pause");//��ʾ���������ͣһ�³���
}
void show_init()
{
	if (Head->next == End)
	{
		cout << "��ǰϵͳΪ�գ��������Ԫ��" << endl;
		system("pause");
		return;
	}
	cout << "ѧ��   ����  C������� �ߵ���ѧ Ӣ��" << endl;
	student* show = Head->next;
	double sum_c = 0, sum_math = 0, sum_english = 0, cnt = 0;
	int max_c = -1, max_math = -1, max_english = -1;
	while (show->next != NULL)
	{
		if (show->c_score > max_c)max_c = show->c_score;
		if (show->math_score > max_math)max_math = show->math_score;
		if (show->english_score > max_english)max_english = show->english_score;
		sum_c += show->c_score;
		sum_math += show->math_score;
		sum_english += show->english_score;
		cout << show->number << "\t";
		cout << show->name << "\t";
		cout << show->c_score << "\t";
		cout << show->math_score << "\t";
		cout << show->english_score << "\t";
		show = show->next;
		cout << endl;
		cnt++;//cnt����ͷβ�Ĵ����ݵĽڵ����
	}
	cout << "ƽ���� \t\t" << sum_c / cnt << "\t" << sum_math / cnt << "\t" << sum_english / cnt << endl;
	cout << "��߷� \t\t" << max_c << "\t" << max_math << "\t" << max_english << endl;
	cout << "ѧ������Ϊ:" << cnt << endl;
	system("pause");
}
void del()//ɾ��ѧ���ɼ�
{

	cout << "��������Ҫɾ����ѧ�����!" << endl;
	int num;
	cin >> num;
	if (find_pos(num) == -1)
	{
		cout << "���޴��ˣ�" << endl;
		return;
	}
	student* pre = NULL;//��������Ϊ��ʼ������������ָ��
	student* cur = Head;
	student* nExt = Head->next;
	for (int i = 1; i <= find_pos(num); i++)
	{
		pre = cur;
		cur = cur->next;
		nExt = nExt->next;
	}
	pre->next = nExt;
	delete cur;
	cout << "ɾ�����!" << endl;
	system("pause");
}
void menu()//������
{
	while (1)
	{
		system("cls");
		cout << "ѧ���ɼ�����ϵͳ" << endl;
		cout << "0.չʾѧ����Ϣ" << endl;
		cout << "3.���ѧ����Ϣ" << endl;
		cout << "4.����ѧ����Ϣ" << endl;
		cout << "5.�޸�ѧ����Ϣ" << endl;
		cout << "6.ɾ��ѧ����Ϣ" << endl;
		cout << "7.�˳�ϵͳ" << endl;
		int a;
		cin >> a;
		if (a == 0)
		{
			show_init();
		}
		else if (a == 4)find();
		else if (a == 3)
		{
			cout << "���������ѧ������" << endl;
			int num;
			cin >> num;
			for (int i = 0; i < num; i++)add();
		}
		else if (a == 5)change();
		else if (a == 6)del();
		else if (a == 7)return;
		else
		{
			cout << "�����������������!" << endl;
			system("pause");
		}
	}
}
int main()//main��������������
{
	init();
	menu();
	delete Head;
	delete End;
	return 0;
}