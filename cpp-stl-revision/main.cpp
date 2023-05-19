#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;  // forgive me lord

void vectorOperations() {
  vector<int> vec = {1, 2, 3};
  vector<int>::iterator x = find(vec.begin(), vec.end(), 2);
  vec.erase(x);
  vec.insert(vec.begin() + 2, 5);
  reverse(vec.begin(), vec.end());
  vector<int> vec2 = {-4, -6};
  vec.insert(vec.end(), vec2.begin(), vec2.end());
}

void listOperations() { /* doubly linked list */
  auto printListForward = [] (list<int>& a) -> void {
    auto x = a.begin();
    while (true) {
      cout << *x;
      x++;
      if (x == a.end()) {
        cout << '\n'; 
        break;
      }
      cout << ' ';
    }
  };

  list<int> doubly;
  doubly.push_back(12);
  doubly.emplace_back(4);
  doubly.push_front(4);
  printListForward(doubly);

  doubly.sort();
  doubly.unique();
  doubly.insert(doubly.begin(), {5, -2, 3});
  printListForward(doubly);

  auto it = find(doubly.begin(), doubly.end(), 3);
  doubly.insert(it, 1000);
  printListForward(doubly);
}

struct Obj {
  int data, id;
  Obj(int data = 0, int id = 0) : data(data), id(id) {}
  int sum() const { return data + id; }
};

bool operator< (const Obj &x, const Obj &y) {
  return x.data + x.id < y.data + y.id;
}

bool operator> (const Obj &x, const Obj &y) {
  return x.data + x.id > y.data + y.id;
}

void pqOperations() {
  priority_queue<Obj, vector<Obj>, greater<Obj> > x;  /* min sum on top */
  x.push(Obj(12, 5));
  x.push(Obj(13, 1));
  cout << x.top().data << ' ' << x.top().id << '\n';
  x.pop();
  cout << x.top().data << ' ' << x.top().id << '\n';
}

void setOperations() {  /* ascending order */
  set<Obj> S;
  S.insert(Obj(3, 4));
  S.insert(Obj(1, 5));
  S.insert(Obj(7, 2));

  set<Obj>::reverse_iterator it = S.rbegin();
  while (it != S.rend()) {
    cout << it->sum() << ' ';  /* this method needs to be const */
    it++;
  } cout << '\n';

  auto hint = S.end();
  hint--;
  S.insert(hint, Obj(1000, -1000));  /* insert with hint */
  S.erase(hint);

  for (auto x : S) {
    cout << x.sum() << ' '; 
  } cout << '\n';

  cout << S.count(Obj(3, 4)) << '\n';
  cout << S.lower_bound(Obj(1, 2))->sum() << '\n';
  S.erase(S.begin(), S.end());    /* not possible with unordered data structures */
}

void heapOperations() {
  cout << "\nHeap\n";
  vector<int> v(5, 0);
  iota(v.begin(), v.end(), 1);
  make_heap(v.begin(), v.end());
  for (auto x : v) cout << x << ' '; cout << '\n';
}

void multimapOperations() { /* does not have .at() and [] */
  cout << "\nMultimap\n";
  multimap<Obj, int> M;
  M.insert({{Obj(1, 2), 5}, {Obj(3, 4), 6}}); /* abusing initializer_list */
  M.insert({Obj(1, 2), 4});
  cout << M.find(Obj(1, 2))->second << '\n';
  cout << M.count(Obj(1, 2)) << '\n';
}

void unorderedMapOperations() {
  cout << "\nUnordered Map\n";
  unordered_map<int, vector<int> > M;
  M[5] = {1, 2, 3};
  M[4] = {5, 6};
  vector<int>& v = M.at(5); /* std::out_of_bound if not in M */
  v.insert(v.begin(), 4);
  /* Iteration is still possible */
  for (auto &x : M)  {
    cout << x.first << '\t';
    for (auto &v : x.second) {
      cout << v << ' '; 
    } cout << '\n';
  }
  /* begin(): no guarantee on which element, but begin -> end covers everything */
  for (auto x = M.begin(); x != M.end(); x++) { 
    cout << x->first << ' '; 
  } cout << '\n';
}

void unorderedSetOperations() {
  cout << "\nUnordered Set\n";
  unordered_set<int, int> S;

}

signed main() {
  vectorOperations();
  listOperations();
  pqOperations();
  setOperations();
  heapOperations();
  multimapOperations();
  unorderedMapOperations();
}