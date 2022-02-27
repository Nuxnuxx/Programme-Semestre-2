using System;


namespace piratePartage
{
    internal class Program
    {

        public static bool ButinPartage(int pieceOr, int bicorne,int tricorne)
        {
            if ((pieceOr - (bicorne * 2 + tricorne * 3)) > 0)
            {
                return true;
            } else
            {
                return false;
            }
        }
        public static void Main(string[] args)
        {
            int pieceOr = Convert.ToInt32(Console.ReadLine());
            int bicorne = Convert.ToInt32(Console.ReadLine());
            int tricorne = Convert.ToInt32(Console.ReadLine());

            bool statutButin = ButinPartage(pieceOr, bicorne,tricorne);
            if (statutButin)
            {
                Console.WriteLine("Partage possible");
            } else
            {
                Console.WriteLine("Partage impossible");
            }

        }
    }
}
