#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

void shuffle(vector<int>& v) {
    for(int i = 0; i < v.size(); ++i) {
        int j = rand() % (v.size() - i) + i;
        swap(v[i], v[j]);
    }
}

void qsort(vector<int>& v) {
    deque<pair<int, int>> q;
    q.push_front(make_pair(0, v.size() - 1));

    while(!q.empty()) {
        auto p = q.front();
        q.pop_front();

        int lo = p.first;
        int hi = p.second;

        if(hi - lo < 1)
            continue;

        int il = lo;
        int ir = hi - 1;

        while(true) {
            bool incL = v[il] < v[hi];
            bool decR = v[ir] >= v[hi];

            if(incL)
                ++il;

            if(decR)
                --ir;

            if(il > ir) {
                swap(v[il], v[hi]);
                q.push_front(make_pair(il + 1, hi));
                q.push_front(make_pair(lo, il - 1));
                break;
            }

            if(!incL && !decR)
                swap(v[il], v[ir]);
        }
    }
}

void ssort(vector<int>& v) {
    for(int i = 0; i < v.size(); ++i) {
        int imin = i;

        for(int j = i; j < v.size(); ++j) {
            if(v[j] < v[imin])
                imin = j;
        }

        swap(v[i], v[imin]);
    }
}

void isort(vector<int>& v) {
    for(int i = 0; i < v.size(); ++i) {
        int j = i + 1;

        while(j > 0 && v[j] < v[j - 1]) {
            swap(v[j], v[j-1]);
            --j;
        }
    }
}

struct Node {
    Node(int d): data(d)
    {}

    Node* insert(int data) {
        if(next)
            return next->insert(data);
        else {
            next = new Node(data);
            next->prev = this;
            return next;
        }
    }

    Node* reverse() {
        auto tmp = next;

        next = prev;
        prev = tmp;

        if(tmp) {
            return tmp->reverse();
        } else {
            return this;
        }
    }

    int data;
    Node* next = nullptr;
    Node* prev = nullptr;
};

class Heap {
public:

    Heap(const vector<int>& v): _data(v.rbegin(), v.rend()) {
        heapify();
    }

    int top() const {
        return _data.back();
    }

    void pop() {
        _data.pop_back();
        heapify();
    }

    bool empty() const {
        return _data.empty();
    }

private:

    int lchild(int i) const {
        int ic = 2 * i + 1;
        return ic < _data.size() ? ic: -1;
    }

    int rchild(int i) const {
        int ic = 2 * i + 2;
        return ic < _data.size() ? ic: -1;
    }

    int parent(int i) const {
        if(i == 0)
            return -1;

        return i % 2 == 1 ? i / 2 : i / 2 - 1;
    }

    bool isHeap(int i) const {
        int lc = lchild(i);
        int rc = rchild(i);

        if(lc != -1 && _data[_data.size() - lc - 1] > _data[_data.size() - i - 1])
            return false;

        if(rc != -1 && _data[_data.size() - rc - 1] > _data[_data.size() - i - 1])
            return false;

        return true;
    }

    void heapify() {
        deque<int> q;
        for(int i = 0; i < _data.size(); ++i)
            q.push_front(i);

        while(!q.empty()) {
            int root = q.front();
            q.pop_front();

            if(isHeap(root))
                continue;

            int lc = lchild(root);
            int rc = rchild(root);
            int imaxc;

            if(lc == -1)
                imaxc = rc;
            else if(rc == -1)
                imaxc = lc;
            else
                imaxc = (_data[_data.size() - lc - 1] > _data[_data.size() - rc - 1]) ? lc : rc;

            swap(_data[_data.size() - imaxc - 1], _data[_data.size() - root - 1]);

            q.push_front(imaxc);

            int p = parent(root);
            if(p != -1)
                q.push_front(p);
        }
    }

    vector<int> _data;
};

void hsort(vector<int> &v) {
    Heap h(v);

    for(auto itr = v.rbegin(); itr != v.rend(); ++itr) {
        *itr = h.top();
        h.pop();
    }
}

int main() {
    vector<int> v(50);

    for(int &n: v)
        n = rand() % 1000;
//
//    qsort(v);
//    shuffle(v);
//
//    for(int n: v)
//        cout << n << endl;
//
//    ssort(v);
//    cout << endl;
//
//    for(int n: v)
//        cout << n << endl;
//
//    shuffle(v);
//
//    isort(v);
//
//    cout << endl;
//    for(int n: v)
//        cout << n << endl;

//    Node* h = new Node(0);
//    for(int i = 0; i < 20; ++i)
//        h->insert(i + 1);
//
//    h = h->reverse();
//
//    auto n = h;
//
//    while(n) {
//        cout << n->data << endl;
//        n = n->next;
//    }

    hsort(v);

    for(auto n: v) {
        cout << n << endl;
    }

    return 0;
}