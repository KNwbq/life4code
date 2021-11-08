using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Puzzle
{
    public class node
    {
        public int hashv;
        public int xpos;
        public char[] arry = new char[9];
    };
    public class node1
    {
        public node1() { far = 399999; oper = 'N'; }
        public int far;
        public char oper;
    };

    public class Anode
    {
        public int hashv;
        public int xpos;
        public char[] arry = new char[9];
        public int f, g, h;

        public Anode() { }
        public Anode(Anode x)
        {
            hashv = x.hashv;
            xpos = x.xpos;
            f = x.f;
            g = x.g;
            h = x.h;
            for (int i = 0; i < 9; ++i) arry[i] = x.arry[i];
        }
    }
    class PriorityQueue
    {
        Anode[] heap;
        public int Count { get; private set; }
        public PriorityQueue(int capacity)
        {
            this.heap = new Anode[capacity];
        }
        public int Compare(Anode x, Anode y)
        {
            if (x.f < y.f) return 1;
            else if (x.f > y.f) return -1;
            else
            {
                if (x.g < y.g) return 1;
                return -1;
            }
        }
        public void Push(Anode v)
        {
            if (Count >= heap.Length) Array.Resize(ref heap, Count * 2);
            heap[Count] = v;
            SiftUp(Count++);
        }
        public Anode Pop()
        {
            var v = Top();
            heap[0] = heap[--Count];
            if (Count > 0) SiftDown(0);
            return v;
        }

        public Anode Top()
        {
            if (Count > 0) return heap[0];
            throw new InvalidOperationException("Priority queue is null!");
        }
        void SiftUp(int n)
        {
            var v = heap[n];
            for (var n2 = (n - 1) / 2; n > 0 && Compare(v, heap[n2]) > 0; n = n2, n2 = (n2-1) / 2) heap[n] = heap[n2];
            heap[n] = v;
        }
        void SiftDown(int n)
        {
            var v = heap[n];
            for (var n2 = n * 2 + 1; n2 < Count; n = n2, n2 = 2*n2 + 1)
            {
                if (n2 + 1 < Count && Compare(heap[n2 + 1], heap[n2]) > 0) n2++;
                if (Compare(v, heap[n2]) >= 0) break;
                heap[n] = heap[n2];
            }
            heap[n] = v;
        }
    }
    public class Comparer : IComparer<Anode>
    {
        public int Compare(Anode x, Anode y)
        {
            if (x.f < y.f) return 1;
            return -1;
        }
    }
}
