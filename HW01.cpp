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
	stack();
	stack(int);
	size_t count() const;
	void push(T const &);
	T pop();
	void printStack();
};

template <typename T>
stack<T>::stack() {
	array_size_ = 2;
	array_ = new T[array_size_];
}

template <typename T>
stack<T>::stack(int maxEl) {
	array_size_ = maxEl;
	array_ = new T[maxEl];
	count_ = 0;
}

template <typename T>
void stack<T>::push(const T &value) {
	if (count_ == array_size_) {
		T* array_size2_ = new T[2 * array_size_];
		for (int i = 0; i != array_size_; ++i) {
			array_size2_[i] = array_[i];
		}
		delete[]array_;
		array_ = array_size2_;
	}
	array_[count_++] = value;
}

template<typename T>
T stack<T>::pop() {
	assert(count_ > 0);
	array_[--count_];
	return array_[count_];
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
	stack<int> st(2);
	int j = 0;
	int je;

	while (j++ < 4) {
		cin >> je;
		st.push(je);
	}

cout << "Ellements of stack" << endl;
cout << endl;

st.printStack();

for (int i = 4; i > 1; i--) {
	st.pop();
}

cout << "Posle Ydaleniya" << endl;
cout << endl;

st.printStack();

cout << endl;

system("pause");
return 0;
}
