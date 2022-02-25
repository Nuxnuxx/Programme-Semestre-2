using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Program
    {
        public static void Mystere(double a, double b,out double c,out double d)
        {
            c = a + b; d = a * b;
        }
        public static void Main(string[] args)
        {
            double x = 2, y = 3, z, t;
            Mystere(x, y, out z,out t);
            Console.WriteLine($"z vaut {z} et t vaut {t}");
        }
    }
}
