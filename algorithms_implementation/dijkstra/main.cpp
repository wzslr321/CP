#include <iostream>
#include <optional>
#include <queue>

template<typename T>
class Dijkstra {
public:
    struct Edge {
        size_t from;
        size_t to;
        T cost;
    };

    struct Node {
        size_t id;
        int64_t value;
    };
private:
    std::vector<std::optional<int64_t>> distances;
    std::vector<T> previous;
    std::vector<std::vector<Edge>> graph;

    static const int EPS = 1e6;


public:
    auto add_edge(const size_t from, const size_t to, const T cost) -> void {
        graph[from].emplace_back(Edge{from, to, cost});
    };

    auto add_edges(const std::vector<Edge> &edges)
    -> void {
        for (const auto &edge : edges) {
            auto[from, to, cost] = edge;
            add_edge(from, to, cost);
        }
    }

    auto reconstruct_path(size_t start, size_t end) -> std::vector<size_t> {
        std::vector<size_t> path{};
        auto distance = run(start, end);
        if (distance == std::nullopt) return path;
        for (size_t i = end; i >= start; i = previous[i]) path.push_back(i);
        reverse(path.begin(), path.end());
        return path;
    }

    auto run(size_t start, size_t end) -> std::optional<int64_t> {
        auto N = graph.size();
        distances.resize(N);
        distances[start] = 0;

        auto compare = [](Node left, Node right) {
            if (std::abs(left.value - right.value) < EPS)return 0;
            return (left.value - right.value) > 0 ? 1 : -1;
        };

        std::priority_queue<Node, std::vector<Node>, decltype(compare)> pq(compare);
        pq.push(Node{start, 0});

        std::vector<bool> visited(N);
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            visited[node.id] = true;

            if (distances[node.id] < node.value) continue;

            for (const auto &edge : graph[node.id]) {
                if (visited[edge.to]) continue;

                auto new_distance = *distances[edge.from] + edge.cost;
                if (new_distance < distances[edge.to]) {
                    previous[edge.to] = edge.from;
                    distances[edge.to] = new_distance;
                    pq.push(Node{edge.to, *distances[edge.to]});
                }
            }
            if (node.id == end) return distances[end];
        }
        return std::nullopt;
    }

};

auto main() -> int {
    Dijkstra<int> dijkstra{};
    std::vector<decltype(dijkstra)::Edge> edges{
            {0, 1, 1},
            {1, 2, 1},
            {2, 4, 1},
            {4, 3, -3},
            {3, 2, 1},
            {1, 5, 4},
            {1, 6, 4},
            {5, 6, 5},
            {6, 7, 4},
            {5, 7, 3},
    };
    dijkstra.add_edges(edges);
    auto distance = dijkstra.run(0, 6);
    !distance ? std::cout << "Unreachable\n" : std::cout << *distance << '\n';
    auto path = dijkstra.reconstruct_path(0, 6);
    for (auto edge : path)
        std::cout << edge << " -> ";
    std::cout << '\n';
}