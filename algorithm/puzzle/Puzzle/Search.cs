using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Puzzle
{
    class Search
    {
        Form1 f1;
        public Search(Form1 a)
        {
            this.f1 = a;
        }
        public int cantor(char[] cstr)
        {
            int ans = 0, cnt;
            for (int i = 0; i < 9; ++i)
            {
                cnt = 0;
                for (int j = 0; j < i; ++j)
                    if (cstr[j] < cstr[i]) ++cnt;
                ans += (cstr[i] - '0' - cnt) * f1.fac[8 - i];
            }
            return ans;
        }
        public int geth(char[] cstr)
        {
            int cnt = 0;
            for (int i = 0; i < 9; ++i)
            {
               if (cstr[i] == '0') continue;
               int x = i / 3, y = i % 3;
               int xx = (cstr[i] - '0' - 1) / 3, yy = (cstr[i] - '0' - 1) % 3;
                cnt += Math.Abs(xx - x) + Math.Abs(yy - y);
            }
            return cnt;

        }

        public static void Swap(ref char foo, ref char bar)
        {
            char tmp = foo;
            foo = bar;
            bar = tmp;
        }
        public void dfs(int hashv)
        {
            if (f1.vis[f1.Node[hashv].far])
            {
                dfs(f1.Node[hashv].far);
                f1.op[f1.cnt++] = f1.Node[hashv].oper;
            }
        }
        public void dfs2(int hashv)
        {
            if (f1.count[f1.Node[hashv].far] != 10000)
            {
                dfs2(f1.Node[hashv].far);
                f1.op[f1.cnt++] = f1.Node[hashv].oper;
            }
        }
        public bool check(char[] cstr)
        {
            int cnt = 0;
            for (int i = 0; i < 9; ++i)
            {
                if (cstr[i] == '0') continue;
                for (int j = 0; j < i; ++j)
                    if (cstr[j] > cstr[i]) ++cnt;
            }
            if (cnt % 2 == 0) return true;
            return false;
        }
        public bool BFS()
        {
            Queue<node> bfs = new Queue<node>();
            for (int i = 0; i < 9; ++i) { f1.orig.arry[i] = f1.arry[i]; if (f1.arry[i] == '0') f1.orig.xpos = i; }
            f1.orig.hashv = cantor(f1.orig.arry); f1.vis[f1.orig.hashv] = true;
            bfs.Enqueue(f1.orig);
            while (bfs.Count != 0) 
            {
                f1.temp = bfs.Dequeue();
                int npos, itshash;
                for (int i = 0; i < 4; ++i)
                {
                    npos = f1.temp.xpos + f1.to[i];
                    f1.buffer = new node();
                    f1.buffer.hashv = f1.temp.hashv;
                    f1.buffer.xpos = f1.temp.xpos;
                    for (int j = 0; j < 9; ++j) f1.buffer.arry[j] = f1.temp.arry[j];
                    if (i == 0 && npos >= 0 || i == 1 && npos < 9 || i == 2 && (npos + 1) % 3 != 0 || i == 3 && npos % 3 != 0)
                    {
                        Swap(ref f1.buffer.arry[npos], ref f1.buffer.arry[f1.buffer.xpos]);
                        itshash = cantor(f1.buffer.arry);
                        if (!f1.vis[itshash])
                        {
                            f1.vis[itshash] = true;
                            f1.buffer.hashv = itshash;
                            f1.buffer.xpos = npos;
                            f1.Node[itshash].far = f1.temp.hashv;
                            f1.Node[itshash].oper = f1.direc[i];
                            if (itshash == 46233) return true;
                            bfs.Enqueue(f1.buffer);
                        }
                    }
                }
            }
            return false;
        }
        public bool BFSbest()
        {
            PriorityQueue bfs = new PriorityQueue(Form1.maxs);
            for (int i = 0; i < 9; ++i) { f1.origg.arry[i] = f1.arry[i]; if (f1.arry[i] == '0') f1.origg.xpos = i; }
            f1.origg.hashv = cantor(f1.origg.arry); f1.vis[f1.origg.hashv] = true; f1.origg.h = geth(f1.origg.arry); f1.origg.g = 0; f1.origg.f = f1.origg.h + f1.origg.g;
            bfs.Push(f1.origg);

            while (bfs.Count != 0)
            {
                f1.tempp = bfs.Pop();
                int npos, itshash;
                if (f1.tempp.hashv == 46233) return true;
                for (int i = 0; i < 4; ++i)
                {
                    npos = f1.tempp.xpos + f1.to[i];
                    
                    f1.bufferr = new Anode();
                    f1.bufferr.hashv = f1.tempp.hashv;
                    f1.bufferr.xpos = f1.tempp.xpos;
                    f1.bufferr.g = f1.tempp.g;
                    f1.bufferr.h = f1.tempp.h;
                    f1.bufferr.f = f1.tempp.f;
                    for (int j = 0; j < 9; ++j) f1.bufferr.arry[j] = f1.tempp.arry[j];
                    
                    if (i == 0 && npos >= 0 || i == 1 && npos < 9 || i == 2 && (npos + 1) % 3 != 0 || i == 3 && npos % 3 != 0)
                    {
                        Swap(ref f1.bufferr.arry[npos], ref f1.bufferr.arry[f1.bufferr.xpos]);
                        itshash = cantor(f1.bufferr.arry);
                        
                        if (!f1.vis[itshash] && check(f1.bufferr.arry))
                        {
                            f1.bufferr.h = geth(f1.bufferr.arry);
                            f1.bufferr.g = f1.tempp.g + 1;
                            f1.bufferr.f = f1.bufferr.h + f1.bufferr.g;
                            f1.bufferr.hashv = itshash;
                            f1.bufferr.xpos = npos;
                            f1.Node[itshash].far = f1.tempp.hashv;
                            f1.Node[itshash].oper = f1.direc[i];
                            f1.vis[f1.bufferr.hashv] = true;
                            bfs.Push(f1.bufferr);
                        }
                    }
                }
            }
            return false;
        }

        public void DFS(node a)
        {
            if (a.hashv == 46233 || !check(a.arry)) return;
            for (int i = 0; i < 4; ++i)
            {
                f1.buffer = new node();
                f1.buffer.hashv = a.hashv;
                f1.buffer.xpos = a.xpos;
                for (int j = 0; j < 9; ++j) f1.buffer.arry[j] = a.arry[j];

                int npos = a.xpos + f1.to[i];
                if (i == 0 && npos >= 0 || i == 1 && npos < 9 || i == 2 && (npos + 1) % 3 != 0 || i == 3 && npos % 3 != 0)
                {
                    Swap(ref f1.buffer.arry[npos], ref f1.buffer.arry[f1.buffer.xpos]);
                    int itshash = cantor(f1.buffer.arry);
                    f1.buffer.hashv = itshash;
                    f1.buffer.xpos = npos;

                    int cnt = f1.count[a.hashv] + 1;
                    if (cnt < 75 && cnt < f1.count[itshash])
                    {
                        f1.count[itshash] = cnt;
                        f1.Node[itshash].far = a.hashv;
                        f1.Node[itshash].oper = f1.direc[i];
                        DFS(f1.buffer);
                    }
                }
            }
        }
        public bool getDFS()
        {
            this.initial3();
            for (int i = 0; i < 9; ++i) { f1.orig.arry[i] = f1.arry[i]; if (f1.arry[i] == '0') f1.orig.xpos = i; }
            f1.orig.hashv = cantor(f1.orig.arry); f1.count[f1.orig.hashv] = 0;
            DFS(f1.orig);
            if (f1.count[46233] != 10000) { dfs2(46233); return true; }
            else return false;
        }
        public void DFSB(node a)
        {
            if (a.hashv == 46233 || !check(a.arry)) return;
            for (int i = 0; i < 4; ++i)
            {
                f1.buffer = new node();
                f1.buffer.hashv = a.hashv;
                f1.buffer.xpos = a.xpos;
                for (int j = 0; j < 9; ++j) f1.buffer.arry[j] = a.arry[j];

                int npos = a.xpos + f1.to[i];
                if (i == 0 && npos >= 0 || i == 1 && npos < 9 || i == 2 && (npos + 1) % 3 != 0 || i == 3 && npos % 3 != 0)
                {
                    Swap(ref f1.buffer.arry[npos], ref f1.buffer.arry[f1.buffer.xpos]);
                    int itshash = cantor(f1.buffer.arry);
                    f1.buffer.hashv = itshash;
                    f1.buffer.xpos = npos;

                    int cnt = f1.count[a.hashv] + 1;
                    if (cnt < f1.count[46233] && cnt < f1.count[itshash]) 
                    {
                        f1.count[itshash] = cnt; 
                        f1.Node[itshash].far = a.hashv;
                        f1.Node[itshash].oper = f1.direc[i]; 
                        DFSB(f1.buffer); 
                    }
                }
            }
        }

        public bool getDFSB()
        { 
            this.initial3();
            for (int i = 0; i < 9; ++i) { f1.orig.arry[i] = f1.arry[i]; if (f1.arry[i] == '0') f1.orig.xpos = i; }
            f1.orig.hashv = cantor(f1.orig.arry); f1.count[f1.orig.hashv] = 0; f1.count[46233] = 35;
            DFSB(f1.orig);
            if (f1.count[46233] != 35) { dfs2(46233); return true; }
            else return false;
        }
        public bool getBFS()
        {
            this.initial();
            if (BFS()) { dfs(46233); return true; }
            else return false;
        }
        public bool getBFSbest()
        {
            this.initial2();
            if (BFSbest()) { 
                dfs(46233); return true; }
            else return false;
        }
        void initial()
        {
            f1.orig = new node(); f1.temp = new node(); f1.buffer = new node();
            f1.Node = new node1[Form1.maxs];
            for (int i = 0; i < Form1.maxs; ++i) f1.Node[i] = new node1();
            f1.vis = new bool[Form1.maxs];
            f1.cnt = 0;
            f1.op = new char[Form1.maxs]; 
        }
        void initial3()
        {
            f1.orig = new node();
            f1.Node = new node1[Form1.maxs];
            for (int i = 0; i < Form1.maxs; ++i) f1.Node[i] = new node1();

            f1.count = new int[Form1.maxs];
            for (int i = 0; i < Form1.maxs; ++i) f1.count[i] = 10000;
            f1.cnt = 0;
            f1.op = new char[Form1.maxs];
        }

        void initial2()
        {
            f1.origg = new Anode(); f1.tempp = new Anode(); f1.bufferr = new Anode();
            f1.Node = new node1[Form1.maxs];
            for (int i = 0; i < Form1.maxs; ++i) f1.Node[i] = new node1();
            f1.vis = new bool[Form1.maxs];
            f1.cnt = 0;
            f1.op = new char[Form1.maxs];
        }
    }
}
