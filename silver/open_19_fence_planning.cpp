#include<fstream>
#include<vector>

using namespace std;

typedef pair<int, int> pii;

int n, m, color = 1, c[100000], x1 = 100000000, x2 = 0, y1 = 100000000, y2 = 0, ans = 400000000;

pii acorns[100000];

vector<int> adj[100000];

void dfs(int a) {
    c[a] = color;

    x1 = min(x1, acorns[a].first);
    x2 = max(x2, acorns[a].first);
    y1 = min(y1, acorns[a].second);
    y2 = max(y2, acorns[a].second);

    for (int i : adj[a])
        if (!c[i])
            dfs(i);
}

int main() {
    ifstream in("fenceplan.in");
    ofstream out("fenceplan.out");
    in >> n >> m;

    for (int i = 0; i < n; i++)
        in >> acorns[i].first >> acorns[i].second;

    for (int i = 0; i < m; i++) {
        int a, b;
        in >> a >> b;

        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < n; i++) {
        if (!c[i]) {
            x1 = 100000000, x2 = 0, y1 = 100000000, y2 = 0;
            dfs(i);
            ans = min(ans, 2 * (x2 - x1 + y2 - y1));
            color++;
        }
    }

    out << ans << "\n";
}
