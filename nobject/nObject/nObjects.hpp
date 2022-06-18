#pragma once

// 이중 연결 리스트, std의 기능을 모두 지원함.
// 리스트, 큐, 스택, 딕셔너리

namespace Nugunga {

	template <typename T>
	class IObjects {
	public:


	};

	template <typename T>
	class Objects : IObjects<T>
	{
		template <typename T>
		struct ObjectNode {
			T data;
			ObjectNode<T> prev;
			ObjectNode<T> next;

			ObjectNode(const T& value, ObjectNode<T> *prev_ptr, ObjectNode<T>* next_ptr) {
				data = value;
				prev = prev_ptr;
				next = next_ptr;
			}
		};

		template <typename T>
		class ObjectIterator {
		private:
			ObjectNode<T>* cur;
		public:
			ObjectIterator(ObjectNode<T>* p = nullptr) : cur(p) { }
			ObjectIterator& operator++() {
				cur = cur->next;
				return *this;
			}
			ObjectIterator& operator--() {
				cur = cur->prev;
				return *this;
			}
			T& operator*() const { return cur->data; }
			bool operator==(const ObjectIterator& ref) { return cur == ref.cur; }
			bool operator!=(const ObjectIterator& ref) { return cur != ref.cur; }
		};


	};
}