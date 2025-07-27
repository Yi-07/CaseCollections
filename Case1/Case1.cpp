#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>
using namespace std;

//选手类
class Person {
public:
	Person(string name, int score) {
		this->p_name = name;
		this->p_score = score;
	}

	string p_name;//选手名
	int p_score;//选手分数
};


void CreatePerson(vector<Person>& v) {
	string temp = "ABCDE";
	for (int i = 0; i < 5; i++) {
		string name = "选手";
		name += temp[i];

		int score = 0;//初始分数为0

		Person p(name, score);//定义类对象

		v.push_back(p);//vector容器存储类对象
	}

	////测试
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
	//	cout << "姓名：" << (*it).p_name << " 分数：" << (*it).p_score<<endl;
	//}
	//cout << endl;
}

void ScoreSet(vector<Person>& v) {
	//对每一名选手进行赋分操作
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		deque<int>d; //deque存储选手分数
		//10个评委打分
		for (int i = 0; i < 10; i++) {
			int num = rand() % 41 + 60;//赋分范围60~100

			d.push_back(num);//deque容器存储评委打分
		}

		////分数异议筛查测试
		//cout << "姓名：" << it->p_name << " 评委打分情况："<<endl;
		//for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
		//	cout<< *dit<<" ";
		//}
		//cout << endl;

		sort(d.begin(), d.end());//对评委打分进行升序

		d.pop_front();//去掉一个最低分
		d.pop_back();//去掉一个最高分

		//求选手的分数（平均得分）
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
			sum += *dit;
		}
		it->p_score = sum / d.size();
	}
}

void ShowScore(vector<Person>& v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {

		cout << "姓名：" << it->p_name << " 分数：" << it->p_score << endl;
	}
}

int main() {

	srand((unsigned int)time(NULL));

	//1.vector存储选手名
	vector<Person>v;

	CreatePerson(v);

	//2.deque存储选手分数

	ScoreSet(v);

	//3.输出选手及对应分数

	ShowScore(v);

	return 0;
}