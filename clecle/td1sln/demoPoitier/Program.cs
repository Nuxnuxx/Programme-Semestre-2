using System;

namespace demoPoitier
{
	 class Program
	{
		static void Main(string[] args)
		{
			double populationPoitiers = 87646;
			int année = 0;

			do
			{
				populationPoitiers += (populationPoitiers * 0.89 / 100);
				année++;
			} while (populationPoitiers < 100000);
			Console.WriteLine($"Il faut {année} années pour atteindre 100000 habitants a poitiers");

		}
	}
}
