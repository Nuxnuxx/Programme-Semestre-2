using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace noisettes
{
    internal class Program
    {
        public static void MAJStockNoisettes(ref int nbNoisettesStock, int nbNoisettesRecoltees)
        {
            nbNoisettesStock += nbNoisettesRecoltees;
        }

        static void Main(string[] args)
        {
            int nbStock = Convert.ToInt32(Console.ReadLine());
            int nbRecolte = Convert.ToInt32(Console.ReadLine());
            MAJStockNoisettes(ref nbStock, nbRecolte);
            Console.WriteLine(nbStock);
        }
    }
}
