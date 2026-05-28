#include <iostream>

struct Step
{
	int disk;
	char from;
	char to;
	Step* prev;
	Step* next;
};

Step* startStep = nullptr;
Step* endStep = nullptr;

void addStep(int disk, char from, char to)
{
	Step* newStep = new Step{disk, from, to, nullptr, nullptr};

	if (startStep == nullptr)
	{
		startStep = newStep;
		endStep = newStep;
	}

	else
	{
		endStep->next = newStep; // (*endStep).next = newStep
		newStep->prev = endStep;
		endStep = newStep;
	}
}

void hanoi(int n, char from, char to, char auxStick)
{
	if (n==1)
	{
		addStep(n, from, to);
		return;
	}
	hanoi(n-1, from, auxStick, to);
	addStep(n, from, to);
	hanoi(n-1, auxStick, to, from);
}

void printList()
{
	Step* current = startStep;
	int numStep = 1;
	while (current != nullptr)
	{
		std::cout << numStep << ".    ";
		std::cout << "Ring " << current->disk << ": ";
		std::cout << current->from << " --> " << current->to << std::endl;
		current = current->next;
		numStep++;
	}
}

void clearList()
{
	Step* current = startStep;
	while (current != nullptr)
	{
		Step* next = current->next;
		delete current;
		current = next;
	}

	startStep = endStep = nullptr;
}

int main(int argc, char* argv[])
{
	int n = std::stod(argv[1]);

	hanoi(n, 'A', 'B', 'C');
	printList();
	clearList();
	return 0;
}
