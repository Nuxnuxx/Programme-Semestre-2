using System;

namespace age
{
	 class Program
	{
		static void Main(string[] args)
		{
			Console.WriteLine("Donnez votre age");
			int age;
			do
			{
				age = Convert.ToInt32(Console.ReadLine());
			} while (age > 120 || age < 0);
			string statut = (age < 18) ? "mineur" : "majeur";
			Console.WriteLine($"Vous êtes {statut}");
		}
	}
}
