#include <iostream>
#include <string>

template <typename T>
struct Node {
	T data;
	Node* next;
};

template <typename T>
void showList(const Node<T>* head);

template <typename T>
Node<T>* arrayToList(const T a[], size_t size);

template <typename T, typename Pred>
Node<T>* extract(Node<T>*& head, Pred pred);

template <typename T>
void deleteList(Node<T>*& head);

bool isLong(const std::string& s) { return s.size() >= 5; }

int main() {
	int tabi[] = { 2, 1, 4, 3, 6, 5, 7, 8 };
	size_t sizei = sizeof(tabi) / sizeof(tabi[0]);
	Node<int>* listAi = arrayToList(tabi, sizei);
	showList(listAi);
	Node<int>* listBi = extract(listAi,
		[](int n) {
			return n % 2 == 0;
		});
	showList(listBi);
	showList(listAi);
	deleteList(listBi);
	deleteList(listAi);

	std::string tabs[]{ "Kasia", "Ola", "Ala",
						"Zosia", "Ela", "Basia" };
	size_t sizes = sizeof(tabs) / sizeof(tabs[0]);
	Node<std::string>* listAs = arrayToList(tabs, sizes);
	showList(listAs);
	Node<std::string>* listBs = extract(listAs, isLong);
	showList(listBs);
	showList(listAs);
	deleteList(listBs);
	deleteList(listAs);
}
template <typename T>
void showList(const Node<T>* head) {
	for (; head; head = head->next)
		 std::cout << head->data << " ";
	std::cout << std::endl;
}
template <typename T>
Node<T>* arrayToList(const T a[], size_t size) {
	Node<T>* head = nullptr;
	for (int i = size - 1; i >= 0; --i) 
		head = new Node<T>{ a[i], head };
	return head;
}
template <typename T, typename Pred>
Node<T>* extract(Node<T>*& head, Pred pred) {
	Node<T>* head2 = nullptr;
	Node<T>* temp = nullptr;
	while(head != nullptr){
		if (pred(head->data)) {
			head2 = new Node<T>{ head->data,head2 };
		} else {
			temp = new Node<T>{ head->data,temp };
		}
		head = head->next;
	}
	head = temp;
	return head2;
}
template <typename T>
void deleteList(Node<T>*& head) {
	while (head != nullptr) {
		std::cout << "DEL " << head->data << "; ";
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}
	std::cout << std::endl;
}