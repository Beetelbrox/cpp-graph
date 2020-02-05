#ifndef _ADJLIST_GUARD
#define _ADJLIST_GUARD

#include <vector>
#include <utility>

class AdjList {
 public:
  size_t get_num_vertices() const;
  size_t get_num_edges() const;
  bool is_directed() const;

 protected:
  AdjList(bool dir=0);
  void add_vertex();
  void add_edge(size_t src, size_t dst, int weight=1);
  bool is_valid_vertex(size_t v) const;
  bool is_valid_edge(size_t src, size_t dst) const;

  size_t num_vertices_;
  size_t num_edges_;
  size_t active_vertices_;
  bool directed_;
 
 private:
  typedef std::pair<size_t, int> EdgeEndpoint;
  std::vector<std::vector<EdgeEndpoint>> in_edges_;
  std::vector<std::vector<EdgeEndpoint>> out_edges_;
  std::vector<bool> vertex_liveness_;

};
#endif