using System;

namespace pain
{
	 class Program
	{
		static void Main(string[] args)
		{
			Console.WriteLine("Donnez un nombre de baguettes a acheter");

			int nombrePain;

			do
			{
				nombrePain = Convert.ToInt32(Console.ReadLine());
				Console.WriteLine("Le nombre doit être entre 1 et 6");
			} while (nombrePain < 1 || nombrePain > 6);

			float prixFinal = 0;
			float prixUneBaguette = 0.80f;

			for (int i = 0; i < nombrePain;i++)
			{
				prixFinal += prixUneBaguette;
				Console.WriteLine($"{i+1} baguette(s) coute(nt) {prixFinal.ToString("n2")} euros");
			}


		}
	}
}
