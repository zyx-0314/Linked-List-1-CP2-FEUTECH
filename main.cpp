#include <iostream>
#include <string>

using namespace std;

struct Queue
{
  // Address
	Queue* next = NULL;
  // Data
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

			if (!counter) // If counter is 0
			{
				head = new Queue; // head ay gagawa ng bagong queue
				head->next = NULL; // in head the next will contain null

        // add data
				cout << "Enter Int: ";
				cin >> head->number;

				cout << "Enter Name: ";
				cin >> head->name;

				tail = head; // tail is pointing to head

			}
			else // else counter is not 0
      {
				temp = new Queue; // temp is making new Queue
				temp->next = tail; // in temp there is next where contains tail

        // add data
				cout << "Enter Int: ";
				cin >> temp->number;

				cout << "Enter Name: ";
				cin >> temp->name;

				tail = temp; // tail will be updated
			}

			counter++; // add counter

			break;
		case 2:
			cout << "Traverse\n\n";

			temp = tail; // temp will point to the tail

			if (temp) // if temp is not empty
			{
				do
				{
					cout << temp->number << ". " << temp->name << "\n"; // display the data

					if (temp->next == NULL) // if the next is empty break the loop
						break;

					temp = temp->next; // replace temp with the next from temp
				}
				while (true);
			}
			else // else empty
			{
				cout << "No List Yet";
			}

			system("pause");

			break;
		case 3:
			cout << "Delete";

      // accept what to delete
			cout << "What to Delete: ";
			cin >> toDelete;

      // temp will point tail
			temp = tail;

			do
			{
				if (toDelete == temp->name) { // if toDelete is match with the temps name
					if (prev != NULL) // if the prev is not empty
						prev->next = temp->next;

					delete temp;
			    counter--;
					break;
				}

        if (temp->next == NULL) // if the next is empty break the loop
						break;

				prev = temp; // prev will point temp
				temp = temp->next; // temp will point the temp next
			} while (true);
			break;
		default:
			break;
		}

		system("cls");
	} while (true);

}
