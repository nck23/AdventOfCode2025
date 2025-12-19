import java.io.IOException;
import java.nio.file.*;
import java.util.ArrayList;
import java.util.List;

public class Solution {
    public static long[][] readFile(String filepath) throws IOException{
        String linie = Files.readString(Paths.get(filepath));
        String formatted = linie.replace("\n", "").replace("\r", "");
        String[] elementy = formatted.split(",");
        long[][] liczby = new long[elementy.length][2];
        for (int i = 0;i < elementy.length;i++) {
            String el = elementy[i];
            String[] para = el.split("-");
            liczby[i][0] = Long.parseLong(para[0]);
            liczby[i][1] = Long.parseLong(para[1]);
        }
        return liczby;
    }

    public static List<Long> get_mirrors(long[][] dane) {
        List<Long> mirrors = new ArrayList<>();
        for (long[] para : dane) {
            long liczba1 = para[0];
            long liczba2 = para[1];
            for (long i = liczba1; i <= liczba2; i++) {
                long length = (int) Math.log10(i) + 1;
                if (length % 2 != 0) continue;
                int divider = (int) Math.pow(10, length / 2);
                long left = i / divider;
                long right = i % divider;
                if (left == right) {
                    mirrors.add(i);
                }
            }
            }
            return mirrors;
        }
}

