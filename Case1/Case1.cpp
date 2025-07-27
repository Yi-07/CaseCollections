#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>
using namespace std;

//ѡ����
class Person {
public:
	Person(string name, int score) {
		this->p_name = name;
		this->p_score = score;
	}

	string p_name;//ѡ����
	int p_score;//ѡ�ַ���
};


void CreatePerson(vector<Person>& v) {
	string temp = "ABCDE";
	for (int i = 0; i < 5; i++) {
		string name = "ѡ��";
		name += temp[i];

		int score = 0;//��ʼ����Ϊ0

		Person p(name, score);//���������

		v.push_back(p);//vector�����洢�����
	}

	////����
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
	//	cout << "������" << (*it).p_name << " ������" << (*it).p_score<<endl;
	//}
	//cout << endl;
}

void ScoreSet(vector<Person>& v) {
	//��ÿһ��ѡ�ֽ��и��ֲ���
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		deque<int>d; //deque�洢ѡ�ַ���
		//10����ί���
		for (int i = 0; i < 10; i++) {
			int num = rand() % 41 + 60;//���ַ�Χ60~100

			d.push_back(num);//deque�����洢��ί���
		}

		////��������ɸ�����
		//cout << "������" << it->p_name << " ��ί��������"<<endl;
		//for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
		//	cout<< *dit<<" ";
		//}
		//cout << endl;

		sort(d.begin(), d.end());//����ί��ֽ�������

		d.pop_front();//ȥ��һ����ͷ�
		d.pop_back();//ȥ��һ����߷�

		//��ѡ�ֵķ�����ƽ���÷֣�
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
			sum += *dit;
		}
		it->p_score = sum / d.size();
	}
}

void ShowScore(vector<Person>& v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {

		cout << "������" << it->p_name << " ������" << it->p_score << endl;
	}
}

int main() {

	srand((unsigned int)time(NULL));

	//1.vector�洢ѡ����
	vector<Person>v;

	CreatePerson(v);

	//2.deque�洢ѡ�ַ���

	ScoreSet(v);

	//3.���ѡ�ּ���Ӧ����

	ShowScore(v);

	return 0;
}