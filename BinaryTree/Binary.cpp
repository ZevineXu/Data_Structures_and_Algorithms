//
// Created by ThinkPad on 2019/11/15.
//author: 软1803 徐志

#include "Binary.h"
#include "SearchTree.h"
#include "AVLTree.h"
#include "Heap.h"
#include "ThreadTree.h"

namespace BinaryTree {

    void SearchTreeTest() {
        SearchTree<int> st(10);
        st.insert(8);
        st.insert(15);
        st.insert(7);
        st.insert(11);
//        st.insert(7);
//        st.insert(9);
//        st.insert(12);
//        st.insert(1);
//        st.insert(13);
//        st.insert(11);
        int leaf = 0;
        int oneChild = 0;
        int twoChild = 0;
        st.noChild(st.getRoot(), &leaf);
        st.oneChild(st.getRoot(), &oneChild);
        st.twoChild(st.getRoot(), &twoChild);

        std::cout << "leaf\t" << leaf << "\toneChild\t" << oneChild << "\ttwoChild\t" << twoChild << std::endl;

        int height = 0;

        st.getHeight(st.getRoot(), &height);
        std::cout << "height\t" << height << std::endl;

        int width = 0;
        st.getWidth(st.getRoot(), &width);
        std::cout << "width\t" << width << std::endl;

        int maxValue = 0;
        st.getMax(st.getRoot(), &maxValue);
        std::cout << "max value\t" << maxValue << std::endl;

//        st.exchange(st.getRoot());
        st.inOrder(st.getRoot());

        // st.deleteCurrentLeaf(st.getRoot(),NULL);

        if (st.isCompleteBinaryTree()) {
            std::cout << "complete binary tree!" << std::endl;
        }
    }

    void AVLTreeTest() {
        using namespace std;
        AVLTree<int> avl;
        avl.insert(50);
        avl.insert(30);
        avl.insert(80);
        avl.inOrder(avl.getRoot());
        cout << endl;
        avl.insert(20);
        avl.insert(10);
        avl.inOrder(avl.getRoot());

        cout << endl;
        avl.insert(90);
        avl.insert(100);
        avl.insert(110);
        avl.inOrder(avl.getRoot());
        cout << endl;
        avl.insert(105);
        avl.inOrder(avl.getRoot());
    }

    void ThreadTreeTest() {
        using namespace std;
        ThreadTree<int> tree(10);
        tree.insert(8);
        tree.insert(12);
        tree.insert(13);
        tree.insert(18);
        tree.insert(6);
        tree.insert(9);
        threadNode<int> *pre = NULL;
        tree.InThread(tree.getRoot(), pre);
        tree.InOrder(tree.getRoot());
    }

    void HeapTest() {
        using std::cout;
        using std::endl;
        int arr[10] = {20, 12, 35, 15, 10, 80, 30, 17, 2, 1};
        Heap<int> *maxhp = new MaxHeap<int>(arr, 10, 20);
        cout << "the max heap" << endl;
        maxhp->display();
//        maxhp->insert(90);
//        cout<<endl;
//        cout<<"insert 90"<<endl;
//        maxhp->display();
//        cout<<endl;

        if (maxhp->remove(1)) {
            cout << "suc" << endl;
        }
        maxhp->display();

//        Heap<int>* minhp = new MinHeap<int>(arr,10,20);
//        cout<<"the min heap"<<endl;
//        minhp->display();
//        minhp->insert(-3);
//        cout<<endl;
//        cout<<"insert -3"<<endl;
//        minhp->display();
    }
}

