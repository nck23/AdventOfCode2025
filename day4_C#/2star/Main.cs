using _1star;

string filePath = "input.txt";

string[] allLines = Solution.ReadFile(filePath).Split('\n');

int output = Solution.Solve_2(allLines);

Console.WriteLine(output);