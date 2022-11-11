#include<iostream>
#include<vector>


using namespace std;

template<typename T>
class Link
{
public:
	
	Link() {
		head = new Node;
		head->next = nullptr;
	}
	~Link() {

	}

	T& operator[](unsigned int Count) {
		if (Count  <= size()) {
			Node* temp = head->next;
			for (size_t i = 0; i < Count; i++)
				temp = temp->next;
			return temp->data;
		}
		throw "lloob";
	}

	Link& operator=(std::vector<T> ar) {
		for (unsigned int i = 0; i < ar.size(); i++)
			AddData(ar[i]);
		return *this;
	}

	unsigned int size() {
		unsigned int Count = 0;
		Node* temp = head->next;
		while (temp->next != nullptr)
		{
			temp = temp->next;
			++Count;
		}

		return Count;
	}

	bool DeleteNode(unsigned int Count) {
		
		if (Count <= size()) {
			Node* temp = head->next;
			Node* temp2 = head;
			for (size_t i = 0; i < Count; i++){
				temp = temp->next;
				temp2 = temp2->next;
			}
			temp2->next = temp->next;
			delete temp;
			return true;
		}
		return false;
	}


	bool InsertNode(T data, unsigned int Count) {
		
		Node* temp = head;
		Node* temp2 = head->next;
		Node* insertnode = new Node{data, nullptr};

		if (Count <= size()) {
			for (unsigned int i = 0; i < Count; i++){
				temp = temp->next;
				temp2 = temp2->next;
			}
			temp->next = insertnode;
			insertnode->next = temp2;
			return true;
		}
		return false;
	}

	Link& AddData(T data) {
		
		Node* t = new Node{data, nullptr};
		if (head->next == nullptr) {
			head->next = t;
			upprt = t;
			return *this;
		}
		upprt->next = t;
		upprt = t;
		return *this;
	}

private:
	typedef struct LinkNode
	{
		T data;
		LinkNode* next;
	}Node;

	Node* head;
	Node* upprt;
};



struct info
{
	char name[10];
	int age;
};


int main() {
	Link<Link<info>> list;

	Link<info> list1;

	list1 = { {"name",10},{"alex",20} };
	
	list.AddData(list1);

	try
	{
		cout << list[0][0].name << "---" << list[0][0].age << endl;
	}
	catch (const char* errinfo)
	{
		cout << errinfo << endl;
	}



	return 0;
}