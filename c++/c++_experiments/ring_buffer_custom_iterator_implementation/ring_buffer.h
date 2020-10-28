#include <iostream>
#include <map>
#include<string>

using namespace std;

template<class T>
class ring {
	private:
		int m_size;
		int index;
		T *m_values;

	public:
		class iterator;

	public:
		ring(int size) : m_size(size), m_values(nullptr) {
			m_values = new T[m_size];
		}

		~ring() {
			delete[] m_values;
		}

		int size() {
			return m_size;
		}

		iterator begin() {
			return iterator(0, *this);
		}

		iterator end() {
			return iterator(m_size, *this);
		}

		void add(T str) {
			m_values[index++] =  str;
			
			if (index == m_size) {
				index = 0;
			}
		}

		T &display(int index) const {
			return m_values[index];
		}
};

template<class T>
class ring<T>::iterator {
	int m_index;
	ring &m_ring;
	public:
		iterator(int index, ring &tRing ) : m_index(index), m_ring(tRing) {
		}

		iterator &operator++() {
			m_index++;
			return *this;
		}

		iterator &operator++(int) {
			m_index++;
			return *this;
		}

		T &operator* () {
			return m_ring.display(m_index);
		}

		bool operator!=(const iterator &other) const{
			return m_index != other.m_index;
		}
};
