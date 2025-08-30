#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

// Maximum number of vertices, plus a small buffer
const int MAXN = 100005; 
// Fenwick Tree (Binary Indexed Tree)
long long bit[MAXN];
int n_vertices;

// Adds a value to the BIT at a given index
void add(int idx, int val) {
    for (; idx <= n_vertices; idx += idx & -idx) {
        bit[idx] += val;
    }
}

// Queries the cumulative sum up to a given index in the BIT
long long query(int idx) {
    long long sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
    }
    return sum;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read number of vertices
    cin >> n_vertices;

    // Map coordinates to 1-based indices for the BIT
    map<pair<long long, long long>, int> coord_to_index;
    for (int i = 0; i < n_vertices; ++i) {
        long long x, y;
        cin >> x >> y;
        coord_to_index[{x, y}] = i + 1;
    }

    // Read number of flight paths (chords)
    int m;
    cin >> m;

    // Store chords as pairs of indices (u, v) where u < v
    vector<pair<int, int>> chords;
    chords.reserve(m);
    for (int i = 0; i < m; ++i) {
        long long sx, sy, px, py;
        cin >> sx >> sy >> px >> py;
        int u = coord_to_index[{sx, sy}];
        int v = coord_to_index[{px, py}];
        if (u > v) {
            swap(u, v);
        }
        chords.push_back({u, v});
    }

    // Sort chords by their starting point `u`
    sort(chords.begin(), chords.end());

    // Calculate total possible pairs of chords
    long long total_pairs = (long long)m * (m - 1) / 2;
    long long non_intersecting_pairs = 0;

    // Iterate through sorted chords to count non-intersecting pairs
    for (const auto& chord : chords) {
        int u = chord.first;
        int v = chord.second;
        
        // Get counts from BIT needed for calculation
        long long total_vs_in_bit = query(n_vertices);
        long long vs_less_than_v = query(v - 1); // Query for v' < v
        long long vs_less_than_u = query(u - 1); // Query for v' < u

        // Count disjoint pairs: v_j < u_i
        long long disjoint_count = vs_less_than_u;
        
        // Count nested pairs: v_i < v_j. This is total count minus those with v_j <= v_i
        long long nested_count = total_vs_in_bit - query(v);
        
        non_intersecting_pairs += disjoint_count + nested_count;
        
        // Add the current chord's endpoint to the BIT for future comparisons
        add(v, 1);
    }
    
    // The final answer is the difference
    long long intersecting_pairs = total_pairs - non_intersecting_pairs;
    cout << intersecting_pairs << endl;

    return 0;
}