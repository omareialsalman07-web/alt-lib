#pragma once

namespace alt {
	template<class T>
	class vector
	{
	private:
		T* m_Data = nullptr;
		size_t m_Size;
		size_t m_Capacity;

	public:
		vector()
		{
			m_Size = 0;
			m_Capacity = 0;
			m_Data = nullptr;
		}
		explicit vector(size_t _count)
		{
			m_Size = _count;
			reAlloc(_count);
		}
		vector(size_t _count, const T& value)
		{
			m_Size = _count;
			m_Capacity = _count;

			m_Data = new T[_count];
			for (size_t i = 0; i < m_Size; i++)
			{
				m_Data[i] = value;
			}
		}

		// Copying
		vector(const vector<T>& others)
		{
			m_Size = others.size();
			m_Capacity = others.capacity();

			if (others.capacity() == 0)
				return;

			m_Data = new T[m_Capacity];
			for (size_t i = 0; i < m_Size; i++)
			{
				m_Data[i] = *(others.begin() + i);
			}
		}
		vector<T>& operator=(const vector<T>& others)
		{
			if (this == &others)
				return *this;

			m_Size = others.size();
			m_Capacity = others.capacity();

			if (others.capacity() == 0)
			{
				delete[] m_Data;
				m_Data = nullptr;
				return *this;
			}

			T* prevData = m_Data;

			m_Data = new T[others.capacity()];
			for (size_t i = 0; i < m_Size; i++)
			{
				m_Data[i] = *(others.begin() + i);
			}

			delete[] prevData;

			return *this;
		}

		~vector()
		{
			delete[] m_Data;
			m_Data = nullptr;
		}

		void reAlloc(size_t newCapacity)
		{
			m_Capacity = newCapacity;

			if (m_Size > newCapacity)
				m_Size = newCapacity;

			T* prevData = m_Data;

			m_Data = new T[newCapacity]();
			if (prevData == nullptr)
				return;

			for (size_t i = 0; i < m_Size; i++)
			{
				m_Data[i] = prevData[i];
			}

			delete[] prevData;
		}

		size_t size() const { return m_Size; }
		size_t capacity() const { return m_Capacity; }
		T* Data() { return m_Data; }

		T& operator[](size_t index)
		{
			if (index >= m_Size)
				throw std::out_of_range("array index out of range");

			return m_Data[index];
		}

		const T& operator[](size_t index) const
		{
			if (index >= m_Size)
				throw std::out_of_range("array index out of range");

			return m_Data[index];
		}

		void push_back(const T& value)
		{
			if (m_Size >= m_Capacity)
				grow();

			m_Data[m_Size] = value;
			m_Size++;
		}
		void pop_back()
		{
			if (m_Size == 0)
				return;

			--m_Size;
		}

		T* erase(T* _data)
		{
			if(_data < begin() || _data >= end())
				throw std::out_of_range("array index out of range");

			for (T* it = _data; it != (end() - 1); ++it)
			{
				*it = *(it + 1);
			}

			--m_Size;
			return  _data;
		}


		// basic iterators
		T* begin() { return m_Data; }
		const T* begin() const { return m_Data; }

		T* end() { return (m_Data + size()); }
		const T* end() const { return (m_Data + size()); }

		void clear()
		{
			m_Size = 0;
		}

		void reverse()
		{
			if (m_Size <= 1)
				return;

			size_t _i = 0;
			for (size_t i = m_Size - 1; i >= m_Size / 2; i--)
			{
				T temp = m_Data[_i];
				m_Data[_i] = m_Data[i]; 
				m_Data[i] = temp;

				_i++;
			}
		}

	private:
		void grow()
		{
			if (m_Capacity == 0)
			{
				reAlloc(2);
				return;
			}

			reAlloc(m_Capacity + (m_Capacity / 2));
		}
	};
}