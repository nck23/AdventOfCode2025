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
        for (long i = liczba1; i <= liczba2; i++) { // iterate through each number
        long length = (long) Math.log10(i) + 1;
        for (long j = 1; j <= length / 2; j++) { // iterate through size length of prefix to length/2
            long sprawdzana_liczba = i;
            long count = 0;
            long divider = (long) Math.pow(10, length - j); // divider to get prefix
            long prefix_value = i / divider;
            while (sprawdzana_liczba != 0) {
                if (sprawdzana_liczba % Math.pow(10, j) == prefix_value) { // modulo dynamically to power of 10s cuz prefix value can be different
                    count++;
                    sprawdzana_liczba /= Math.pow(10, j);
                } else {
                    break;
                }
            }
            if (count*j == length) { // count*j cuz j is prefix length and if its bigger count need to be adjusted
                mirrors.add(i);
                break;
            } 
        }   
    }
    }
        return mirrors;
    }
}

