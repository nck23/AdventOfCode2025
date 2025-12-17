using System.IO;

namespace _1star
{
    public class Solution
    {
        public static string ReadFile(string filePath)
        {
            if (File.Exists(filePath))
            {
                return File.ReadAllText(filePath);
            }
            else
            {
                return "Plik nie istnieje";
            }
        }
        public static int Solve(string[] allLines)
        {
            int width = allLines[0].Length;
            int height = allLines.Length;
            int counter = 0;
            for (int i =0; i < height; i++)
            {
                for (int j =0; j < width; j++)
                {
                    // Console.WriteLine(allLines[i][j]);
                    if (allLines[i][j] == '.' )
                    {
                        continue;
                    } 
                    int internal_counter = 0; // max_4
                    for (int it = i - 1;it <= i + 1; it++)
                    {
                        if (it < 0 || it >= height) continue;
                         
                        for (int jt = j - 1;jt <= j + 1; jt++)
                        {
                            if (jt < 0 || jt >= width) continue;
                            if (jt == j && it == i) continue;
                            // Console.Write($"it: {it} jt: {jt} i: {i} j: {j} counter: {counter}\n\n");
                            if (allLines[it][jt] == '@')
                            {
                                internal_counter += 1;
                            }
                        }
                        
                    }
                    if (internal_counter < 4)
                    {
                        counter += 1;
                    }
                }
            }
            return counter;
        }
    }
}