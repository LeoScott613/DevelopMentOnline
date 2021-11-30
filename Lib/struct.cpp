#include <iostream>
using namespace std;
struct group
{
	int element;
	char charac;
} debate;
// You can define an struct virable right after the'}', or you can then in main() use struct group to define a struct virable.
struct person
{
	bool gender;
	int age, height;
	person(bool g, int a, int hei) : gender(g), age(a), height(hei) {}
};

int main()
{
	group two;
	group one;
	// Don't need a "struct" before group. group is surely a 类型 now.
	one.element = 1;
	one.charac = '-';
	cout << one.charac << one.element << endl;

	debate.element = 100;
	debate.charac = '%';
	cout << debate.element << debate.charac << endl;

	// error: int *p=&group; group is a type, not a varible. And it cannot be an int
	struct group *p = &debate; // correct method to write a struct pointer
	cout << p->element << p->charac << endl;

	person lhx(true, 19, 181);
	struct person *l = &lhx;
	cout << l->gender << l->age << l->height << endl;
	return 0;
}
