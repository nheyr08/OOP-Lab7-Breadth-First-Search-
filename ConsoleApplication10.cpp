
#pragma once
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <fstream>
#include <set>
#include<iomanip>
using namespace std;
class Solver {
public:
	Solver(vector<vector<char> > maze, pair<int, int> startPos, pair<int, int> endPos) {
		this->maze = maze;
		this->currentPos = startPos;
		this->endPos = endPos;
		this->startPos = startPos;
		moveCount = 0;
		NodeLeftInLayer = 100;
		NodeInNextLayer = 0;


		vector<int> temp;
		vector<char>TEMP;
		for (int i = 0; i < maze.size(); i++) {
			for (int j = 0; j < maze.at(0).size(); j++) {
				temp.push_back(0);
				TEMP.push_back('a');
			}
			this->distanceMap.push_back(temp);
			this->VisitedNodesMap.push_back(temp);
			this->AnswerMap.push_back(TEMP);
		}
	}
	void solve() {

		q.push(startPos);

		VisitedNodesMap[startPos.first][startPos.second] = true;
		while (!q.empty()) {
			this->currentPos = q.front();
			//cout << "current" << currentPos.first << " current pos second"<<currentPos.second << endl;
			VisitedNodesMap[currentPos.first][currentPos.second] = 1;
			if (this->currentPos.first == endPos.first&&this->currentPos.second == endPos.second)
			{
				//reached_end = true;
				break;
				cout << "Win" << endl;//to b changed
				break;
			}
			else {
				//for (int i = 0; i < maze.size()-1; i++)
					//for (int j = 0; j < 100; j++) 
				performCheck();
				//currentPos.first = i;
				//currentPos.second = j;

				//currentPos.first = currentPos.first + 1;
				//currentPos.second = currentPos.second + 1;

				//NodeLeftInLayer--;
			}
			if (NodeLeftInLayer == 0)
			{
				NodeLeftInLayer = NodeInNextLayer;
				NodeInNextLayer = 0;
				moveCount++;
			}
			if (reachedEnd)
			{
				//visitedNodes();
				cout << "DONE!" << endl;
				break;
			}
			else
			{
				//return-1;
			}
			//cout << "the size of queue bfor pop" << q.size() << endl;
			q.pop();
			//i++;
			//cout << "go" << endl;
			//}

		}
	}
	void VisitedNodes()
	{
		for (int i = 0; i < VisitedNodesMap.size(); i++)
		{
			for (int j = 0; j < VisitedNodesMap.at(0).size(); j++)
			{ 

				if(VisitedNodesMap.at(i).at(j)>10)
				cout << " "<<this->VisitedNodesMap.at(i).at(j);
				else { VisitedNodesMap.at(i).at(j); }
			}
			cout << endl;
		}
		cout << endl;
		cout << endl;
		cout << " I did all that route= " << Route << endl;;
	}
	void printDistancetravelled() {
		for (int i = 0; i < distanceMap.size(); i++) {
			for (int j = 0; j < distanceMap.at(0).size(); j++) {
				cout << setw(4) << this->distanceMap.at(i).at(j);
		    }
			cout << endl;
		}
		cout << endl;
		cout << endl;
	}

