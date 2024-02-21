#include <iostream>
#include <string>

using namespace std;

struct Queue
{
	Queue* next = NULL;
	int number = 0;
	string name = "";
};


int main() {
	int choice, counter = 0;
	string toDelete;
	Queue* head = NULL, * tail = NULL,* temp = NULL,* prev = NULL;

	do
	{
		cout
			<< "1. Add New Queue\n"
			<< "2. Display Queue\n"
			<< "3. Delete Queue\n"
			<< "0. Exit\n"
			<< "\n"
			<< ":: ";
		cin >> choice;

		system("cls");

		switch (choice)
		{
		case 0:
			return 0;
		case 1:
			cout << "Add\n";

			if (!counter)
			{
				head = new Queue;
				head->next = NULL;

				cout << "Enter Int: ";
				cin >> head->number;

				cout << "Enter Name: ";
				cin >> head->name;

				tail = head;

			}
			else {
				temp = new Queue;
				temp->next = tail;

				cout << "Enter Int: ";
				cin >> temp->number;

				cout << "Enter Name: ";
				cin >> temp->name;

				tail = temp;
			}

			counter++;

			break;
		case 2:
			cout << "Traverse\n\n";

			temp = tail;

			if (temp)
			{
				do
				{
					cout << temp->number << ". " << temp->name << "\n";

					if (temp->next == NULL)
						break;

					temp = temp->next;
				}
				while (true);
			}
			else
			{
				cout << "No List Yet";
			}

			system("pause");

			break;
		case 3:
			cout << "Delete";

			cout << "What to Delete: ";
			cin >> toDelete;

			temp = tail;

			do
			{
				if (toDelete == temp->name) {
					if (prev != NULL)
						prev->next = temp->next;

					delete temp;
					break;
				}

				prev = temp;
				temp = temp->next;
			} while (true);

			counter--;


			break;
		default:
			break;
		}

		system("cls");
	} while (true);

}
