/*
	Program 4
		Rabih Salamey & Hassan Mehdi
		CIS 200 - 02
		12/13/2016
*/

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int t, p, nt, np, time = 0;
	vector<int> itemsPerTrain, itemsPerPlane;
	vector<stack<int>> dockStacks;	//vector of stacks pertaining to train
	queue<int> assemblyLine;

	vector<int> trainFinalTime, planeFinalTime;
	cin >> t >> p >> nt >> np;

	int trainItemsToAdd = nt;

	//temporary data for the time vectors
	for (int i = 0; i < t; i++) {
		trainFinalTime.push_back(0);
	}

	for (int i = 0; i < p; i++) {
		planeFinalTime.push_back(0);
	}

	//inputting the number of items on a train
	/*
	Precondition: t must be greater than 0
	PostCondition: each train is assigned a number of items to be given 
	*/
	for (int i = 0; i < t; i++) {
		int temp;
		cin >> temp;
		itemsPerTrain.push_back(temp);
	}

	//inputting the number if items on a plane
	/*
	Precondition: p must be greater than 0
	PostCondition: each plane is assigned a number of items to be given 
	*/
	for (int i = 0; i < p; i++) {
		int temp;
		cin >> temp;
		itemsPerPlane.push_back(temp);
	}

	//loading the stacks on the dock
	/*
	Precondition: items must not be 0
	PostCondition: stacks are loaded onto the dock
	*/
	for (int i = 0; i < t; i++) {
		stack<int> tempStack;
		if (trainItemsToAdd >= 5) {
			for (int j = 0; j < 5; j++) {
				int temp;
				cin >> temp;
				tempStack.push(temp);
			}
			trainItemsToAdd -= 5;
			dockStacks.push_back(tempStack);
		}
		else {
			for (int j = 0; j < trainItemsToAdd; j++) {
				int temp = 0;
				cin >> temp;
				tempStack.push(temp);
			}
			trainItemsToAdd = 0;
			dockStacks.push_back(tempStack);
		}
	}

	//calculating train time
	/*
	Precondition:  dockStacks must not be empty
	PostCondition: time for trains to be loaded is calculated
	*/
	for (int i = 0; i < t; i++)
		while (dockStacks[i].empty() != true) {
			time += dockStacks[i].top() * 2;
			if (--itemsPerTrain[dockStacks[i].top() - 1] == 0)
				trainFinalTime[dockStacks[i].top() - 1] = time - dockStacks[i].top();
			dockStacks[i].pop();
		}

	//loading plane items
	/*
	Precondition: np must be greater than 0
	PostCondition: items are loaded
	*/
	for (int i = 0; i < np; i++) {
		int temp;
		cin >> temp;
		assemblyLine.push(temp);
	}
	time = 0;
	
	//calculating plane time
	/*
	Precondition: assemblyLine must not be empty
	PostCondition: time for planes to be loaded is calculated
	*/
	while (assemblyLine.empty() != true) {
		time += assemblyLine.front() * 10;
		if (--itemsPerPlane[assemblyLine.front() - 1] == 0)
			planeFinalTime[assemblyLine.front() - 1] = time - assemblyLine.front() * 10 / 2;
		assemblyLine.pop();
	}

	//printing time for each train
	/*
	Precondition: N/A
	PostCondition: time for each train is printed
	*/
	for (int i = 0; i < t; i++)
		cout << trainFinalTime[i] << " ";
	cout << endl;
	
	//printing plane printing time for each plane
	/*
	Precondition: N/A
	PostCondition: time for each plane is printed
	*/
	for (int i = 0; i < p; i++)
		cout << planeFinalTime[i] << " ";

	system("pause");
	return 0;
}