	void Answer()
	{
		cout << "the answer yield" << endl;;
		int Dx[4] = { -1,1,0,0 };
		int Dy[4] = { 0,0,-1,1 };
		pair<int, int>myPair;
		pair<int, int>current;
		pair<int, int>previous = endPos;

		for (int i = distanceMap[endPos.first][endPos.second]; i > 0; i--)
		{
			for (int j = 0; j < 4; j++)
			{

				
				current.first = previous.first + Dx[j];
				current.second = previous.second + Dy[j];
				if (current.first >= 0 && current.second >= 0 && current.first < maze.size() && current.second < maze.at(0).size()) {
					if (distanceMap[current.first][current.second] == i)
					{
						maze[current.first][current.second] = 'o';
						previous = current;
						break;
					}

				}

			}
		}

		for (int i = 0; i < maze.size(); i++)
		{
			for (int j = 0; j < maze.at(0).size(); j++)
			{



				cout << maze[i][j];
			}
			cout << endl;
		}
		/*
				 int N = 0;
				 int R=0,Rr=0,RRr=0,RRR = 0;

				 if(i>0&&j>0)
					 if (((distanceMap[i - 1][j - 1] == distanceMap[i][j]) && distanceMap[endPos.first][endPos.second] - i * j > distanceMap[i][j])) {
						 AnswerMap[i][j] = 'o';
					 }

				 if (i > 0 && j > 0) {
					 Rr = (AnswerMap[i - 1][j] - distanceMap[i][j]);
					 RRr = (AnswerMap[i][j - 1] - distanceMap[i][j]);
				 }
				 //if (j < maze.size()-1)
				 //R = (AnswerMap[i][j + 1] - distanceMap[i][j]);

				 */
				 //if (i < maze.size()-1)
				 //RRR= (AnswerMap[i+1][j] - distanceMap[i][j]);

				 /*distanceMap[i][j] = maze[i][j];


				 switch (Rr)
				 {
				 case 0: {AnswerMap[i][j] = maze[i][j]; break; };
				 //case  : {AnswerMap[i][j] = 'o'; break; }
				 case 1: {AnswerMap[i][j] = 'o'; break; }
				 default:
					 break;
				 }
				 switch (R)
				 {
				 case 0: {AnswerMap[i][j] = maze[i][j]; break; };
				 case-1: {AnswerMap[i][j] = maze[i][j]; break; };
						 //case  : {AnswerMap[i][j] = 'o'; break; }
				 case 1: {AnswerMap[i][j] = 'o'; break; }
				 default:
					 break;
				 }
				 /*switch (RRR)
				 {
				 case 0: {AnswerMap[i][j] = maze[i][j]; break; };
				 case-1: {AnswerMap[i][j] = maze[i][j]; break; };
						 //case  : {AnswerMap[i][j] = 'o'; break; }
				 case 1: {AnswerMap[i][j] = 'o'; break; }
				 default:
					 break;
				 }
				 switch (RRr)
				 {
				 case 0: {AnswerMap[i][j] = maze[i][j]; break; };
				 case-1: {AnswerMap[i][j] = maze[i][j]; break; };
						 //case  : {AnswerMap[i][j] = 'o'; break; }
				 case 1: {AnswerMap[i][j] = 'o'; break; }
				 default:
					 break;
				 }*/


				 /*AnswerMap[i][j] = maze[i][j];
				 //cout << endPos.first;
				 //cout <<"<-first second end value->"<< endPos.second <<" maze size"<< maze.size ()<<"first element size"<<maze.at(0).size()<< endl;
					 //for (int j = endPos.second; j > -1; j--)
				 if (endPos.first - i > 0 && endPos.second - j > 0) {
					 if (distanceMap[endPos.first - i][endPos.second - j] == distanceMap[endPos.first][endPos.second] - k)
					 {
						 AnswerMap[endPos.first - i][endPos.second - j] = 'o';
						 //cout << "hmm1" << endl;
					 }
				 }
			 //	else if (endPos.first + i < maze.size() && endPos.second + j < maze.at(0).size())
					 if (distanceMap[endPos.first + i][endPos.second + j] == distanceMap[endPos.first][endPos.second] - k)
					 {
						 AnswerMap[endPos.first - i][endPos.second - j] = 'o';
						 cout << "hmm2" << endl;
					 }
					 if (distanceMap[endPos.first + i][endPos.second - j] == distanceMap[endPos.first][endPos.second] - k)
					 {
						 AnswerMap[endPos.first - i][endPos.second - j] = 'o';
						 cout << "hmm3" << endl;
					 }
					 if (distanceMap[endPos.first + i][endPos.second - j] == distanceMap[endPos.first][endPos.second] - k)
					 {
						 AnswerMap[endPos.first + i][endPos.second - j] = 'o';
						 cout << "hmm4" << endl;
					 }
					 else { AnswerMap[i][j] = maze[i][j];
					 cout << "hmm5" << endl;
					 }
					 cout << "hmm6" << endl;

				 //cout << "hmm didnt go though loop" << endl;

				 if (distanceMap[i][j] == 0) {
					 AnswerMap[i][j] = maze[i][j];
				 }
				 else if (i < maze.size()-1 && distanceMap[i + 1][j] == distanceMap[i][j] + 1)
					 this->AnswerMap[i][j] = 'o';
				 else if (i > 0 && distanceMap[i - 1][j] == distanceMap[i][j] + 1)
					 this->AnswerMap[i][j] = 'o';
				 else if (j > 0 && distanceMap[i][j - 1] == distanceMap[i][j] + 1)
					 this->AnswerMap[i][j] = 'o';
				 else if(distanceMap[i][j]-distanceMap[endPos.first][endPos.second] +k!=0)
					 this->AnswerMap[i][j] = 'o';
				 //else if (j < maze.at(0).size() && distanceMap[i][j + 1] == distanceMap[i][j] + 1)
					 //this->AnswerMap[i][j] = 'o';
				 //else if((distanceMap[i][j] != distanceMap[i][j - 1] - 1 || distanceMap[i][j] != distanceMap[i - 1][j] - 1 || distanceMap[i][j] != distanceMap[i + 1][j] - 1 || distanceMap[i][j] != distanceMap[i][j + 1] - 1)//||distanceMap[i][j]=='E'|| distanceMap[i][j] =='S')
				 {
					 //AnswerMap[i][j] ='0';
					 //else
					 //	AnswerMap[i][j] = maze[i][j];
					 cout << AnswerMap[i][j];
					 //}cout << endl;
					 k++;
				 }

			 }


			 cout << endl;
		 }*/
	}

	void printMaze();
	
private:
	vector<vector<char> > maze;
	vector<vector<int> > distanceMap;
	vector<vector<int> > VisitedNodesMap;
	vector<vector<char> > AnswerMap;
	pair<int, int> startPos;
	pair<int, int> endPos;
	pair<int, int> currentPos;
	queue<pair<int, int> > q;
	int Value;
	int moveCount;
	int	NodeLeftInLayer;
	int NodeInNextLayer;
	bool reachedEnd;
	int Route;


