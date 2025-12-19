import java.util.List;

public class Main {
    public static void main(String[] args) throws Exception{
        long suma = 0;
        long[][] dane = Solution.readFile("input.txt");
        List<Long> wynik = Solution.get_mirrors(dane);
        for (long wartosc : wynik) {
            // System.out.println(wartosc);
            suma += wartosc;
        }
        System.out.println(suma);
    }
}