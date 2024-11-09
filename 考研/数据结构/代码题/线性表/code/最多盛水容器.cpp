#include <algorithm>
#include <iostream>
#include <vector>

int maxArea(std::vector<int>& height) {
	int left = 0;
	int right = height.size() - 1;
	int max_water = 0;

	while (left < right) {
		int width = right - left;
		int current_height = std::min(height[left], height[right]);
		int current_water = width * current_height;
		max_water = std::max(max_water, current_water);

		// Move the shorter line towards the center
		if (height[left] < height[right]) {
			left++;
		} else {
			right--;
		}
	}

	return max_water;
}

int main() {
	std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	int result = maxArea(height);
	std::cout << "The maximum amount of water that can be contained is: "
	          << result << std::endl;
	return 0;
}
