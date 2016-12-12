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
	vector<int> itemsPerTrain;
	vector<stack<int>> dockStacks;	//vector of stacks pertaining to train

	vector<int> trainFinalTime;
	cin >> t >> p >> nt >> np;

	int trainItemsToAdd = nt;

	//temporary data for the time vectors
	for (int i = 0; i < t; i++) {
		trainFinalTime.push_back(0);
	}


	//inputting the number of items on a train
	for (int i = 0; i < t; i++) {
		int temp;
		cin >> temp;
		itemsPerTrain.push_back(temp);
	}


	//loading the stacks on the dock
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
	for (int i = 0; i < t; i++)
		while (dockStacks[i].empty() != true) {
			time += dockStacks[i].top() * 2;
			if (--itemsPerTrain[dockStacks[i].top() - 1] == 0)
				trainFinalTime[dockStacks[i].top() - 1] = time - dockStacks[i].top();
			dockStacks[i].pop();
		}

	//printing train
	for (int i = 0; i < t; i++)
		cout << trainFinalTime[i] << " ";

	return 0;
}
