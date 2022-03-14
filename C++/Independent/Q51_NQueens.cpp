#include<cstdio>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
private:
	int m_depth;
	vector<vector<int>> availability;
	vector<vector<string>> boardSolutions;

	void Initialize(int _size)
	{
		m_depth = _size;
		availability.clear();
		boardSolutions.clear();
		vector<int> row(_size, 0);
		for(int i = 0; i < _size; i++)
			availability.push_back(row);
	}
	void PrintAvailableBoard()
	{
		cout << "Printing Board..." << endl;
		for(int i = 0; i < availability.size(); i++)
		{
			for(int j = 0; j < availability[i].size(); j++)
			{
				cout << availability[i][j];
			}
			cout << endl;
		}
	}

	bool CheckAvailability(int _startColumn)
	{
		bool foundBlock = false;
		for(int i = 0; i < availability.size(); i++)
		{
			for(int j = _startColumn; j < availability[i].size(); j++)
			{
				if(availability[i][j] == 0)
				{
					foundBlock = true;
					break;
				}
			}
			if(foundBlock)
				break;
		}
		return foundBlock;
	}

	void SetOrRewindDirtyMark(bool _isSet, int _y, int _x)
	{
		// 90 degree
		for(int i = 0; i < availability.size(); i++)
		{
			if(i != _y)
				availability[i][_x] += (_isSet) ? 1 : -1;
		}

		// 180 degree
		for(int i = 0; i < availability[_y].size(); i++)
		{
			if(i != _x)
				availability[_y][i] += (_isSet) ? 1 : -1;
		}

		// 135 degree
		int startY = _y;
		int startX = _x;
		while((startY > 0) && (startX > 0))
		{
			startY--;startX--;
		}
		for(int i = startY, j = startX; i < availability.size() && j < availability[i].size(); i++, j++)
		{
			if(i != _y || j != _x)
				availability[i][j] += (_isSet) ? 1 : -1;			
		}

		// 45 degree
		startY = _y;
		startX = _x;
		while((startY < availability.size()-1) && (startX > 0))
		{
			startY++;startX--;
		}
		for(int i = startY, j = startX; i >= 0 && j < availability[i].size(); i--, j++)
		{
			if(i != _y || j != _x)
				availability[i][j] += (_isSet) ? 1 : -1;			
		}

		// Center
		availability[_y][_x] = (_isSet) ? -1 : 0;
	}

	void AddSolution()
	{
		vector<string> solution;
		
		int queenFound = 0;
		for(int i = 0; i < availability.size(); i++)
		{
			string row = "";
			for(int j = 0; j < availability[i].size(); j++)
			{
				if(availability[i][j] == -1)
				{
					queenFound++;
					row.append("Q");
				}
				else
					row.append(".");
			}
			solution.push_back(row);
		}

		if(queenFound == m_depth)
			boardSolutions.push_back(solution);
		else
			cout << "m_depth: " << m_depth << ", but queenOnlyFound " << queenFound << endl;
	}

	void RecursiveSearch(int _currentdepth)
	{
		if(_currentdepth >= m_depth)
		{
			AddSolution();
			return;
		}
		else if(!CheckAvailability(_currentdepth))
		{
			return;
		}
		else
		{
			for(int i = 0; i < availability.size(); i++)
			{
				if(availability[i][_currentdepth] == 0)
				{
					SetOrRewindDirtyMark(true, i, _currentdepth);
					RecursiveSearch(_currentdepth + 1);
					SetOrRewindDirtyMark(false, i, _currentdepth);
				}
			}
		}
	}
public:
    vector<vector<string>> solveNQueens(int n) {
        Initialize(n);

		RecursiveSearch(0);

		return boardSolutions;
    }

	int totalNQueens(int n) {
        Initialize(n);

		RecursiveSearch(0);
		
		return boardSolutions.size();
    }
};

int main()
{
	Solution solution;

	vector<vector<string>> answer = solution.solveNQueens(9);
	cout << answer.size() << " answers found!" << endl;
	for(int i = 0; i < answer.size(); i++)
	{
		cout << "Answer: " << i+1 << endl;
		for(int j = 0; j < answer[i].size(); j++)
		{
			cout << answer[i][j] << endl;
		}
		cout << endl;
	}

	return 0;
}