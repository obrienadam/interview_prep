#include <iostream>
#include <vector>
#include <limits>

using namespace std;

template<class T>
class TreeNode
{
public:

    TreeNode()
        : _left(nullptr), _right(nullptr)
    {}

    TreeNode(const T& data)
        : TreeNode()
    {
        _data = data;
    }

    ~TreeNode()
    {
        if(_left)
            delete _left;

        if(_right)
            delete _right;
    }

    void insert(const T& data)
    {
        if(data < _data)
        {
            if(_left)
                _left->insert(data);
            else
                _left = new TreeNode(data);
        }
        else
        {
            if(_right)
                _right->insert(data);
            else {
                _right = new TreeNode(data);
            }
        }
    }

    T max() const
    {
        if(_right)
            return _right->max();
        else {
            return _data;
        }
    }

    T min() const
    {
        if(_left)
            return _left->min();
        else {
            return _data;
        }
    }

    void printSorted(bool reverse = false) const {
        if(_left)
            _left->printSorted();

        cout << _data << " ";

        if(_right)
            _right->printSorted();
    }

    T get2ndLargest(TreeNode<T> *parent = nullptr) {
        if(_right)
            return _right->get2ndLargest(this);
        else if(parent)
            return parent->_data;
        else {
            return _data;
        }
    }

    T get2ndSmallest(TreeNode<T> *parent = nullptr) {
        if(_left)
            return _left->get2ndSmallest(this);
        else if (parent) {
            return parent->_data;
        }
        else {
            return _data;
        }
    }

    int getDepth() const {
        int ldepth = _left ? _left->getDepth() + 1 : 0;
        int rdepth = _right ? _right->getDepth() + 1 : 0;
        return std::max(ldepth, rdepth);
    }

    bool isLeafNode() const {
        return !(_left || _right);
    }

    bool isBst(T min = numeric_limits<T>::min(), T max = numeric_limits<T>::max()) const {
        cout << min << " " << max << " " << _data << endl;

        return ((_left ? _left->isBst(min, _data): true) && _data < max) && ((_right ? _right->isBst(_data, max) : true) && _data >= min);
    }

private:

    T _data;

    TreeNode<T> *_left, *_right;
};

int main()
{
    TreeNode<int> root(5);

    root.insert(2);
    root.insert(9);
    root.insert(13);
    root.insert(12);
    root.insert(2);
    root.insert(3);
    root.insert(231);
    root.insert(1);
    root.insert(8);
    root.insert(94);
    root.insert(423);
    root.insert(21);
    root.insert(11);
    root.insert(8);
    root.insert(8);

    cout << root.max() << endl
         << root.min() << endl
         << root.get2ndLargest() << endl
         << root.get2ndSmallest() << endl
         << "depth = " << root.getDepth() << endl
         << root.isBst() << endl;

    return 0;
}