	void performCheck()
	{
		//for (int i = 0; i < 4; i++) {jjj
		//This check if the current position is in the bound we ser
	//	if (currentPos.first < 0 || currentPos.first < 0)
		
			checkUp();
			checkLeft();
			checkDown();
			checkRight();
	}
 
	void checkUp() {
		if (canGoUp()) {
     		pair<int, int> tempPos = this->currentPos;
			int val = 0;
			tempPos.first = tempPos.first - 1;
			val = this->distanceMap.at(currentPos.first).at(currentPos.second);
			this->distanceMap.at(tempPos.first).at(tempPos.second) = val + 1;
			this->VisitedNodesMap.at(tempPos.first).at(tempPos.second) = 1;
			q.push(tempPos);
			Route++;
		}
	}
	void checkDown() {
		if (canGoDown())
		{
			pair<int, int> tempPos = this->currentPos;
			tempPos.first = tempPos.first + 1;
			int val = this->distanceMap.at(currentPos.first).at(currentPos.second);
			this->distanceMap.at(tempPos.first).at(tempPos.second) = val + 1;
			this->VisitedNodesMap.at(tempPos.first).at(tempPos.second) = 1;
			q.push(tempPos);
			Route++;
		}
		
	}
	void checkLeft() {
		if (canGoLeft())
		{
			pair<int, int> tempPos = this->currentPos;
			tempPos.second = tempPos.second - 1;
			int val = this->distanceMap.at(currentPos.first).at(currentPos.second);
			this->distanceMap.at(tempPos.first).at(tempPos.second) = val + 1;
			this->VisitedNodesMap.at(tempPos.first).at(tempPos.second) = 1;
			q.push(tempPos);
			Route++;
			

		}
		
	}
	void checkRight() {
		if (canGoRight())
		{
			pair<int, int> tempPos = this->currentPos;
			tempPos.second = tempPos.second + 1;
			int val = this->distanceMap.at(currentPos.first).at(currentPos.second);
			this->distanceMap.at(tempPos.first).at(tempPos.second) = val + 1;
			this->VisitedNodesMap.at(tempPos.first).at(tempPos.second) = 1;
			q.push(tempPos);
			Route++;
				
		}
	}
	bool winning()
	{
		if (this->currentPos.first == endPos.first&&this->currentPos.second == endPos.second)
		{
		
			return 1;
		}
		else return false;
	}

	bool canGoUp()
	{
		if (currentPos.first <=0) {
			return 0;
		}
		 if (this->maze.at(currentPos.first -1).at(currentPos.second) == '#'||VisitedNodesMap[currentPos.first - 1][currentPos.second]==1) {
			return 0;
		}
		 
		else {
			return 1;
		}
	}
	bool canGoDown()
	{
		if (currentPos.first >= maze.size() - 1) {
			return 0;
		}
		else if (this->maze.at(currentPos.first + 1).at(currentPos.second) == '#' || VisitedNodesMap[currentPos.first + 1][currentPos.second] == 1) {
			return 0;
		}
		else {
			return 1;
		}

	}
	bool canGoRight()
	{
		if (currentPos.second >= maze.at(0).size()-1) {
			return 0;
		}
 	    if (this->maze.at(currentPos.first).at(currentPos.second + 1) == '#' || VisitedNodesMap[currentPos.first ][currentPos.second+1] == 1) {
			return 0;
		}
			return 1;
    }
	bool canGoLeft()
	{
		if (currentPos.second <= 0) {
			
			return 0;

		}
		else if (this->maze.at(currentPos.first).at(currentPos.second -1) == '#' || VisitedNodesMap[currentPos.first][currentPos.second -1] == 1) {
          			
			return 0;
		}
		
			return 1;
	
	}

};

	int main() {
		fstream  file;
		file.open("input.txt");
		if (!file.is_open()) {
			cout << "Failed to open file!" << endl;
			return 0;
		}
		int TestCase = 0;
		file >> TestCase;
		while (TestCase) {
			pair<int, int> startPos, endPos;
			vector<vector<char> > maze;
			int mazeRowSize, mazeColSize;
			file >> mazeRowSize >> mazeColSize;
			for (int i = 0; i < mazeRowSize; i++) {
				vector<char> row;
				for (int j = 0; j < mazeColSize; j++) {
					char temp;
					file >> temp;
					row.push_back(temp);
					if (temp == 'S') {
						startPos.first = i;
						startPos.second = j;
					}
					if (temp == 'E') {
						endPos.first = i;
						endPos.second = j;
					}
				}
				maze.push_back(row);
			}

			Solver* m = new Solver(maze, startPos, endPos);
			m->printMaze();
			m->solve();
			m->printDistancetravelled();
			m->Answer();
		
		

			delete m;
			TestCase--;
		}
		return 0;
	}

	void Solver::printMaze() {
		for (int i = 0; i < maze.size(); i++) {
			for (int j = 0; j < maze.at(0).size(); j++) {
				cout << this->maze.at(i).at(j);
			}
			cout << endl;
		}
		cout << endl;
		cout << endl;
	}
	/*
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	*/