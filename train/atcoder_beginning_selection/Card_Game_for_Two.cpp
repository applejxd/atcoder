#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

int main() {
	int n{0};
	std::cin >> n;
	if (n < 1 || n > 100) {
		throw std::runtime_error("input error");
	}
	
	std::vector<int> a(n,0);
	for (int idx=0; idx<n; ++idx) {
		std::cin >> a.at(idx);
		if (a.at(idx) < 1 || a.at(idx) > 100) {
		    throw std::runtime_error("input error");
	    }
	}
	
	std::sort(a.begin(), a.end(), 
	    [](int a, int b) { return a > b; });
	
	std::vector<int> alice_vec{}, bob_vec{};
	for (int idx=0; idx<a.size(); ++idx) {
		if (idx % 2 == 0) {
			alice_vec.push_back(a.at(idx));
		} else {
			bob_vec.push_back(a.at(idx));
		}
	}
	
	int alice_score = std::accumulate(alice_vec.begin(), alice_vec.end(), 0);
	int bob_score = std::accumulate(bob_vec.begin(), bob_vec.end(), 0);
	
	std::cout << alice_score - bob_score << std::endl;
	
	return 0;
}
