using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

namespace Puzzle
{
    public partial class Form1 : Form
    {
        public char[] arry;
        public const int maxs = 400000;
        public node orig = new node(), temp = new node(), buffer = new node();
        public node1[] Node = new node1[maxs];
        public Anode origg = new Anode(), tempp = new Anode(), bufferr = new Anode();
        public bool[] vis = new bool[maxs];
        public int[] count = new int[maxs];

        public char[] direc = new char[4] { 'u', 'd', 'l', 'r' };
        public int[] to = new int[4] { -3, 3, -1, 1 };
        public int[] fac = new int[10] { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
        public int cnt = 0;
        public int xxpos;
        public char[] op = new char[maxs];
        Search sol;

        public Form1()
        {
            InitializeComponent();
            MessageBox.Show("19计创 吴斌权 201930343483");
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            sol = new Search(this);
            if (radioButton1.Checked)
            {
                long oldtime = DateTime.Now.Ticks;
                bool flag = sol.getBFS();
                double useTime = (DateTime.Now.Ticks - oldtime) / 10000000.0D;
                if (flag) MessageBox.Show("Find the solution!");
                    else MessageBox.Show("No solution!");
                textBox3.Text = Convert.ToString(cnt);
                textBox2.Text = Convert.ToString(useTime);
                for (int i = 0; i < 9; ++i)
                    if (arry[i] == '0') xxpos = i;
                for (int i = 0; i < cnt; ++i)
                {
                    if(op[i] == 'u') { Search.Swap(ref arry[xxpos], ref arry[xxpos - 3]); xxpos -= 3; updatelabel(); Thread.Sleep(500); }
                    else if (op[i] == 'd') { Search.Swap(ref arry[xxpos], ref arry[xxpos + 3]); xxpos += 3; updatelabel(); Thread.Sleep(500); }
                    else if (op[i] == 'l') { Search.Swap(ref arry[xxpos], ref arry[xxpos - 1]); xxpos -= 1; updatelabel(); Thread.Sleep(500); }
                    else if (op[i] == 'r') { Search.Swap(ref arry[xxpos], ref arry[xxpos +1]); xxpos += 1; updatelabel(); Thread.Sleep(500); }
                }
                MessageBox.Show("Finished!");
            }

            else if (radioButton2.Checked)
            {
                long oldtime = DateTime.Now.Ticks;
                bool flag = sol.getDFS();
                double useTime = (DateTime.Now.Ticks - oldtime) / 10000000.0D;
                if (flag) MessageBox.Show("Find the solution!");
                else MessageBox.Show("No solution!");
                textBox3.Text = Convert.ToString(cnt);
                textBox2.Text = Convert.ToString(useTime);
                for (int i = 0; i < 9; ++i)
                    if (arry[i] == '0') xxpos = i;
                for (int i = 0; i < cnt; ++i)
                {
                    if (op[i] == 'u') { Search.Swap(ref arry[xxpos], ref arry[xxpos - 3]); xxpos -= 3; updatelabel(); Thread.Sleep(500); }
                    else if (op[i] == 'd') { Search.Swap(ref arry[xxpos], ref arry[xxpos + 3]); xxpos += 3; updatelabel(); Thread.Sleep(500); }
                    else if (op[i] == 'l') { Search.Swap(ref arry[xxpos], ref arry[xxpos - 1]); xxpos -= 1; updatelabel(); Thread.Sleep(500); }
                    else if (op[i] == 'r') { Search.Swap(ref arry[xxpos], ref arry[xxpos + 1]); xxpos += 1; updatelabel(); Thread.Sleep(500); }
                }
                MessageBox.Show("Finished!");
            }

            else if (radioButton3.Checked)
            {
                long oldtime = DateTime.Now.Ticks;
                bool flag = sol.getBFSbest();
                double useTime = (DateTime.Now.Ticks - oldtime) / 10000000.0D;
                if (flag) MessageBox.Show("Find the solution!");
                else MessageBox.Show("No solution!");
                textBox3.Text = Convert.ToString(cnt);
                textBox2.Text = Convert.ToString(useTime);
                for (int i = 0; i < 9; ++i)
                    if (arry[i] == '0') xxpos = i;
                for (int i = 0; i < cnt; ++i)
                {
                    if (op[i] == 'u') { Search.Swap(ref arry[xxpos], ref arry[xxpos - 3]); xxpos -= 3; updatelabel(); Thread.Sleep(500); }
                    else if (op[i] == 'd') { Search.Swap(ref arry[xxpos], ref arry[xxpos + 3]); xxpos += 3; updatelabel(); Thread.Sleep(500); }
                    else if (op[i] == 'l') { Search.Swap(ref arry[xxpos], ref arry[xxpos - 1]); xxpos -= 1; updatelabel(); Thread.Sleep(500); }
                    else if (op[i] == 'r') { Search.Swap(ref arry[xxpos], ref arry[xxpos + 1]); xxpos += 1; updatelabel(); Thread.Sleep(500); }
                }
                MessageBox.Show("Finished!");
            }

            else if (radioButton4.Checked)
            {
                long oldtime = DateTime.Now.Ticks;
                bool flag = sol.getDFSB();
                double useTime = (DateTime.Now.Ticks - oldtime) / 10000000.0D;
                if (flag) MessageBox.Show("Find the solution!");
                else MessageBox.Show("No solution!");
                textBox3.Text = Convert.ToString(cnt);
                textBox2.Text = Convert.ToString(useTime);
                for (int i = 0; i < 9; ++i)
                    if (arry[i] == '0') xxpos = i;
                for (int i = 0; i < cnt; ++i)
                {
                    if (op[i] == 'u') { Search.Swap(ref arry[xxpos], ref arry[xxpos - 3]); xxpos -= 3; updatelabel(); Thread.Sleep(500); }
                    else if (op[i] == 'd') { Search.Swap(ref arry[xxpos], ref arry[xxpos + 3]); xxpos += 3; updatelabel(); Thread.Sleep(500); }
                    else if (op[i] == 'l') { Search.Swap(ref arry[xxpos], ref arry[xxpos - 1]); xxpos -= 1; updatelabel(); Thread.Sleep(500); }
                    else if (op[i] == 'r') { Search.Swap(ref arry[xxpos], ref arry[xxpos + 1]); xxpos += 1; updatelabel(); Thread.Sleep(500); }
                }
                MessageBox.Show("Finished!");
            }
        }
        private void updatelabel()
        {
            if (arry[0] != '0') this.label1.Text = arry[0].ToString();
            else this.label1.Text = "";
            if (arry[1] != '0') this.label2.Text = arry[1].ToString();
            else this.label2.Text = "";
            if (arry[2] != '0') this.label3.Text = arry[2].ToString();
            else this.label3.Text = "";
            if (arry[3] != '0') this.label4.Text = arry[3].ToString();
            else this.label4.Text = "";
            if (arry[4] != '0') this.label5.Text = arry[4].ToString();
            else this.label5.Text = "";
            if (arry[5] != '0') this.label6.Text = arry[5].ToString();
            else this.label6.Text = "";
            if (arry[6] != '0') this.label7.Text = arry[6].ToString();
            else this.label7.Text = "";
            if (arry[7] != '0') this.label8.Text = arry[7].ToString();
            else this.label8.Text = "";
            if (arry[8] != '0') this.label9.Text = arry[8].ToString();
            else this.label9.Text = "";
            this.label1.Refresh();
            this.label2.Refresh();
            this.label3.Refresh();
            this.label4.Refresh();
            this.label5.Refresh();
            this.label6.Refresh();
            this.label7.Refresh();
            this.label8.Refresh();
            this.label9.Refresh();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            arry = new char[9];
            int[] check = new int[] { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
            for (int i = 0; i < 9; ++i)
            {
                Random ra = new Random();
                int num = ra.Next(0, 8);
                while (true)
                {
                    if (check[num] == 1)
                    {
                         ra = new Random();
                         num = ra.Next(0, 9);
                    }
                    else
                    {
                        check[num] = 1;
                        arry[i] = Convert.ToChar(num+'0');
                        break;
                    }
                }
            }
            updatelabel();
        }
    }
}
