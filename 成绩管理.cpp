#include<iostream>
#include<string>
using namespace std;
struct student//定义一个student的结构体
{
	int number;//序号
	string name;//名字
	int c_score;//c程序设计
	int math_score;//高等数学
	int english_score;//英语
	int rank;//排行
	int sum;//总和
	student* next;//下一个学生
};
student* Head = new student;//student类的结构体指针，名字为Head
student* End = new student;//new是开辟一段新的内存空间
void init()//init是用来初始化链表的函数
{
	Head->next = End;
	End->next = NULL;
}

int find_pos(int num)//通过学号查找节点在链表中的位置
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
void change()//修改已有学生信息
{
	cout << "输入需要修改的学生编号" << endl;
	int num;
	cin >> num;
	if (find_pos(num) == -1)cout << "查无此人！" << endl;
	else
	{
		student* cur = Head;//cur为了找到要修改学生的地址而和设置的临时变量
		for (int i = 1; i <= find_pos(num); i++)
		{
			cur = cur->next;
		}
		int Number, c, math, english;
		string Name;
		cout << "输入编号 姓名 c语言成绩 数学成绩 英语成绩";
		cin >> Number >> Name >> c >> math >> english;
		cur->number = Number;
		cur->name = Name;
		cur->c_score = c;
		cur->math_score = math;
		cur->english_score = english;
		cur->sum = c + math + english;
	}
	cout << "更改完毕" << endl;
	system("pause");
}
void find()//查找已有学生编号
{
	cout << "输入需要查找的学生编号" << endl;
	int num;
	cin >> num;
	if (find_pos(num) == -1)cout << "查无此人！" << endl;
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
void add()//添加学生成绩
{
	student* Node = new student;
	Node->next = Head->next;
	Head->next = Node;
	int Number, c, math, english;
	string Name;
	while (1)
	{
		system("cls");
		cout << "输入编号 姓名 c语言成绩 数学成绩 英语成绩";
		cin >> Number >> Name >> c >> math >> english;
		student* show = Head->next;
		int flag = 0;
		while (show->next != NULL)//检测有没有重复输入学号
		{
			if (show->number == Number)
			{
				flag = 1;
				break;
			}
			show = show->next;//往后走一步
		}
		if (flag == 1)
		{
			flag = 0;
			cout << "输入有误，您输入的学生学号已经存在，请重新输入！" << endl;
			system("pause");
			continue;
		}
		else break;
	}
	Node->number = Number;//给Node里面赋值
	Node->name = Name;
	Node->c_score = c;
	Node->math_score = math;
	Node->english_score = english;
	Node->sum = c + math + english;
	cout << "添加完毕！" << endl;
	system("pause");//显示输入完毕暂停一下程序
}
void show_init()
{
	if (Head->next == End)
	{
		cout << "当前系统为空，请先添加元素" << endl;
		system("pause");
		return;
	}
	cout << "学号   姓名  C程序设计 高等数学 英语" << endl;
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
		cnt++;//cnt不算头尾的存数据的节点个数
	}
	cout << "平均分 \t\t" << sum_c / cnt << "\t" << sum_math / cnt << "\t" << sum_english / cnt << endl;
	cout << "最高分 \t\t" << max_c << "\t" << max_math << "\t" << max_english << endl;
	cout << "学生人数为:" << cnt << endl;
	system("pause");
}
void del()//删除学生成绩
{

	cout << "请输入需要删除的学生序号!" << endl;
	int num;
	cin >> num;
	if (find_pos(num) == -1)
	{
		cout << "查无此人！" << endl;
		return;
	}
	student* pre = NULL;//以下三行为初始化，定义三个指针
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
	cout << "删除完毕!" << endl;
	system("pause");
}
void menu()//整体框架
{
	while (1)
	{
		system("cls");
		cout << "学生成绩管理系统" << endl;
		cout << "0.展示学生信息" << endl;
		cout << "3.添加学生信息" << endl;
		cout << "4.查找学生信息" << endl;
		cout << "5.修改学生信息" << endl;
		cout << "6.删除学生信息" << endl;
		cout << "7.退出系统" << endl;
		int a;
		cin >> a;
		if (a == 0)
		{
			show_init();
		}
		else if (a == 4)find();
		else if (a == 3)
		{
			cout << "请输入添加学生人数" << endl;
			int num;
			cin >> num;
			for (int i = 0; i < num; i++)add();
		}
		else if (a == 5)change();
		else if (a == 6)del();
		else if (a == 7)return;
		else
		{
			cout << "输入错误，请重新输入!" << endl;
			system("pause");
		}
	}
}
int main()//main函数（主函数）
{
	init();
	menu();
	delete Head;
	delete End;
	return 0;
}