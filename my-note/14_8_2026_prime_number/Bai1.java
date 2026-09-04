import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
import java.util.Arrays;

// i = prime
// sieve[i] = uoc nho nhat cua prime

class Bai1 {

    static final int MAX = 100001;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = Integer.valueOf(scanner.nextLine());

        int[] sieve = Bai1.buildSieve();

        Map<Integer, Integer> factors = prime_factorization(sieve, n);

        boolean first = true;
        for (Map.Entry<Integer, Integer> entry : factors.entrySet()) {
            if (!first) System.out.print(" * ");
            System.out.print(String.format("%d^%d", entry.getKey(), entry.getValue()));
            first = false;
        }

        scanner.close();
    }

    private static int[] buildSieve() {
        int[] sieve = new int[MAX + 1];

        Arrays.fill(sieve, 0);

        for (int i = 2; i < MAX + 1; i++) {
            if (sieve[i] == 0) { // prime
                for (int u = i; u < MAX + 1; u += i) { // bội của prime
                    if (sieve[u] == 0) {
                        sieve[u] = i;
                    }
                }
            }
        }

        return sieve;
    }

    private static Map<Integer, Integer> prime_factorization(int[] sieve, int n) {
        Map<Integer, Integer> factors = new HashMap<>();

        while (n > 1) {
            int p = sieve[n];
            int count = 0;

            while (n % p == 0) {
                count += 1;
                n /= p;
            }

            factors.put(p, count);
        }

        return factors;
    }
}
