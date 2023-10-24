#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

string comppath = "d:/prog/versenyek/hackercup";
string year = "2022";
string roundname = "round1";
string chapter = "1";
string probl = "consecutive_cuts";
// string pathstart = comppath + "/" + year + "/" + roundname + "/" + probl +
//                    (chapter.empty() ? "" : "_chapter_" + chapter);
string pathstart = probl + (chapter.empty() ? "" : "_chapter_" + chapter);

vector<string> inputs({pathstart + "_sample_input.txt",
                       pathstart + "_validation_input.txt",
                       pathstart + "_input.txt"});
vector<string> outputs({pathstart + "_sample_out.txt",
                        pathstart + "_validation_out.txt",
                        pathstart + "_out.txt"});
int submitlevel = 2;

int main() {
  auto start = chrono::high_resolution_clock::now();
  fstream inp, outp;
  inp.open(inputs[submitlevel]);
  outp.open(outputs[submitlevel], ios::out);
  int cases;
  inp >> cases;
  cout << cases << endl;
  for (int cas = 1; cas <= cases; ++cas) {
    int n, k, x;
    inp >> n >> k;
    vector<int> a;
    a.reserve(n);
    vector<int> b;
    b.reserve(n);
    cout << cas << ": " << n << " " << k << endl;
    bool same = true;
    for (int i = 0; i < n; ++i) {
      inp >> a[i];
    }
    int diff;
    for (int i = 0; i < n; ++i) {
      inp >> b[i];
      if (a[0] == b[i]) {
        diff = i;
      }
      if (a[i] != b[i]) {
        same = false;
      }
    }
    cout << "all read: "
         << chrono::duration_cast<chrono::seconds>(
                chrono::high_resolution_clock::now() - start)
                .count()
         << endl;
    bool ok;
    if (n == 2) {
      ok = ((k % 2 == 0) == same);
    } else {
      if (k == 0) {
        ok = same;
      } else {
        ok = k > 1 || !same;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[(i + diff) % n]) {
        ok = false;
        break;
      }
    }
    outp << "Case #" << cas << (ok ? ": YES" : ": NO") << endl;
    outp.flush();
    cout << "case end: "
         << chrono::duration_cast<chrono::seconds>(
                chrono::high_resolution_clock::now() - start)
                .count()
         << endl;
  }
  inp.close();
  outp.close();
  cout << "done: "
       << chrono::duration_cast<chrono::seconds>(
              chrono::high_resolution_clock::now() - start)
              .count()
       << endl;
  return 0;
}