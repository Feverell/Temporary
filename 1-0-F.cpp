#include <iostream>
#include <vector>

int Price(std::vector<int>& x, std::vector<int>& y) {
  if (x[0] >= y[0]) {
    return 1;
  }
  if (x[x.size() - 1] <= y[y.size() - 1]) {
    return x.size();
  }
  int left = 0;
  int right = x.size();
  int middle;
  while (left + 1 != right) {
    middle = (left + right) / 2;
    if (x[middle] <= y[middle]) {
      left = middle;
    } else {
      right = middle;
    }
  }
  if (y[left] < x[right]) {
    return left + 1;
  }
  return right + 1;
}

int main() {
  int n;
  int m;
  int l;
  std::cin >> n >> m >> l;
  std::vector<std::vector<int> > a(n, std::vector<int>(l));
  std::vector<std::vector<int> > b(m, std::vector<int>(l));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < l; j++) {
      std::cin >> a[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < l; j++) {
      std::cin >> b[i][j];
    }
  }
  int q;
  std::cin >> q;
  std::vector<int> ans(q);
  int i;
  int j;
  for (int it = 0; it < q; it++) {
    std::cin >> i >> j;
    i--;
    j--;
    ans[it] = Price(a[i], b[j]);
  }
  for (int it = 0; it < q; it++) {
    std::cout << ans[it] << '\n';
  }
  return 0;
}