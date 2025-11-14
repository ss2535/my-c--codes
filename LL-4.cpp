#include<iostream>
using namespace std;

class LinkedList {
	private:
		class Node {
			public:
				string data;
				Node* link;
		};

		Node* first = 0;
		Node* last = 0;
	public:
		void Add(string data) {
			Node *nN = new Node();
			nN->link = 0;
			nN->data = data;
			if(last == 0) {
				first = last = nN;
				return;
			}
			last->link = nN;
			last = nN;
		}
	private:
		Node* get_i_th_node(int i) {
			Node* itr = first;
			for(int j = 0; j < i; j++) {
				if(!itr)
					return 0;
				itr = itr->link;
			}
			return itr;
		}
	public:
		string get_i_th(int i) {
			Node *retN = get_i_th_node(i);
			if(retN == 0)
				return "$";
			return retN->data;
		}
};
int main() {
	LinkedList myList;
	for(int i = 0; i < 1000; i++)
		myList.Add(to_string(i));
	
	cout << myList.get_i_th(140) << endl;
	cout << myList.get_i_th(1000);
	return 0;
}