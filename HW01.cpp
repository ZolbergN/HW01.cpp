#include <iostream>
#include <cassert>
#include <iomanip>

using namespace std;

template <typename T>
class stack
{
private:
	T * array_;
	size_t array_size_;
	size_t count_;
public:
	stack(int);
	size_t count() const;
	void push(T const &);
	T pop();
	void printStack();
};

template <typename T>
stack<T>::stack(int maxEl) : array_size_(maxEl) {
	array_ = new T[array_size_];
	count_ = 0;
}

template <typename T>
void stack<T>::push(const T &value) {
	assert(count_ < array_size_);
	array_[count_++] = value;
}

template<typename T>
T stack<T>::pop() {
	assert(count_ > 0);
	array_[--count_];
}

template<typename T>
size_t stack<T>::count() const {
	return array_size_;
}

template<typename T>
void stack<T>::printStack() {
	for (int i = count_ - 1; i >= 0; i--)
		cout << "[" << setw(4) << array_[i] << "]" << endl;
}

int main() {
	stack<int> st(5);
	int j = 0;
	int je;

	while (j++ < 5) {
		cin >> je;
		st.push(je);
	}

	cout << endl;

	st.printStack();

	system("pause");
	return 0;
}
