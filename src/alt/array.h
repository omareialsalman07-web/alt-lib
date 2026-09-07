#pragma once

namespace alt {
	template<class T, size_t _size>
	class array {
	public:

		T& operator[](size_t index) {
			if (index >= _size) 
				throw std::out_of_range("array index out of range");

			return m_data[index];
		}

		const T& operator[](size_t index) const {
			if (index >= _size) 
				throw std::out_of_range("array index out of range");

			return m_data[index];
		}

		size_t size() const { return _size; }

		T* data() { return m_data; }
		const T* data() const { return m_data; }

		// basic iterators
		T* begin() { return m_data; }
		const T* begin() const { return m_data; }

		T* end() { return (m_data + size()); }
		const T* end() const { return (m_data + size()); }

	private:
		T m_data[_size];
	};
}