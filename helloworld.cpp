#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int numIslands(vector<vector<char>>& grid) {
	const int H = grid.size(), W = grid[0].size(); 

	function<void(int, int)> dfs = [&dfs, &grid, H, W](int r, int c) {
		if (r < 0 || r >= H || c < 0 || c >= W
			|| 1 != grid[r][c]) {
				return; 
			}
		grid[r][c] = 2; 
		dfs(r - 1, c); 
		dfs(r, c + 1); 
		dfs(r + 1, c); 
		dfs(r, c - 1);
	};

	int islands = 0; 
	for (int r = 0; r < H; ++r) 
		for (int c = 0; c < W; ++c) {
			if (1 == grid[r][c]) {
				dfs(r, c); 
				islands++; 
			}
		}
	return islands; 
}


int main()
{
	vector<int> nums = {-1,0,1,2,-1,-4}; 
	threeSum(nums); 
	return 0; 
}